/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge_me.class.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/05/19 11:02:49 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge_me.class.hpp"

/****************************************************/
/*             Container setup                      */
/****************************************************/

template <template <typename> class container_wrapper>
void add_numbers_to_container(int argc, char** argv, typename container_wrapper<int>::type& container)
{
    if (argc != 2)
        error_and_exit("Error: Invalid number of arguments");

    add_numbers_from_string<container_wrapper>(std::string(argv[1]), container);

    if (container.size() == 1)
    {
        std::cout << container[0] << std::endl;
        std::exit(0);
    }
}

template <template <typename> class container_wrapper>
void setup_container(int argc, char **argv, t_data<typename container_wrapper<int>::type>& container)
{
    add_numbers_to_container<container_wrapper>(argc, argv, container.original_container);
    container.total = container.original_container.size();
    container.info = get_usage_up_to_max_level(container.total);

    if (DEBUG == 1) 
    {
        print_vector<int, container_wrapper>(container.original_container);
        print_usage_info(container.info, container.total); 
    }
}

template <template <typename> class container_wrapper>
void add_numbers_from_string(const std::string& input, typename container_wrapper<int>::type& container)
{
    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ' '))
    {
        if (token.empty())
            continue;

        if (!is_valid_number(token))
        {
            std::string msg = std::string("Error: Invalid input '") + token + "'";
            error_and_exit(msg);
        }
        container.push_back(convert_to_int(token)); // или convert_to<T> если реализуешь
    }
}

template <typename T, template <typename> class container_wrapper>
void print_vector(const typename container_wrapper<T>::type& vec) 
{
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i != vec.size() - 1) std::cout << " ";
    }
    std::cout << "\n";
}

/****************************************************/
/*                    Meta                          */
/****************************************************/

template <template <typename> class container_wrapper>
void dispatcher(t_data<typename container_wrapper<int>::type>& container)
{
    int count = container.original_container.size();
    int calculated_max_depth = recursion_levels(count);
    
    switch (calculated_max_depth) 
    {
        case 0:
            meta_recursive<container_wrapper, 0>(container);
            break;
        case 1:
            meta_recursive<container_wrapper, 1>(container);
            break;
        case 2:
            meta_recursive<container_wrapper, 2>(container);
            break;
        case 3:
            meta_recursive<container_wrapper, 3>(container);
            break;
        case 4:
            meta_recursive<container_wrapper, 4>(container);
            break;
        case 5:
            meta_recursive<container_wrapper, 5>(container);
            break;
        case 6:
            meta_recursive<container_wrapper, 6>(container);
            break;
        case 7:
            meta_recursive<container_wrapper, 7>(container);
            break;
        case 8:
            meta_recursive<container_wrapper, 8>(container);
            break;
        case 9:
            meta_recursive<container_wrapper, 9>(container);
            break;
        case 10:
            meta_recursive<container_wrapper, 10>(container);
            break;
        case 11:
            meta_recursive<container_wrapper, 11>(container);
            break;
    }
}

template <template <class> class container_wrapper, int Max>
void meta_recursive(t_data<typename container_wrapper<int>::type>& container_data)
{
    typedef typename PairN<Max>::type FinalPairType;
    typedef typename container_wrapper<FinalPairType>::type FinalVectorType;
    
    FinalVectorType final_result = 
		ConstructLevels<0, Max, container_wrapper>::run(container_data.original_container, true, container_data);
	
	typedef typename PairN<0>::type UnwrappedElementType;
    typedef typename container_wrapper<UnwrappedElementType>::type UnwrappedVectorType;

    UnwrappedVectorType unwrapped_vec = RecursiveUnwrapper<Max, 0, container_wrapper>::run(final_result, container_data);
}

/****************************************************/
/*         Template for constructors                */
/****************************************************/


template <int N, int max_level, template <class> class container_wrapper>
struct ConstructLevels
{
    typedef typename PairN<N>::type current_level_pair_type;
    typedef typename container_wrapper<current_level_pair_type>::type current_level_container_type;

    typedef typename PairN<max_level>::type final_level_pair_type;
    typedef typename container_wrapper<final_level_pair_type>::type final_vector_type;

