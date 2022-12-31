/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/31 23:02:28 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.hpp"

#define TESTED_NAMESPACE ft
int main()
{
    typedef TESTED_NAMESPACE::pair<int, int> pair;
    typedef TESTED_NAMESPACE::map<int, int>::iterator iterator;
    typedef TESTED_NAMESPACE::map<int, int> map;
    
    map m;
    m.insert(ft::make_pair<int, int>(10, 20));
    m.erase(m.begin());
    iterator it = m.begin();
    iterator ite = m.end();
    while (it != ite)
        std::cout << "K: " << it->first << " V: " << it++->second << std::endl;
}