/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/05 12:44:28 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.hpp"

#include <map>
#include <set>
// #include "ft_containers-terminator/tests/tests/map/map_prelude.hpp"
#define NAMESPACE ft
int main()
{
    ft::map<int, int> map;
    map.insert(ft::make_pair(10, 20));
    ft::map<int, int>::const_iterator it = map.begin();

    it->second = 30;

}