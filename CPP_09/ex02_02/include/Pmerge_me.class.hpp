/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge_me.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/05/19 21:45:23 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_CLASS_H
#define PMERGE_ME_CLASS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <cmath>
#include <iterator>

template <int N>
struct PairN;

template <int N>
class PmergeMe
{
private:
    typename PairN<N>::type pair;
    int num;
    std::string ab;
    int index_ab;
    int index;

public:
    PmergeMe(typename PairN<N>::type v, int n, std::string ab, int index_ab, int i);
    PmergeMe(const std::string &ab, int index);
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    typename PairN<N>::type get_pair() const;
    int get_num() const;
    int get_index() const;
    std::string get_ab() const;
    int get_index_ab() const;
    void set_index(int i);

    bool operator==(const PmergeMe<N> &other) const
    {
        return this->get_ab() == other.get_ab() && this->get_index_ab() == other.get_index_ab();
    }
};


/****************************************************/
/*             structs                             */
/****************************************************/

template <int N>
struct PairN
{
    typedef std::pair<typename PairN<N - 1>::type, typename PairN<N - 1>::type> type;
};

template <>
struct PairN<1>
{
    typedef std::pair<int, int> type;
};

template <>
struct PairN<0>
{
    typedef int type;
};

template <typename T>
struct VectorWrapper {
    typedef std::vector<T> type;
    static const char* name() { return "vector"; }
};

template <typename T>
struct DequeWrapper {
    typedef std::deque<T> type;
    static const char* name() { return "deque"; }
};

template<int M, template <class> class container_wrapper>
struct RecursiveFlattener;

template<template <class> class container_wrapper>
struct RecursiveFlattener<0, container_wrapper>;

struct t_level_info
{
    int used;
    int rest;
    int pairs;
    int numbers_in_pair;
    
    t_level_info(int u, int r, int p, int n)
        : used(u), rest(r), pairs(p), numbers_in_pair(n) {}
};

template <typename Container>
struct t_data
{
    Container original_container;
    Container used;
    Container leftovers;
    std::vector<t_level_info> info;
    int total;
    int total_comparisons;

    t_data()
        : original_container(), used(), leftovers(), info(), total(0), total_comparisons(0){}
};

template <int N, int max_level, template <class> class container_wrapper>
struct ConstructLevels;

template <int max_level, template <class> class container_wrapper>
struct ConstructLevels<max_level, max_level, container_wrapper>;

template <int N>
struct GetSecond;

template <>
struct GetSecond<0>;

template <int n, int target_level, template <class> class container_wrapper>
struct RecursiveUnwrapper;

template <int target_level, template <class> class container_wrapper>
struct RecursiveUnwrapper<target_level, target_level, container_wrapper>;

/****************************************************/
/*             Templates                            */
/****************************************************/

template <template <typename> class container_wrapper>
void add_numbers_to_container(int argc, char** argv, typename container_wrapper<int>::type& container);

template <template <typename> class container_wrapper>
void setup_container(int argc, char **argv, t_data<typename container_wrapper<int>::type>& container);

template <template <typename> class container_wrapper>
void add_numbers_from_string(const std::string& input, typename container_wrapper<int>::type& container);

template <typename T, template <typename> class container_wrapper>
void print_vector(const typename container_wrapper<T>::type& vec);

template <template <typename> class container_wrapper>
void dispatcher(t_data<typename container_wrapper<int>::type>& container);

template <template <class> class container_wrapper, int Max>
void meta_recursive(t_data<typename container_wrapper<int>::type>& container_data_obj);

template <int N, template <class> class container_wrapper>
typename container_wrapper<typename PairN<N + 1>::type>::type
group_into_pairs(const typename container_wrapper<typename PairN<N>::type>::type& input, bool is_wrap);

template<int N>
bool sort_numbers(typename PairN<N>::type& first, typename PairN<N>::type& second);

template<int N>
int second_number(typename PairN<N>::type& first);

