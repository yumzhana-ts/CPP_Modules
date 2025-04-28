/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge_me.class.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/28 21:29:25 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge_me.class.hpp"
#pragma once

/****************************************************/
/*                    Constructor                   */
/****************************************************/

template <typename T>
PmergeMe::PairLevel<T>::PairLevel() : level(0) {}

template <typename T>
PmergeMe::PairLevel<T>::PairLevel(int lvl, std::vector<std::pair<T, T> > &vc)
    : vec(vc), level(lvl)
{
}

template <typename T>
PmergeMe::PairLevel<T>::PairLevel(const PmergeMe::PairLevel<T> &other)
    : vec(other.vec), level(other.level) {}

/****************************************************/
/*                    Overload                      */
/****************************************************/

template <typename T>
typename PmergeMe::PairLevel<T> &PmergeMe::PairLevel<T>::operator=(const PmergeMe::PairLevel<T> &other)
{
    if (this != &other)
    {
        vec = other.vec;
        level = other.level;
    }
    return *this;
}

/****************************************************/
/*                    Destructor                    */
/****************************************************/

template <typename T>
PmergeMe::PairLevel<T>::~PairLevel() {}

/****************************************************/
/*                Member Functions                  */
/****************************************************/

template <typename T>
std::vector<std::pair<T, T> > &PmergeMe::PairLevel<T>::get_vector() // Return by reference
{
    return vec;
}

template <typename T>
int PmergeMe::PairLevel<T>::get_level() const
{
    return level;
}

template <typename T>
std::pair<T, T> *PmergeMe::PairLevel<T>::find_pair_by_number(const T &number)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (vec[i].first == number || vec[i].second == number)
        {
            return &vec[i];
        }
    }
    return NULL;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, PmergeMe::PairLevel<T> &pl)
{
    os << "Level: " << pl.get_level() << "\n";
    std::cout << GREEN << "Generated pairs: [";
    for (size_t i = 0; i < pl.get_vector().size(); ++i)
    {
        if (i != 0)
            os << ", ";
        os << pl.get_vector()[i];
    }
    os << "]" << RESET_COLOR << std::endl;
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

template <typename T>
T &get_deepest(T &value)
{
    return value;
}

template <typename T1, typename T2>
T2 &get_deepest(std::pair<T1, std::pair<T2, T2> > &p)
{
    return get_deepest(p.second);
}

template <typename T1, typename T2>
T2 &get_deepest(std::pair<T1, T2> &p)
{
    return get_deepest(p.second);
}

template <typename T>
void sort_numbers(std::vector<std::pair<T, T> > &output)
{
    typename std::vector<std::pair<T, T> >::iterator it = output.begin();
    for (; it != output.end(); ++it)
    {
        T &a = it->first;
        T &b = it->second;

        int a_deep = get_deepest(a).get_number();
        int b_deep = get_deepest(b).get_number();

        if (a_deep > b_deep)
        {
            std::swap(a, b);
        }
        // std::cout << "a: " << a_deep << " b: " << b_deep << std::endl;
    }
}

template <int N>
struct PairN
{
    typedef std::pair<typename PairN<N - 1>::type, typename PairN<N - 1>::type> type;
};

template <>
struct PairN<1>
{
    typedef std::pair<PmergeMe::SingleNumber, PmergeMe::SingleNumber> type;
};

template <>
struct PairN<0>
{
    typedef PmergeMe::SingleNumber type;
};


template<int N>
std::vector<typename PairN<N + 1>::type> group_into_pairs(const std::vector<typename PairN<N>::type>& input)
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
            output.push_back(std::make_pair(first, second));
        }
        else
        {
            break;
        }
    }
    print_pairs_vector(output);
    return output;
}

/*template<int N>
void recursive_group(std::vector<typename PairN<N>::type>& vec)
{
    if (vec.size() <= 1)
        return;

    // Явное указание типа для нового вектора
    std::vector<typename PairN<N + 1>::type> new_vec = group_into_pairs<N>(vec);

    // Явный вызов рекурсивной функции для типа с N + 1
    recursive_group<N + 1>(new_vec);
}*/

template<int N>
std::vector<typename PairN<N+1>::type> recursive_group(std::vector<typename PairN<N>::type>& vec)
{
    if (vec.size() <= 1)
        return vec;  // Return the vector as is when the size is 1 or less
    
    std::vector<typename PairN<N + 1>::type> new_vec = group_into_pairs<N>(vec);
    return recursive_group<N + 1>(new_vec);  // Recursively call and return the result
}