/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:08:00 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/14 15:28:00 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(MACRO)
#define MACRO

#include <iostream>
#include <iterator>
#include <set>
#include "iterator_traits.hpp"

namespace ft
{
    template <class T>
    class iterator
    {
    public:
        typedef typename ft::iterator_traits<T *>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<T *>::difference_type difference_type;
        typedef typename ft::iterator_traits<T *>::value_type value_type;
        typedef typename ft::iterator_traits<T *>::pointer pointer;
        typedef typename ft::iterator_traits<T *>::reference reference;

        inline iterator () : _ptr (nullptr) {}
        inline iterator(pointer ptr) : _ptr(ptr) {}
        inline reference operator*(void) { return *_ptr; }
        inline pointer operator->(void) { return _ptr; }
        inline ptrdiff_t operator-(iterator const &right) { return this->_ptr - right._ptr; }
        inline ptrdiff_t operator+(iterator const &right) { return this->_ptr + right._ptr; }
        inline iterator operator-(const int n) { return this->_ptr - n; }
        inline iterator operator+(const int n) { return this->_ptr + n; }
        inline bool operator==(iterator const &right) { return this->_ptr == right._ptr; }
        inline bool operator!=(iterator const &right) { return this->_ptr != right._ptr; }
        inline bool operator<(iterator const &right) { return this->_ptr < right._ptr; }
        inline bool operator>(iterator const &right) { return this->_ptr > right._ptr; }
        inline bool operator<=(iterator const &right) { return this->_ptr <= right._ptr; }
        inline bool operator>=(iterator const &right) { return this->_ptr >= right._ptr; }
        inline reference operator[](const int n) { return _ptr[n]; }
        inline iterator(iterator const &obj) { this->_ptr = obj._ptr; }

        inline iterator operator+=(difference_type n)
        {
            this->_ptr += n;
            return this->_ptr;
        }
        inline iterator operator-=(difference_type n)
        {
            this->_ptr -= n;
            return this;
        }
        inline iterator operator--(void)
        {
            iterator temp = *this;
            this->_ptr--;
            return temp;
        }
        inline iterator operator++(void)
        {
            iterator temp = *this;
            this->_ptr++;
            return temp;
        }
        inline iterator operator++(int notUsed)
        {
            (void)notUsed;
            this->_ptr++;
            return *this;
        }
        inline iterator operator--(int notUsed)
        {
            (void)notUsed;
            this->_ptr--;
            return *this;
        }
        inline iterator &operator=(iterator const &rhs)
        {
            this->_ptr = rhs._ptr;
            return *this;
        }
        ~iterator() {}

    private:
        T *_ptr;
    };

}

#endif
