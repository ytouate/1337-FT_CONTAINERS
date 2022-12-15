/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:53:21 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/15 21:02:47 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(RED_BLACK_HPP)
#define RED_BLACK_HPP

#include "../inc.hpp"
#define RED 0
#define BLACK 1

namespace ft
{
    template <class T>
    struct t_node
    {
        bool color;
        t_node *leftChild;
        t_node *rightChild;
        t_node *parent;
        T data;
    };

    template <class T>
    class redBlackTree
    {
    public:
        t_node<T> *creteNode(bool _color, T &_data, t_node<T> *_parent)
        {
            t_node<T> _new = new t_node<T>;
            _new->color = _color;
            _new->data = _data;
            _new->leftChild = NULL;
            _new->rightChild = NULL;
            _new->parent = _parent;
            return _new;
        }
        
    private:
        t_node<T> *root;
    };
};

#endif // RED_BLACK_HPP
