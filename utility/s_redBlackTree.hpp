/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_redBlackTree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:52:16 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/06 16:11:01 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(SET_HPP)
#define SET_HPP

#include "../inc.hpp"
namespace ft
{
    template <class T, class Compare = std::less<T>,
              class Allocator = std::allocator<T> >
    class set
    {
    public:
        typedef T key_type;
        typedef T value_type;
        typedef Compare key_compare;
        typedef Compare value_compare;
        typedef typename Allocator::reference reference;
        typedef typename Allocator::pointer pointer;
        typedef typename Allocator::const_reference const_reference;
        typedef typename Allocator::const_pointer const_pointer;
        typedef ft::map_iterator<value_type> iterator;
        typedef ft::map_iterator<value_type> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef ft::iterator_traits<iterator>::size_type size_type;

        explicit set(const Compare &comp = Compare(), const Allocator & = Allocator());
        template <class InputIterator>
        set(InputIterator first, InputIterator last,
            const Compare &comp = Compare(),
            const Allocator & = Allocator());
        set(const set &x);
        ~set();
        set operator = (const set &x);
        
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_iterator rbegin() ;
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;

        bool empty() const;
        size_type size() const;
        size_type max_size() const;

        ft::pair<iterator, bool> insert (const value_type &x);
        iterator insert(iterator position, const value_type &x)
        template <class InputIterator>
        void insert(InputI)
    };
}

#endif // SET_HPP
