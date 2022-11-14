/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:54:33 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/14 14:37:57 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(VECTOR_HPP)
#define VECTOR_HPP

#include "../reverse_iterator.hpp"
#include "../iterator.hpp"
#include <iostream>

namespace ft
{    
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
    private:
        size_t len;
        Allocator _alloc;
        T *vec;
    public:
        typedef typename Allocator::reference reference;
        typedef typename Allocator::const_reference const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef Allocator allocator_type;
        typedef typename Allocator::pointer pointer;
        typedef ft::iterator<T> iterator;
        typedef typename Allocator::const_pointer const_pointer;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        

        iterator begin()
        {
            return ft::iterator<T> (&vec[0]);
        }
        iterator end()
        {
            return ft::iterator<T> (&vec[len]);
        }
        vector(const Allocator &alloc = Allocator())
        {
            len = 0;
            // alloc.allocate(len);
        }
        vector(size_type n, const T& value = T(), const Allocator &alloc = Allocator())
        {
            len = n;
            this->_alloc = alloc;
            this->vec = this->_alloc.allocate(n);
            for (int i = 0; i < n; i++)
                this->vec[i] = n;
        }
        vector &operator=(vector const &rhs);
        vector(vector const &obj);
        ~vector()
        {
        }
    };
}

#endif // VECTOR_HPP
