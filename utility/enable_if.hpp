/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:49:07 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/02 19:52:17 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(ENABLE_IF)
#define ENABLE_IF

#include "../inc.hpp"

namespace ft
{
    template <bool Cond, class T = void>
    struct enable_if {};

    template <class T>
    struct enable_if<true, T> { typedef T type; };
};

#endif // ENABLE_IF
