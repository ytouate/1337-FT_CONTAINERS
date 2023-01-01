/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/01 13:49:30 by ytouate          ###   ########.fr       */
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
    // m.erase(m.begin());
    iterator it = m.begin();
    iterator ite = m.end();
    // std::cout << ite->first << std::endl;
    while (it != ite)
        std::cout << "K: " << it->first << " V: " << it++->second << std::endl;
}