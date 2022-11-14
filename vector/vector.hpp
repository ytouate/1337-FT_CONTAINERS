/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:54:33 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/14 23:17:09 by ytouate          ###   ########.fr       */
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
        size_t capacity;
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
        reference operator [] (size_type n)  { return this->vec[n]; }
        const_reference operator [] (size_type n) const { return this->vec[n]; }
        const_reference at(size_type n) const
        {
            if (n >= this->len)
                throw std::out_of_range("Index out of Range");
            return this->vec[n];
        }
        reference at(size_type n)
        {
            if (n >= this->len)
                throw std::out_of_range("Index out of range");
            return this->vec[n];
        }
        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;
        size_type max_size() const { return this->_alloc.max_size(); }
        iterator begin() { return ft::iterator<T>(&vec[0]); }
        iterator end() { return ft::iterator<T>(&vec[len]); }
        reverse_iterator rbegin() { return ft::reverse_iterator <ft::iterator <T> > (&vec[len - 1]); }
        reverse_iterator rend() { return ft::reverse_iterator <ft::iterator <T> > (&vec[-1]); }
        vector(const Allocator &alloc = Allocator())
        {
            this->len = 0;
            this->vec = this->_alloc.allocate(this->len);
        }
        vector(size_type n, const T &value = T(), const Allocator &alloc = Allocator())
        {
            len = n;
            this->_alloc = alloc;
            this->vec = this->_alloc.allocate(n);
            for (int i = 0; i < n; i++)
                this->vec[i] = n;
        }
        
        allocator_type get_allocator() const { return this->_alloc; }
        size_type size() const { return this->len; }
        
        // unimplimented functions
        vector &operator=(vector const &rhs);
        vector(vector const &obj);
        ~vector()
        {
        }
    };
}

#endif // VECTOR_HPP
