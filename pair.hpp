/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:31:32 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/02 17:17:07 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(PAIR)
#define PAIR

#include "inc.hpp"

namespace ft
{
    template <class T, class T2>
    class pair
    {
        typedef T first_type;
        typedef T2 second_type;

    public:
        T first;
        T2 second;
        pair() : first(), second() {}

        template <class U, class V>
        pair(const pair<U, V> &pr)
        {
            this->first = pr.first;
            this->second = pr.second;
        }

        pair(const first_type &a, const second_type &b)
        {
            this->first = a;
            this->second = b;
        }

        pair &operator=(const pair &pr)
        {
            this->first = pr.first;
            this->second = pr.second;
            return *this;
        }
        void swap(pair &pr) throw()
        {
            pair temp = pr;
            pr = *this;
            *this = temp;
        }

    private:
    };
    template <class T1, class T2>
    bool operator==(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }

    template <class T1, class T2>
    bool operator!=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class T1, class T2>
    bool operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
    }

    template <class T1, class T2>
    bool operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return !(rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return rhs < lhs;
    }

    template <class T1, class T2>
    bool operator>=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return !(lhs < rhs);
    }

    template <class T1, class T2>  void swap (ft::pair<T1,T2>& x, ft::pair<T1,T2>& y) throw()
    {
        x.swap(y);
    }
};



#endif // PAIR
