/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/01 16:02:38 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.class.hpp"
#include "WrongAnimal.class.hpp"
#include "Cat.class.hpp"
#include "WrongCat.class.hpp"
#include "Dog.class.hpp"

int main() 
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* k = new WrongCat();

    
    std::cout << "The " << j->get_type() << " says: ";
    j->make_sound();
    std::cout << "The " << i->get_type() << " says: ";
    i->make_sound();
    std::cout << "The " << k->get_type() << " says: ";
    k->make_sound();
    std::cout << "The " << meta->get_type() << " says: ";
    meta->make_sound();
    

    delete j;
    delete i;
    delete meta;
    delete k;
    return (0);
}