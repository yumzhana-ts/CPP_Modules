/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/11/27 16:29:06 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BoogyWoogyException.class.hpp"

int main() 
{
    std::string word = "marshmallow";
    try 
    {
        if (20 >= word.size())
        {
            throw BoogyWoogyException();
        }
        std::cout << word.at(20) << std::endl;
    }
    catch(const BoogyWoogyException& e)  // Поймать стандартное исключение
    {
        std::cout << e.what() << std::endl;  // Вывод сообщения об ошибке
    }
    return (0);
}