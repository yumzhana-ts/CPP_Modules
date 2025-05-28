/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge_me.class.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/05/19 16:36:35 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge_me.class.hpp"
#pragma once

/****************************************************/
/*                    Constructor                   */
/****************************************************/

template <int N>
PmergeMe<N>::PmergeMe() : num(0), ab("") {}

template <int N>
PmergeMe<N>::PmergeMe(typename PairN<N>::type v, int n, std::string a, int iab, int i)
    : pair(v), num(n), ab(a), index_ab(iab), index(i)
    {}

template <int N>
PmergeMe<N>::PmergeMe(const std::string& ab, int index) 
    : ab(ab), index_ab(index) 
    {}

template <int N>
PmergeMe<N>::PmergeMe(const PmergeMe<N> &other)
    : pair(other.pair), num(other.num), ab(other.ab), index_ab(other.index_ab), index(other.index)
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
        ab = other.ab;
        index_ab = other.index_ab;
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
std::string PmergeMe<N>::get_ab() const
{
    return ab;
}

template <int N>
int PmergeMe<N>::get_index_ab() const
{
    return index_ab;
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
       << " label: " << pl.get_ab() << pl.get_index_ab()
       << " index of pair: " << pl.get_index();
    return os;
}



template <typename T>
std::ostream &operator<<(std::ostream &o, const std::pair<T, T> &pair)
{
    o << "{" << pair.first << ", " << pair.second << "}";
    return o;
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
    if (group == true && DEBUG == 1)
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
unpack_main_structure
void reconstrust_main_vec(std::vector<PmergeMe<N> > &main, t_original_vector &vec)
{
    std::vector<typename PairN<N>::type> m;
    for (size_t i = 0; i < main.size(); ++i)
    {
        m.push_back(main[i].get_pair());
    }
    std::vector <int> r = reconstruct_from_nested_pairs<N>(m);
    vec.used.clear();
    vec.used.insert(vec.used.begin(), r.begin(), r.end());
}

template<int N>
void print_chains(std::vector<PmergeMe<N> > &main, std::vector<PmergeMe<N> > &pend, std::string sign)
{
    if (DEBUG == 1)
    {
        std::cout << RED << LINE << sign << LINE<< RESET_COLOR << std::endl;
        std::cout << RED << "main: " << RESET_COLOR << std::endl;
        print_pair_object<N>(main);
        std::cout << RED << "pend: " << RESET_COLOR << std::endl;
        print_pair_object<N>(pend);        
    }

}

template <typename T>
void print_pairs_vector(const std::vector<std::pair<T, T> >& vec)
{
    if (DEBUG == 1)
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
}

template <int N>
void print_smart(const std::vector<typename PairN<N>::type>& vec)
{
    if (DEBUG == 1)
    {
        std::cout << GREEN << "[";
        for (size_t i = 0; i < vec.size(); ++i)
        {
            if (i != 0)
                std::cout << ", ";
            std::cout << vec[i];
        }
        std::cout << "]" << RESET_COLOR << std::endl;
    }
}

/****************************************************/
/*         Template for constructors                */
/****************************************************/


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
            if (DEBUG == 1){std::cout << "Recursion level: " << N << " -> " << N + 1 << std::endl;}
            std::vector<int> reconstructed_current = reconstruct_from_nested_pairs<N>(current_vec);
            save_rest_to_vector(vec.info, reconstructed_current, vec.leftovers, N+1);
        }
        typename std::vector<typename PairN<N+1>::type> next_level_vec = group_into_pairs<N>(current_vec, group);
        if(group)
        {
            vec.used = reconstruct_from_nested_pairs<N+1>(next_level_vec);
            if (DEBUG == 2){pretty_print(vec);}
        }
        (void)vec;
        if(next_level_vec.size() == 1)
        {
            if (DEBUG == 2){std::cout << "i am grouped at " << N + 1 << std::endl;}
            vec.used = reconstruct_from_nested_pairs<N+1>(next_level_vec);
            restore_original_vector(vec);
        }
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
            if (DEBUG == 1){pretty_print(vec);}
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
        if (DEBUG == 1){std::cout << "Recursion level: " << N << " -> " << N - 1 << std::endl;}
        typename std::vector<typename PairN<N-1>::type> next_level_vec = unwrap_pairs<N>(current_vec);
        process_rest_and_reconstruct<N>(vec, next_level_vec);
        unwrapped_sort<N-1>(next_level_vec, vec);
        next_level_vec = ConstructLevels<0, N - 1>::run(vec.used, false, vec);
        if (DEBUG == 2){pretty_print(vec);}
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
        //process_rest_and_reconstruct<TargetLevel>(vec, current_vec);
        //unwrapped_sort<0>(current_vec, vec);
        //current_vec = ConstructLevels<0, TargetLevel>::run(vec.used, false, vec);
        //pretty_print(vec);
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


