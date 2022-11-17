/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/17 14:29:06 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <set>
#include <forward_list>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <array>
#include <memory.h>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "vector/vector.hpp"
#include <memory>

int main(void)
{
    ft::vector<int> myVec;
    std::vector<int> theirVec;
    ft::vector<int>::iterator it = myVec.begin();
    // myVec.push_back(10);
    // myVec.push_back(20);
    // myVec.push_back(30);

    // theirVec.push_back(10);
    // theirVec.push_back(20);
    // theirVec.push_back(30);
    // theirVec.insert(theirVec.begin(), 1, 5);
    theirVec.insert(theirVec.begin(), 1, 10);
    theirVec.insert(theirVec.begin(), 1, 20);
    theirVec.insert(theirVec.begin(), 1, 30);
    theirVec.insert(theirVec.begin(), 1, 40);
    theirVec.insert(theirVec.begin(), 1, 50);
    theirVec.insert(theirVec.begin(), 1, 60);
    theirVec.insert(theirVec.begin(), 1, 70);
    theirVec.insert(theirVec.begin(), 1, 10);
    theirVec.insert(theirVec.begin(), 1, 20);
    theirVec.insert(theirVec.begin(), 1, 30);
    theirVec.insert(theirVec.begin(), 1, 40);
    theirVec.insert(theirVec.begin(), 1, 50);
    theirVec.insert(theirVec.begin(), 1, 60);
    theirVec.insert(theirVec.begin(), 1, 70);
    theirVec.insert(theirVec.begin(), 1, 10);
    theirVec.insert(theirVec.begin(), 1, 20);
    theirVec.insert(theirVec.begin(), 1, 30);
    theirVec.insert(theirVec.begin(), 1, 40);
    theirVec.insert(theirVec.begin(), 1, 50);
    theirVec.insert(theirVec.begin(), 1, 60);
    theirVec.insert(theirVec.begin(), 1, 70);
    theirVec.insert(theirVec.begin(), 1, 10);
    theirVec.insert(theirVec.begin(), 1, 20);
    theirVec.insert(theirVec.begin(), 1, 30);
    theirVec.insert(theirVec.begin(), 1, 40);
    theirVec.insert(theirVec.begin(), 1, 50);
    theirVec.insert(theirVec.begin(), 1, 60);
    theirVec.insert(theirVec.begin(), 1, 70);
    theirVec.insert(theirVec.begin() + 2, 1, 999);
    myVec.insert(myVec.begin(), 1, 10);
    myVec.insert(myVec.begin(), 1, 20);
    myVec.insert(myVec.begin(), 1, 30);
    myVec.insert(myVec.begin(), 1, 40);
    myVec.insert(myVec.begin(), 1, 50);
    myVec.insert(myVec.begin(), 1, 60);
    myVec.insert(myVec.begin(), 1, 70);
    myVec.insert(myVec.begin(), 1, 10);
    myVec.insert(myVec.begin(), 1, 20);
    myVec.insert(myVec.begin(), 1, 30);
    myVec.insert(myVec.begin(), 1, 40);
    myVec.insert(myVec.begin(), 1, 50);
    myVec.insert(myVec.begin(), 1, 60);
    myVec.insert(myVec.begin(), 1, 10);
    myVec.insert(myVec.begin(), 1, 20);
    myVec.insert(myVec.begin(), 1, 30);
    myVec.insert(myVec.begin(), 1, 40);
    myVec.insert(myVec.begin(), 1, 50);
    myVec.insert(myVec.begin(), 1, 60);
    myVec.insert(myVec.begin(), 1, 70);
    myVec.insert(myVec.begin(), 1, 10);
    myVec.insert(myVec.begin(), 1, 20);
    myVec.insert(myVec.begin(), 1, 30);
    myVec.insert(myVec.begin(), 1, 40);
    myVec.insert(myVec.begin(), 1, 50);
    myVec.insert(myVec.begin(), 1, 60);
    myVec.insert(myVec.begin(), 1, 70);
    myVec.insert(myVec.begin(), 1, 70);
    myVec.insert(myVec.begin() + 2, 1, 999);
    
    
    // myVec.insert(myVec.begin(), 1, 20);
    std::cout << theirVec.size() << " " << theirVec.capacity() << std::endl;
    std::cout << myVec.size() << " " << myVec.capacity() << std::endl;
    std::copy(theirVec.begin(), theirVec.end(), std::ostream_iterator<int> (std::cout, " "));
    std::cout << std::endl;
    std::copy(myVec.begin(), myVec.end(), std::ostream_iterator<int> (std::cout, " "));
    std::cout << "\n";
    system("leaks main.exe");
    return (0);
}