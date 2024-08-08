/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/08 01:20:02 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.class.hpp"
#include "Character.class.hpp"
#include "AMateria.class.hpp"
#include "Ice.class.hpp"
#include "Cure.class.hpp"
#include "IMateriaSource.class.hpp"
#include "MateriaSource.class.hpp"

/* int main() 
{
    ICharacter* me = new Character("me");
    std::cout << me->get_name() << std::endl;

    ICharacter* copy_me = new Character(*static_cast<Character*>(me)); // Copy Constructor called
    std::cout << copy_me->get_name() << std::endl;

    ICharacter* not_me = new Character("waste"); // Properly initialize not_me
    *static_cast<Character*>(not_me) = *static_cast<Character*>(me); // Copy Assignment Operator called
    std::cout << not_me->get_name() << std::endl;

    delete me;
    delete copy_me;
    delete not_me;

    return 0;
} */

/* int main() 
{
    AMateria* tmp = new Ice();
    std::cout << tmp->get_type() << std::endl;
    AMateria* test_ice = tmp->clone();
    std::cout << test_ice->get_type() << std::endl;

    AMateria* t = new Cure();
    std::cout << t->get_type() << std::endl;
    AMateria* test_cure = t->clone();
    std::cout << test_cure->get_type() << std::endl;
    
    delete tmp;
    delete t;
    delete test_cure;
    delete test_ice;
} */

/* int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learn_materia(new Ice);
    src->learn_materia(new Ice);
    src->learn_materia(new Cure);
    src->learn_materia(new Cure);
    src->print_materia();

    IMateriaSource* dst = new MateriaSource(*static_cast<MateriaSource*>(src));
    dst->print_materia();
    IMateriaSource* cpy_dst = new MateriaSource();
    cpy_dst->print_materia();
    AMateria* tmp_f = cpy_dst->create_Materia("g");
    *static_cast<MateriaSource*>(cpy_dst) = *static_cast<MateriaSource*>(dst);
    cpy_dst->print_materia();
    
    AMateria* tmp = dst->create_Materia("cure");
    //std::cout << tmp->get_type();
    delete src;
    delete dst;
    delete tmp;
    delete tmp_f;
} */

int main() 
{
    IMateriaSource* src = new MateriaSource(); 
    src->learn_materia(new Ice()); 
    src->learn_materia(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->create_Materia("ice");
    me->equip(tmp);
    tmp = src->create_Materia("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob"); me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0; 
}