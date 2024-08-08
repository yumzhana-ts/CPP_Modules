/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/01 16:15:08 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"
#include "Dog.class.hpp"

int main() 
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->get_type() << " " << std::endl;
    std::cout << i->get_type() << " " << std::endl;
    i->make_sound();
    j->make_sound();
    meta->make_sound();
    delete j;
    delete i;
    delete meta;

    return (0);
}