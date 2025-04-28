/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge_me.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/28 17:41:02 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_CLASS_H
#define PMERGE_ME_CLASS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

class PmergeMe 
{
public:
    class SingleNumber {
    private:
        int number;
        std::vector<PmergeMe::SingleNumber>::iterator position;
    public:
        SingleNumber(int n);
        ~SingleNumber();
        SingleNumber(const SingleNumber& other);
        SingleNumber& operator=(const SingleNumber& other);

        std::vector<PmergeMe::SingleNumber>::iterator get_position() const;
        int get_number() const { return number; }
        void set_position(std::vector<SingleNumber>::iterator it);
    };

    template <typename T>
    class PairLevel {
    private:
        std::vector<std::pair<T, T> > vec;
        int level;

    public:
        PairLevel();
        PairLevel(int lvl, std::vector<std::pair<T, T> >& val);
        PairLevel(const PairLevel& other);
        PairLevel& operator=(const PairLevel& other);
        ~PairLevel();

        std::vector<std::pair<T, T> >& get_vector();
        int get_level() const;

        std::pair<T, T>* find_pair_by_number(const T& number);

    };
};

template <int N>
struct PairN;

template <>
struct PairN<1>;

template <>
struct PairN<0>;

std::ostream& operator<<(std::ostream& os, const PmergeMe::SingleNumber& sn);
template <typename T>
std::ostream& operator<<(std::ostream& os, PmergeMe::PairLevel<T>& pl);

void save_numbers_to_vector(int argc, char **argv, std::vector<PmergeMe::SingleNumber> &vec);
void add_numbers_to_vector(int argc, char **argv, std::vector<PmergeMe::SingleNumber>& vec);
void link_elements(std::vector<PmergeMe::SingleNumber>& vec);
void print_linked_list(const std::vector<PmergeMe::SingleNumber>& vec);

template <typename T>
std::ostream& operator<<(std::ostream& o, const std::pair<T, T>& pair);

template <typename T>
void print_pairs_vector(const std::vector<std::pair<T, T> >& vec);

template<typename T>
T& get_deepest(T& value);

template<typename T1, typename T2>
T2& get_deepest(std::pair<T1, std::pair<T2, T2> >& p);

template<typename T1, typename T2>
T2& get_deepest(std::pair<T1, T2>& p);


template<typename T>
void sort_numbers(std::vector<T>& output);

void sort_numbers(std::vector<std::pair<PmergeMe, PmergeMe> > &output);

template <typename T>
void print_pairs_vector(const std::vector<std::pair<T, T> >& vec);

template<int N>
std::vector<typename PairN<N + 1>::type> group_into_pairs(const std::vector<typename PairN<N>::type>& input);


template<int N>
std::vector<typename PairN<N+1>::type> recursive_group(std::vector<typename PairN<N>::type>& vec);

#define DEBUG 2
// Define ANSI escape sequences for colors
#define RESET_COLOR "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"
#define BOLD_BLACK "\033[1;30m"
#define BG_WHITE "\033[0;47m"

#include "../srcs/Pmerge_me.class.tpp" 
#endif