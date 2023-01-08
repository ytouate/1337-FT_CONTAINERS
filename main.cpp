/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/08 13:45:01 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.hpp"

#include <map>
#include <set>


int		main(void)
{
	ft::set<int> set;
	srand(time(0));
	for (int i = 0; i < 100; i++)
	{
		set.insert(rand());
	}
	set.insert(10);
	std::cout << set.size() << std::endl;
	ft::set<int>::iterator it = set.begin();
	ft::set<int>::iterator ite(it);
	ft::set<int>::const_iterator cit = set.begin();
	it = set.begin();
	ite = it;
	std::advance(it, 34);
	std::advance(ite, 55);
	set.erase(it, ite);
}
