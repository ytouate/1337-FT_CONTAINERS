/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:52:16 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/14 14:46:00 by ytouate          ###   ########.fr       */
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
        typedef Allocator allocator_type;
        typedef typename Allocator::reference reference;
        typedef typename Allocator::pointer pointer;
        typedef typename Allocator::const_reference const_reference;
        typedef typename Allocator::const_pointer const_pointer;
        typedef ft::map_iterator<value_type, allocator_type> iterator;
        typedef ft::map_iterator<value_type, allocator_type> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef std::ptrdiff_t difference_type;
        typedef size_t size_type;

        explicit set(const Compare &comp = Compare(), const Allocator &alloc = Allocator())
            : _alloc(alloc), _comp(comp) {}

        template <class InputIterator>
        set(InputIterator first, InputIterator last,
            const Compare &comp = Compare(),
            const Allocator &alloc = Allocator())
        {
            for (; first != last; ++first)
                _tree.insert(*first);
            _alloc = alloc;
            _comp = comp;
        }
        set(const set &x)
            : _tree(x._tree)
        {
            _alloc = x._alloc;
            _comp = x._comp;
        }
        ~set() { _tree.clear(); }
        set operator=(const set &x)
        {
            _tree = x._tree;
            _alloc = x._alloc;
            _comp = x._comp;
            return *this;
        }

        iterator begin() { return _tree.begin(); }
        const_iterator begin() const { return _tree.begin(); }
        iterator end() { return _tree.end(); }
        const_iterator end() const { return _tree.end(); }
        reverse_iterator rbegin() { return _tree.rbegin(); }
        const_reverse_iterator rbegin() const { return _tree.rbegin(); }
        reverse_iterator rend() { return _tree.rend(); }
        const_reverse_iterator rend() const { return _tree.rend(); }

        bool empty() const { return _tree.size() == 0; }
        size_type size() const { return _tree.size(); }
        size_type max_size() const { return _alloc.max_size(); }

        ft::pair<iterator, bool> insert(const value_type &x)
        {
            iterator res;
            t_node<value_type, allocator_type> *node = _tree.search(x);
            if (node != NULL)
            {
                return ft::make_pair(iterator(node, _tree.getRoot()), false);
            }
            iterator it = _tree.insert(x);
            return ft::make_pair(it, true);
        }
        iterator insert(iterator position, const value_type &x)
        {
            (void)position;
            iterator res;
            _tree.insert(x);
            res = iterator(_tree.search(x), _tree.getRoot());
            return res;
        }
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            for (; first != last; ++first)
                _tree.insert(*first);
        }

        void erase(iterator position)
        {
            iterator it = begin();
            iterator ite = end();
            iterator temp;
            while (it != ite)
            {
                if (it == position)
                {
                    _tree.erase(*it);
                    return;
                }
                ++it;
            }
        }
        size_type erase(const key_type &x)
        {
            t_node<value_type, allocator_type> *node = _tree.search(x);
            if (node == NULL)
                return 0;
            _tree.erase(x);
            return 1;
        }
        void erase(iterator first, iterator last)
        {
            if (first == begin() and last == end())
            {
                return clear();
            }
            while (first != last)
            {
                erase(first++);
            }
                // _tree.erase(*first++);
        }

        void swap(set &x)
        {
            _tree.swap(x._tree);
        }

        void clear() { _tree.clear(); }

        key_compare key_comp() const { return _comp; }
        value_compare value_comp() const { return _comp; }
        allocator_type get_allocator() const { return _alloc; }

        iterator find(const key_type &x) const { return iterator(_tree.search(x), _tree.getRoot()); }
        size_type count(const key_type &x) const { return _tree.count(x); }

        iterator lower_bound(const key_type &x) const
        {
            return _tree.lower_bound(x);
        }
        iterator upper_bound(const key_type &x) const
        {
            return _tree.upper_bound(x);
        }

        pair<iterator, iterator> equal_range(const key_type &x) const
        {
            return ft::make_pair(lower_bound(x), upper_bound(x));
        }

    private:
        s_redBlackTree<value_type, allocator_type, key_compare> _tree;
        allocator_type _alloc;
        key_compare _comp;
    };
    template <class Key, class Compare, class Allocator>
    bool operator==(const set<Key, Compare, Allocator> &x,
                    const set<Key, Compare, Allocator> &y)
    {
        if (x.size() == y.size())
            return ft::equal(x.begin(), x.end(), y.begin());
        return false;
    }
    template <class Key, class Compare, class Allocator>
    bool operator!=(const set<Key, Compare, Allocator> &x,
                    const set<Key, Compare, Allocator> &y)
    {
        return !(x == y);
    }
    template <class Key, class Compare, class Allocator>
    bool operator<(const set<Key, Compare, Allocator> &x,
                   const set<Key, Compare, Allocator> &y)
    {
        return ft::lexicographical_compare(x.begin(), x.end(),
                                           y.begin(), y.end());
    }
    template <class Key, class Compare, class Allocator>
    bool operator<=(const set<Key, Compare, Allocator> &x,
                    const set<Key, Compare, Allocator> &y)
    {
        return !(y < x);
    }
    template <class Key, class Compare, class Allocator>
    bool operator>(const set<Key, Compare, Allocator> &x,
                   const set<Key, Compare, Allocator> &y)
    {
        return y < x;
    }
    template <class Key, class Compare, class Allocator>
    bool operator>=(const set<Key, Compare, Allocator> &x,
                    const set<Key, Compare, Allocator> &y)
    {
        return !(x < y);
    }
    template <class Key, class Compare, class Allocator>
    void swap(set<Key, Compare, Allocator> &x,
              set<Key, Compare, Allocator> &y)
    {
        x.swap(y);
    }
}

#endif // SET_HPP
