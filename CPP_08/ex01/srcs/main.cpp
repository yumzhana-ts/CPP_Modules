/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/03/20 13:04:24 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"

void orthodox_test()
{
    Span obj1(1);
    Span obj2(obj1);
    Span obj3(1);
    obj3 = obj2;
}

/*int main() 
{
    Span super_vector(3);
    super_vector.add_number(100);
    super_vector.add_number(1);
    super_vector.add_number(2);
    super_vector.print_vector();
    std::cout << super_vector.shortest_span() << std::endl;
    std::cout << super_vector.longest_span() << std::endl;
    return (0);
}*/

int main()
{
    Span sp = Span(5);
    /*sp.add_number(5);
    sp.add_number(3);
    sp.add_number(17);
    sp.add_number(9);
    sp.print_vector();
    std::cout << sp.shortest_span() << std::endl;
    std::cout << sp.longest_span() << std::endl;*/
    sp.add_number(1);
    int array[5] = {1,2,3,4,5};
    int size_array = (sizeof(array)/sizeof(array[0]));
    std::vector<int> vec2(array, array+size_array);
    sp.add_number(vec2);
    sp.print_vector();
}