/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/29 19:59:15 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.hpp"
#include <unistd.h>
#include <sys/time.h>
#include "containers_test/srcs/base.hpp"
#define TESTED_TYPE int


int main(void)
{
    typedef ft::vector<std::string>::iterator iterator;
    
    ft::vector<std::string> vec;
    // vec.push_back(25);
    // vec.push_back(15);
    // vec.push_back(20);
    vec.insert(vec.begin(), 2, "1tW0KWfXxeFO69tByqcE"); 
    vec.insert(vec.begin(), 2, "OaxJUSm3nYN9Y8Ela7sS");
    std::cout << vec.capacity() << " " << vec.size() << std::endl;
    // vec.insert(vec.begin(), 2, "Mq4RRaeLvSAO0z2ibp8Q");
    // vec.insert(vec.begin() + 1, 20);
    iterator it = vec.begin();
    iterator ite = vec.end();
    // std::cout << *ret << std::endl;
    while (it != ite)
        std::cout << *it++ << std::endl;
    return (0);
}