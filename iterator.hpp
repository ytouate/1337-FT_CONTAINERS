/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:08:00 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/10 12:47:47 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(MACRO)
#define MACRO

#include <iostream>
#include <iterator>
#include <set>

template <class T>
class iterator
{
public:
    typedef std::random_access_iterator_tag iterator_category;
    typedef ptrdiff_t difference_type;
    typedef T value_type;
    typedef T *pointer;
    typedef T &reference;
    iterator(pointer ptr) : _ptr(ptr) {}
    reference operator*(void) { return *_ptr; }
    pointer operator->(void) { return _ptr; }
    iterator operator+=(difference_type n)
    {
        this->_ptr += n;
        return this->_ptr;
    }
    iterator operator-=(difference_type n)
    {
        this->_ptr -= n;
        return this;
    }
    iterator operator--(void)
    {
        iterator temp = *this;
        this->_ptr--;
        return temp;
    }
    iterator operator++(void)
    {
        iterator temp = *this;
        this->_ptr++;
        return temp;
    }
    iterator operator++(int notUsed)
    {
        (void)notUsed;
        this->_ptr++;
        return *this;
    }
    iterator operator--(int notUsed)
    {
        (void)notUsed;
        this->_ptr--;
        return *this;
    }
    ptrdiff_t operator - (iterator const &right) {return this->_ptr - right._ptr; }
    ptrdiff_t operator + (iterator const &right) {return this->_ptr + right._ptr; }
    iterator operator - (const int n) {return this->_ptr - n; }
    iterator operator + (const int n) {return this->_ptr + n; }
    bool operator==(iterator const &right) { return this->_ptr == right._ptr; }
    bool operator!=(iterator const &right) { return this->_ptr != right._ptr; }
    bool operator<(iterator const &right) { return this->_ptr < right._ptr; }
    bool operator>(iterator const &right) { return this->_ptr > right._ptr; }
    bool operator<=(iterator const &right) { return this->_ptr <= right._ptr; }
    bool operator>=(iterator const &right) { return this->_ptr >= right._ptr; }
    reference operator[](const int n) { return _ptr[n]; }
    iterator &operator=(iterator const &rhs)
    {
        rhs._ptr = this->_ptr;
        return *this;
    }
    iterator(iterator const &obj) { this->_ptr = obj._ptr; }
    ~iterator() {}

private:
    T *_ptr;
};

#endif
