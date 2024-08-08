/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/05 23:53:11 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.class.hpp"
#include "AAnimal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"


void fill_array(AAnimal* array[], int size)
{
    int c = 0;
    while(c < (size/2))
    {
        array[c] = new Cat();
        std::cout << c + 1 << " " << array[c]->get_type() << " slipped into the presentation hall, curiously exploring the venue." << std::endl;
        array[c]->get_brain()->set_ideas("Meow!");
        std::cout << "The cat took the stage and shared its idea with a simple, heartfelt: " << RED << std::endl;
        array[c]->get_brain()->print_ideas();
        std::cout << RESET_COLOR;
        c++;
    }
    while(c < size)
    {
        array[c] = new Dog();
        std::cout << c + 1 << " " << array[c]->get_type() << " trotted into the presentation hall, eagerly sniffing around the venue." << std::endl;
        array[c]->get_brain()->set_ideas("Woof!");
        std::cout << "The dog stepped up to the stage and expressed its idea with an enthusiastic: "  << YELLOW <<  std::endl;
        array[c]->get_brain()->print_ideas();
        std::cout << RESET_COLOR;
        c++;
    }
}

void fill_array_deep_copy(AAnimal* array[], int size)
{
    int flag = true;
    int c = 0;
    while(c < (size/2))
    {
        if(c == 0)
        {
            array[0] = new Cat();
            std::cout << 1 << " " << array[c]->get_type() << " slipped into the presentation hall, curiously exploring the venue." << std::endl;
            array[c]->get_brain()->set_ideas("Meow!");
            std::cout << "The cat took the stage and shared its idea with a simple, heartfelt: " << RED << std::endl;
            array[c]->get_brain()->print_ideas();
            std::cout << RESET_COLOR;
        }
        else
        {
            array[c] = new Cat();
            *static_cast<Cat*>(array[c]) = *static_cast<Cat*>(array[0]);
            std::cout << c + 1 << " " << array[c]->get_type() << " slipped into the presentation hall, curiously exploring the venue." << std::endl;
            std::cout << "The cat took the stage and shared its idea with a simple, heartfelt: " << RED << std::endl;
            array[c]->get_brain()->print_ideas();
            std::cout << RESET_COLOR;
        }
        c++;
    }
    while(c < size)
    {
        if(flag)
        {
            array[c] = new Dog();
            std::cout << c + 1 << " " << array[c]->get_type() << " trotted into the presentation hall, eagerly sniffing around the venue." << std::endl;
            array[c]->get_brain()->set_ideas("Woof!");
            std::cout << "The dog stepped up to the stage and expressed its idea with an enthusiastic: "  << YELLOW <<  std::endl;
            array[c]->get_brain()->print_ideas();
            std::cout << RESET_COLOR;
            flag = false;
        }
        else
        {   
            array[c] = new Dog();
            *static_cast<Dog*>(array[c]) = *static_cast<Dog*>(array[c-1]);
            std::cout << c + 1 << " " << array[c]->get_type() << " trotted into the presentation hall, eagerly sniffing around the venue." << std::endl;
            std::cout << "The dog stepped up to the stage and expressed its idea with an enthusiastic: "  << YELLOW <<  std::endl;
            array[c]->get_brain()->print_ideas();
            std::cout << RESET_COLOR;
        }
        c++;
    }
}


void fill_array_copy(AAnimal* array[], int size)
{
    int flag = true;
    int c = 0;
    while(c < (size/2))
    {
        if(c == 0)
        {
            array[0] = new Cat();
            array[c]->get_brain()->print_address();
            std::cout << 1 << " " << array[c]->get_type() << " slipped into the presentation hall, curiously exploring the venue." << std::endl;
            array[c]->get_brain()->set_ideas("Meow!");
            std::cout << "The cat took the stage and shared its idea with a simple, heartfelt: " << RED << std::endl;
            array[c]->get_brain()->print_ideas();
            std::cout << RESET_COLOR;
        }
        else
        {
            array[c] = new Cat(*static_cast<Cat*>(array[0]));
            array[c]->get_brain()->print_address();
            std::cout << c + 1 << " " << array[c]->get_type() << " slipped into the presentation hall, curiously exploring the venue." << std::endl;
            std::cout << "The cat took the stage and shared its idea with a simple, heartfelt: " << RED << std::endl;
            array[c]->get_brain()->print_ideas();
            std::cout << RESET_COLOR;
        }
        c++;
    }
    while(c < size)
    {
        if(flag)
        {
            array[c] = new Dog();
            array[c]->get_brain()->print_address();
            std::cout << c + 1 << " " << array[c]->get_type() << " trotted into the presentation hall, eagerly sniffing around the venue." << std::endl;
            array[c]->get_brain()->set_ideas("Woof!");
            std::cout << "The dog stepped up to the stage and expressed its idea with an enthusiastic: "  << YELLOW <<  std::endl;
            array[c]->get_brain()->print_ideas();
            std::cout << RESET_COLOR;
            flag = false;
        }
        else
        {   
            array[c] = new Dog(*static_cast<Dog*>(array[c-1]));
            array[c]->get_brain()->print_address();
            std::cout << c + 1 << " " << array[c]->get_type() << " trotted into the presentation hall, eagerly sniffing around the venue." << std::endl;
            std::cout << "The dog stepped up to the stage and expressed its idea with an enthusiastic: "  << YELLOW <<  std::endl;
            array[c]->get_brain()->print_ideas();
            std::cout << RESET_COLOR;        
        }
        c++;
    }
}

void delete_array(AAnimal* array[], int size)
{
    int c = 0;
    while(c < size)
    {
        if (array[c] != NULL)
        {
            if(array[c]->get_type() == "Cat")
                std::cout << c + 1 << " " << array[c]->get_type() << " gracefully slipped out of the presentation hall with a flick of its tail." << std::endl;
            if(array[c]->get_type() == "Dog")
                std::cout << c + 1<< " " << array[c]->get_type() << " exited the presentation hall with a cheerful wag of its tail." << std::endl;
            delete array[c];
        }
        c++;
    }
}


int main()
{
    int i = 4;
    AAnimal* array[i];
    std::cout << BLUE <<  "A total of " << i <<  " animals — half energetic dogs and half sharp-witted cats \n— invited for a global presentation on the impact of AI in enhancing AAnimal lives." << RESET_COLOR << "\n"<<std::endl;
    //fill_array(array, i);
    //fill_array_deep_copy(array, i);
    fill_array_copy(array, i);
    delete_array(array, i);
}