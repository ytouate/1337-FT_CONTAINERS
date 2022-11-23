/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:54:33 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/23 22:23:35 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(VECTOR_HPP)
#define VECTOR_HPP

#include "../reverse_iterator.hpp"
#include "../iterator.hpp"
#include <iostream>

template <class T>
void ft_swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}
namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {

    public:
        char *s;
        // types
        typedef typename Allocator::reference reference;
        typedef typename Allocator::const_reference const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef Allocator allocator_type;
        typedef typename Allocator::pointer pointer;
        typedef ft::iterator<T> iterator;
        typedef ft::iterator<const T> const_iterator;
        typedef typename Allocator::const_pointer const_pointer;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

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
        void swap(vector<T, Allocator> &x)
        {
            ft_swap(this->_alloc, x._alloc);
            ft_swap(this->vec, x.vec);
            ft_swap(this->len, x.len);
            ft_swap(this->_capacity, x._capacity);
        }
        // iterators
        const_iterator begin() const { return ft::iterator<T>(vec); }
        const_iterator end() const { return ft::iterator<T>(&this->vec[this->len]); }
        iterator begin() { return ft::iterator<T>(&vec[0]); }
        iterator end() { return ft::iterator<T>(&vec[this->len]); }
        const_reverse_iterator rbegin() const { return ft::reverse_iterator<ft::iterator<const T> >(&this->vec[this->len]); }
        reverse_iterator rbegin() { return ft::reverse_iterator<ft::iterator<T> >(&vec[this->len]); }
        reverse_iterator rend() { return ft::reverse_iterator<ft::iterator<T> >(&vec[0]); }
        const_reverse_iterator rend() const { return ft::reverse_iterator<ft::iterator<const T> >(&this->vec[0]); }

        // capacity
        size_type max_size() const { return std::min<size_type>(this->_alloc.max_size(), std::numeric_limits<ptrdiff_t>::max()); }
        size_type size() const { return this->len; }
        size_type capacity() const { return this->_capacity; }
        bool empty() const { return this->len == 0; }
        void reserve(size_type n)
        {
            if (n <= this->_capacity)
                return;
            T tmp[this->len];
            for (size_type i = 0; i < this->len; ++i)
            {
                tmp[i] = this->vec[i];
                this->_alloc.destroy(&vec[i]);
            }
            if (_capacity > 0)
                this->_alloc.deallocate(vec, this->_capacity);
            this->vec = this->_alloc.allocate(n);
            this->_capacity = n;
            for (size_type i = 0; i < this->len; i++)
                this->_alloc.construct(&this->vec[i], tmp[i]);
        }

        iterator erase(iterator position)
        {
            T tmp[this->len - 1];
            size_type i = 0;
            iterator it = this->begin();
            while (it != this->end())
            {
                if (it != position)
                    tmp[i++] = *it;
                it++;
            }
            this->pop_back();
            for (size_type j = 0; j < this->len; j++)
            {
                this->vec[j] = tmp[j];
                // this->_alloc.construct(&this->vec[j], tmp[j]);
            }
            return position;
        }
        bool isInRange(iterator first, iterator last, iterator toFind)
        {
            for (; first != last; first++)
            {
                if (toFind == first)
                    return true;
            }
            return false;
        }

        iterator erase(iterator first, iterator last)
        {
            difference_type diff = last - first;
            bool flag = false;
            T tmp[this->len];
            size_type i = 0;
            iterator it = this->begin();
            while (diff)
            {
                if (!isInRange(first, last, it))
                {
                    tmp[i++] = *it;
                    flag = true;
                }
                else
                {
                    this->len--;
                    diff--;
                }
            }
            if (flag)
            {
                this->len = i;
                for (size_type j = 0; j < i; j++)
                {
                    this->vec[j] = tmp[j];
                }
            }
            return first;
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

        void insert(iterator position, size_type n, const T &x)
        {
            iterator it = this->begin();

            if (position == this->begin())
                addFront(n, x);
            else
                insertAfter(position, n, x);
        }
        iterator insert(iterator position, const T &x)
        {
            difference_type diff = position - this->begin();
            insert(position, 1, x);
            return (this->begin() + diff);
        }
        void resize(size_type n, T c = T())
        {
            if (n > this->len)
            {
                this->reserve(n);
                for (size_type i = this->len; i < n; i++)
                {
                    this->_alloc.construct(&this->vec[i], c);
                }
            }
            else
            {
                while (this->len > n)
                    this->pop_back();
            }
            this->len = n;
        }
        void clear(void)
        {
            for (size_type i = 0; i < this->len; i++)
            {
                this->_alloc.destroy(vec + i);
            }
            this->len = 0;
        }

        void pop_back(void)
        {
            if (this->empty())
                return;
            this->_alloc.destroy(&this->vec[--this->len]);
        }
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
            this->_alloc.construct(&this->vec[this->len], x);
            this->len++;
        }

        // construction / destruction / assignment / copy construction
        explicit vector(const Allocator &alloc = Allocator())
        {
            this->len = 0;
            this->_capacity = 0;
            this->_alloc = alloc;
        }
        explicit vector(size_type n, const T &value = T(), const Allocator &alloc = Allocator())
        {
            len = n;
            this->_capacity = n;
            this->_alloc = alloc;
            if (n != 0)
                this->vec = this->_alloc.allocate(n);
            for (size_type i = 0; i < n; i++)
                this->_alloc.construct(&this->vec[i], value);
        }
        allocator_type get_allocator() const { return this->_alloc; }
        vector &operator=(const vector<T, Allocator> &rhs)
        {
            assign(rhs.begin(), rhs.end());
        }
        vector(const vector<T, Allocator> &x)
        {
            this->len = x.size();
            this->_capacity = x.capacity();
            this->_alloc = x.get_allocator();
            this->vec = this->_alloc.allocate(this->_capacity);
            for (size_type i = 0; i < this->len; i++)
                this->_alloc.construct(&this->vec[i], x[i]);
        }
        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const Allocator &alloc = Allocator())
        {
            difference_type diff = last - first;
            this->_alloc = alloc;
            this->vec = this->_alloc.allocate(diff);
            this->_capacity = diff;
            this->len = diff;
            for (difference_type i = 0; i < diff; i++)
            {
                _alloc.construct(&vec[i], *first);
                first++;
            }
        }
        void assign(size_type n, const T &t)
        {
            for (size_type i = 0; i < len; i++)
                _alloc.destroy(&vec[i]);
            erase(begin(), end());
            insert(begin(), n, t);
        }

        ~vector()
        {
            this->clear();
            if (this->_capacity)
                this->_alloc.deallocate(&*this->begin(), this->_capacity);
            this->_capacity = 0;
        }


    private:
        void addFront(size_type n, const T &x)
        {
            size_type newCapacity = getNewCapacity(n);
            iterator it = this->begin();
            vector tmp;
            tmp.reserve(this->len + n);
            while (n--)
                tmp.push_back(x);
            while (it != this->end())
                tmp.push_back(*it++);
            this->reserve(newCapacity);
            for (size_type i = 0; i < tmp.len; i++)
            {
                if (i < this->len)
                    this->_alloc.destroy(&this->vec[i]);
                this->_alloc.construct(&this->vec[i], tmp[i]);
            }
            this->len = tmp.len;
        }

        void insertAfter(iterator position, size_type n, const T &x)
        {
            if (n > max_size())
                _alloc.allocate(n);
            size_type newCapacity = getNewCapacity(n);
            iterator it = this->begin();
            vector tmp;
            tmp.reserve(this->len + n);
            while (it < position)
                tmp.push_back(*it++);
            while (n--)
                tmp.push_back(x);
            while (it != this->end())
                tmp.push_back(*it++);
            this->reserve(newCapacity);
            for (size_type i = 0; i < tmp.len; i++)
            {
                if (i < this->len)
                    this->_alloc.destroy(&this->vec[i]);
                this->_alloc.construct(&this->vec[i], tmp[i]);
            }
            this->len = tmp.len;
        }
        size_type len;
        Allocator _alloc;
        size_type _capacity;
        T *vec;
    };
}

