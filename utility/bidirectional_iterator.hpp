/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:55:07 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/27 14:46:20 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(BIDIRECTIONA_ITERATOR_HPP)
#define BIDIRECTIONA_ITERATOR_HPP

#include "../inc.hpp"

namespace ft
{
    template <class U>
    class bidirectional_iterator
    {

    public:
        typedef U &reference;
        typedef U *pointer;
        typedef U value_type;
        typedef std::ptrdiff_t difference_type;
        typedef std::bidirectional_iterator_tag iterator_category;

        bidirectional_iterator() : current(NULL) {}
        bidirectional_iterator(bidirectional_iterator const &obj) : current(obj.current) {}
        bidirectional_iterator(pointer ptr) : current(ptr) {}
        bidirectional_iterator &operator=(bidirectional_iterator const &rhs)
        {
            this->current = rhs.current;
            return *this;
        }
        bool operator==(const bidirectional_iterator &a) { return this->current == a.current; };
        bool operator!=(const bidirectional_iterator &a) { return this->current != a.current; };
        typename U::reference operator*(void) const { return *(*current); }
        typename U::pointer operator->(void) const { return current->operator->(); }
        operator bidirectional_iterator() const { return bidirectional_iterator(this->current); }
        bidirectional_iterator operator--(int)
        {
            bidirectional_iterator temp = *this;
            --(*this);
            return temp;
        }
        inline bidirectional_iterator operator++(int)
        {
            bidirectional_iterator temp(*this);
            ++(*this);
            return temp;
        }
        inline bidirectional_iterator &operator++(void)
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
        inline bidirectional_iterator &operator--(void)
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
        ~bidirectional_iterator() {}

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
    };

}

#endif // bidirectional_iterator
