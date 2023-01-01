/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/01 19:59:58 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.hpp"
#include <map>

#define NAMESPACE ft
int main()
{
    typedef NAMESPACE::pair<int, std::string> pair;
    typedef NAMESPACE::map<int, std::string>::iterator iterator;
    typedef NAMESPACE::map<int, std::string> map;
    typedef NAMESPACE::vector<pair> vector;

    vector v;
    for (vector::size_type i = 0; i < 25; ++i)
        v.push_back(NAMESPACE::make_pair(10 + i, "Hello"));
    map m(v.begin(), v.end());
    iterator _it = m.begin();
    m.erase(_it);
    _it = m.begin();
    std::advance(_it, 21);
    m.erase(_it);
    _it = m.end();
    std::advance(_it, -10);
    m.erase(_it);
    _it = m.end();
    std::advance(_it, -3);
    m.erase(_it);
    iterator it = m.begin();
    iterator ite = m.end();

    for (; it != ite; it = m.begin())
    {
        m.erase(it);
    }
}