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

int main() 
{
    std::cout << "\nTest 1: Testing Orthodox Canonical Form" << std::endl;
    Bureaucrat Alex(1, "Alex"); // Default Constructor called
    Bureaucrat Dan(Alex); // Copy Constructor called
    Bureaucrat John(1, "John");
    John = Dan; // Copy Assignment Operator called
    std::cout << LINE << std::endl;
    
    std::cout << "\nTest 2: Testing Bureaucrat creation" << std::endl;
    std::cout << BLUE "Welcome to the Banana Bureau of Sticker Affairs," << std::endl << "where every fruit gets properly labeled and processed before it can go anywhere!" << std::endl;
    Bureaucrat Jim(1, "Jim");
    std::cout << RED <<  Jim.get_name() << " at grade " << Jim.get_grade() << " oversees the entire Banana Bureau of Sticker Affairs, making the rules and approving the banana stickers" RESET_COLOR << std::endl;
    Bureaucrat Lucy(150, "Lucy");
    std::cout << RED << Lucy.get_name() << " at grade " << Lucy.get_grade() <<  " spends her days mindlessly applying them, stuck in the endless cycle of bureaucracy. " RESET_COLOR << std::endl;
    std::cout << LINE << std::endl;
    
    std::cout << "\nTest 3: Testing Bureaucrat increase and decrease" << std::endl;
    std::cout << Jim << std::endl;
    Jim.decrement_grade();
    std::cout << Jim << std::endl;
    std::cout << Lucy << std::endl;
    Lucy.increment_grade();
    std::cout << Lucy << std::endl;
    std::cout << LINE << std::endl;

    std::cout << "\nTest 4: Testing Bureaucrat creation with invalid grade" << std::endl;
    try
    {
        Bureaucrat Rosy(0, "Lucy");
        std::cout << Rosy << std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << LINE << std::endl;
    
    std::cout << "\nTest 5: Testing Bureaucrat creation with invalid decrease and increase grade" << std::endl;
    try
    {
        Lucy.decrement_grade();
        std::cout << Lucy << std::endl;
        Lucy.decrement_grade();
        std::cout << Lucy << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException  &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException  &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Jim.increment_grade();
        std::cout << Jim << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException  &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException  &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}