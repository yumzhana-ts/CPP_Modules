/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge_me.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/19 23:17:02 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_CLASS_H
#define PMERGE_ME_CLASS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "../srcs/t_utils.tpp"

//objekt ve kterem bude ulo6en vektor s pary a levelem
template <typename T>
class OurPair
{
private:
    int level;
    std::vector<std::pair<T, T> > pairs;
public:
    OurPair(int level, std::vector<std::pair<T, T> > pairs)
        : level(level), pairs(pairs){};
	~OurPair(void);

	int get_level(){ return this->level;}
    std::pair<T, T> pair() const {
        return pairs.front(); // nebo jiná logika, např. poslední
    }
};

class Pmerge_me
{
private:
    int number;
    std::vector<Pmerge_me>::iterator position;
public:
    Pmerge_me(int n);
    ~Pmerge_me(void);
    Pmerge_me(const Pmerge_me& other);
    Pmerge_me& operator=(const Pmerge_me& other);

    std::vector<Pmerge_me>::iterator get_position() const;
    int get_number() const{return this->number;};
    void set_position(std::vector<Pmerge_me>::iterator it);
};


std::ostream& operator<<(std::ostream& os, const Pmerge_me& pm);
void add_numbers_to_vector(int argc, char **argv, std::vector<Pmerge_me>& vec);
void link_elements(std::vector<Pmerge_me>& vec);
void print_linked_list(const std::vector<Pmerge_me>& vec);
void sort_numbers_level_one(std::vector<std::pair<Pmerge_me, Pmerge_me> > &output);
std::vector<std::pair<Pmerge_me, Pmerge_me> > start_pair_sorting(std::vector<Pmerge_me> &vec, int &level);
template <typename T>
std::vector<std::pair<T, T>> group_into_pairs(const std::vector<T>& input);

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

#include "../srcs/t_utils.tpp" 
#endif