template<int N>
void update_indexes(std::vector<PmergeMe<N> > &main, int insert_position, std::vector<PmergeMe<N> > &pend)
{
    typename std::vector<PmergeMe<N> >::iterator it = main.begin();
    for (; it < main.end(); ++it)
    {
        update_index<N>(*it, pend);
    }
    (void)insert_position;
    typename std::vector<PmergeMe<N> >::iterator it_p = pend.begin();
    for (; it_p < pend.end(); it_p++)
    {
        update_index<N>(*it_p, main);
    }
}


/****************************************************/
/*         binary insertion                          */
/****************************************************/

template<int N>
void update_index(PmergeMe<N> &obj, std::vector<PmergeMe<N> > &vec) 
{
    std::string find_pair_ab = (obj.get_ab() == "a") ? "b" : "a";
    int position = obj.get_index_ab();
    
    PmergeMe<N> target(find_pair_ab, position);
    typename std::vector<PmergeMe<N> >::iterator it = std::find(vec.begin(), vec.end(), target);
    if (it != vec.end()) 
    {
        obj.set_index(std::distance(vec.begin(), it));
    } else {
        obj.set_index(-1);
    }
}

template<int N>
void binary_insertion(std::vector<PmergeMe<N> > &main, PmergeMe<N> &number, std::vector<PmergeMe<N> > &pend, int &total_comparisons)
{
    int comparison_count = 0;
    int end_of_slice = number.get_index();
    if (end_of_slice < 0)
        end_of_slice = main.size();
    int insert_num = number.get_num();
    int start_of_slice = 0;

    if (DEBUG == 2 || DEBUG == 1) {
        std::cout << "\n--- Binary Insertion Start ---\n";
        std::cout << number << std::endl;
        std::cout << "Insert number: " << insert_num << "\n";
        std::cout << "Search range: [0, " << number.get_index() << ")\n";
        std::cout << "Initial main vector size: " << main.size() << "\n";
    }

    int position_to_insert = insert_position(main, start_of_slice, end_of_slice, insert_num, comparison_count);
    total_comparisons += comparison_count;

    if (DEBUG == 1 || DEBUG == 2)
    {
        std::cout << "\n[ Total comparisons (this step): " << comparison_count
                  << " | Numbers to compare: " << end_of_slice << " ]" << std::endl;
        std::cout << "[ Inserting at position: " << position_to_insert << " ]" << std::endl;
    }

    main.insert(main.begin() + position_to_insert, number);

    if (DEBUG == 2) {
        std::cout << "Updated main vector size: " << main.size() << "\n";
        std::cout << "--- Binary Insertion End ---\n\n";
    }

    update_indexes(main, end_of_slice, pend);
}


template<int N>
int insert_position(std::vector<PmergeMe<N> > &main, int start_of_slice, int end_of_slice, int insert_num, int &comparison_count)
{
    if (DEBUG == 2) {
        std::cout << "Checking range [" << start_of_slice << ", " << end_of_slice << ")\n";
    }

    if (start_of_slice >= end_of_slice) {
        if (DEBUG == 2) {
            std::cout << "Base case hit. Insert position: " << start_of_slice << "\n";
        }
        return start_of_slice;  // Insert at the start position if the range is empty
    }

    comparison_count++;
    int mid = (start_of_slice + end_of_slice) / 2;
    int mid_num = main[mid].get_num();

    if (DEBUG == 2) {
        std::cout << "Comparing insert_num " << insert_num << " with mid_num " << mid_num << " at index " << mid << "\n";
    }

    // We want to find the first position where insert_num can be inserted
    if (insert_num <= mid_num) {
        if (DEBUG == 2) {
            std::cout << "Going left or insert_num == mid_num: [" << start_of_slice << ", " << mid << ")\n";
        }
        return insert_position(main, start_of_slice, mid, insert_num, comparison_count);
    }
    else {
        if (DEBUG == 2) {
            std::cout << "Going right: [" << (mid + 1) << ", " << end_of_slice << ")\n";
        }
        return insert_position(main, mid + 1, end_of_slice, insert_num, comparison_count);
    }
}



/****************************************************/
/*         main and pend                            */
/****************************************************/

