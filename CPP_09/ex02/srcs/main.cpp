/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:41:01 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/05/15 13:49:20 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Pmerge_me.class.hpp"


void print_vector_wi(const std::vector<int>& vec) 
{
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i != vec.size() - 1) std::cout << " ";
    }
    std::cout << "\n";
}

bool is_sorted(const std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i - 1] > vec[i]) {
            std::cout << "⛔️ Not sorted at index " << i - 1 << " and " << i << "!\n";
            return false;
        }
    }
    std::cout << "✅ Vector is sorted!\n";
    return true;
}

void pmerge_me_dispatcher(t_original_vector &vec)
{
    int count = vec.original_vector.size();
    int calculated_max_depth = recursion_levels(count);
    
    switch (calculated_max_depth) 
    {
        case 0:
            meta_recursive<0>(vec);
            break;
        case 1:
            meta_recursive<1>(vec);
            break;
        case 2:
            meta_recursive<2>(vec);
            break;
        case 3:
            meta_recursive<3>(vec);
            break;
        case 4:
            meta_recursive<4>(vec);
            break;
        case 5:
            meta_recursive<5>(vec);
            break;
        case 6:
            meta_recursive<6>(vec);
            break;
        case 7:
            meta_recursive<7>(vec);
            break;
        case 8:
            meta_recursive<8>(vec);
            break;
        case 9:
            meta_recursive<9>(vec);
            break;
        case 10:
            meta_recursive<10>(vec);
            break;
        case 10:
            meta_recursive<10>(vec);
            break;
    }
}

int main(int argc, char **argv)
{
    t_original_vector vec;
    parse_and_store_numbers(argc, argv, vec);
    pmerge_me_dispatcher(vec);
    print_vector_wi(vec.used);
    return 0;
}