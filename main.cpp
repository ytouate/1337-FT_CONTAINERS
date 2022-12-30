/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/30 15:57:06 by ytouate          ###   ########.fr       */
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

    ft::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    vec.push_back(60);
    vec.push_back(70);
    vec.push_back(80);
    vec.push_back(90);
    vec.erase(vec.begin(), vec.begin() + 10);
    iterator it = vec.begin();
    for (; it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    return (0);
}