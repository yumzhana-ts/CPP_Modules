/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/05 23:46:12 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.class.hpp"
#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"


void fill_array(Animal* array[], int size)
{
    int c = 0;
    while(c < (size/2))
    {
        array[c] = new Cat();
        std::cout << c + 1 << " " << array[c]->get_type() << " slipped into the presentation hall, curiously exploring the venue." << std::endl;
        c++;
    }
    while(c < size)
    {
        array[c] = new Dog();
        std::cout << c + 1 << " " << array[c]->get_type() << " trotted into the presentation hall, eagerly sniffing around the venue." << std::endl;
        c++;
    }
}

void fill_array_deep_copy(Animal* array[], int size)
{
    int flag = true;
    int c = 0;
    while(c < (size/2))
    {
        if(c == 0)
        {
            array[0] = new Cat();
            std::cout << 1 << " " << array[c]->get_type() << " slipped into the presentation hall, curiously exploring the venue." << std::endl;
        }
        else
        {
            array[c] = new Cat();
            *static_cast<Cat*>(array[c]) = *static_cast<Cat*>(array[0]);
            std::cout << c + 1 << " " << array[c]->get_type() << " slipped into the presentation hall, curiously exploring the venue." << std::endl;
        }
        c++;
    }
    while(c < size)
    {
        if(flag)
        {
            array[c] = new Dog();
            std::cout << c + 1 << " " << array[c]->get_type() << " trotted into the presentation hall, eagerly sniffing around the venue." << std::endl;
            flag = false;
        }
        else
        {   
            array[c] = new Dog();
            *static_cast<Dog*>(array[c]) = *static_cast<Dog*>(array[c - 1]);
            std::cout << c + 1 << " " << array[c]->get_type() << " trotted into the presentation hall, eagerly sniffing around the venue." << std::endl;
        }
        c++;
    }
}

void fill_array_copy(Animal* array[], int size)
{
    int flag = true;
    int c = 0;
    while(c < (size/2))
    {
        if(c == 0)
        {
            array[0] = new Cat();
            std::cout << 1 << " " << array[c]->get_type() << " slipped into the presentation hall, curiously exploring the venue." << std::endl;
        }
        else
        {
            
            array[c] = new Cat(*static_cast<Cat*>(array[0]));
            std::cout << c + 1 << " " << array[c]->get_type() << " slipped into the presentation hall, curiously exploring the venue." << std::endl;
        }
        c++;
    }
    while(c < size)
    {
        if(flag)
        {
            array[c] = new Dog();
            std::cout << c + 1 << " " << array[c]->get_type() << " trotted into the presentation hall, eagerly sniffing around the venue." << std::endl;
            flag = false;
        }
        else
        {   
            array[c] = new Dog(*static_cast<Dog*>(array[c-1]));
            std::cout << c + 1 << " " << array[c]->get_type() << " trotted into the presentation hall, eagerly sniffing around the venue." << std::endl;
        }
        c++;
    }
}

void delete_array(Animal* array[], int size)
{
    int c = 0;
    while(c < size)
    {
        if (array[c] != NULL)
        {
            delete array[c];
            if(array[c]->get_type() == "Cat")
                std::cout << c + 1 << " " << array[c]->get_type() << " gracefully slipped out of the presentation hall with a flick of its tail." << std::endl;
            if(array[c]->get_type() == "Dog")
                std::cout << c + 1<< " " << array[c]->get_type() << " exited the presentation hall with a cheerful wag of its tail." << std::endl;
        }
        c++;
    }
}


int main()
{
    int i = 10;
    Animal* array[i];
    std::cout << BLUE <<  "A total of " << i <<  " animals — half energetic dogs and half sharp-witted cats \n— invited for a global presentation on the impact of AI in enhancing animal lives." << RESET_COLOR << "\n"<<std::endl;
    //fill_array(array, i);
    fill_array_copy(array, i);
    delete_array(array, i);
}