/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/03 16:53:20 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.hpp"
#include <map>
// #include "ft_containers-terminator/tests/tests/map/map_prelude.hpp"
#define NAMESPACE ft
int main()
{
    typedef NAMESPACE::pair<int, std::string> pair;
    typedef NAMESPACE::map<int, std::string>::iterator iterator;
    typedef NAMESPACE::map<int, std::string>::const_iterator const_iterator;
    typedef NAMESPACE::map<int, std::string> map;
    typedef NAMESPACE::vector<pair> vector;

    vector v;
    for (vector::size_type i = 0; i < 25; ++i)
        v.push_back(NAMESPACE::make_pair(10 + i, "Hello"));
    map m(v.begin(), v.end());
    iterator it = m.begin();
    m.insert(ft::make_pair(-78, "hello"));
    std::cout << m.begin()->first << std::endl;

    // while (!m.empty())
    // {
    //     m.erase(it);
    //     it = m.begin();
    // }
}