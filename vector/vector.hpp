/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:54:33 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/18 13:10:22 by ytouate          ###   ########.fr       */
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
        void reserve(size_type n)
        {
            if (n <= this->_capacity)
                return;
            this->_capacity = n;
            T *tmp = this->vec;
            this->vec = this->_alloc.allocate(n);
            for (size_type i = 0; i < this->len; i++)
                this->vec[i] = tmp[i];
            delete tmp;
        }

        size_type getNewCapacity(size_type n)
        {
            size_type newCapacity = 0;
            if (this->empty())
                newCapacity += n;
            else if (this->_capacity < this->len + n)
            {
                newCapacity = this->_capacity * 2;
                if (newCapacity < this->len + n)
                    newCapacity = this->_capacity + n;
            }
            return newCapacity;
        }

        void addFront(iterator position, size_type n, const T &x)
        {
            size_type sz = 0;
            size_type newSize = this->len + n;
            size_type newCapacity = getNewCapacity(n);
            iterator it = this->begin();
            T tmp[newSize];
            while (n--)
                tmp[sz++] = x;
            while (it != this->end())
            {
                tmp[sz++] = *it;
                it++;
            }
            this->reserve(newCapacity);
            for (int i = 0; i < sz; i++)
                this->vec[i] = tmp[i];
            this->len = sz;
        }

        void insertAfter(iterator position, size_type n, const T &x)
        {
            size_type sz = 0;
            size_type newSize = this->len + n;
            size_type newCapacity = getNewCapacity(n);
            iterator it = this->begin();
            T tmp[newSize];

            while (it < position)
            {
                tmp[sz] = *it;
                it++;
                sz++;
            }
            while (n--)
                tmp[sz++] = x;
            while (it != this->end())
            {
                tmp[sz] = *it;
                sz++;
                it++;
                
            }
            this->reserve(newCapacity);
            for (int i = 0; i < sz; i++)
                this->vec[i] = tmp[i];
            this->len = sz;
        }

        void insert(iterator position, size_type n, const T &x)
        {
            size_type newSize = this->len + n;
            size_type newCapacity = 0;

            T tmp[newSize];
            size_type sz = 0;
            iterator it = this->begin();
            if (position == this->begin())
                addFront(position, n, x);
            else
                insertAfter(position, n, x);
        }
        iterator    insert(iterator position, const T &x)
        {
            insert(position, 1, x);
            return (position);
        }
        void resize(size_type n, T c = T())
        {

            if (n > this->_capacity)
            {
                this->reserve(n);
                for (int i = this->len; i < this->_capacity; i++)
                    this->push_back(c);
            }
            else
            {
                while (this->len > n)
                    this->pop_back();
            }
        }

        // modifiers
        void pop_back(void)
        {
            if (this->empty())
                return;
            this->len--;
            this->reserve(this->len);
        }
        // iterator insert(iterator position, const T &x);
        // void insert(iterator position, size_type n, const T & x);
        void push_back(const T &x)
        {
            size_type n;
            if (this->len == 0)
                this->reserve(1);
            else if (this->len + 1 > this->_capacity)
            {
                n = this->_capacity * 2;
                this->reserve(n);
            }
            this->vec[this->len] = x;
            this->len++;
        }

        // construction / destruction / assignment / copy construction
        explicit vector(const Allocator &alloc = Allocator())
        {
            this->len = 0;
            this->_capacity = 0;
            this->_alloc = alloc;
            this->vec = this->_alloc.allocate(this->len);
        }
        explicit vector(size_type n, const T &value = T(), const Allocator &alloc = Allocator())
        {
            len = n;
            this->_capacity = n;
            this->_alloc = alloc;
            this->vec = this->_alloc.allocate(n);
            for (int i = 0; i < n; i++)
                this->vec[i] = n;
        }
        allocator_type get_allocator() const { return this->_alloc; }
        vector &operator=(const vector<T, Allocator> &rhs);
        vector(vector const &obj);
        ~vector() { delete this->vec; }

    private:
        size_type len;
        Allocator _alloc;
        size_type _capacity;
        T *vec;
    };
}

#endif // VECTOR_HPP
