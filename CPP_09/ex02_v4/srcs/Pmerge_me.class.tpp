/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge_me.class.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/05/08 02:24:24 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge_me.class.hpp"
#pragma once

/****************************************************/
/*                    Constructor                   */
/****************************************************/

template <int N>
PmergeMe<N>::PmergeMe() : num(0), label("") {}

template <int N>
PmergeMe<N>::PmergeMe(typename PairN<N>::type v, int n, std::string l, int i)
    : pair(v), num(n), label(l), index(i)
    {}

template <int N>
PmergeMe<N>::PmergeMe(const PmergeMe<N> &other)
    : pair(other.pair), num(other.num), label(other.label), index(other.index)
    {}

/****************************************************/
/*                    Overload                      */
/****************************************************/

template <int N>
PmergeMe<N> &PmergeMe<N>::operator=(const PmergeMe<N> &other)
{
    if (this != &other)
    {
        pair = other.pair;
        num = other.num;
        label = other.label;
        index = other.index;
    }
    return *this;
}

/****************************************************/
/*                    Destructor                    */
/****************************************************/

template <int N>
PmergeMe<N>::~PmergeMe() {}

/****************************************************/
/*                Member Functions                  */
/****************************************************/

template <int N>
typename PairN<N>::type PmergeMe<N>::get_pair() const
{
    return pair;
}

template <int N>
int PmergeMe<N>::get_num() const
{
    return num;
}

template <int N>
std::string PmergeMe<N>::get_label() const
{
    return label;
}

template <int N>
int PmergeMe<N>::get_index() const
{
    return index;
}

template <int N>
void PmergeMe<N>::set_index(int i)
{
    this->index = i;
}


/****************************************************/
/*                Output Overload                   */
/****************************************************/

template <int N>
std::ostream &operator<<(std::ostream &os, const PmergeMe<N> &pl)
{
    os << "pair: " << pl.get_pair()
       << " num: " << pl.get_num()
       << " label: " << pl.get_label()
       << " index of pair: " << pl.get_index();
    return os;
}

/****************************************************/
/*         Functions to make and sort pairs         */
/****************************************************/

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::pair<T, T> &pair)
{
    o << "{" << pair.first << ", " << pair.second << "}";
    return o;
}

template <typename T>
void print_pairs_vector(const std::vector<std::pair<T, T> > &vec)
{
    std::cout << GREEN << "Generated pairs: [";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (i != 0)
            std::cout << ", ";
        std::cout << vec[i];
    }
    std::cout << "]" << RESET_COLOR << std::endl;
}

/****************************************************/
/*                    Make pairs                   */
/****************************************************/

template<int N>
std::vector<typename PairN<N + 1>::type> group_into_pairs(const std::vector<typename PairN<N>::type>& input, bool group)
{
    typedef typename PairN<N + 1>::type Pair;
    std::vector<Pair> output;

    typename std::vector<typename PairN<N>::type>::const_iterator it = input.begin();
    typename std::vector<typename PairN<N>::type>::const_iterator end = input.end();

    while (it != end)
    {
        typename PairN<N>::type first = *it++;
        if (it != end)
        {
            typename PairN<N>::type second = *it++;
            if (group == true)
                sort_numbers<N>(first, second);
            output.push_back(std::make_pair(first, second));
        }
        else
        {
            break;
        }
    }
    if (group == true)
    {
        print_pairs_vector(output);
    }
    return output;
}


/****************************************************/
/*         Template for getting second value        */
/****************************************************/

template <int N>
struct GetSecond
{
    typedef typename PairN<N>::type PairType;
    static typename PairN<0>::type& getSecond(PairType& pair)
    {
        return GetSecond<N - 1>::getSecond(pair.second);
    }
};

template <>
struct GetSecond<0>
{
    static int& getSecond(int& value)
    {
        return value;
    }
};

template<int N>
int second_number(typename PairN<N>::type& first)
{
    int& a_deep = GetSecond<N>::getSecond(first);
    return a_deep;
}

/****************************************************/
/*                    Sort numbers                  */
/****************************************************/