    static final_vector_type run(current_level_container_type &current_data, bool is_wrap, t_data<typename container_wrapper<int>::type>& container) 
    {
        typedef typename PairN<N + 1>::type next_level_pair_type;
        typedef typename container_wrapper<next_level_pair_type>::type next_level_container_type;
		if (is_wrap == true)
		{
			typename container_wrapper<int>::type reconstructed_current = flatten_vector_of_nested_pairs<N, container_wrapper>(current_data);
			save_rest_to_vector<container_wrapper>(container.info, reconstructed_current, container.leftovers, N+1);
		}
        next_level_container_type next_level_data = group_into_pairs<N, container_wrapper>(current_data, is_wrap);
		if (is_wrap == true || next_level_data.size() == 1)
			container.used = flatten_vector_of_nested_pairs<N+1, container_wrapper>(next_level_data);
        if (next_level_data.size() == 1)
			restore_original_vector<container_wrapper>(container);
        print_pairs_vector<typename next_level_pair_type::first_type, container_wrapper>(next_level_data);
        return ConstructLevels<N + 1, max_level, container_wrapper>::run(next_level_data, true, container);
    }
};


template <int max_level, template <class> class container_wrapper>
struct ConstructLevels<max_level, max_level, container_wrapper> 
{
    typedef typename PairN<max_level>::type final_level_pair_type;
    typedef typename container_wrapper<final_level_pair_type>::type final_vector_type;

    static final_vector_type run(final_vector_type &current_data, bool is_wrap, t_data<typename container_wrapper<int>::type>& container) 
    {
		(void)is_wrap;
		(void)container;
        return current_data;
    }
};

/****************************************************/
/*               Construct pairs                    */
/****************************************************/

template <int N, template <class> class container_wrapper>
typename container_wrapper<typename PairN<N + 1>::type>::type
group_into_pairs(const typename container_wrapper<typename PairN<N>::type>::type& input, bool is_wrap)
{
    typedef typename PairN<N>::type        input_pair_type;
    typedef typename PairN<N + 1>::type    output_pair_type;
    typedef typename container_wrapper<output_pair_type>::type output_container_type;

    output_container_type output;
    typename container_wrapper<input_pair_type>::type::const_iterator it = input.begin();
    typename container_wrapper<input_pair_type>::type::const_iterator end = input.end();

    while (it != end)
    {
        input_pair_type first = *it;
        ++it;
        if (it != end)
        {
            input_pair_type second = *it;
            ++it;
			if(is_wrap == true)
				sort_numbers<N>(first, second);
            output.push_back(std::make_pair(first, second));
        }
        else
        {
            break; 
        }
    }
    return output;
}


/****************************************************/
/*    Template for getting second value/ sort       */
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
/*                    utils                         */
/****************************************************/

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::pair<T, T> &pair)
{
    o << "{" << pair.first << ", " << pair.second << "}";
    return o;
}

template <typename T, template <class> class container_wrapper>
void print_pairs_vector(const typename container_wrapper<std::pair<T, T> >::type& vec)
{
    if (DEBUG == 1)
    {
        std::cout << GREEN << "Generated pairs: [";
        typedef typename container_wrapper<std::pair<T, T> >::type ConcreteContainerType;
        typedef typename ConcreteContainerType::const_iterator const_iterator;

        for (const_iterator it = vec.begin(); it != vec.end(); ++it)
        {
            if (it != vec.begin())
            {
                std::cout << ", ";
            }
            std::cout << *it;
        }
        std::cout << "]" << RESET_COLOR << std::endl;
    }
}

/****************************************************/
/*            flatten_nested_pair                   */
/****************************************************/

template<int M, template <class> class container_wrapper>
struct RecursiveFlattener {
    static void flatten(typename PairN<M>::type& nested_pair,
                        typename container_wrapper<typename PairN<0>::type>::type& flat_output)
    {
        RecursiveFlattener<M - 1, container_wrapper>::flatten(nested_pair.first, flat_output);
        RecursiveFlattener<M - 1, container_wrapper>::flatten(nested_pair.second, flat_output);
    }
};


template<template <class> class container_wrapper>
struct RecursiveFlattener<0, container_wrapper> {
    static void flatten(typename PairN<0>::type& value,
                        typename container_wrapper<typename PairN<0>::type>::type& flat_output)
    {
        flat_output.push_back(value);
    }
};

template<int N, template <class> class container_wrapper>
typename container_wrapper<typename PairN<0>::type>::type
flatten_vector_of_nested_pairs(typename container_wrapper<typename PairN<N>::type>::type& nested_pairs_vector)
{
    typedef typename container_wrapper<typename PairN<0>::type>::type flat_container;
    flat_container flattened_result;

    typedef typename container_wrapper<typename PairN<N>::type>::type nested_container;
    typedef typename nested_container::iterator it_in;

    for (it_in it = nested_pairs_vector.begin(); it != nested_pairs_vector.end(); ++it)
    {
        typename PairN<N>::type& current_pair_object = *it;
        RecursiveFlattener<N, container_wrapper>::flatten(current_pair_object, flattened_result);
    }
    return flattened_result;
}

