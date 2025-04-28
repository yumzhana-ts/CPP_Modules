/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge_me.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/15 16:10:03 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_CLASS_H
#define PMERGE_ME_CLASS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

class Pmerge_me
{
private:
    int number;
    std::vector<Pmerge_me>::iterator it;
public:
    Pmerge_me(int n);
    ~Pmerge_me(void);
    Pmerge_me(const Pmerge_me& other);
    Pmerge_me& operator=(const Pmerge_me& other);

    int get_number(void) const {return (this->number);}
    std::vector<Pmerge_me>::iterator get_iterator(void) const { return (this->it);}
    void set_it(std::vector<Pmerge_me>::iterator it_pair) {this->it = it_pair;}
    int get_pair_index(std::vector<Pmerge_me> &chain);
};


template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &o, const std::pair<T1, T2> &pair);

template <typename T>
void print_vec(const std::vector<T>& vec);

typedef struct s_chains
{
    std::vector<Pmerge_me> main_chain;
    std::vector<Pmerge_me> insert_chain;
    std::vector<std::pair<int, int> > pair_vector;
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > pair_pair_vector;
    int jacobstahl_number_last;
    int jacobstahl_number;
} t_chains;

#include "../srcs/t_utils.tpp" 
void debug(const std::string& str);
void ford_johnson(std::vector<int> &vec, t_chains &chains);
void pair_combination(std::vector<int> &vec, t_chains &chains);
void pair_element_sort(t_chains &chains);
void pair_combination_pair(std::vector<std::pair<int,int> > &vec, t_chains &chains);


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
#endif