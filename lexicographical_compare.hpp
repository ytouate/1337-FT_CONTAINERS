/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:08:38 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/02 17:10:39 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(LEXICOGRAPHICAL_COMPARE)
#define LEXICOGRAPHICAL_COMPARE

#include "inc.hpp"

namespace ft
{
    template <class It, class It2>
    bool lexicographical_compare(It first1, It last1,
                                It2 first2, It2 last2)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }
}

#endif // LEXICOGRAPHICAL_COMPARE
