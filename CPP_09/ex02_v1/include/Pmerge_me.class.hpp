/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge_Me.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/09 22:33:12 by ytsyrend         ###   ########.fr       */
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

typedef struct s_chains
{
    std::vector<Pmerge_me> main_chain;
    std::vector<Pmerge_me> insert_chain;
    std::vector<std::pair<Pmerge_me, Pmerge_me> > pair_vector;
    int jacobstahl_number_last;
    int jacobstahl_number;
} t_chains;


std::ostream &operator<<(std::ostream & o, Pmerge_me const &rhs);
std::ostream& operator<<(std::ostream& o, const std::pair<Pmerge_me, Pmerge_me>& pair);
void combine_to_pairs(std::vector<Pmerge_me> &vec, std::vector<std::pair<Pmerge_me,Pmerge_me> > &pair_vector);
bool compare_by_first(Pmerge_me &ob_1, Pmerge_me &ob_2);
void chain_split(std::vector<Pmerge_me> &main_chain, std::vector<Pmerge_me> &insert_chain, std::vector<std::pair<Pmerge_me, Pmerge_me> > &pair_vector);
void insert(std::vector<Pmerge_me> &main_chain, int position_to_insert, std::vector<Pmerge_me> &insert_chain, int position_from_insert);
void print_ob_vec(const std::vector<Pmerge_me> vec);
void save_it(std::vector<Pmerge_me> &main_chain, std::vector<Pmerge_me> &insert_chain);
void save_it(t_chains &chains);
void binary_insertion(t_chains &chains, int main_position);
int insert_position(t_chains &chains, int insert_index, int start, int end, int &comparison_count);
#include "../srcs/t_utils.tpp" 

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