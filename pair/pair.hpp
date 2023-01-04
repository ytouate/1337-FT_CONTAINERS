/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:31:32 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/04 18:15:03 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(PAIR)
#define PAIR

// #include "../inc.hpp"
#include <iostream>
namespace ft
{
    template <class T, class T2>
    class pair
    {

    public:
        typedef T first_type;
        typedef T2 second_type;
        T first;
        T2 second;
        pair() : first(), second() {}

        template <class U, class V>
        pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}

        pair(const first_type &a, const second_type &b) : first(a), second(b) {}

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
    void swap(ft::pair<T1, T2> &x, ft::pair<T1, T2> &y) throw()
    {
        x.swap(y);
    }
    /*
        Specialization
    */
    template <class T, class T2>
    class pair<const T, T2>
    {

    public:
        typedef T first_type;
        typedef T2 second_type;
        T first;
        T2 second;
        pair() : first(), second() {}

        template <class U, class V>
        pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}

        pair(const first_type &a, const second_type &b) : first(a), second(b) {}

        pair &operator=(const pair<const T, const T2> &pr)
        {
            this->second = pr.first;
            return *this;
        }
        void swap(const pair<const T, const T2> &pr) throw()
        {
            pair<const T, const T2> temp = pr;
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

    template <class T1, class T2>
    void swap(ft::pair<const T1, T2> &x, ft::pair<const T1, T2> &y) throw()
    {
        x.swap(y);
    }
};

#endif // PAIR
