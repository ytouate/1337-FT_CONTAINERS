/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:49:07 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/27 23:46:54 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(ENABLE_IF)
#define ENABLE_IF

#include <iostream>
#include <vector>
#include <set>

namespace ft
{
    template <bool Cond, class T = void>
    struct enable_if {};

    template <class T>
    struct enable_if<true, T> { typedef T type; };
};

#endif // ENABLE_IF
