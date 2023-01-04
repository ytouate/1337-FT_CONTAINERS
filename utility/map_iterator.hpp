/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:55:07 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/01 18:01:39 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(BIDIRECTIONA_ITERATOR_HPP)
#define BIDIRECTIONA_ITERATOR_HPP

#include "../inc.hpp"

class t_node;
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

        bool color;
        t_node<T, Allocator> *leftChild;
        t_node<T, Allocator> *rightChild;
        t_node<T, Allocator> *parent;
        T data;
    };
    template <class T, class Allocator = std::allocator<T> >
    class map_iterator
    {

    public:
        typedef t_node<T> *treeNode;
        typedef T &reference;
        typedef T *pointer;
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef std::bidirectional_iterator_tag iterator_category;

        map_iterator() : current(NULL), root(NULL) {}
        map_iterator(map_iterator const &obj)
        {
            this->current = obj.current;
            this->root = obj.root;
        }

        map_iterator(treeNode ptr, treeNode _root)
        {
            this->current = ptr;
            this->root = _root;
        }
        map_iterator &operator=(map_iterator const &rhs)
        {
            this->current = rhs.current;
            this->root = rhs.root;
            return *this;
        }
        bool operator==(const map_iterator &a)
        {
            return this->current == a.current;
        }
        bool operator!=(const map_iterator &a)
        {
            return this->current != a.current;
        }
        typename pair_type * operator*(void) const { return *(*current); }
        const pair_type * operator->(void) const
        {
            return current->operator->();
        }
        map_iterator operator--(int)
        {
            map_iterator temp = *this;
            --(*this);
            return temp;
        }
        inline map_iterator operator++(int)
        {
            map_iterator temp(*this);
            ++(*this);
            return temp;
        }
        inline map_iterator &operator++(void)
        {
            if (this->current->rightChild != NULL)
            {
                this->current = this->current->rightChild;
                this->current = leftMostDescendant(this->current);
            }
            else
            {
                treeNode p = this->current->parent;
                while (p != NULL and this->current == p->rightChild)
                {
                    this->current = p;
                    p = p->parent;
                }
                this->current = p;
            }
            return *this;
        }
        inline map_iterator &operator--(void)
        {
            if (this->current == NULL)
                this->current = rightMostDescendant(this->root);
            else if (this->current->leftChild)
            {
                this->current = rightMostDescendant(this->current->leftChild);
            }
            else
            {
                while (this->current && this->current->parent->leftChild == this->current)
                    this->current = this->current->parent;
                this->current = this->current->parent;
            }
            return *this;
        }
        ~map_iterator() {}

    private:
        treeNode leftMostDescendant(treeNode node)
        {
            if (node == NULL)
                return NULL;
            while (node->leftChild)
                node = node->leftChild;
            return node;
        }
        treeNode rightMostDescendant(treeNode node)
        {
            if (node == NULL)
                return NULL;
            while (node->rightChild)
                node = node->rightChild;
            return node;
        }
        treeNode current;
        treeNode root;
    };

}

#endif // map_iterator