template<int N>
bool sort_numbers(typename PairN<N>::type& first, typename PairN<N>::type& second)
{
    int& a_deep = GetSecond<N>::getSecond(first);
    int& b_deep = GetSecond<N>::getSecond(second);

    if (a_deep > b_deep)
    {
        std::swap(first, second);
        return (true);
    }
    return(false);
}

/****************************************************/
/*         utils                                    */
/****************************************************/

template<int N>
void reconstrust_main_vec(std::vector<PmergeMe<N> > &main, t_original_vector &vec)
{
    std::vector<typename PairN<N>::type> m;
    for (size_t i = 0; i < main.size(); ++i)
    {
        m.push_back(main[i].get_pair());
    }
    std::vector <int> r = reconstruct_from_nested_pairs<N>(m);
    vec.used.insert(vec.used.begin(), r.begin(), r.end());
}

template<int N>
void print_chains(std::vector<PmergeMe<N> > &main, std::vector<PmergeMe<N> > &pend, std::string sign)
{
    std::cout << RED << LINE << sign << LINE<< RESET_COLOR << std::endl;
    std::cout << RED << "main: " << RESET_COLOR << std::endl;
    print_pair_object<N>(main);
    std::cout << RED << "pend: " << RESET_COLOR << std::endl;
    print_pair_object<N>(pend);
}

/****************************************************/
/*         Template for constructors                */
/****************************************************/

template <int N, int MaxLevel>
struct ConstructLevels 
{
    typedef typename PairN<N>::type CurrentLevelType;
    typedef std::vector<CurrentLevelType> CurrentVectorType;
    typedef typename PairN<MaxLevel>::type FinalLevelType;
    typedef std::vector<FinalLevelType> FinalVectorType;
    static FinalVectorType run(CurrentVectorType& current_vec, bool group, t_original_vector &vec) 
    {
        if(group)
        {
            std::cout << "Recursion level: " << N << " -> " << N + 1 << std::endl;
            std::vector<int> reconstructed_current = reconstruct_from_nested_pairs<N>(current_vec);
            save_rest_to_vector(vec.info, reconstructed_current, vec.leftovers, N+1);
        }
        typename std::vector<typename PairN<N+1>::type> next_level_vec = group_into_pairs<N>(current_vec, group);
        if(group)
        {
            vec.used = reconstruct_from_nested_pairs<N+1>(next_level_vec);
            pretty_print(vec);
        }
        (void)vec;
        return ConstructLevels<N + 1, MaxLevel>::run(next_level_vec, group, vec);
    }
};

template <int MaxLevel>
struct ConstructLevels<MaxLevel, MaxLevel> 
{
    typedef typename PairN<MaxLevel>::type FinalLevelType;
    typedef std::vector<FinalLevelType> FinalVectorType;

    static FinalVectorType run(FinalVectorType& current_vec, bool group, t_original_vector &vec) 
    {
        if (group)
        {
            vec.used = reconstruct_from_nested_pairs<MaxLevel>(current_vec);
            restore_original_vector(vec);
        }
        (void)group;
        return current_vec;
    }
};

/****************************************************/
/*         Template for unwrapping                  */
/****************************************************/

template<int N, typename VecType, typename NextLevelVecType>
void process_rest_and_reconstruct(VecType& vec, NextLevelVecType& next_level_vec)
{
    std::vector<int> rest_vec;
    rest_vec.insert(rest_vec.end(), vec.leftovers.begin(), vec.leftovers.begin() + vec.info[N - 1].rest);
    vec.leftovers.erase(vec.leftovers.begin(), vec.leftovers.begin() + vec.info[N - 1].rest);

    if (!rest_vec.empty())
    {
        typedef typename PairN<N - 1>::type FinalPairType;
        typedef std::vector<FinalPairType> FinalVectorType;
        FinalVectorType final_result = ConstructLevels<0, N - 1>::run(rest_vec, false, vec);
        next_level_vec.push_back(final_result[0]);
    }
}


template <int N>
std::vector<typename PairN<N - 1>::type> unwrap_pairs(const std::vector<typename PairN<N>::type>& input)
{
    typedef typename PairN<N>::type InputPair;
    typedef typename PairN<N - 1>::type OutputType;
    typedef typename std::vector<InputPair>::const_iterator InputIterator;
    std::vector<OutputType> output;
    for (InputIterator it = input.begin(); it != input.end(); ++it) 
    {
        output.push_back(it->first);
        output.push_back(it->second);
    }
    return output;
}