template <int N>
PmergeMe<N> pair_object(typename PairN<N>::type p, int c, std::string s, int i)
{
    typedef typename PairN<N>::type PairType;
    PairType first = p;
    int num = second_number<N>(p);
    return(PmergeMe<N> (first, num, s, c, i));
}

template<int N>
void unwrapped_sort(std::vector<typename PairN<N>::type>& input, t_original_vector &vec)
{
    typedef typename PairN<N>::type PairType;
    typedef PmergeMe<N> PmergeMeType;

    std::vector<PmergeMeType> main;
    std::vector<PmergeMeType> pend;
    print_smart<N>(input);
    if (input.size() != 1)
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
        vec.total_comparisons+= chains_jakobstahl_sequence(main, pend);
        reconstrust_main_vec(main, vec);
    }
}

/****************************************************/
/*         jakobstahls                              */
/****************************************************/

template<int N>
void jakob_queue(std::vector<PmergeMe<N> > &main, std::vector<PmergeMe<N> > &pend, int jakob_prev_index, int jakob_index, int &total_comparisons)
{
    int full_size = jakob_index - jakob_prev_index;
    int i = 1;

    // Create reversed queue
    std::vector<int> reverse_queue;
    for (int index = jakob_index - 1; index >= jakob_prev_index; --index)
        reverse_queue.push_back(index);

    // Process reversed queue
    for (std::vector<int>::size_type k = 0; k < reverse_queue.size(); ++k)
    {
        int idx = reverse_queue[k];
        PmergeMe<N> &item = pend[idx];
        binary_insertion(main, item, pend, total_comparisons);
        if (DEBUG == 1)
        {
            std::ostringstream oss;
            oss << "Jacobstahl reversed. Queue: " << i << "/" << full_size;
            print_chains(main, pend, oss.str());
        }
        ++i;
    }
}

template<int N>
int chains_jakobstahl_sequence(std::vector<PmergeMe<N> > &main, std::vector<PmergeMe<N> > &pend)
{
    int total_comparisons = 0;

    int limit = pend.size();
    int index_start = 0;
    int jacob_prev = 1;
    int jacob_curr = 1;

    print_chains<N>(main, pend, "before changes");
    jakob_queue<N>(main, pend, index_start, index_start + 1, total_comparisons);
    index_start++;

    int jacob_next = jacob_curr + 2 * jacob_prev;
    while (jacob_next <= limit)
    {
        int count = jacob_next - jacob_curr;
        jakob_queue<N>(main, pend, index_start, index_start + count, total_comparisons);
        index_start += count;

        jacob_prev = jacob_curr;
        jacob_curr = jacob_next;
        jacob_next = jacob_curr + 2 * jacob_prev;
    }
    if (index_start < limit)
    {
        jakob_queue<N>(main, pend, index_start, limit, total_comparisons);
    }
    if (DEBUG == 1) {std::cout << "\n[ TOTAL COMPARISONS: " << total_comparisons << " ]" << std::endl;}
    return (total_comparisons);
}

/****************************************************/
/*        meta meta meta                            */
/****************************************************/


template <int MAX_RECURSION_DEPTH>
void meta_recursive(t_original_vector &vec)
{
    enum { TARGET_UNWRAP_LEVEL = 0};
    if (vec.original_vector.size() <= 1) 
    {
        std::cout << "Vector size is less then one" << std::endl;
        return;
    }
    typedef typename PairN<MAX_RECURSION_DEPTH>::type FinalPairType;
    typedef  std::vector<FinalPairType> FinalVectorType;
    if (DEBUG == 1) {std::cout << BLUE << LINE << "wrapping numbers" << LINE <<  RESET_COLOR << std::endl;}
    FinalVectorType final_result = ConstructLevels<0, MAX_RECURSION_DEPTH>::run(vec.original_vector, true, vec);
    if (DEBUG == 1) {std::cout << BLUE << "\n "<< LINE << "vector after sorting" << LINE <<  RESET_COLOR << std::endl;}
    if (DEBUG == 1) {std::cout << BLUE << "\n "<< LINE <<  "unwrapping numbers" << LINE <<  RESET_COLOR << std::endl;}
    typedef typename PairN<TARGET_UNWRAP_LEVEL>::type UnwrappedElementType;
    typedef std::vector<UnwrappedElementType> UnwrappedVectorType;

    UnwrappedVectorType unwrapped_vec = RecursiveUnwrapper<MAX_RECURSION_DEPTH, TARGET_UNWRAP_LEVEL>::run(final_result, vec);
}
