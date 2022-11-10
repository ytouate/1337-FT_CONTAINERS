/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/10 12:48:38 by ytouate          ###   ########.fr       */
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
    std::string name;
    iterator<Integers >  begin() { return iterator <Integers >( this ); }
    iterator<Integers >  end() { return iterator <Integers > (this + 1); }
    void f () { std::cout << "hello world\n"; }
    Integers()
    {
        this->name = "Youssef";
        std::srand(time(NULL));
        for (int i = 0; i < 200; i++)
        {
            vec.push_back(i);
        }
    }
    ~Integers() { vec.clear(); }
    friend std::ostream & operator << (std::ostream &os, Integers const &obj)
    {
        os << obj.name;
        return os;
    }
};

int main( void )
{
    Integers ints;
    iterator<Integers> it = ints.begin();
    iterator<Integers> ite = ints.end();
    (void)ints, (void)it, (void)ite;
    (*it).name = "Something else";
    it->name = "Hello world";
    

    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);

    // std::random_access_iterator_tag something;
    
    // std::vector<int>::iterator it2 = vec.begin();
    // std::vector<int>::iterator ite2 = vec.end();
    std::vector<int>::iterator rit = vec.begin();
    std::vector<int>::iterator rite = vec.end();

    while (rit < rite)
    {
        std::cout << *rit << std::endl;
        rit++;
    }
    return (0);
}