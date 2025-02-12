/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/07/13 03:54:02 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.class.hpp"


void null_test()
{
    std::cout << GREEN << "Test case 1: Pointer is NULL" << RESET_COLOR << std::endl;
    Data *data = NULL;
    uintptr_t int_ptr = Serialize::serialize(data);
    Serialize::deserialize(int_ptr);
    std::cout << LINE;
}


int main() 
{
    null_test();
    std::cout << GREEN "Test case 2: Check deserialization" << RESET_COLOR << std::endl;
    
    Data data;
    data.x = 1;
    uintptr_t int_ptr = Serialize::serialize(&data);
    if (Serialize::deserialize(int_ptr) == &data)
        std::cout << "Test passed: deserialized pointer matches original: " << Serialize::deserialize(int_ptr) <<  std::endl;
    else
        std::cout << "Test failed: deserialized pointer doesnt match original" << std::endl;
    std::cout << LINE;

    std::cout << GREEN "Test case 3: Compare serialization of c and c++ style" << RESET_COLOR << std::endl;
    uintptr_t int_ptr_c = (uintptr_t)&data;
    if (Serialize::serialize(&data) == int_ptr_c)
        std::cout << "Serialized pointers are identical! What a surprise!: " <<  Serialize::serialize(&data) << std::endl;
    else
        std::cout << "Test failed: serialized pointer doesnt match original" << std::endl;  
}