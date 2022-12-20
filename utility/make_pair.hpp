/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:08:41 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/20 16:15:59 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(MAKE_PAIR)
#define MAKE_PAIR

#include "../inc.hpp"

namespace ft
{
    template <class T1, class T2>
    ft::pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return ft::pair<T1, T2>(x, y);
    }
} // namespace ft

#endif // MAKE_PAIR
