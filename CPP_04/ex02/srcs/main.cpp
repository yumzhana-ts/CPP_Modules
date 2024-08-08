/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/06 01:37:51 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.class.hpp"
#include "AAnimal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"

int main()
{
    const AAnimal* j = new Dog();    
    const AAnimal* i = new Cat();
    
    delete j;
    delete i;
    return 0;
}
