/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:08:00 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/21 11:55:22 by ytouate          ###   ########.fr       */
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
        typedef T const &const_reference;
        operator ft::iterator< const T> () const
        {
            ft::iterator<const T> constThis (this->_ptr);
            return constThis;
        }
        inline const_reference operator*(void) const { return *_ptr; }
        inline const_reference operator[](const int n) const { return _ptr[n]; }
        inline iterator() : _ptr(NULL) {}
        inline iterator(pointer ptr) : _ptr(ptr) {}
        inline reference const operator*(void) { return *_ptr; }
        inline pointer operator->(void) const { return _ptr; }
        inline ptrdiff_t operator-(iterator const &right) const { return this->_ptr - right._ptr; }
        inline bool operator==(iterator const &right) const { return this->_ptr == right._ptr; }
        inline bool operator!=(iterator const &right) const { return this->_ptr != right._ptr; }
        inline bool operator<(iterator const &right) const { return this->_ptr < right._ptr; }
        inline bool operator>(iterator const &right) const { return this->_ptr > right._ptr; }
        inline bool operator<=(iterator const &right) const { return this->_ptr <= right._ptr; }
        inline bool operator>=(iterator const &right) const { return this->_ptr >= right._ptr; }
        inline reference operator[](const int n) { return _ptr[n]; }
        inline iterator(iterator const &obj) { this->_ptr = obj._ptr; }
        inline iterator operator-(difference_type n)
        {
            this->_ptr = this->_ptr - n;
            return *this;
        }
        inline iterator operator+(difference_type n)
        {
            this->_ptr = this->_ptr + n;
            return *this;
        }
        inline iterator operator+=(difference_type n)
        {
            this->_ptr += n;
            return *this;
        }
        inline iterator operator-=(difference_type n)
        {
            this->_ptr -= n;
            return *this;
        }
        inline iterator operator--(int)
        {
            iterator temp = *this;
            this->_ptr--;
            return temp;
        }
        inline iterator operator++(int)
        {
            iterator temp = *this;
            this->_ptr++;
            return temp;
        }

        inline iterator & operator++(void)
        {
            this->_ptr++;
            return *this;
        }
        inline iterator & operator--(void)
        {
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
// template <class _Iter>
// inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_IF_NODEBUG
// __wrap_iter<_Iter>
// operator+(typename __wrap_iter<_Iter>::difference_type __n,
//           __wrap_iter<_Iter> __x) _NOEXCEPT_DEBUG
// {
//     __x += __n;
//     return __x;
// }

template <class T>
ft::iterator<T> operator+(typename ft::iterator<T>::difference_type n, ft::iterator<T> &x)
{
    x += n;
    return x;
}

#endif
