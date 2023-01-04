/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:16:21 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/04 15:10:37 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(NODE_HPP)
#define NODE_HPP

#include "../inc.hpp"

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
            return data;
        }
        pointer operator->()
        {
            return &data;
        }
        const pointer operator->() const
        {
            return &data;
        }
        t_node(): color(0), leftChild(NULL), rightChild(NULL), parent(NULL)
        {
        }
        t_node(t_node<T, Allocator> *x)
        {
            this->leftChild = x->leftChild;
            this->rightChild = x->rightChild;
            this->parent = x->parent;
            this->color = x->color;
        }
        void setData(T _data)
        {
            data = _data;
        }
        t_node(t_node &x) : data(x.data), color(x.color),
                            leftChild(x.leftChild),
                            rightChild(x.rightChild),
                            parent(x.parent)
        {
        }

        bool color;
        t_node<T, Allocator> *leftChild;
        t_node<T, Allocator> *rightChild;
        t_node<T, Allocator> *parent;
        T data;
    };
}

#endif // NODE_HPP
