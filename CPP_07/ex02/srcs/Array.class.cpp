/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/02/18 20:50:14 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.class.tpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

template <typename T>
Array<T>::Array(void) 
{
    this->my_array = NULL;
    this->n = 0;
    if (DEBUG){ std::cout << GREEN << "[Array] Default Constructor called" << RESET_COLOR << std::endl;}
}

template <typename T>
Array<T>::Array(unsigned int size):my_array(new T[size]), n(size)
{
    if (DEBUG){ std::cout << GREEN << "[Array] Default Constructor called" << RESET_COLOR << std::endl;}
}

/*template <typename T>
Array<T>::Array(const Array& src): value(src.value) 
{
    if (DEBUG){std::cout << GREEN << "[Array] Copy Constructor called" << RESET_COLOR << std::endl;}
}*/


/****************************************************/
/*                    Destructor.                   */
/****************************************************/
template <typename T>
Array<T>::~Array(void) 
{
    delete[] this->my_array;
    if (DEBUG){std::cout << GREEN << "[Array] Destructor called" << RESET_COLOR << std::endl;}
}

/****************************************************
*                    Overload                      *
****************************************************/

/*template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs) 
{
    if (DEBUG){std::cout << GREEN << "[Array] Copy assignment operator called" << std::endl;}
    if (this != &rhs)
        this->value = rhs.get_value();
    return (*this);
}*/


/****************************************************
*                 Memeber Functions                *
****************************************************/
template <typename T>
T Array<T>::get_element(unsigned int n_element)
{
    try
    {
        if (n_element > this->n)
            throw std::out_of_range("Index out of range");
    }
    catch(const std::out_of_range &e)
    {
        std::cerr << RED << "Exception: " << RESET_COLOR << e.what() << std::endl; 
    }
    return (this->my_array[n_element]);
}

template <typename T>
void Array<T>::nice_testing(unsigned int n_element)
{
    std::cout << "Array size: "<< this->n << std::endl;
    std::cout << n_element << " element of array: " << std::endl;
    //this->get_element(n_element) 
    std::cout << LINE << std::endl;
}

template class Array<int>;
template class Array<double>;
template class Array<bool>;
template class Array<std::string>;
