/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/20 13:30:43 by ytouate          ###   ########.fr       */
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
#include <fstream>
int main(void)
{
    ft::vector<int> myVec;

    myVec.reserve(64);
    system("leaks main.exe");
    return 0;
    std::vector<int> theirVec;
    
    ft::vector<int>::iterator myVecIt = myVec.begin();
    ft::vector<int>::iterator myVecIte = myVec.end();
    ft::vector<int>::const_iterator constMyVecIt = myVec.begin();
    ft::vector<int>::const_iterator constMyVecIte = myVec.end();
    std::vector<int>::const_iterator j = theirVec.begin();
    std::vector<int>::const_iterator p = theirVec.end();
    std::vector<int>::iterator theirVecIt;

    // constMyVecIt++;
    // j++;
    // constMyVecIt--;
    // ++constMyVecIt;
    // --constMyVecIt;
    j = p;
    // ft::vector<int>::const_iterator temp = constMyVecIt;
    // constMyVecIt = constMyVecIte;
    // constMyVecIte = temp; 
    std::vector<int>::iterator theirVecIte;
    
    std::ofstream theirResult("theirResult.txt");
    std::ofstream myResult("myResult.txt");
    std::srand(time(NULL));
    for (int i = 0; i < 1000; i++)
    {
        const int val = std::rand();
        myVec.push_back(val);
        theirVec.push_back(val);
    }
    theirResult << theirVec.size() << std::endl;
    myResult << myVec.size() << std::endl;
    for (int i = 0; i < 1000; i++)
    {
        if (i % 2)
        {
            myVec.erase(myVec.begin());
            theirVec.erase(theirVec.begin());
        }
    }
    theirResult << theirVec.size() << std::endl;
    myResult << myVec.size() << std::endl;
    for (int i = 0; i < 1000; i++)
    {
        if (i % 2)
        {
            myVec.push_back(i);
            theirVec.push_back(i);
        }
    }
    theirResult << theirVec.size() << std::endl;
    myResult << myVec.size() << std::endl;
    myVec.erase(myVec.begin(), myVec.end());
    theirVec.erase(theirVec.begin(), theirVec.end());
    for (int i = 0; i < 1000; i++)
    {
        const int val = std::rand();
        myVec.insert(myVec.begin(), val);
        theirVec.insert(theirVec.begin(), val);
    }
    theirResult << theirVec.size() << std::endl;
    myResult << myVec.size() << std::endl;
    for (int i = 0; i < 500; i++)
    {
        const int val = std::rand();
        myVec.insert(myVec.begin() + i, val);
        theirVec.insert(theirVec.begin() + i, val);
    }
    theirResult << theirVec.size() << std::endl;
    myResult << myVec.size() << std::endl;
    for (int i = 0; i < 1000; i++)
    {
        myResult << myVec[i] << "\n";
        theirResult << theirVec[i] << "\n";
    }
    theirResult << theirVec.size() << std::endl;
    myResult << myVec.size() << std::endl;
    bool res = system("diff theirResult.txt myResult.txt");
    if (!res)
        std::cout << "OK\n";
    else
        std::cout << "KO\n";
    system("rm theirResult.txt myResult.txt");
    return res;
    
}