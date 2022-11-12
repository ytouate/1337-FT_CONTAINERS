/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/12 14:31:55 by ytouate          ###   ########.fr       */
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

class Integers
{
private:
    int vec[200];
    int size;

public:
    iterator<int> begin() { return iterator<int>(&vec[0]); }
    iterator<int> end() { return iterator<int>(&vec[200]); }
    ft::reverse_iterator<iterator<int> > rbegin() { return ft::reverse_iterator<iterator<int> >(&vec[199]); }
    ft::reverse_iterator<iterator<int> > rend() { return ft::reverse_iterator<iterator<int> >(&vec[size - (size + 1)]); }
    void f() { std::cout << "hello world\n"; }
    Integers(): size(200)
    {
        std::srand(time(NULL));
        for (int i = 0; i < 200; i++)
        {
            vec[i] = i + 1;
        }
    }
    ~Integers() {}
};

int main(void)
{

    Integers ints;

    iterator<int> it = ints.begin();
    iterator<int> ite = ints.end();

    ft::reverse_iterator<iterator<int> > rit = ints.rbegin();
    ft::reverse_iterator<iterator<int> > rite = ints.rend();


    // rit++;
    // rit--;
    
    std::vector<int> vec;
    for (int i = 0; i < 200; i++)
    {
        vec.push_back(i + 1);
    }

    std::vector<int>::reverse_iterator rit2 = vec.rbegin();
    std::vector<int>::reverse_iterator rite2 = vec.rend();
    ft::reverse_iterator< iterator <int> > another(rit);
    rite = rit;
    // rite--;
    // std::cout << *rite2 << std::endl;
    std::cout << *(rite - 1)<< std::endl;
    // Integers ints;
    // iterator<Integers> it = ints.begin();
    // iterator<Integers> ite = ints.end();
    // (void)ints, (void)it, (void)ite;
    // (*it).name = "Something else";
    // it->name = "Hello world";

    // std::vector<int> vec;
    // vec.push_back(10);
    // vec.push_back(20);

    // // std::random_access_iterator_tag something;
    // std::vector<int>::iterator::iterator_type
    // // std::vector<int>::iterator it2 = vec.begin();
    // // std::vector<int>::iterator ite2 = vec.end();
    // std::vector<int>::iterator rit = vec.begin();
    // std::vector<int>::iterator rite = vec.end();

    // ++it;
    // while (rit < rite)
    // {
    //     std::cout << *rit << std::endl;
    //     rit++;
    // }
    return (0);
}