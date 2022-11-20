/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/20 12:20:48 by ytouate          ###   ########.fr       */
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
    std::vector<int> theirVec;
    
    ft::vector<int>::iterator myVecIt = myVec.begin();
    ft::vector<int>::iterator myVecIte = myVec.end();
    ft::vector<int>::const_iterator constMyVecIt = myVec.begin();
    ft::vector<int>::const_iterator constMyVecIte = myVec.end();
    std::vector<int>::const_iterator j = theirVec.begin();
    std::vector<int>::const_iterator p = theirVec.end();
    std::vector<int>::iterator theirVecIt;
    // *x = 10;
    // x + y;
    myVecIt - myVecIte;
    bool i = myVecIt != myVecIte;
    i = myVecIt == myVecIte;
    i = myVecIt < myVecIt;
    i = myVecIte <= myVecIte;
    i = myVecIt > myVecIt;
    i = myVecIt >= myVecIt;
    myVecIt + 1;
    myVecIt - 1;
    myVecIt - myVecIt;
    myVecIt += 1;
    myVecIt -= 1;
    myVecIt++;
    myVecIt--;
    ++myVecIt;
    --myVecIt;

    constMyVecIt - constMyVecIte;
    i = myVecIt != constMyVecIte;
    i = constMyVecIt == constMyVecIte;
    i = constMyVecIt < constMyVecIt;
    i = constMyVecIte <= constMyVecIte;
    i = constMyVecIt > constMyVecIt;
    i = constMyVecIt >= constMyVecIt;
    constMyVecIt + 1;
    constMyVecIt - 1;
    constMyVecIt - constMyVecIt;
    j += 1;
    constMyVecIt += 1;
    constMyVecIt -= 1;
    // constMyVecIt++;
    // j++;
    // constMyVecIt--;
    // ++constMyVecIt;
    // --constMyVecIt;
    j = p;
    // ft::vector<int>::const_iterator temp = constMyVecIt;
    // constMyVecIt = constMyVecIte;
    // constMyVecIte = temp; 
    return 0;
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