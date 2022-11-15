/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:54:33 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/15 11:29:07 by ytouate          ###   ########.fr       */
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
        size_t _capacity;
        T *vec;

    public:
        // types
        typedef typename Allocator::reference reference;
        typedef typename Allocator::const_reference const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef Allocator allocator_type;
        typedef typename Allocator::pointer pointer;
        typedef ft::iterator<T> iterator;
        typedef const iterator const_iterator;
        typedef typename Allocator::const_pointer const_pointer;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef const reverse_iterator const_reverse_iterator;

        // element access
        reference operator[](size_type n) { return this->vec[n]; }
        reference front() { return this->vec[0]; }
        const_reference front() const { return this->vec[0]; }
        reference back() { return this->vec[this->len - 1]; }
        const_reference back() const { return this->vec[this->len - 1]; }
        const_reference operator[](size_type n) const { return this->vec[n]; }
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

        // iterators
        const_iterator begin() const { return ft::iterator<T>(&this->vec[0]); }
        const_iterator end() const { return ft::iterator<T>(&this->vec[this->len]); }
        iterator begin() { return ft::iterator<T>(&vec[0]); }
        iterator end() { return ft::iterator<T>(&vec[this->len]); }
        const_reverse_iterator rbegin() const { return ft::reverse_iterator<ft::iterator<T> >(&this->vec[this->len - 1]); }
        reverse_iterator rbegin() { return ft::reverse_iterator<ft::iterator<T> >(&vec[this->len - 1]); }
        reverse_iterator rend() { return ft::reverse_iterator<ft::iterator<T> >(&vec[-1]); }
        const_reverse_iterator rend() const { return ft::reverse_iterator<ft::iterator<T> >(&this->vec[-1]); }

        // capacity
        size_type max_size() const { return this->_alloc.max_size(); }
        size_type size() const { return this->len; }
        size_type capacity() const { return this->_capacity; }
        bool empty() const { return this->len == 0; }
        void reserve(size_type n);
        void resize(size_type sz, T c = T());

        // construction / destruction / assignment / copy construction
        explicit vector(const Allocator &alloc = Allocator())
        {
            this->len = 0;
            this->vec = this->_alloc.allocate(this->len);
        }
        explicit vector(size_type n, const T &value = T(), const Allocator &alloc = Allocator())
        {
            len = n;
            this->_alloc = alloc;
            this->vec = this->_alloc.allocate(n);
            for (int i = 0; i < n; i++)
                this->vec[i] = n;
        }
        allocator_type get_allocator() const { return this->_alloc; }
        vector &operator=(const vector<T, Allocator> &rhs);
        vector(vector const &obj);
        ~vector() {}
    };
}

#endif // VECTOR_HPP
