/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:40:36 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/05 19:45:10 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(SET_HPP)
#define SET_HPP

#include "../inc.hpp"

namespace ft
{
    template <class Key,
              class Compare = std::less<Key>,
              class Allocator = std::allocator<Key> >
    class set
    {
        public:
            typedef Key key_type;
            typedef Key value_type;
            typedef Compare key_compare;
            typedef Compare value_compare;
            typedef Allocator allocator_type;
            typedef typename Allocator::reference reference;
            typedef typename Allocator::pointer pointer;
            typedef typename Allocator::const_pointer const_pointer;
            typedef typename Allocator::const_reference const_reference;
            
    };
}

#endif // SET_HPP
