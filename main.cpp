/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/28 21:43:07 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.hpp"

#include "containers_test/srcs/base.hpp"
#define TESTED_TYPE int
// #define TESTED_NAMESPACE std
int main(void)
{
	const int size = 5;
	ft::vector<TESTED_TYPE> vct(size);
	ft::vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
	ft::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();	
	ft::vector<std::string>::iterator _it;

	_it.base();
	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;

	it = it + 5;
	it = 1 + it;
	it = it - 4;
	std::cout << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	// printSize(vct, true);
	return (0);
}
