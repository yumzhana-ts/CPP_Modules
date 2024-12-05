/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BoogyWoogyException.class.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/11/27 16:28:27 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BoogyWoogyException_CLASS_H
#define BoogyWoogyException_CLASS_H

#include <iostream>
#include <exception>

class BoogyWoogyException: public std::exception
{
public:
    const char* what() const throw()
    {
        return("He boogie-woogied right into a pie!");
    }
    BoogyWoogyException();
    ~BoogyWoogyException() throw();
};


#define DEBUG 1
#define RESET_COLOR "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"
#define BOLD_BLACK "\033[1;30m"
#define BG_WHITE "\033[0;47m"
#endif