/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:35:09 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/22 15:29:29 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(REVERSE_ITERATOR_HPP)
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator"

template <class T>
class iterator;

// typedef iterator< const T const_iterator;
namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
    public:
        typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<Iterator>::value_type iterator_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
        typedef typename ft::iterator_traits<Iterator>::pointer pointer;
        typedef typename ft::iterator_traits<Iterator>::reference reference;
        inline reference operator*(void) const { return *this->base(); }
        explicit reverse_iterator(Iterator ptr) : _iter(ptr) {}
        template <class U>
        reverse_iterator(const reverse_iterator<U> &u)
        {
            _iter = u.base();
        }
        reverse_iterator() : _iter(NULL) {}
        // inline difference_type operator-(reverse_iterator const &right) const
        // {
        //     // Iterator temp = this->base().right.base();
        //     // return reverse_iterator <Iterator> (temp);
        // }
        // inline difference_type operator+(reverse_iterator const &right) const
        // {
        //     return this->_iter - right._iter;
        // }

        inline reverse_iterator operator-(difference_type n) const
        {
            reverse_iterator<Iterator> temp(this->base() + n);
            return temp;
        }
        inline reverse_iterator operator+(difference_type n) const
        {
            reverse_iterator<Iterator> temp(this->base() - n);
            return temp;
        }
        inline bool operator==(reverse_iterator const &right) { return this->_iter == right._iter; }
        inline bool operator!=(reverse_iterator const &right) { return this->_iter != right._iter; }
        inline bool operator<(reverse_iterator const &right) { return this->_iter < right._iter; }
        inline bool operator>(reverse_iterator const &right) { return this->_iter > right._iter; }
        inline bool operator<=(reverse_iterator const &right) { return this->_iter <= right._iter; }
        inline bool operator>=(reverse_iterator const &right) { return this->_iter >= right._iter; }
        Iterator base() const
        {
            return this->_iter;
        }
        pointer operator->(void) const
        {
            return _iter.operator->();
        }
        inline reverse_iterator operator--(int)
        {
            reverse_iterator temp = *this;
            this->_iter++;
            return temp;
        }
        reverse_iterator& operator+=(difference_type n)
        {
            *this = *this + n;
            return *this;
        }
        reference operator[](difference_type n) const
        {
            reference ref = _iter[n];
            return ref;
        }
        reverse_iterator& operator-=(difference_type n)
        {
            *this = *this - n;
            return *this;
        }
        inline reverse_iterator operator++(int)
        {
            reverse_iterator temp = *this;
            this->_iter--;
            return temp;
        }
        inline reverse_iterator operator++(void)
        {
            this->_iter--;
            return *this;
        }
        inline reverse_iterator operator--(void)
        {
            this->_iter++;
            return *this;
        }
        inline reverse_iterator &operator=(reverse_iterator const &rhs)
        {
            this->_iter.operator=(rhs._iter);
            // this->_iter = rhs._iter;
            return *this;
        }
        reverse_iterator(reverse_iterator const &obj) : _iter(NULL)
        {
            this->_iter = obj._iter;
        }

        friend reverse_iterator operator+(reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &x)
        {
            // reverse_iterator < Iterator > temp = x.operator+(n);
            return x + n;
        }

    private:
        Iterator _iter;
    };
};
template <class Iterator>
typename ft::reverse_iterator<Iterator>::difference_type operator-(
    const ft::reverse_iterator<Iterator> &x,
    const ft::reverse_iterator<Iterator> &y)

{
    typename ft::reverse_iterator<Iterator>::difference_type result = x.base() - y.base();
    return result < 0 ? -result : result;
}
#endif // REVERSE_ITERATOR_HPP
