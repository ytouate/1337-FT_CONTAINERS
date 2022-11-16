/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/16 18:52:51 by ytouate          ###   ########.fr       */
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

// class Integers
// {
// private:
//     int vec[200];
//     int size;

// public:
//     ft::iterator<int> begin() { return ft::iterator<int>(&vec[0]); }
//     ft::iterator<int> end() { return ft::iterator<int>(&vec[200]); }
//     ft::reverse_iterator<ft::iterator<int> > rbegin() { return ft::reverse_iterator<ft::iterator<int> >(&vec[199]); }
//     ft::reverse_iterator<ft::iterator<int> > rend() { return ft::reverse_iterator<ft::iterator<int> >(&vec[size - (size + 1)]); }
//     void f() { std::cout << "hello world\n"; }
//     Integers() : size(200)
//     {
//         std::srand(time(NULL));
//         for (int i = 0; i < 200; i++)
//         {
//             vec[i] = i + 1;
//         }
//     }
//     ~Integers() {}
// };

int main(void)
{

    std::vector<int> i;
    ft::vector<int> myVec;

    myVec.push_back(10);
    myVec.push_back(20);
    myVec.push_back(30);
    i.push_back(10);
    i.push_back(20);
    i.push_back(30);

    myVec.resize(2);    
    i.resize(2);
    i.resize(10);
    myVec.resize(10);
    std::cout << "Size: " <<  i.size() << std::endl;
    std::cout << "Capacity: " << i.capacity()  << std::endl;
    std::cout << "myVec Size: " <<  myVec.size() << std::endl;
    std::cout << "myVec Capacity: " << myVec.capacity()  << std::endl;
    return 0;

    // i.push_back(10);
    // i.push_back(20);
    // i.insert(i.begin(), 1, 30);
    // myVec.push_back(10);
    // myVec.push_back(20);
    // myVec.insert(myVec.begin(), 1, 3);
    // myVec.insert(myVec.begin(), 1, 2);
    // myVec.insert(myVec.begin(), 1, 2);
    // myVec.insert(myVec.begin(), 1, 20);
    // return 0;
    ft::vector<int>::iterator myIt = myVec.begin();
    ft::vector<int>::iterator myIte  = myVec.end();
    for (; myIt != myIte; myIt++)
        std::cout << *myIt << std::endl;
    // i.insert(i.begin(), 1, 30);
    // i.push_back(10);
    // i.push_back(20);
    // i.insert(myVec.begin(), 1, 30);
    std::vector<int>::iterator iIt = i.begin();
    std::vector<int>::iterator iIte = i.end();

    std::cout << "MyVec capacity:\t" << myVec.capacity() << std::endl;
    std::cout << "MyVec size:\t" << myVec.size() << std::endl;
    // system("leaks main.exe");
    return 0;
    ft::vector<int>::iterator it = myVec.begin();
    ft::vector<int>::iterator ite = myVec.end();
    std::vector<int> v;
    int n = 1;
    for (; it != ite; ++it)
    {
        *it = n;
        n++;
        std::cout << *it << std::endl;
    }
    ft::vector<int>::reverse_iterator rit = myVec.rbegin();
    ft::vector<int>::reverse_iterator rite = myVec.rend();

    // for (; rit != rite; ++rit)
    //     std::cout << *rit << std::endl;
    return 0;
    int arr[200];

    ft::iterator<int> arrit(&arr[0]);
    ft::iterator<int> arrite(&arr[200]);
    for (int i = 0; i < 200; i++)
        arr[i] = i;
    for (int i = 0; i < 200; i++)
    {
        std::cout << *arrit << std::endl;
        arrit++;
    }
    return 0;

    // Integers ints;

    // ft::iterator<int> it = ints.begin();
    // ft::iterator<int> ite = ints.end();

    // ft::reverse_iterator<ft::iterator<int> > rit = ints.rbegin();
    // ft::reverse_iterator<ft::iterator<int> > rite = ints.rend();

    // // rit++;
    // // rit--;

    // std::vector<int> vec;
    // for (int i = 0; i < 200; i++)
    // {
    //     vec.push_back(i + 1);
    // }

    // std::vector<int>::reverse_iterator rit2 = vec.rbegin();
    // std::vector<int>::reverse_iterator rite2 = vec.rend();
    // ft::reverse_iterator<ft::iterator<int> > another(rit);
    // rite = rit;
    // // rite--;
    // // std::cout << *rite2 << std::endl;
    // std::cout << *(rite - 1) << std::endl;
    // // Integers ints;
    // // iterator<Integers> it = ints.begin();
    // // iterator<Integers> ite = ints.end();
    // // (void)ints, (void)it, (void)ite;
    // // (*it).name = "Something else";
    // // it->name = "Hello world";

    // // std::vector<int> vec;
    // // vec.push_back(10);
    // // vec.push_back(20);

    // // // std::random_access_iterator_tag something;
    // // std::vector<int>::iterator::iterator_type
    // // // std::vector<int>::iterator it2 = vec.begin();
    // // // std::vector<int>::iterator ite2 = vec.end();
    // // std::vector<int>::iterator rit = vec.begin();
    // // std::vector<int>::iterator rite = vec.end();

    // // ++it;
    // // while (rit < rite)
    // // {
    // //     std::cout << *rit << std::endl;
    // //     rit++;
    // // }
    // return (0);
}