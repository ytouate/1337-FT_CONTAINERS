/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/12 19:33:33 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.hpp"

#include <map>
#include <set>


int		main(void)
{
	ft::map<int, int, std::greater<int> > a;
	
	a.insert(ft::make_pair(10, 20));
	a.insert(ft::make_pair(20, 20));
	a.insert(ft::make_pair(30, 20));
	a.insert(ft::make_pair(50, 20));
	a.insert(ft::make_pair(90, 20));
	
	std::cout << a.lower_bound(78)->first << std::endl;
	std::cout << a.lower_bound(48)->first << std::endl;
	std::cout << a.lower_bound(19)->first << std::endl;
	std::cout << a.lower_bound(58)->first << std::endl;
	std::cout << a.lower_bound(88)->first << std::endl;
}