template <int N, int TargetLevel>
struct RecursiveUnwrapper 
{
    typedef typename PairN<N>::type CurrentLevelType;
    typedef std::vector<CurrentLevelType> CurrentVectorType;
    typedef typename PairN<N-1>::type PrevLevelType;
    typedef std::vector<PrevLevelType> PrevVectorType;
    typedef typename PairN<TargetLevel>::type FinalLevelType;
    typedef std::vector<FinalLevelType> FinalVectorType;

    static FinalVectorType run(const CurrentVectorType& current_vec, t_original_vector &vec) 
    {
        std::cout << "Recursion level: " << N << " -> " << N - 1 << std::endl;
        typename std::vector<typename PairN<N-1>::type> next_level_vec = unwrap_pairs<N>(current_vec);
        if (N - 1 <= 2)
        {
            process_rest_and_reconstruct<N>(vec, next_level_vec);
            unwrapped_sort<N-1>(next_level_vec, vec);
            next_level_vec = ConstructLevels<0, N - 1>::run(vec.used, false, vec);
        }
        return RecursiveUnwrapper<N - 1, TargetLevel>::run(next_level_vec, vec);
    }
};

template <int TargetLevel>
struct RecursiveUnwrapper<TargetLevel, TargetLevel> 
{
    typedef typename PairN<TargetLevel>::type FinalLevelType;
    typedef std::vector<FinalLevelType> FinalVectorType;
    static FinalVectorType run(const FinalVectorType& current_vec, t_original_vector &vec) 
    {
        (void)vec;
        return current_vec;
    }
};

/****************************************************/
/*       Template for vector reconstruction        */
/****************************************************/

template<int M>
void unwrap_single_pair_recursive(typename PairN<M>::type& pair_to_unwrap, std::vector<int>& output_vec)
{
    unwrap_single_pair_recursive<M - 1>(pair_to_unwrap.first, output_vec);
    unwrap_single_pair_recursive<M - 1>(pair_to_unwrap.second, output_vec);
}


template<>
inline void unwrap_single_pair_recursive<0>(int& pair_to_unwrap, std::vector<int>& output_vec)
{
    output_vec.push_back(pair_to_unwrap);
}

template<int N>
std::vector<int> reconstruct_from_nested_pairs(std::vector<typename PairN<N>::type>& input_vector)
{
    std::vector<int> result_vector;
    typedef typename std::vector<typename PairN<N>::type>::iterator InputIter;
    for (InputIter it = input_vector.begin(); it != input_vector.end(); ++it)
    {
        typename PairN<N>::type& current_pair_object = *it;
        unwrap_single_pair_recursive<N>(current_pair_object, result_vector);
    }
    return result_vector;
}

/****************************************************/
/*                Sort indexes                      */
/****************************************************/
template<int N>
void print_pair_object(std::vector<PmergeMe<N> > vec)
{
    typename std::vector<PmergeMe<N> >::iterator it = vec.begin();
    typename std::vector<PmergeMe<N> >::iterator end = vec.end();
    while (it != end)
    {
        std::cout << *it << std::endl;
        it++;
    }
}

template <int N>
PmergeMe<N> pair_object(typename PairN<N>::type p, int c, std::string s, int i)
{
    typedef typename PairN<N>::type PairType;
    PairType first = p;
    int num = second_number<N>(p);
    std::string label = s + std::to_string(c);
    return(PmergeMe<N> (first, num, label, i));
}


//TODO: by some pretty, but ugly logic - it works :)
template<int N>
void update_indexes(std::vector<PmergeMe<N> > &main, int insert_position, std::vector<PmergeMe<N> > &pend)
{
    typename std::vector<PmergeMe<N> >::iterator it = main.begin();
    for (; it < main.end(); ++it)
    {
        it->set_index(-1);
    }
    typename std::vector<PmergeMe<N> >::iterator it_p = pend.begin() + insert_position;
    for (; it_p < pend.end(); it_p++)
    {
        if(it_p->get_index() > 0)
            it_p->set_index(it_p->get_index() + 1);
    }
}

