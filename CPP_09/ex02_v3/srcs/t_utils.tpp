/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_utils.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:16 by ytsyrend          #+#    #+#             */
/*   Updated: 2025/04/19 23:00:16 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge_me.class.hpp"


//TODO: 1. take numebrs and put to class Pmerge_me and put to vector
//TODO: 2. combine pairs by adding each pair to object
//TODO: 3. 

// template <typename T>
// class Pair
// {
// private:
//     int level;
//     std::vector<std::pair<T, T> >;
// public:
//     Pair(int level, std::pair<T,T> pair);
// 	~Pmerge_me(void);

// 	int get_level(){ return this->level;}
// 	std::pair<T,T> pair(){return this->pair;}
// }

template <typename T>
std::ostream& operator<<(std::ostream& o, const std::pair<T, T>& pair)
{
    o << "{" << pair.first << ", " << pair.second << "}";
    return o;
}

template <typename T>
void print_pairs_vector(const std::vector<std::pair<T, T> >& vec)
{
    std::cout << GREEN << "Generated pairs: [";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (i != 0)
            std::cout << ", ";
        std::cout << vec[i];
    }
    std::cout << "]" << RESET_COLOR << std::endl;
}

template<typename T>
T& get_deepest(T& value) {
    return value;
}

template<typename T1, typename T2>
T2& get_deepest(std::pair<T1, std::pair<T2, T2> >& p) {
    return get_deepest(p.second);
}

template<typename T1, typename T2>
T2& get_deepest(std::pair<T1, T2>& p) {
    return get_deepest(p.second);
}

/*template<typename T>
std::vector<std::pair<T, T> > sort_numbers(std::vector<std::pair<T, T> > output)
{
    typename std::vector<std::pair<T, T> >::iterator it = output.begin();
    for (; it != output.end(); ++it)
    {
        T& a = it->first;
        T& b = it->second;

        int a_deep = get_deepest(a).get_number();
        int b_deep = get_deepest(b).get_number();

		if (a_deep > b_deep)
		{
			std::swap(a, b);
		}

        //std::cout << "a: " << a_deep << " b: " << b_deep << std::endl;
    }
    return output;
}*/

template<typename T>
std::vector<std::pair<T, T> > sort_numbers(std::vector<T>& output)
{
    typename std::vector<std::pair<T, T> >::iterator it = output.begin();
    for (; it != output.end(); ++it)
    {
        T& a = it->first;
        T& b = it->second;

        int a_deep = get_deepest(a).get_number();
        int b_deep = get_deepest(b).get_number();

		if (a_deep > b_deep)
		{
			std::swap(a, b);
		}
        //std::cout << "a: " << a_deep << " b: " << b_deep << std::endl;
    }
    return output;
}


template <typename T>
std::vector<std::pair<T, T> > group_into_pairs(const std::vector<T>& input)
{
    std::vector<std::pair<T, T> > output;
    typename std::vector<T>::const_iterator it = input.begin();
    typename std::vector<T>::const_iterator end = input.end();

    while (it != end)
    {
        T first = *it;
        ++it;

        if (it != end)
        {
            T second = *it;
            ++it;
            output.push_back(std::make_pair(first, second));
        }
        else
        {
            break;
        }
    }
    return output;
}


template<typename T>
std::vector<std::pair<T, T> > group_sort_pairs(const std::vector<T>& input)
{
    std::vector<std::pair<T, T> > grouped = group_into_pairs(input);
	print_pairs_vector(grouped);
    return grouped;
}

template<typename T>
std::vector<std::pair<T, T> > recursive_group_into_pairs(const std::vector<T>& input) 
{
    if (input.size() <= 1) {
        return input;
    }
    return (recursive_group_into_pairs(group_into_pairs(input)));
}

/*template<typename T>
void group_sort_pairs(std::vector<T> input, std::vector<std::pair<T, T> >& output)
{
	output = group_into_pairs(input);
	sort_numbers(output);
}

template<typename T>
std::vector<std::pair<T, T> > recursive_sort_pairs(std::vector<T> input)
{
	std::vector<std::pair<T, T> > current;
	group_sort_pairs(input, current);

	if (current.size() <= 1)
		return current;
	return recursive_sort_pairs(current);
}*/