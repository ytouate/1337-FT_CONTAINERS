/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <touateyoussef2003@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/08 17:47:01 by ytouate          ###   ########.fr       */
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
# include "iterator.hpp"


class Integers
{
private:
    std::vector <int> vec;
public:
    iterator<int>  begin() { return iterator <int> (&vec[0]); }
    iterator<int>  end() { return iterator <int> (&vec[vec.size()]); }
    Integers()
    {
        std::srand(time(NULL));
        for (int i = 0; i < 200; i++)
        {
            vec.push_back(i);
        }
    }
    ~Integers() { vec.clear(); }

};

int main(int ac, char **av, char **envp)
{
    Integers ints;
    iterator<int > it = ints.begin();
    iterator<int > ite = ints.end();
    *++it;

    if (it == ite)
        
    std::cout << *it <<std::endl;
}