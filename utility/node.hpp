/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:16:21 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/06 14:41:32 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(NODE_HPP)
#define NODE_HPP

// #include "../inc.hpp"

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    struct t_node
    {
        typedef T value_type;
        typedef T &reference;
        typedef const T &const_reference;
        typedef T *pointer;

        reference operator*()
        {
            return *data;
        }
        const_reference operator*() const
        {
            return *data;
        }
        pointer operator->()
        {
            return data;
        }
        const pointer operator->() const
        {
            return data;
        }
        bool color;
        Allocator _alloc;
        t_node<T, Allocator> *leftChild;
        t_node<T, Allocator> *rightChild;
        t_node<T, Allocator> *parent;
        T *data;
    };
}

#endif // NODE_HPP
