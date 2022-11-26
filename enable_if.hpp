/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:49:07 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/26 12:50:34 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(ENABLE_IF)
#define ENABLE_IF

namespace ft
{
    template <bool Cond, class T = void>
    struct enable_if
    {
        
    };
};

#endif // ENABLE_IF
