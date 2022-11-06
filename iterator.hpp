/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <touateyoussef2003@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:08:00 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/06 19:17:49 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(MACRO)
#define MACRO

#include <iostream>
#include <iterator>
#include <set>
class iterator
{

public:
    typedef std::random_access_iterator_tag iterator_category;
    typedef ptrdiff_t difference_type;
    typedef int value_type;
    typedef int *pointer;
    typedef int &reference;
    iterator(pointer ptr) : m_ptr(ptr) {}
    reference operator*(void) { return *m_ptr; }
    pointer operator->(void) { return m_ptr; }
    iterator operator++(void)
    {
        m_ptr++;
        return *this;
    }
    iterator operator++(int)
    {
        iterator temp = *this;
        m_ptr++;
        return temp;
    }
    iterator operator--(void)
    {
        --m_ptr;
        return *this;
    }
    iterator operator--(int)
    {
        iterator temp = *this;
        m_ptr--;
        return temp;
    }
    friend bool operator==(iterator const &right, iterator const &left) { return right.m_ptr == left.m_ptr; }
    friend bool operator!=(iterator const &right, iterator const &left) { return right.m_ptr != left.m_ptr; }
    friend bool operator<(iterator const &right, iterator const &left) { return right.m_ptr < left.m_ptr; }
    friend bool operator>(iterator const &right, iterator const &left) { return right.m_ptr > left.m_ptr; }
    friend bool operator<=(iterator const &right, iterator const &left) { return right.m_ptr <= left.m_ptr; }
    friend bool operator>=(iterator const &right, iterator const &left) { return right.m_ptr >= left.m_ptr; }

    

    ~iterator() {}

private:
    pointer m_ptr;
};

// iterator::iterator()
// {
// }

// iterator::~iterator()
// {
// };

#endif // MACRO
