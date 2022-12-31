/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/30 21:51:52 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.hpp"
#include <unistd.h>
#include <sys/time.h>
#include "containers_test/srcs/base.hpp"
#define TESTED_TYPE int

int main(void)
{
    typedef ft::vector<int>::iterator iterator;
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i+1);
    }
    ft::vector<int> vec;
    // vec.insert(vec.begin(), v.begin(), v.end());
    vec.insert(vec.end(), 10, 99);
    iterator it = vec.begin();
    for (; it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    return (0);
}