/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/12/01 22:50:01 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.class.hpp"
#include "A.class.hpp"
#include "B.class.hpp"
#include "C.class.hpp"

/****************************************************/
/*                    Destructor.                   */
/****************************************************/

Base::~Base(void) 
{
    if (DEBUG){std::cout << GREEN << "[Base] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                 Memeber Functions                *
****************************************************/

Base* Base::generate(void)
{
    Base *random_class = NULL;
    srand(time(0));
    int choice = rand() % 3;
    switch(choice)
    {
        case(0):
            random_class = new A();
            break;
        case(1):
            random_class = new B();
            break;
        case(2):
            random_class = new C();
            break;
    }
    std::cout << choice << std::endl;
    return random_class;
}

void Base::identify(Base* p)
{
    A* test = dynamic_cast<A *>(p);
    if (test != NULL)
        std::cout << "Actual type of the object: A class " << std::endl;
    else
    {
        B* test = dynamic_cast<B *>(p);
        {
            if (test != NULL)
                std::cout << "Actual type of the object: B class " << std::endl;
            else
                std::cout << "Actual type of the object: C class " << std::endl;
        }
    }
    delete test;
}

void Base::identify(Base& p)
{
    try
    {
        A& test = dynamic_cast<A&>(p);
        (void) test;
        std::cout << "Actual type of the object: A class" <<  std::endl;
    }
    catch(std::exception &e)
    {
        
    }
    try
    {
        B& test = dynamic_cast<B&>(p);
        (void) test;
        std::cout << "Actual type of the object: B class" <<  std::endl;
    }
    catch(std::exception &e)
    {

    }
    try
    {
        C& test = dynamic_cast<C&>(p);
        (void) test;
        std::cout << "Actual type of the object: C class" <<  std::endl;
    }
    catch(std::exception &e)
    {

    }
}