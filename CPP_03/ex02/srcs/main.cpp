/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/15 19:00:22 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"
#include "FragTrap.class.hpp"
#include "ScavTrap.class.hpp"

int main() 
{
    ClapTrap obj1("Yuma");
    obj1.attack("creature");
    obj1.print_state();
    obj1.take_damage(2);
    obj1.print_state();
    obj1.be_repaired(2);
    obj1.print_state();

    ScavTrap obj2("Mika");
    obj2.attack("creature");
    obj2.print_state();
    obj2.take_damage(2);
    obj2.print_state();
    obj2.be_repaired(2);
    obj2.guard_gate();
    obj2.print_state();

    FragTrap obj3("Buba");
    obj3.attack("creature");
    obj3.print_state();
    obj3.take_damage(2);
    obj3.print_state();
    obj3.be_repaired(2);
    obj3.high_fives_guys();
    obj3.print_state();   
    return (0);
}