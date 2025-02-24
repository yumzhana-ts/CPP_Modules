/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/02/23 21:33:52 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/****************************************************/
/*                    Constructor                   */
/****************************************************/

template <typename T>
Array<T>::Array(void)
{
    this->my_array = NULL;
    this->n = 0;
    if (DEBUG) {std::cout << GREEN << "[Array] Default Constructor called" << RESET_COLOR << std::endl;}
}

template <typename T>
Array<T>::Array(size_t size) : my_array(new T[size]()), n(size)
{
    if (DEBUG) {std::cout << GREEN << "[Array] Default Constructor called" << RESET_COLOR << std::endl;}
}

template <typename T>
Array<T>::Array(const Array &src) : my_array(new T[src.n]), n(src.n)
{
    for (size_t i = 0; i < this->n; i++)
    {
        this->my_array[i] = src.my_array[i]; // Copy elements
    }
    if (DEBUG){std::cout << GREEN << "[Array] Copy Constructor called" << std::endl;}
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
Array<T> &Array<T>::operator=(const Array &rhs)
{
    if (this != &rhs)
    {
        delete[] this->my_array;
        this->n = rhs.n;
        this->my_array = new T[this->n];
        for (size_t i = 0; i < this->n; i++)
        {
            this->my_array[i] = rhs.my_array[i];
        }
    }
    if (DEBUG){ std::cout << GREEN << "[Array] Copy assignment operator called" << std::endl;}
    return *this;
}

template <typename T>
T &Array<T>::operator[](size_t index) {
    //if (DEBUG) {std::cout << "[Array] Non-const operator[] called with index: " << index << std::endl;}
    if (index >= this->n) 
    {
        throw std::out_of_range("Index out of bounds");
    }
    return my_array[index];
}

template <typename T>
const T &Array<T>::operator[](size_t index) const {
    //if (DEBUG) {std::cout << "[Array] Const operator[] called with index: " << index << std::endl;}
    if (index >= this->n) 
    {
        throw std::out_of_range("Index out of bounds");
    }
    return my_array[index];
}