template <class T, class Alloc>
bool operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
    if (lhs.size() == rhs.size())
    {
        size_t i = 0;
        for (; i < lhs.size(); i++)
        {
            if (lhs[i] != rhs[i])
                return false;
        }
        return true;
    }
    return false;
}

template <class T, class Alloc>
bool operator!=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
    return !(lhs == rhs);
}

template <class T, class Alloc>
bool operator<(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
    if (lhs.size() < rhs.size())
        return true;
    else if (lhs.size() > rhs.size())
        return false;
    else
    {
        size_t i = 0;
        for (; i < lhs.size(); i++)
        {
            if (lhs[i] < rhs[i])
                return true;
            else if (lhs[i] < rhs[i])
                return false;
        }
        return false;
    }
}

template <class T, class Alloc>
bool operator<=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
    if (lhs.size() > rhs.size())
        return false;
    else
    {
        size_t i = 0;
        for (; i < lhs.size(); i++)
        {
            if (lhs[i] > rhs[i])
                return false;
        }
        return true;
    }
}

template <class T, class Alloc>
bool operator>(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
    return (!(lhs <= rhs));
}

template <class T, class Alloc>
bool operator>=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
    return lhs == rhs or lhs > rhs;
}

template <class T, class Allocator>
void swap(ft::vector<T, Allocator> &x, ft::vector<T, Allocator> &y)
{
    x.swap(y);
}
#endif // VECTOR_HPP
