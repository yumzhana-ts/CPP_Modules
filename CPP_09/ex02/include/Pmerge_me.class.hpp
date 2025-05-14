/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge_me.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/05/14 16:35:49 by ytsyrend         ###   ########.fr       */
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

template<int N>
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
        PmergeMe(const std::string& ab, int index);
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        typename PairN<N>::type get_pair() const;
        int get_num() const;
        int get_index() const;
        std::string get_ab() const;
        int get_index_ab() const;
        void set_index(int i);

        bool operator==(const PmergeMe<N>& other) const {
            return this->get_ab() == other.get_ab() && this->get_index_ab() == other.get_index_ab();
    }
};
struct t_level_info
{
    int used;
    int rest;
    int pairs;
    int numbers_in_pair;
    t_level_info(int u, int r, int p, int n) : used(u), rest(r), pairs(p),numbers_in_pair(n) {}
};

struct t_original_vector
{
    std::vector<int> original_vector;
    std::vector<int> used;
    std::vector<int> leftovers;
    std::vector<t_level_info> info;
    int total;
    int total_comparisons;
};

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


template <int N, int MaxLevel>
struct ConstructLevels;

template <int MaxLevel>
struct ConstructLevels<MaxLevel, MaxLevel>;

template <int MaxLevel>
typename ConstructLevels<MaxLevel, MaxLevel>::FinalVectorType
get_sorted_vector(const typename ConstructLevels<MaxLevel, MaxLevel>::FinalVectorType& input_vec);

template <int N, int MaxLevel>
struct UnwrappedLevels;

template <int MaxLevel>
struct UnwrappedLevels<MaxLevel, MaxLevel>;

template <int N>
struct GetSecond;

template <>
struct GetSecond<0>;



template <int N>
std::ostream &operator<<(std::ostream &os, const PmergeMe<N> &pl);


void parse_and_store_numbers(int argc, char **argv, t_original_vector &vec);
void add_numbers_to_vector(int argc, char **argv, std::vector<int>& vec);
void link_elements(std::vector<int>& vec);
void print_linked_list(const std::vector<int>& vec);

template <typename T>
std::ostream& operator<<(std::ostream& o, const std::pair<T, T>& pair);

template <typename T>
void print_pairs_vector(const std::vector<std::pair<T, T> >& vec);

template<int N>
bool sort_numbers(typename PairN<N>::type& first, typename PairN<N>::type& second);

template<int N>
std::vector<typename PairN<N + 1>::type> group_into_pairs(const std::vector<typename PairN<N>::type>& input, bool group);

template <int MAX_RECURSION_DEPTH>
void meta_recursive(t_original_vector &vec);

template <int N, int TargetLevel>
struct RecursiveUnwrapper;

template <int TargetLevel>
struct RecursiveUnwrapper<TargetLevel, TargetLevel>;

template <int N>
std::vector<typename PairN<N - 1>::type> unwrap_pairs(const std::vector<typename PairN<N>::type>& input);

template<int N>
int second_number(typename PairN<N>::type& first);

template<int N>
void print_pair_object(std::vector<PmergeMe<N> > vec);


template<int N>
void unwrapped_sort(std::vector<typename PairN<N>::type>& input, t_original_vector &vec);

template <int N>
PmergeMe<N> pair_object(typename PairN<N>::type p, int c, std::string s, int i);

template<int N>
int insert_position(std::vector<PmergeMe<N> > &main, int start_of_slice, int end_of_slice, int insert_num, int &comparison_count);

template<int N>
void binary_insertion(std::vector<PmergeMe<N> > &main, PmergeMe<N> &number, std::vector<PmergeMe<N> > &pend, int &total_comparisons);

template<int N>
void jakob_queue(std::vector<PmergeMe<N> > &main, std::vector<PmergeMe<N> > &pend, int jakob_prev_index, int jakob_index, int &total_comparisons);

template<int N>
void print_chains(std::vector<PmergeMe<N> > &main, std::vector<PmergeMe<N> > &pend, std::string sign);

template<int N>
int chains_jakobstahl_sequence(std::vector<PmergeMe<N> > &main, std::vector<PmergeMe<N> > &pend);

template<int N>
void update_indexes(std::vector<PmergeMe<N> > &main, int insert_position, std::vector<PmergeMe<N> > &pend);

int recursion_levels(int n);

void print_usage_info(const std::vector<t_level_info> &usage_info, int total);

std::vector<t_level_info> get_usage_up_to_max_level(int total);

template<int M>
void unwrap_single_pair_recursive(typename PairN<M>::type& pair_to_unwrap,
    std::vector<int>& output_vec);
    

template<int N>
std::vector<int> reconstruct_from_nested_pairs(std::vector<typename PairN<N>::type>& input_vector);

void save_rest_to_vector(std::vector<t_level_info> levels, std::vector<int> &vec, std::vector<int> &rest, int level);

void print_vector(const std::string& name, const std::vector<int>& vec);

void pretty_print(const t_original_vector& data);

template<int N>
void reconstrust_main_vec(std::vector<PmergeMe<N> > &main, t_original_vector &vec);

void restore_original_vector(t_original_vector& vec);

template<int N, typename VecType, typename NextLevelVecType>
void process_rest_and_reconstruct(VecType& vec, NextLevelVecType& next_level_vec);

template <int N>
void print_smart(const std::vector<typename PairN<N>::type>& vec);

template<int N>
void update_index(PmergeMe<N> &obj, std::vector<PmergeMe<N> > &vec);

int F(int n);


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