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
    template <class U>
    class map_iterator
    {

    public:
        typedef U &reference;
        typedef U *pointer;
        typedef U value_type;
        typedef std::ptrdiff_t difference_type;
        typedef std::bidirectional_iterator_tag iterator_category;

        map_iterator() : current(NULL), root(NULL) {}
        map_iterator(map_iterator const &obj)
        {
            this->current = obj.current;
            // this->root = obj.root;
        }

        map_iterator(pointer ptr)
        {
            // (void)_root;
            this->current = ptr;
            // this->root = _root;
        }
        map_iterator &operator=(map_iterator const &rhs)
        {
            this->current = rhs.current;
            // this->root = rhs.root;
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
        typename U::reference operator*(void) const { return *(*current); }
        typename U::pointer operator->(void) const
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
            if (this->current == NULL)
            {
                this->current = this->getRoot(this->current);
                if (this->current == NULL)
                {
                    throw std::out_of_range("UnderFlowException");
                }
                while (this->current->leftChild != NULL)
                {
                    this->current = this->current->leftChild;
                }
            }
            else
            {
                if (this->current->rightChild != NULL)
                {
                    this->current = this->current->rightChild;
                    while (this->current->leftChild != NULL)
                    {
                        this->current = this->current->leftChild;
                    }
                }
                else
                {
                    U *p = this->current->parent;
                    while (p != NULL and this->current == p->rightChild)
                    {
                        this->current = p;
                        p = p->parent;
                    }
                    this->current = p;
                }
            }
            return *this;
        }
        inline map_iterator &operator--(void)
        {
            if (this->current->leftChild)
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
        U *getRoot(U *_node) const
        {
            while (_node->parent)
            {
                _node = _node->parent;
            }
            return _node;
        }
        U *leftMostDescendant(U *node)
        {
            while (node->leftChild)
                node = node->leftChild;
            return node;
        }
        U *rightMostDescendant(U *node)
        {
            if (node == NULL)
                return NULL;
            while (node->rightChild)
                node = node->rightChild;
            return node;
        }
        U *current;
        U *root;
    };

}

#endif // map_iterator
