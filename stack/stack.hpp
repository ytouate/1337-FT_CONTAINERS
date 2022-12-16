/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:20:20 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/16 14:59:13 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(STACK_HPP)
#define STACK_HPP

#include "../inc.hpp"

namespace ft
{
    template <class T, class Container = std::vector<T> >
    class stack
    {
    public:
        typedef typename Container::value_type value_type;
        typedef typename Container::size_type size_type;
        typedef typename Container::reference reference;
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
        void swap(stack &s) throw()
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
        container_type getC() const { return this->c; }
        // template <class U, class C>
        // friend bool operator<=(const stack<U, C> &x,
        //                        const stack<U, C> &y)
        // {
        //     return x.c <= y.c;
        // }
    };
    template <class U, class C>
     bool operator<=(const stack<U, C> &x,
                           const stack<U, C> &y)
    {
        return x.getC() <= y.getC();
    }
    template <class T, class Container>
    void swap(stack<T, Container> &x, stack<T, Container> &y) throw()
    {
        x.swap(y);
    }
}

#endif // STACK_HPP
