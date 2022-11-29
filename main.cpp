/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/30 00:23:54 by ytouate          ###   ########.fr       */
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
#include <math.h>
#include "lexicographical_compare.hpp"
#include "is_integral.hpp"
#include "pair.hpp"
#include "istream"
#include <string>
#include <sstream>
#include "make_pair.hpp"

        // intvector v(s_int, s_int + s_size);

        // CHECK_AND_PRINT_ALL(v);

        // v.push_back(64);
        // v.assign(v.begin(), v.begin() + 21);

        // CHECK_AND_PRINT_ALL(v);

        // v.push_back(64);
        // v.assign(v.begin(), v.end());

        // CHECK_AND_PRINT_ALL(v);
int main(void)
{
    std::vector<int> v(12, 20);
    ft::vector<int> vec(12, 20);
    vec.push_back(64);
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << "\n\n";
    std::cout << "the begin i passed " << *(vec.begin() + 1) << std::endl; 
    vec.assign(vec.begin(), vec.begin() + 1);
    v.push_back(64);
    // v.assign(v.begin(), v.begin() + 10);
    
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    // std::vector<char> v(it, end);
    // std::pair<std::vector<int>, std::vector<int>> theirPr;
    // theirPr.swap(theirPr);
    // ft::vector<int>::reverse_iterator it = myVec.rbegin();
    // ft::vector<int>::reverse_iterator ite = myVec.rend();
    // std::vector<int>::reverse_iterator cit = theiVec.rbegin();
    // std::vector<int>::reverse_iterator cite = theiVec.rend();
    // bool _bool = ft::lexicographical_compare(ait, aite, ait + 10, aite);
    // std::cout << _bool << std::endl;
    // theiVec.insert(theiVec.begin(), list.begin(), list.end());
    // myVec.insert(myVec.begin(), list.begin(), list.end());
    // // while (!myVec.empty())
    // // {
    //     std::cout << myVec.size() << std::endl;
    //     myVec.erase(myVec.begin() + 1, myVec.begin() + 2);
    //     std::cout << myVec.size() << std::endl;
    //     std::cout << myVec.capacity() << std::endl;
    // // }
    // std::cout << " size = " << v.size() << std::endl;
    // for (int i = 0; i < v.size(); i++)
    //     std::cout << v[i] << std::endl;
    // std::copy(v.begin(), v.end(), std::ostream_iterator<char> (std::cout, " "));
    
    // std::cout << " \n";
    // std::copy(vec.begin(), vec.end(), std::ostream_iterator<char> (std::cout, " "));
    // if (cit == theiVec.rbegin())
    //     std::cout << "am here\n";
    // std::vector<std::string> theirVec(5000, "Test");
    // std::vector<int>::iterator bit;
    // std::vector<int>::iterator bite;
    // myVec.insert(myVec.begin(), 0, 10);
    // theirVec.insert(theirVec.begin(), 0, 10);
    // myVec.insert(myVec.begin() + 115, std::numeric_limits<short int>::max(), 10);
    // myVec.insert(myVec.begin() + 15, (std::size_t)std::numeric_limits<std::ptrdiff_t>::max(), "123");
    // myVec.push_back(10);
    // myVec.push_back(20);
    // ft::vector<int>::const_iterator b = myVec.begin();
    // // it = myVec.begin();
    // // it++;
    // b++;

    // std::cout << *b << std::endl;
    // ft::vector<int> s;
    // std::vector<int> a;

    // srand(time(NULL));
    // for (int i = 0; i < 1000; i++)
    // {
    //     const int val = rand() % 1000;
    //     s.push_back(val);
    //     a.push_back(val);
    // }
    // // std::vector<int>::iterator it = a.begin();
    // ft::vector<int>::iterator cit = s.begin();
    // ft::vector<int>::const_iterator cite = s.end();
    // std::vector<int>::iterator it = a.begin();
    // std::vector<int>::iterator ite = a.end();

    // if (cit < cite)
    //     std::cout << "am here\n";
    // std::cout << *(42 + it) << std::endl;
    // std::cout << *(42 + it - 3) << std::endl << std::endl;
    // std::cout << *(42 + cit) << std::endl;
    // std::cout << *(42 + cit - 3) << std::endl;
    // std::vector<int>::iterator a = s.begin();
    // std::vector<int>::iterator b = s.end();
    // 42 + a;
    // 42 - a;

    // myVec.push_back(10);
    // myVec.push_back(20);
    // it = myVec.begin();
    // ite = myVec.end();
    // std::cout << *it++ << std::endl;
    // std::cout << std::numeric_limits<size_t>::max() / sizeof(unsigned char) << std::endl;
    // myVec.reserve(64);
    // system("leaks main.exe");
    //  _VSTD::min<size_type>(__alloc_traits::max_size(this->__alloc()),
    //                              numeric_limits<difference_type>::max());
    // std::cout <<  << std::endl;
    // std::cout << static_cast<int>(std::numeric_limits<char>::max()) << std::endl;
    // std::cout << std::numeric_limits<int>::max()  << std::endl;
    // std::cout << std::numeric_limits<ptrdiff_t>::max() << std::endl;
    // std::cout << myVec.get_allocator().max_size() << std::endl;
    // std::cout << std::min<size_t> (myVec.get_allocator().max_size(), std::numeric_limits<ptrdiff_t>::max());
    // if (PTRDIFF_MAX < myVec.get_allocator().max_size())
    //     return PTRDIFF_MAX;
    // return myVec.get_allocator().max_size();
    // std::cout <<  << std::endl;
    // return 0;
    // std::vector<int> theirVec;
    // theirVec.max_size();
    // ft::vector<int>::iterator myVecIt = myVec.begin();
    // ft::vector<int>::iterator myVecIte = myVec.end();
    // ft::vector<int>::const_iterator constMyVecIt = myVec.begin();
    // ft::vector<int>::const_iterator constMyVecIte = myVec.end();
    // std::vector<int>::const_iterator j = theirVec.begin();
    // std::vector<int>::const_iterator p = theirVec.end();
    // std::vector<int>::iterator theirVecIt;

    // constMyVecIt++;
    // j++;
    // constMyVecIt--;
    // ++constMyVecIt;
    // --constMyVecIt;
    // j = p;
    // // ft::vector<int>::const_iterator temp = constMyVecIt;
    // // constMyVecIt = constMyVecIte;
    // // constMyVecIte = temp;
    // std::vector<int>::iterator theirVecIte;

    // std::ofstream theirResult("theirResult.txt");
    // std::ofstream myResult("myResult.txt");
    // std::srand(time(NULL));
    // for (int i = 0; i < 1000; i++)
    // {
    //     const int val = std::rand();
    //     myVec.push_back(val);
    //     theirVec.push_back(val);
    // }
    // theirResult << theirVec.size() << std::endl;
    // myResult << myVec.size() << std::endl;
    // for (int i = 0; i < 1000; i++)
    // {
    //     if (i % 2)
    //     {
    //         myVec.erase(myVec.begin());
    //         theirVec.erase(theirVec.begin());
    //     }
    // }
    // theirResult << theirVec.size() << std::endl;
    // myResult << myVec.size() << std::endl;
    // for (int i = 0; i < 1000; i++)
    // {
    //     if (i % 2)
    //     {
    //         myVec.push_back(i);
    //         theirVec.push_back(i);
    //     }
    // }
    // theirResult << theirVec.size() << std::endl;
    // myResult << myVec.size() << std::endl;
    // myVec.erase(myVec.begin(), myVec.end());
    // theirVec.erase(theirVec.begin(), theirVec.end());
    // for (int i = 0; i < 1000; i++)
    // {
    //     const int val = std::rand();
    //     myVec.insert(myVec.begin(), val);
    //     theirVec.insert(theirVec.begin(), val);
    // }
    // theirResult << theirVec.size() << std::endl;
    // myResult << myVec.size() << std::endl;
    // for (int i = 0; i < 500; i++)
    // {
    //     const int val = std::rand();
    //     myVec.insert(myVec.begin() + i, val);
    //     theirVec.insert(theirVec.begin() + i, val);
    // }
    // theirResult << theirVec.size() << std::endl;
    // myResult << myVec.size() << std::endl;
    // for (int i = 0; i < 1000; i++)
    // {
    //     myResult << myVec[i] << "\n";
    //     theirResult << theirVec[i] << "\n";
    // }
    // theirResult << theirVec.size() << std::endl;
    // myResult << myVec.size() << std::endl;
    // bool res = system("diff theirResult.txt myResult.txt");
    // if (!res)
    //     std::cout << "OK\n";
    // else
    //     std::cout << "KO\n";
    // system("rm theirResult.txt myResult.txt");
    // return res;
}