template <typename T>
std::ostream &operator<<(std::ostream &o, const std::pair<T, T> &pair);

template <typename T, template <class> class container_wrapper>
void print_pairs_vector(const typename container_wrapper<std::pair<T, T> >::type& vec);

template<int N, template <class> class container_wrapper> typename container_wrapper<typename PairN<0>::type>::type
flatten_vector_of_nested_pairs(typename container_wrapper<typename PairN<N>::type>::type& nested_pairs_vector);

template<template <typename> class container_wrapper>
void restore_original_vector(t_data<typename container_wrapper<int>::type>& container);

template <template <typename> class container_wrapper>
void save_rest_to_vector(std::vector<t_level_info> levels, typename container_wrapper<int>::type& container, typename container_wrapper<int>::type& rest, int level);

template <int N, template <typename> class container_wrapper>
typename container_wrapper<typename PairN<N - 1>::type>::type unwrap_pairs( const typename container_wrapper<typename PairN<N>::type>::type& input);

template<template <typename> class container_wrapper, int N>
void wrap_up_with_remaining_pair(t_data<typename container_wrapper<int>::type>& container, typename container_wrapper<typename PairN<N>::type>::type &next_level_vec);

template<int N, template <class> class container_wrapper>
void unwrapped_sort(const typename container_wrapper<typename PairN<N>::type>::type& input, t_data<typename container_wrapper<int>::type>& container);

template <int N>
PmergeMe<N> pair_object(typename PairN<N>::type p, int c, std::string s, int i);

template<int N, template <class> class container_wrapper>
int merge_by_jacobsthal_sequence(typename container_wrapper<PmergeMe<N> >::type &main, typename container_wrapper<PmergeMe<N> >::type &pend);

template<int N, template <class> class container_wrapper>
void process_jacobsthal_batch(typename container_wrapper<PmergeMe<N> >::type &main, typename container_wrapper<PmergeMe<N> >::type &pend,
    int jakob_prev_index, int jakob_index, int &total_comparisons);

template<int N, template <class> class container_wrapper>
void insert_with_binary_search(typename container_wrapper<PmergeMe<N> >::type &main, PmergeMe<N> &number, typename container_wrapper<PmergeMe<N> >::type &pend, int &total_comparisons);

template<int N, template <class> class container_wrapper>
int find_insert_position(typename container_wrapper<PmergeMe<N> >::type &main, int start_of_slice, int end_of_slice, int insert_num, int &comparison_count);

template<int N, template <class> class container_wrapper>
void update_pair_index(PmergeMe<N> &obj, typename container_wrapper<PmergeMe<N> >::type &vec);

template<int N, template <class> class container_wrapper>
void update_container_indexes(typename container_wrapper<PmergeMe<N> >::type &main, typename container_wrapper<PmergeMe<N> >::type &pend, int position_to_insert);

template<int N, template <class> class container_wrapper>
void unpack_sorted_main(typename container_wrapper<PmergeMe<N> >::type &main, t_data<typename container_wrapper<int>::type>& container);

template<int N, template <class> class container_wrapper>
void print_pair_object(typename container_wrapper<PmergeMe<N> >::type &vec);

template<int N, template <class> class container_wrapper>
void print_chains(typename container_wrapper<PmergeMe<N> >::type &main, typename container_wrapper<PmergeMe<N> >::type &pend, std::string sign);


/****************************************************/
/*             Functions                            */
/****************************************************/

int recursion_levels(int n);

void print_usage_info(const std::vector<t_level_info> &usage_info, int total);

int convert_to_int(const std::string& s);

void error_and_exit(const std::string& msg);

bool is_valid_number(const std::string& s);

std::vector<t_level_info> get_usage_up_to_max_level(int total);


#define DEBUG 0
// Define ANSI escape sequences for colors
#define RESET_COLOR "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"
#define BOLD_BLACK "\033[1;30m"
#define BG_WHITE "\033[0;47m"
#define LINE "  ------------------------ "

#include "../srcs/Pmerge_me.class.tpp"
#endif