/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/02/19 21:54:44 by ytsyrend         ###   ########.fr       */
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
Array<T>::Array(unsigned int size):my_array(new T[size]()), n(size)
{
    if (DEBUG){ std::cout << GREEN << "[Array] Default Constructor called" << RESET_COLOR << std::endl;}
}

template <typename T>
Array<T>::Array(const Array& src):my_array(new T[src.n]), n(src.n)
{
    for (unsigned int i = 0; i < this->n; i++)
    {
        this->my_array[i] = src.my_array[i]; // Copy elements
    }
    if (DEBUG) 
    { 
        std::cout << GREEN << "[Array] Copy Constructor called" << std::endl; 
        std::cout << "Address pointer src: " << src.my_array << " Address pointer current: " << this->my_array << RESET_COLOR << std::endl;
    }
}


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

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs) 
{
    if (this != &rhs)
    {
        delete[] this->my_array;
        this->n = rhs.n;
        this->my_array = new T[this->n];
        for (unsigned int i = 0; i < this->n; i++)
        {
            this->my_array[i] = rhs.my_array[i];
        }
    }
    if (DEBUG) 
    {
        std::cout << GREEN << "[Array] Copy assignment operator called" << std::endl; 
        std::cout << "Address pointer src: " << rhs.my_array << " Address pointer current: " << this->my_array << RESET_COLOR << std::endl;
    }
    return *this;
}


/****************************************************
*                 Memeber Functions                *
****************************************************/
template <typename T>
T Array<T>::get_element(unsigned int n_element)
{
    if (n_element >= this->n)
    {
        throw std::out_of_range("Index out of range");
    }
    return this->my_array[n_element];
}

template <typename T>
void Array<T>::nice_testing(unsigned int n_element)
{
    std::cout << "Array [size: "<< this->n;
    try
    {
        std::cout << "]  →  index "<< n_element << ": " << this->get_element(n_element) << std::endl;
    }
    catch(std::out_of_range &e)
    {
        std::cout << RED << e.what() << RESET_COLOR << std::endl;
    }
    std::cout << LINE << std::endl;
}

template class Array<int>;
template class Array<double>;
template class Array<bool>;
template class Array<std::string>;
