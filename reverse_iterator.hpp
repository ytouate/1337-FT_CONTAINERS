/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:35:09 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/12 12:11:04 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(REVERSE_ITERATOR_HPP)
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
namespace ft
{
    template <class T>
    class reverse_iterator
    {
    public:
        typedef typename ft::iterator_traits<T>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<T>::value_type iterator_type;
        typedef typename ft::iterator_traits<T>::difference_type difference_type;
        typedef typename ft::iterator_traits<T>::pointer pointer;
        typedef typename ft::iterator_traits<T>::reference reference;

        inline reference operator*(void) { return *_iter; }
        reverse_iterator (T ptr): _iter(ptr) {} 
        inline difference_type operator-(reverse_iterator const &right) { return this->_iter - right._iter; }
        inline difference_type operator+(reverse_iterator const &right) { return this->_iter + right._iter; }
        inline reverse_iterator operator-(const int n) { return this->_iter - n; }
        inline reverse_iterator operator+(const int n) { return this->_iter + n; }
        inline bool operator==(reverse_iterator const &right) { return this->_iter == right._iter; }
        inline bool operator!=(reverse_iterator const &right) { return this->_iter != right._iter; }
        inline bool operator<(reverse_iterator const &right) { return this->_iter < right._iter; }
        inline bool operator>(reverse_iterator const &right) { return this->_iter > right._iter; }
        inline bool operator<=(reverse_iterator const &right) { return this->_iter <= right._iter; }
        inline bool operator>=(reverse_iterator const &right) { return this->_iter >= right._iter; }
        inline reverse_iterator operator--(void)
        {
            reverse_iterator temp = *this;
            this->_iter++ ;
            return temp;
        }
        inline reverse_iterator operator++(void)
        {
            reverse_iterator temp = *this;
            this->_iter--;
            return temp;
        }
        inline reverse_iterator operator++(int notUsed)
        {
            (void)notUsed;
            this->_iter--;
            return *this;
        }
        inline reverse_iterator operator--(int notUsed)
        {
            (void)notUsed;
            this->_iter++;
            return *this;
        }
    private:
        T _iter;
    };
};
#endif // REVERSE_ITERATOR_HPP
