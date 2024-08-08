/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/05 15:27:36 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.class.hpp"
#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"

int main()
{
    const Animal* j = new Dog();    
    const Animal* i = new Cat();
    
    delete j;
    delete i;
    return 0;
}