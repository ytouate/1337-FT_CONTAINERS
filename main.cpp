/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/03 16:38:10 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.hpp"

int main(void)
{
    /*
     * Strings to store the results
     */
    std::string s1, s2, s3, ft_s1, ft_s2, ft_s3;
    std::string sit1, ft_sit1; // strings to store the result by iterators
    /*
     * Var to store the size and the capacity
     */
    size_t z1, z2, z3, ft_z1, ft_z2, ft_z3;
    size_t c1, c2, c3, ft_c1, ft_c2, ft_c3;
    /*
     * iterators to check the iterator validity
     *  it : iterator, eit : iterator to the end
     */
    std::vector<std::string>::iterator valid_it, valid_eit;
    ft::vector<std::string>::iterator ft_valid_it, ft_valid_eit;
    // bool to check if the function throw or not
    bool exec_throwed = false;
    /*------------------ std::vectors ---------------------*/
    std::vector<std::string> v1(10, "string2");
    std::vector<char> v2;
    /*------------------ std::vectors ---------------------*/
    ft::vector<std::string> ft_v1(10, "string2");
    ft::vector<char> ft_v2;
    try
    {
        ft_v1.reserve(ft_v1.max_size() + 1);
    }
    catch (std::length_error const &e)
    {
        (void)e;
        exec_throwed = true;
    }
    v1.reserve(100);
    ft_v1.reserve(100);

    z1 = v1.size();
    ft_z1 = ft_v1.size();
    c1 = v1.capacity();
    ft_c1 = ft_v1.capacity();

    for (size_t i = 0; i < v1.size(); ++i)
        s1 += v1[i];

    ft_valid_it = ft_v1.begin();
    for (; ft_valid_it != ft_v1.end(); ++ft_valid_it)
        ft_s1 += *ft_valid_it;

    valid_it = v1.begin();
    valid_eit = v1.end();
    ft_valid_it = ft_v1.begin();
    ft_valid_eit = ft_v1.end();
    v1.reserve(50);
    ft_v1.reserve(50);

    z2 = v1.size();
    ft_z2 = ft_v1.size();
    c2 = v1.capacity();
    ft_c2 = ft_v1.capacity();

    for (size_t i = 0; i < v1.size(); ++i)
        s2 += v1[i];

    for (; valid_it != valid_eit; ++valid_it)
        sit1 += *valid_it;

    for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
        ft_s2 += *it;

    for (; ft_valid_it != ft_valid_eit; ++ft_valid_it)
        ft_sit1 += *ft_valid_it;

    v2.reserve(200);
    ft_v2.reserve(200);
    z3 = v2.size();
    ft_z3 = ft_v2.size();
    c3 = v2.capacity();
    ft_c3 = ft_v2.capacity();

    for (size_t i = 0; i < v2.size(); ++i)
        s3 += v2[i];

    for (ft::vector<char>::iterator it = ft_v2.begin(); it != ft_v2.end(); ++it)
        ft_s3 += *it;
}