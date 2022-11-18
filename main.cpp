/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/18 18:23:09 by ytouate          ###   ########.fr       */
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
    theirVec.insert(theirVec.begin(), 10);
    theirVec.insert(theirVec.begin(), 20);
    theirVec.insert(theirVec.begin(), 30);
    theirVec.insert(theirVec.begin(), 40);
    theirVec.insert(theirVec.begin(), 50);
    theirVec.insert(theirVec.begin(), 60);
    theirVec.insert(theirVec.begin(), 70);
    theirVec.insert(theirVec.begin(), 80);

    myVec.insert(myVec.begin(), 10);
    myVec.insert(myVec.begin(), 20);
    myVec.insert(myVec.begin(), 30);
    myVec.insert(myVec.begin(), 40);
    myVec.insert(myVec.begin(), 50);
    myVec.insert(myVec.begin(), 60);
    myVec.insert(myVec.begin(), 70);
    myVec.insert(myVec.begin(), 80);

    myVec.erase(myVec.begin(), myVec.end() - 9);
    // theirVec.erase(theirVec.begin(), theirVec.end() - 8);
    // std::vector<int>::iterator a = theirVec.insert(theirVec.begin() + 1, 10);
    // return 0;
    // myVec.insert(myVec.begin(), 1, 20);
    std::cout << "==== myVec Data ====\n";
    std::cout << myVec.size() << " " << myVec.capacity() << std::endl;
    std::copy(theirVec.begin(), theirVec.end(), std::ostream_iterator<int> (std::cout, " "));
    std::cout << std::endl;
    std::cout << "==== theirVec Data ====\n";
    std::cout << theirVec.size() << " " << theirVec.capacity() << std::endl;
    std::copy(myVec.begin(), myVec.end(), std::ostream_iterator<int> (std::cout, " "));
    std::cout << "\n";
    // system("leaks main.exe");
    return (0);
}