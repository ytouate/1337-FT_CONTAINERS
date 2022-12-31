/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbidirectional_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:08:33 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/31 19:39:42 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(R_BIDIRECTIONAL_ITERATOR)
#define R_BIDIRECTIONAL_ITERATOR

namespace ft
{
    template <class bIter>
    class r_bidirectional_iterator
    {

    public:
        typedef typename bIter::reference reference;
        typedef typename bIter::pointer pointer;
        typedef typename bIter::value_type value_type;
        typedef std::ptrdiff_t difference_type;
        typedef std::bidirectional_iterator_tag iterator_category;
        r_bidirectional_iterator(bIter x) : _iter(x) {}
        template <class U>
        r_bidirectional_iterator(const r_bidirectional_iterator<U> &u) : _iter(u._iter) {}
        typename value_type::reference operator*(void) const { return *_iter; }
        typename value_type::pointer operator->(void) const { return _iter.operator->(); }
        r_bidirectional_iterator &operator=(r_bidirectional_iterator const &rhs)
        {
            this->_iter = rhs._iter;
            return *this;
        }
        bool operator==(const r_bidirectional_iterator &a) { return this->_iter == a._iter; };
        bool operator!=(const r_bidirectional_iterator &a) { return this->_iter != a._iter; };
        r_bidirectional_iterator operator--(int)
        {
            r_bidirectional_iterator temp(*this);
            ++this->_iter;
            return temp;
        }
        r_bidirectional_iterator operator++(int)
        {
            r_bidirectional_iterator temp(*this);
            --this->_iter;
            return temp;
        }
        r_bidirectional_iterator &operator++(void)
        {
            --this->_iter;
            return *this;
        }
        r_bidirectional_iterator &operator--(void)
        {
            ++this->_iter;
            return *this;
        }

    private:
        bIter _iter;
    };
}

#endif // R_BIDIRECTIONAL_ITERATOR
