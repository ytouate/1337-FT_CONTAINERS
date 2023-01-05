/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmap_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:48:37 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/05 11:49:45 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(RMAP_ITERATOR_HPP)
#define RMAP_ITERATOR_HPP

namespace ft
{
    template <class Iterator>
    class rmap_iterator
    {
    public:
        typedef Iterator iterator_type;
        typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<Iterator>::value_type value_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
        typedef typename ft::iterator_traits<Iterator>::pointer pointer;
        typedef typename ft::iterator_traits<Iterator>::reference reference;

        explicit rmap_iterator(Iterator x) : _iter(x) {}
        template <class U>
        rmap_iterator(const rmap_iterator<U> &u)
        {
            _iter = u.base();
        }
        Iterator base() const
        {
            return _iter;
        }
        inline reference operator*(void) const
        {
            Iterator temp = _iter;
            return *--temp;
        }
        pointer operator->(void) const
        {
            return &(operator*());
        }
        rmap_iterator() : _iter(NULL, NULL) {}

        inline rmap_iterator operator++(int)
        {
            rmap_iterator temp = *this;
            --this->_iter;
            return temp;
        }
        inline rmap_iterator operator--(int)
        {
            rmap_iterator temp = *this;
            ++this->_iter;
            return temp;
        }
        inline rmap_iterator operator++(void)
        {
            --this->_iter;
            return *this;
        }
        inline rmap_iterator operator--(void)
        {
            ++this->_iter;
            return *this;
        }
        inline rmap_iterator operator+(difference_type n) const
        {
            return rmap_iterator<Iterator>(this->base() - n);
        }
        rmap_iterator &operator+=(difference_type n)
        {
            this->_iter -= n;
            return *this;
        }
        rmap_iterator operator-(difference_type n) const
        {
            rmap_iterator<Iterator> temp(this->base() + n);
            return temp;
        }
        rmap_iterator &operator-=(difference_type n)
        {
            this->_iter += n;
            return *this;
        }
        reference operator[](rmap_iterator<Iterator>::difference_type n)
        {
            return _iter[-n - 1];
        }
        inline rmap_iterator &operator=(rmap_iterator const &rhs)
        {
            this->_iter.operator=(rhs._iter);
            return *this;
        }
        difference_type operator-(const rmap_iterator &other) const
        {
            return other._iter - this->_iter;
        }

    private:
        Iterator _iter;
    };
    template <class Iterator_a, class Iterator_b>
    inline bool operator==(
        ft::rmap_iterator<Iterator_a> const &x,
        ft::rmap_iterator<Iterator_b> const &y)
    {
        return x.base() == y.base();
    }

    template <class Iterator_a, class Iterator_b>
    bool operator<(
        const ft::rmap_iterator<Iterator_a> &x,
        const ft::rmap_iterator<Iterator_b> &y)
    {
        return x.base() > y.base();
    }

    template <class Iterator_a, class Iterator_b>
    bool operator!=(
        const ft::rmap_iterator<Iterator_a> &x,
        const ft::rmap_iterator<Iterator_b> &y)
    {
        return x.base() != y.base();
    }

    template <class Iterator, class Iterator_b>
    bool operator>(
        const ft::rmap_iterator<Iterator> &x,
        const ft::rmap_iterator<Iterator_b> &y)
    {
        return x.base() < y.base();
    }

    template <class Iterator, class Iterator_b>
    bool operator>=(
        const ft::rmap_iterator<Iterator> &x,
        const ft::rmap_iterator<Iterator_b> &y)
    {
        return x.base() <= y.base();
    }

    template <class Iterator, class Iterator_b>
    bool operator<=(
        const ft::rmap_iterator<Iterator> &x,
        const ft::rmap_iterator<Iterator_b> &y)
    {
        return x.base() >= y.base();
    }

    template <class Iterator>
    typename ft::rmap_iterator<Iterator> operator+(
        typename ft::rmap_iterator<Iterator>::difference_type n,
        const ft::rmap_iterator<Iterator> &x)
    {
        ft::rmap_iterator<Iterator> temp(x.base() - n);
        return temp;
    }
};

#endif // RMAP_ITERATOR_HPP
