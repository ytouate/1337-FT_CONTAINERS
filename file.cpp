/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <touateyoussef2003@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/09 10:53:47 by ytouate          ###   ########.fr       */
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
    int operator * (void) { return 43; }
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

int main(int ac, char **av, char **envp)
{
    Integers ints;
    iterator<Integers > it = ints.begin();
    iterator<Integers > ite = ints.end();
    ++it;
    --it;
    std::cout << (*it).name << std::endl;
}