/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:54:33 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/11 23:43:36 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(VECTOR_HPP)
#define VECTOR_HPP

#include "../inc.hpp"

namespace ft
{
    template <class U>
    void ftSwap(U &a, U &b)
    {
        U c = a;
        a = b;
        b = c;
    }
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {

    public:
        // types
        typedef typename Allocator::reference reference;
        typedef typename Allocator::const_reference const_reference;
        typedef size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef T value_type;
        typedef Allocator allocator_type;
        typedef typename Allocator::pointer pointer;
        typedef ft::iterator<T> iterator;
        typedef ft::iterator<const T> const_iterator;
        typedef typename Allocator::const_pointer const_pointer;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

        // construct - copy - destroy
        /*
            default constructor initializes the private attributes
            to default values
        */
        explicit vector(const Allocator &alloc = Allocator())
        {
            this->len = 0;
            this->_capacity = 0;
            this->_alloc = alloc;
        }

        /*
            parametrize constructor allocate n for the vector and constructs the 
            allocated memory with <value>
        */
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

        /*
            range constructor will fill the container with the values is
            in the range [first, last)
        */
        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const Allocator &alloc = Allocator(),
               typename ft::enable_if<std::__is_input_iterator<InputIterator>::value &&
                                      !std::__is_forward_iterator<InputIterator>::value &&
                                      !ft::is_integral<InputIterator>::value>::type * = 0)
        {
            this->_alloc = alloc;
            this->len = 0;
            this->_capacity = 0;
            for (; first != last; ++first)
                this->push_back(*first);
        }

        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const Allocator &alloc = Allocator(),
               typename ft::enable_if<!ft::is_integral<InputIterator>::value &&
                                      std::__is_forward_iterator<InputIterator>::value>::type * = 0)
        {
            difference_type diff = std::distance(first, last);
            this->_alloc = alloc;
            if (diff != 0)
                this->vec = this->_alloc.allocate(diff);
            this->_capacity = diff;
            this->len = diff;
            for (difference_type i = 0; i < diff; i++)
            {
                _alloc.construct(&vec[i], *first);
                first++;
            }
        }

        /*
            copy constructor copies the content of x
            to the calling object (this)
        */
        vector(const vector<T, Allocator> &x)
        {
            this->len = x.size();
            this->_capacity = x.capacity();
            this->_alloc = x.get_allocator();
            this->vec = this->_alloc.allocate(this->_capacity);
            for (size_type i = 0; i < this->len; i++)
                this->_alloc.construct(&this->vec[i], x[i]);
        }

        /*
            Destructor will call the clear() method on the conatainer
        */
        ~vector()
        {
            this->clear();
            if (this->_capacity)
                this->_alloc.deallocate(&*this->begin(), this->_capacity);
            this->_capacity = 0;
            this->len = 0;
        }

        /*
            assignment operator will copy the content of rhs to the calling object
            after clearing the calling object
        */
        vector<T, Allocator> &operator=(const vector<T, Allocator> &rhs)
        {

            while (!empty())
                this->_alloc.destroy(&this->vec[--this->len]);
            size_type i = 0;
            size_type newSize = rhs.len - this->len;
            size_type newCapcity = getNewCapacity(newSize);
            this->reserve(newCapcity);
            while (this->len != rhs.len)
            {
                this->_alloc.construct(&this->vec[i], rhs[i]);
                this->len++;
                i++;
            }
            return *this;
        }

        /*
            clears the calling object before assigning the content of [first, last)
            to it the allocator remain unchanged
        */
        template <class Iterator>
        void assign(Iterator first, Iterator last,
                    typename ft::enable_if<!ft::is_integral<Iterator>::value &&
                                           std::__is_input_iterator<Iterator>::value &&
                                           !std::__is_forward_iterator<Iterator>::value>::type * = 0)
        {
            while (!empty())
                this->_alloc.destroy(&this->vec[--this->len]);
            while (first != last)
                this->push_back(*first++);
        }
        
        /*
            slightly optimized than the assign method that takes input iterator
            because all the allocations is done before the assignment
        */
        template <class Iterator>
        void assign(Iterator first, Iterator last,
                    typename ft::enable_if<!ft::is_integral<Iterator>::value &&
                                           std::__is_forward_iterator<Iterator>::value>::type * = 0)
        {
            while (!empty())
                this->_alloc.destroy(&this->vec[--this->len]);
            size_type newSize = std::distance(first, last);
            this->reserve(newSize);
            while (first != last)
                this->push_back(*first++);
        }

        /*
            clears the calling object and resizes it to hold n
            elements initizialized with t
        */
        void assign(size_type n, const T &t)
        {
            while (!empty())
                this->_alloc.destroy(&this->vec[--this->len]);
            size_type newSize = n;
            size_type newCapacity = getNewCapacity(newSize);
            this->reserve(newCapacity);
            while (this->len != n)
            {
                this->_alloc.construct(&this->vec[this->len], t);
                this->len++;
            }
        }

        /*
            returns the container's allocator
        */
        allocator_type get_allocator() const { return this->_alloc; }

        // iterators
        iterator begin() { return ft::iterator<T>(vec); }
        const_iterator begin() const { return ft::iterator<T>(vec); }
        iterator end() { return ft::iterator<T>(&vec[len]); }
        const_iterator end() const { return ft::iterator<T>(&vec[len]); }
        reverse_iterator rbegin() { return ft::reverse_iterator<ft::iterator<T> >(&vec[len]); }
        const_reverse_iterator rbegin() const { return ft::reverse_iterator<ft::iterator<const T> >(&vec[len]); }
        reverse_iterator rend() { return ft::reverse_iterator<ft::iterator<T> >(vec); }
        const_reverse_iterator rend() const { return ft::reverse_iterator<ft::iterator<const T> >(vec); }

        // capacity

        /*
            returns the size of the vector;
        */
        size_type size() const { return this->len; }

        /*
            
        */
        size_type max_size() const
        {
            return std::min<size_type>(this->_alloc.max_size(),
                                       std::numeric_limits<std::ptrdiff_t>::max());
        }
        size_type capacity() const { return this->_capacity; }
        bool empty() const { return this->len == 0; }
        void resize(size_type n, T c = T())
        {
            if (n > this->len)
            {
                this->reserve(n);
                for (size_type i = this->len; i < n; i++)
                    this->_alloc.construct(&this->vec[i], c);
            }
            else
            {
                while (this->len > n)
                    this->pop_back();
            }
            this->len = n;
        }

        /*
            reserves n for the vector if n is less than the vector capacity
            no change will occure
        */
        void reserve(size_type n)
        {
            if (n > max_size())
                this->_alloc.allocate(n);
            else if (n <= this->_capacity)
                return;
            size_type tmpLen = this->len;
            T *tmp = this->_alloc.allocate(tmpLen);
            for (size_type i = 0; i < this->len; ++i)
            {
                this->_alloc.construct(&tmp[i], this->vec[i]);
                this->_alloc.destroy(&vec[i]);
            }
            if (this->_capacity > 0 && n <= max_size())
                this->_alloc.deallocate(vec, this->_capacity);
            this->vec = this->_alloc.allocate(n);
            this->_capacity = n;
            for (size_type i = 0; i < this->len; i++)
            {
                this->_alloc.construct(&this->vec[i], tmp[i]);
                this->_alloc.destroy(&tmp[i]);
            }
            this->_alloc.deallocate(tmp, tmpLen);
        }

        // element access
        /* 
            returns the elements at n;
        */
        reference operator[](size_type n) { return this->vec[n]; }
        const_reference operator[](size_type n) const { return this->vec[n]; }
        
        /*
            returns the element at n if the n is out of range an exception is thrown 
        */
        reference at(size_type n)
        {
            if (n >= this->len)
                throw std::out_of_range("Index out of range");
            return this->vec[n];
        }
        const_reference at(size_type n) const
        {
            if (n >= this->len)
                throw std::out_of_range("Index out of Range");
            return this->vec[n];
        }
        /*
            returns the first element at the vector vec[0]
        */
        reference front() { return this->vec[0]; }
        const_reference front() const { return this->vec[0]; }

        /*
            returns the last element in the vector vec[len - 1]
        */
        reference back() { return this->vec[this->len - 1]; }
        const_reference back() const { return this->vec[this->len - 1]; }

        // modifiers
        /*
            add the given element at the back of the vector
        */
        void push_back(const T &x)
        {
            if (this->len == 0)
                this->reserve(1);
            else if (this->len + 1 > this->_capacity)
            {
                this->reserve(this->_capacity * 2);
            }
            this->_alloc.construct(&this->vec[this->len], x);
            this->len++;
        }

        /*
            removes the last element of the vector
        */
        void pop_back(void)
        {
            if (this->empty())
                return;
            this->_alloc.destroy(&this->vec[--this->len]);
        }

        void insert(iterator position, size_type n, const T &x)
        {
            int count = 0;
            iterator ite = end() + 1;
            iterator it = begin();
            if (n == 0)
                return;
            else if (n == 1)
            {
                insert(position, x);
                return;
            }
            while (it != ite)
            {
                if (position == it)
                {
                    this->reserve(getNewCapacity(n));
                    int oldSize = this->len ? this->len - 1 : 0;
                    int newSize = (oldSize + n);
                    if (this->empty())
                        goto fill;
                    while (oldSize >= count)
                    {
                        if ((size_type)newSize >= this->len)
                            this->_alloc.construct(&this->vec[newSize], this->vec[oldSize]);
                        else
                            this->vec[newSize] = this->vec[oldSize];
                        oldSize--;
                        newSize--;
                    }
                fill:
                    for (size_t t = count; t < count + n; t++)
                    {
                        if (t < this->len)
                            this->_alloc.destroy(&this->vec[t]);
                        this->_alloc.construct(&this->vec[t], x);
                    }
                    this->len += n;
                    return;
                }
                count++;
                it++;
            }
        }

        iterator insert(iterator position, const T &x)
        {
            int n = 0;
            value_type tmp;
            iterator ite = end() + 1;
            iterator it = begin();
            while (it != ite)
            {
                if (position == it)
                {
                    this->push_back(x);
                    tmp = vec[n];
                    vec[n] = vec[len - 1];
                    vec[len - 1] = tmp;
                    int i = this->len - 1;
                    while ((i - 1) > n)
                    {
                        tmp = vec[i];
                        vec[i] = vec[i - 1];
                        vec[i - 1] = tmp;
                        i--;
                    }
                    it = &this->vec[n];
                    return it;
                }
                n++;
                it++;
            }
            return end();
        }

        template <class Iterator>
        void insert(iterator position,
                    Iterator first, Iterator last,
                    typename ft::enable_if<!ft::is_integral<Iterator>::value>::type * = 0)
        {
            vector temp(first, last);
            iterator ite = end() + 1;
            iterator it = begin();
            int count = 0;
            if (temp.size() == 0)
                return;
            else if (temp.size() == 1)
            {
                insert(position, temp.front());
                return;
            }
            while (it != ite)
            {
                if (position == it)
                {
                    this->reserve(getNewCapacity(temp.size()));
                    int oldSize = this->len ? this->len - 1 : 0;
                    int newSize = oldSize + temp.size();
                    if (this->empty())
                        goto fill;
                    while (oldSize >= count)
                    {
                        if ((size_type)newSize >= this->len)
                            this->_alloc.construct(&this->vec[newSize], this->vec[oldSize]);
                        else
                            this->vec[newSize] = this->vec[oldSize];
                        oldSize--;
                        newSize--;
                    }
                fill:
                    int idx = 0;
                    for (size_t t = count; t < count + temp.len; t++)
                    {
                        if (t < this->len)
                            this->_alloc.destroy(&this->vec[t]);
                        this->_alloc.construct(&this->vec[t], temp[idx++]);
                    }
                    this->len += temp.size();
                    return;
                }
                count++;
                it++;
            }
        }

        iterator erase(iterator position)
        {
            int count = 0;
            value_type tmp;
            iterator it = this->begin();
            iterator ite = this->end();
            while (it != ite)
            {
                if (it == position)
                {
                    this->_alloc.destroy(&this->vec[this->len - 1]);
                    this->len--;
                    int nbSwaps = this->len - count;
                    int save = count;
                    while (nbSwaps > 0)
                    {
                        tmp = vec[count];
                        vec[count] = this->vec[count + 1];
                        vec[count + 1] = tmp;
                        nbSwaps--;
                        count++;
                    }
                    it = &this->vec[save];
                    return it;
                }
                count++;
                it++;
            }
            return position;
        }

        iterator erase(iterator first, iterator last)
        {
            difference_type distance = std::distance(first, last);
            if (distance < 0)
                return first;
            int count = 0;
            iterator it = begin();
            iterator ite = end();
            while (it != ite)
            {
                if (it == first)
                {
                    size_type _len = this->len;
                    for (difference_type i = count; i < (count + distance); i++)
                        this->_alloc.destroy(&vec[--len]);
                    size_type j = count + distance;
                    while (j < _len)
                    {
                        value_type tmp = this->vec[j];
                        this->vec[j] = this->vec[count];
                        this->vec[count] = tmp;
                        j++;
                        count++;
                    }
                    return first;
                }
                it++;
                count++;
            }
            return first;
        }

        void swap(vector<T, Allocator> &x)
        {
            ftSwap(this->_alloc, x._alloc);
            ftSwap(this->vec, x.vec);
            ftSwap(this->len, x.len);
            ftSwap(this->_capacity, x._capacity);
        }

        void clear(void)
        {
            for (size_type i = 0; i < this->len; i++)
            {
                this->_alloc.destroy(vec + i);
            }
            this->len = 0;
        }

    private:
        void addFront(size_type n, const T &x)
        {
            size_type newCapacity = getNewCapacity(n);
            iterator it = this->begin();
            vector tmp;
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
        size_type getNewCapacity(size_type n)
        {
            // capacity > this->len + n;
            // capacity < this->len + n;
            // empty vector;
            // capcity >= size + n;
            // capcity < size + n && n > size;
            // capacity < size + n && n <= size;
            size_type newCapacity = 0;
            if (len == 0)
                newCapacity = n;
            else if (_capacity < len + n)
            {
                if (n > len)
                    newCapacity = n + len;
                else
                    newCapacity = this->_capacity * 2;
            }
            else if (_capacity >= len + n)
            {
                newCapacity = _capacity;
            }
            return newCapacity;
        }

        size_type len;
        Allocator _alloc;
        size_type _capacity;
        T *vec;
    };
    /*---- NON-MEMBER FUNCTIONS ----*/

    // comparisons
    template <class T, class Alloc>
    bool operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
    {
        if (lhs.size() == rhs.size())
            return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
        return false;
    }

    template <class T, class Alloc>
    bool operator<(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Alloc>
    bool operator!=(
        const ft::vector<T, Alloc> &lhs,
        const ft::vector<T, Alloc> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class T, class Alloc>
    bool operator<=(
        const ft::vector<T, Alloc> &lhs,
        const ft::vector<T, Alloc> &rhs)
    {
        return (lhs < rhs or lhs == rhs);
    }

    template <class T, class Alloc>
    bool operator>(
        const ft::vector<T, Alloc> &lhs,
        const ft::vector<T, Alloc> &rhs)
    {
        return !(lhs <= rhs);
    }
    template <class T, class Alloc>
    bool operator>=(
        const ft::vector<T, Alloc> &lhs,
        const ft::vector<T, Alloc> &rhs)
    {
        return !(lhs < rhs);
    }

    // specialized algorithms:
    template <class T, class Allocator>
    void swap(ft::vector<T, Allocator> &x, ft::vector<T, Allocator> &y)
    {
        x.swap(y);
    }
}

#endif // VECTOR_HPP