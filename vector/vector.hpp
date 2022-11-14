/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:54:33 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/14 13:12:58 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(VECTOR_HPP)
#define VECTOR_HPP

#include "../reverse_iterator.hpp"
#include "../iterator.hpp"
#include <iostream>

template <class T, class Allocator = std::allocator<T> >
class vector
{
private:
    size_t len;
public:
    typedef typename Allocator::reference reference;
    typedef typename Allocator::const_reference const_reference;
    typedef int size_type;
    typedef ptrdiff_t difference_type;
    typedef T value_type;
    typedef Allocator allocator_type;
    typedef typename Allocator::pointer pointer;
    typedef ft::iterator<T> iterator;
    typedef typename Allocator::const_pointer const_pointer;
    typedef ft::reverse_iterator<iterator> reverse_iterator;
    vector()
    {
        len = 0;
    }
    vector &operator=(vector const &rhs);
    vector(vector const &obj);
    ~vector();
};

#endif // VECTOR_HPP
