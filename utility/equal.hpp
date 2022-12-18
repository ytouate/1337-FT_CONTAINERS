/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:59:49 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/14 14:01:51 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(EQUAL_HPP)
#define EQUAL_HPP

#include "../inc.hpp"
template <class InputIterator1, class InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
    while (first1 != last1)
    {
        if (!(*first1 == *first2))
            return false;
        ++first1;
        ++first2;
    }
    return true;
}

#endif // EQUAL_HPP