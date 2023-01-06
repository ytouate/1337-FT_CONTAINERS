/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/06 19:58:19 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.hpp"

#include <map>
#include <set>


int		main(void)
{
	ft::set<int> set;
	set.insert(set.begin(), 10);
	set.insert(20);
	ft::set<int> b(set);
	b.insert(set.begin(), set.end());
	std::cout << set.count(10) << std::endl;
}