/****************************************************/
/*         binary insertion                          */
/****************************************************/

template<int N>
void binary_insertion(std::vector<PmergeMe<N> > &main, PmergeMe<N> number, std::vector<PmergeMe<N> > &pend)
{
    int comparison_count = 0;
    int end_of_slice = number.get_index();
    if (end_of_slice < 0)
        end_of_slice = main.size();
    int insert_num = number.get_num();
    int start_of_slice = 0;

    int position_to_insert = insert_position(main, start_of_slice, end_of_slice, insert_num, comparison_count);
    std::cout << "\n[ Total comparisons: " << comparison_count << " | Numbers to compare " << end_of_slice << "]" << std::endl;
    std::cout << "[ Inserting at position " << position_to_insert << "]" << std::endl;
    main.insert(main.begin() + position_to_insert, number);
    update_indexes(main, end_of_slice, pend);
}

template<int N>
int insert_position(std::vector<PmergeMe<N> > &main, int start_of_slice, int end_of_slice, int insert_num, int &comparison_count)
{
    if (start_of_slice >= end_of_slice)
        return start_of_slice;
    comparison_count++;
    int mid = (start_of_slice + end_of_slice) / 2;
    int mid_num = main[mid].get_num();
    if (insert_num == mid_num)
        return mid;
    else if (insert_num > mid_num)
        return insert_position(main, mid + 1, end_of_slice, insert_num, comparison_count);
    else
        return insert_position(main, start_of_slice, mid, insert_num, comparison_count);
}


/****************************************************/
/*         main and pend                            */
/****************************************************/

template<int N>
void unwrapped_sort(std::vector<typename PairN<N>::type>& input, t_original_vector &vec)
{
    typedef typename PairN<N>::type PairType;
    typedef PmergeMe<N> PmergeMeType;

    std::vector<PmergeMeType> main;
    std::vector<PmergeMeType> pend;

    if (input.size() != 2)
    {
        typename std::vector<PairType>::iterator it = input.begin();
        typename std::vector<PairType>::iterator end = input.end();

        int c = 1;
        int i = 0;
        while (it != end)
        {
            if(it+1 == end )
            {
                i = -1;
            }
            pend.push_back(pair_object<N>(*it, c, "b", i));
            ++it;

            if (it != end)
            {
                main.push_back(pair_object<N>(*it, c, "a", i));
                ++it;
            }
            ++c;
            ++i;
        }
        chains_jakobstahl_sequence(main, pend);
        reconstrust_main_vec(main, vec);
        print_vector("main after sort",vec.used);
    }
}

/****************************************************/
/*         jakobstahls                              */
/****************************************************/

template<int N>
void jakob_queue(std::vector<PmergeMe<N> > &main, std::vector<PmergeMe<N> > &pend, int jakob_prev_index, int jakob_index)
{
    std::deque<PmergeMe<N> > dq(pend.begin() + jakob_prev_index, pend.begin() + jakob_index);
    int full_size = dq.size();
    int i = 1;
    while (!dq.empty()) 
    {
        PmergeMe<N> item = dq.back();
        binary_insertion(main, item, pend);
        print_chains(main, pend, "Jacobstahl number: " + std::to_string(jakob_index) + ". Queue: " + std::to_string(i) + "/"  + std::to_string(full_size));
        dq.pop_back();
        i++;
    } 
}

template<int N>
void chains_jakobstahl_sequence(std::vector<PmergeMe<N> > &main, std::vector<PmergeMe<N> > &pend)
{
    int limit = pend.size();
    int index_start = 0;
    int jacob_prev = 1;
    int jacob_curr = 1;

    print_chains<N>(main, pend, "before changes");
    jakob_queue<N>(main, pend, index_start, index_start + 1);
    index_start++;


    int jacob_next = jacob_curr + 2 * jacob_prev;
    while (jacob_next <= limit)
    {
        int count = jacob_next - jacob_curr;
        jakob_queue<N>(main, pend, index_start, index_start + count);
        index_start += count;

        jacob_prev = jacob_curr;
        jacob_curr = jacob_next;
        jacob_next = jacob_curr + 2 * jacob_prev;
    }
    if (index_start < limit)
    {
        jakob_queue<N>(main, pend, index_start, limit);
    }
}


