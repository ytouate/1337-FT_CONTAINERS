/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:55:07 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/27 12:51:55 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(BIDIRECTIONA_ITERATOR_HPP)
#define BIDIRECTIONA_ITERATOR_HPP

#include "../inc.hpp"

// namespace ft
// {
//     template <class T>
//     struct t_node
//     {
//         bool color;
//         t_node *leftChild;
//         t_node *rightChild;
//         t_node *parent;
//         T data;
//     };
// };

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

        inline bidirectional_iterator() : current(NULL) {}
        inline bidirectional_iterator(bidirectional_iterator const &obj)
        {
            this->current = obj.current;
        }
        inline bidirectional_iterator(pointer ptr) : current(ptr)
        {
        }
        inline bidirectional_iterator &operator=(bidirectional_iterator const &rhs)
        {
            this->current = rhs.current;
            return *this;
        }
        bool operator==(const bidirectional_iterator &a) { return this->current == a.current; };
        bool operator!=(const bidirectional_iterator &a) { return this->current != a.current; };
        typename U::reference operator*(void) const
        {
            return *(*current);
        }
        typename U::pointer operator->(void) const { return current->operator->(); }
        // operator bidirectional_iterator() const
        // {
        //     bidirectional_iterator constThis(this->current);
        //     return constThis;
        // }

        inline bidirectional_iterator operator--(int)
        {
            bidirectional_iterator temp = *this;
            --(*this);
            return temp;
        }

        U *getRoot(U *_node) const
        {
            while (_node->parent)
            {
                _node = _node->parent;
            }
            return _node;
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
                    throw("Under Flow Exception");
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
            if (this->current == NULL)
                std::cout << "NULL\n";
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
        bidirectional_iterator next()
        {
            if (this->current->rightChild)
            {
                return leftMostDescendant(this->current->rightChild);
            }
            else
            {
                while (this->current->parent != NULL &&
                       this->current->parent->rightChild == this->current)
                {
                    this->current = this->current->parent;
                }
                return this->current->parent;
            }
        }
        U *previous()
        {
            if (this->current->leftChild)
                return rightMostDescendant(this->current->leftChild);
            else
            {
                while (this->current && this->current->parent->leftChild == this->current)
                    this->current = this->current->parent;
                return this->current->parent;
            }
        }
        bool hasNext() const
        {
            return this->current != NULL;
        }

    private:
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
