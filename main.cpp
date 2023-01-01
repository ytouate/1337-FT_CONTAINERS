/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/01 15:44:42 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.hpp"

#define NAMESPACE ft
int main()
{
    typedef NAMESPACE::pair<int, std::string> pair;
    typedef NAMESPACE::map<int, std::string>::iterator iterator;
    typedef NAMESPACE::map<int, std::string> map;
    
    map m;
    m.insert(NAMESPACE::make_pair(34, "seiurhg8347wo83twerw"));
    m.insert(NAMESPACE::make_pair(2, "dsghesrzarherheat43"));
    m.insert(NAMESPACE::make_pair(9, "awgfawe4t3A4YSDFGAS"));
    m.insert(NAMESPACE::make_pair(3, "dzfg45yrthsdfgshju"));
    m.insert(NAMESPACE::make_pair(22, "j564wedfshgj6ee5yegrs"));
    m.insert(NAMESPACE::make_pair(10, "cfngcvcx56;oiliuee"));
    map::size_type c = m.count(9);
    std::cout << c << std::endl;
    m.erase(9);
    // c = m.count(9);
    for (iterator it = m.begin(); it != m.end(); ++it)
        std::cout << it->first << std::endl;
    // std::cout << c << std::endl;
}