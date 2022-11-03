/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <touateyoussef2003@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/03 12:47:27 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> vec;
    std::vector<int>::value_type val_type = 43;
    std::vector<int>::reference ref = val_type;
    std::vector<int>::iterator it = vec.begin();
    std::vector<int>::const_iterator cit = it;
    bool type = std::vector<int>::difference_type();
    unsigned int size = std::vector<int>::size_type();
    std::allocator< std::vector<int> > alloc = vec.get_allocator();
    std::cout << "the allocator max size\t" << alloc.max_size() << std::endl;
    std::cout << " the vector max size\t" << vec.max_size() << std::endl;
    std::vector<int>vec_b;
    vec.push_back(10);
    return vec < vec_b ? 1 : 0;
}
