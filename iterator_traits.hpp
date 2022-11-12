/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:41:14 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/12 11:23:06 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(ITERATOR_TRAITS_HPP)
#define ITERATOR_TRAITS_HPP

namespace ft
{
    template <class T>
    struct iterator_traits
    {
        typedef typename T::value_type   value_type;
        typedef typename T::difference_type difference_type;
        typedef typename T::iterator_category iterator_category;
        typedef typename T::pointer pointer;
        typedef typename T::reference reference;
    };

    // template <class T>
    // struct iterator_traits
    // {
    //     typedef typename T::value_type   value_type;
    //     typedef typename T::difference_type difference_type;
    //     typedef typename T::iterator_category iterator_category;
    //     typedef typename T::pointer pointer;
    //     typedef typename T::reference reference;
    // };
};

#endif // ITERATOR_TRAITS_HPP