template <template <typename> class container_wrapper>
void restore_original_vector(t_data<typename container_wrapper<int>::type>& container)
{
    container.original_container.clear();
    container.original_container.insert(container.original_container.begin(), container.leftovers.begin(), container.leftovers.end());
    container.original_container.insert(container.original_container.begin(), container.used.begin(), container.used.end());
    container.used.clear();
}


template <template <typename> class container_wrapper>
void save_rest_to_vector(std::vector<t_level_info> levels, typename container_wrapper<int>::type& container, typename container_wrapper<int>::type& rest, int level)
{
    size_t leftovers = levels[level - 1].rest;
    if (leftovers > 0 && leftovers <= container.size())
    {
        typename container_wrapper<int>::type slice(container.end() - leftovers, container.end());
        rest.insert(rest.begin(), slice.begin(), slice.end());
        container.erase(container.end() - leftovers, container.end());
    }
}


/****************************************************/
/*         Template for unwrapping                  */
/****************************************************/

template<template <typename> class container_wrapper, int N>
void wrap_up_with_remaining_pair(t_data<typename container_wrapper<int>::type>& container, typename container_wrapper<typename PairN<N-1>::type>::type &next_level_vec)
{
    typename container_wrapper<int>::type rest_vec;
    rest_vec.insert(rest_vec.end(), container.leftovers.begin(), container.leftovers.begin() + container.info[N - 1].rest);
    container.leftovers.erase(container.leftovers.begin(), container.leftovers.begin() + container.info[N - 1].rest);

    if (!rest_vec.empty())
    {
        typedef typename PairN<N - 1>::type FinalPairType;
        typedef typename container_wrapper<FinalPairType>::type FinalVectorType;
        FinalVectorType final_result = ConstructLevels<0, N - 1, container_wrapper>::run(rest_vec, false, container);
        next_level_vec.push_back(final_result[0]);
    }
}


template <int N, template <typename> class container_wrapper>
typename container_wrapper<typename PairN<N - 1>::type>::type unwrap_pairs( const typename container_wrapper<typename PairN<N>::type>::type& input)
{
    typedef typename PairN<N>::type InputPair;
    typedef typename PairN<N - 1>::type OutputType;
    typedef typename container_wrapper<InputPair>::type::const_iterator InputIterator;
    typedef typename container_wrapper<OutputType>::type OutputContainer;

    OutputContainer output;
    for (InputIterator it = input.begin(); it != input.end(); ++it) 
    {
        output.push_back(it->first);
        output.push_back(it->second);
    }
    return output;
}


template <int N, int target_level, template <class> class container_wrapper>
struct RecursiveUnwrapper 
{
    typedef typename PairN<N>::type current_level_type;
    typedef typename container_wrapper<current_level_type>::type current_vector_type;
    typedef typename PairN<target_level>::type final_level_type;
    typedef typename container_wrapper<final_level_type>::type final_vector_type;

    static final_vector_type run(const current_vector_type& current_data, t_data<typename container_wrapper<int>::type>& container) 
    {
        typedef typename container_wrapper<typename PairN<N - 1>::type>::type next_level_vec_type;
        next_level_vec_type next_level_vec = unwrap_pairs<N, container_wrapper>(current_data);
        wrap_up_with_remaining_pair<container_wrapper, N>(container, next_level_vec);
		//TODO: sorting mechanism 
        unwrapped_sort<N - 1>(next_level_vec, container);
        next_level_vec = ConstructLevels<0, N- 1, container_wrapper>::run(container.used, false, container);
        return RecursiveUnwrapper<N - 1, target_level, container_wrapper>::run(next_level_vec, container);
    }
};


template <int target_level, template <class> class container_wrapper>
struct RecursiveUnwrapper<target_level, target_level, container_wrapper>
{
    typedef typename PairN<target_level>::type final_level_type;
    typedef typename container_wrapper<final_level_type>::type final_vector_type;

    static final_vector_type run(const final_vector_type& current_data, t_data<typename container_wrapper<int>::type>& container) 
    {
        (void)container;
        return current_data;
    }
};

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