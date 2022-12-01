/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:20:20 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/30 17:33:15 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(STACK_HPP)
#define STACK_HPP

#include "../vector/vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
    public:
        typedef typename Container::value_type value_type;
        typedef typename Container::size_type size_type;
        typedef typename Container::reference   reference;
        typedef typename Container::const_reference const_reference;
        typedef Container container_type;

    protected:
        Container c;

    public:
        explicit stack(const Container cont = Container())
        {
            c = cont;
        }
        stack &operator=(const stack &s)
        {
            c = s.c;
            return *this;
        }
        void push(const value_type &s) { c.push_back(s); }
        void swap(stack &s) _NOEXCEPT
        {
            ft::swap(c, s.c);
        }
        bool empty() const { return c.empty(); }
        size_type size() const { return c.size(); }
        value_type &top() { return c.back(); }
        const value_type &top() const { return c.back(); }
        void pop() { c.pop_back(); }
        template <class U, class C>
        friend bool operator==(const stack<U, C> &x,
                        const stack<U, C> &y)
        {
            return x.c == y.c;
        }
         template <class U, class C>
        friend bool operator<(const stack<U, C> &x,
                    const stack<U, C> &y)
        {
            return x.c < y.c;
        }
         template <class U, class C>
        friend bool operator!=(const stack<U, C> &x,
                        const stack<U, C> &y)
        {
            return x.c != y.c;
        }
         template <class U, class C>
        friend bool operator>(const stack<U, C> &x,
                    const stack<U, C> &y)
        {
            return x.c > y.c;
        }
         template <class U, class C>
        friend bool operator>=(const stack<U, C> &x,
                        const stack<U, C> &y)
        {
            return x.c >= y.c;
        }
         template <class U, class C>
        friend bool operator<=(const stack<U, C> &x,
                        const stack<U, C> &y)
        {
            return x.c <= y.c;
        }
    };
}

#endif // STACK_HPP