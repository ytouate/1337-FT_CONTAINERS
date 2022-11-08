/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <touateyoussef2003@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:08:00 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/08 17:46:09 by ytouate          ###   ########.fr       */
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
    typedef  T value_type;
    typedef  T *pointer;
    typedef  T &reference;
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
    friend bool operator==(iterator const &right, iterator const &left) { return right._ptr == left._ptr; }
    friend bool operator!=(iterator const &right, iterator const &left) { return right._ptr != left._ptr; }
    friend bool operator<(iterator const &right, iterator const &left) { return right._ptr < left._ptr; }
    friend bool operator>(iterator const &right, iterator const &left) { return right._ptr > left._ptr; }
    friend bool operator<=(iterator const &right, iterator const &left) { return right._ptr <= left._ptr; }
    friend bool operator>=(iterator const &right, iterator const &left) { return right._ptr >= left._ptr; }

    ~iterator() {}
private:
    T *_ptr;
};

#endif
