/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:55:07 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/26 14:18:40 by ytouate          ###   ########.fr       */
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
        // modified
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef typename ft::iterator_traits<U *>::difference_type difference_type;
        typedef typename ft::iterator_traits<U *>::value_type value_type;
        typedef U *pointer;
        // typedef typename ft::iterator_traits<U *>::pointer pointer;
        typedef typename ft::iterator_traits<U *>::reference reference;
        typedef U const &const_reference;
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
        typename value_type::value_type operator*(void)
        {
            return current->data;
        }
        inline value_type *operator->(void) const { return current; }
        operator bidirectional_iterator() const
        {
            bidirectional_iterator constThis(this->current);
            return constThis;
        }

        inline bidirectional_iterator operator--(int)
        {
            bidirectional_iterator temp = *this;
            this->current--;
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
            std::cout << current->data << " \n";
            if (this->current == NULL)
            {
                this->current = getRoot(this->current);
                if (this->current == NULL)
                    throw std::out_of_range("Over Flow exception");
                while (this->current->rightChild != NULL)
                    this->current = this->current->rightChild;
            }
            else
            {
                if (this->current->leftChild != NULL)
                {
                    this->current = this->current->leftChild;
                    while (this->current->rightChild != NULL)
                        this->current = this->current->rightChild;
                }
                else
                {
                    if (this->current == getRoot(this->current))
                        puts("hna");
                    U *p = this->current->parent;
                    while (p != NULL && this->current == p->leftChild)
                    {
                        this->current = p;
                        p = p->parent;
                    }
                    this->current = p;
                }
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
                return  this->current->parent;
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
            while (node->rightChild)
                node = node->rightChild;
            return node;
        }
        U *current;
    };

}

#endif // bidirectional_iterator
