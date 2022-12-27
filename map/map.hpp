/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:16:00 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/27 16:26:10 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(MAP_HPP)
#define MAP_HPP

#include "../inc.hpp"

namespace ft
{
    template <class Key,
              class Value,
              class Compare = std::less<Key>,
              class Alloc = std::allocator<ft::pair<Key, Value> > >
    class map
    {

    public:
        typedef Key key_type;
        typedef Value mapped_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef ft::pair<Key, Value> value_type;
        typedef typename Alloc::reference reference;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_reference const_reference;
        typedef typename Alloc::const_pointer const_pointer;
        typedef ft::bidirectional_iterator<t_node<value_type> > iterator;
        typedef ft::r_bidirectional_iterator<iterator> reverse_iterator;

        typedef typename ft::bidirectional_iterator<t_node<value_type> >::difference_type difference_type;
        typedef size_t size_type;

        class value_compare
            : public std::binary_function<value_type, value_type, bool>
        {
            friend class map;

        protected:
            Compare comp;
            value_compare(Compare c) : comp(c) {}

        public:
            bool operator()(const value_type &x, const value_type &y) const
            {
                return comp(x.first, y.first);
            }
        };

        explicit map(const key_compare &comp = key_compare(),
                     const allocator_type &alloc = allocator_type()) : _alloc(alloc), _comp(comp) {}

        template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type())
        {
            while (first != last)
            {
                _tree.insert(*first);
                first++;
            }
            _alloc = alloc;
            _comp = comp;
        }

        map(const map &x) : _tree(x._tree)
        {
            _alloc = x._alloc;
            _comp = x._comp;
        }

        ~map()
        {
            _tree.clear();
        }
        map &operator=(const map &x)
        {
            this->_tree = x._tree;
            this->_alloc = x._alloc;
            this->_comp = x._comp;
        }
        iterator begin()
        {
            return _tree.begin();
        }

        iterator end()
        {
            return _tree.end();
        }

        reverse_iterator rbegin()
        {
            return _tree.rbegin();
        }
        reverse_iterator rend()
        {
            return _tree.rend();
        }
        bool empty() const
        {
            return _tree.size() == 0;
        }
        size_type size() const
        {
            return _tree.size();
        }
        size_type max_size() const
        {
            return std::min<size_type>(this->_alloc.max_size(),
                                       std::numeric_limits<difference_type>::max());
        }

        mapped_type &operator[](const key_type &k)
        {
            t_node<value_type> *tmp = _tree.search(k);
            if (tmp == NULL)
                throw std::invalid_argument("Not found Key");
            return tmp->data.second;
        }

        key_compare key_comp() const
        {
            return _comp;
        }
        value_compare value_comp() const
        {
            return value_compare(_comp);
        }
        size_type count(const key_type& k) const
        {
            return _tree.count(k);
        }
    private:
        redBlackTree<t_node<value_type>, Alloc, key_compare> _tree;
        allocator_type _alloc;
        key_compare _comp;
    };
}

#endif // MAP_HPP
