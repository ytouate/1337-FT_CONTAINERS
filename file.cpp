/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <touateyoussef2003@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/06 19:17:36 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <vector>
# include <iostream>
# include <set>
# include <forward_list>
# include <map>
# include <list>
# include <deque>
# include <stack>
# include <array>
# include <memory.h>


void fun(std::forward_list<std::string> &list, std::string s1, std::string s2)
{
    std::forward_list<std::string>::iterator it = list.begin();
    std::forward_list<std::string>::iterator ite = list.end();
    std::forward_list<std::string>::iterator itprev = list.before_begin();

    while (it != ite)
    {
        if (*it == s1)
        {
            it = list.insert_after(it, s2);
        }
        else
        {
            itprev = it;
            it++;
        }
    }
    
}
#include "iterator.hpp"
#include <set>
class Integers
{
private:
    int m_data[200];
public:
    iterator  begin() { return iterator( &m_data[0]); }
    iterator  end() { return iterator( &m_data[200]); }
    Integers()
    {
        std::srand(time(NULL));
        for (int i = 0; i < 200; i++)
            m_data[i] = i + 1;
    }
    ~Integers() {}

};
int main(int ac, char **av, char **envp)
{
    Integers ints;
    iterator it = ints.begin();
    iterator ite = ints.end();
    std::vector<int> vec;
    std::vector<int>::iterator it1;

    vec.push_back(10);
    vec.push_back(100);
    vec.push_back(1);
    it1 = vec.begin();
    
    std::cout << ++*it <<std::endl;
    
}