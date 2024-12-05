/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/12/01 23:00:42 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

int main() 
{
    std::cout << "\nTest 1: Testing Orthodox Canonical Form" << std::endl;
    Form banana_sticker("Chiquita", 1, 1);
    std::cout << banana_sticker;
    Form scam_sticker(banana_sticker);
    std::cout << scam_sticker;
    Form sticker_overload("Aloha", 1, 1);
    sticker_overload = banana_sticker;
    std::cout << sticker_overload;
    std::cout << LINE << std::endl;

    std::cout << "\nTest 2: Incorrect grades of forms" << std::endl;
    try
    {
        Form too_high_sign("test_sign", 0, 1);
    }
    catch(const )
    Form too_low_sign("test_not_sign", 0, 1);
    Form too_high_exec("test_exec", 1, 0);
    Form too_low_exec()
    std::cout << "\nTest 3: Grade of bureaucrat is not high enough" << std::endl;
    std::cout << "\nTest 4: Form is signed by Bureaucrat" << std::endl;
}