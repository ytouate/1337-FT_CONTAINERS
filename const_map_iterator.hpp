/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_const_map_iterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:51:44 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/04 10:51:47 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class Pair>
    class const_map_iterator
    {

    public:
        typedef t_node<Pair> U;
        typedef U &reference;
        typedef U *pointer;
        typedef U value_type;
        typedef typename U::value_type pair_type;
        typedef std::ptrdiff_t difference_type;
        typedef std::bidirectional_iterator_tag iterator_category;

        const_map_iterator() : current(NULL), root(NULL) {}
        const_map_iterator(const_map_iterator const &obj): current(obj.current), root(obj.root)
        {
        }

        const_map_iterator(pointer ptr, pointer _root) : current(ptr), root(_root)
        {
        }
        const_map_iterator(const t_node<const Pair> *ptr, const t_node<const Pair> * _root)
            : current(ptr), root(_root)
        {

        }
        const_map_iterator &operator=(const_map_iterator const &rhs)
        {
            this->current = rhs.current;
            this->root = rhs.root;
            return *this;
        }
        bool operator==(const const_map_iterator &a)
        {
            return this->current == a.current;
        }
        bool operator!=(const const_map_iterator &a)
        {
            return this->current != a.current;
        }
        typename U::reference operator*(void) const { return *(*current); }
        typename U::pointer operator->()
        {
            return current->operator->();
        }
        const typename U::pointer operator->(void) const
        {
            return current->operator->();
        }
        const_map_iterator operator--(int)
        {
            const_map_iterator temp = *this;
            --(*this);
            return temp;
        }
        inline const_map_iterator operator++(int)
        {
            const_map_iterator temp(*this);
            ++(*this);
            return temp;
        }
        inline const_map_iterator &operator++(void)
        {
            if (this->current->rightChild != NULL)
            {
                this->current = this->current->rightChild;
                this->current = leftMostDescendant(this->current);
            }
            else
            {
                pointer p = this->current->parent;
                while (p != NULL and this->current == p->rightChild)
                {
                    this->current = p;
                    p = p->parent;
                }
                this->current = p;
            }
            return *this;
        }
        inline const_map_iterator &operator--(void)
        {
            if (this->current == NULL)
                this->current = rightMostDescendant(this->root);
            else if (this->current->leftChild)
            {
                this->current = rightMostDescendant(this->current->leftChild);
            }
            else
            {
                while (this->current && this->current->parent->leftChild == this->current)
                    this->current = this->current->parent;
                this->current = this->current->parent;
            }
            return *this;
        }
        ~const_map_iterator() {}

    private:
        pointer leftMostDescendant(pointer node)
        {
            if (node == NULL)
                return NULL;
            while (node->leftChild)
                node = node->leftChild;
            return node;
        }
        pointer rightMostDescendant(pointer node)
        {
            if (node == NULL)
                return NULL;
            while (node->rightChild)
                node = node->rightChild;
            return node;
        }
        pointer current;
        pointer root;
    };