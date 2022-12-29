/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:08:00 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/29 10:25:41 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(ITERATOR_HPP)
#define ITERATOR_HPP

#include "../inc.hpp"
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
        typedef ft::iterator<const T> const_iterator;
        typedef T const &const_reference;
        operator ft::iterator< const T> () const
        {
            ft::iterator<const T> constThis (this->_ptr);
            return constThis;
        }
        const_reference operator*(void) const { return *_ptr; }
        const_reference operator[](difference_type n) const { return _ptr[n]; }
        iterator() : _ptr(NULL) {}
        iterator(pointer ptr) : _ptr(ptr) {}
        reference const operator*(void) { return *_ptr; }
        pointer operator->(void) const { return _ptr; }
        friend bool operator<= (const iterator& a, const iterator& b) { return a._ptr <= b._ptr; };
        friend bool operator< (const iterator& a, const iterator& b) { return a._ptr < b._ptr; };  
        friend bool operator>= (const iterator& a, const iterator& b) { return a._ptr >= b._ptr; };
        friend bool operator> (const iterator& a, const iterator& b) { return a._ptr > b._ptr; };     
        difference_type operator-(iterator const &right)  { return this->_ptr - right._ptr; }
        reference operator[](difference_type n) { return _ptr[n]; }
        iterator(iterator const &obj) { this->_ptr = obj._ptr; }
        iterator operator-(difference_type n)
        {
            pointer oldPtr = _ptr;
            _ptr -= n;
            iterator temp(*this);
            _ptr = oldPtr;
            return temp;
        }
        
        iterator operator+(difference_type n)
        {
            pointer oldPtr = _ptr;
            _ptr += n;
            iterator temp(*this);
            _ptr = oldPtr;
            return temp;
        }

        iterator operator+=(difference_type n)
        {
            this->_ptr += n;
            return *this;
        }
        iterator operator-=(difference_type n)
        {
            this->_ptr -= n;
            return *this;
        }
        
        iterator operator--(int)
        {
            iterator temp = *this;
            this->_ptr--;
            return temp;
        }
        iterator operator++(int)
        {
            iterator temp = *this;
            this->_ptr++;
            return temp;
        }
        iterator & operator++(void)
        {
            this->_ptr++;
            return *this;
        }
        iterator & operator--(void)
        {
            this->_ptr--;
            return *this;
        }
        T* base() const
        {
            return _ptr;
        }
        iterator &operator=(iterator const &rhs) 
        {
            this->_ptr = rhs._ptr;
            return *this;
        }
        ~iterator() {}
        friend iterator operator+(difference_type n, iterator &x)
        {
            pointer oldPtr = x._ptr;
            x._ptr += n;
            iterator temp(x);
            x._ptr = oldPtr;
            return temp;
        }
        template <class Iter, class Iter2>
        friend bool operator != (const Iter &a, const Iter2 &b)
        {
            return a._ptr != b._ptr;
        }
        template <class Iter, class Iter2>
        friend bool operator == (const Iter &a, const Iter2 &b)
        {
            return a._ptr == b._ptr;
        }
    private:
        T *_ptr;
    };
}

#endif
