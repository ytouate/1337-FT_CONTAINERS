/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:53:21 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/04 19:08:11 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(RED_BLACK_HPP)
#define RED_BLACK_HPP

#include "../pair/pair.hpp"
#include "node.hpp"
#include "map_iterator.hpp"

#include <iostream>
#define RED 0
#define BLACK 1

/*
    Red Black Tree Rules
        - Every node is red or black
        - root is always black
        - new insertions are always red
        - every path from root to leaf has the same number of black nodes
        - no path can have two consecutive red
        - null nodes are considered to be black
    Red Black Tree Rebalnce
        Black Annt  -> Rotate
        Red Annt    -> colorflip
        After Rotation
                black
                 |
                / \
             red   red
        After Color flip
                Red
                 |
                / \
            black black

    lower_bound : returns an iterator pointing to the first element that is not less than key
    upper_bound : returns an iterator pointing to the first element that is greater than key

    predecessor and successor are the neighbors of a certain node

*/
namespace ft
{

    template <
        class T,
        class Allocator = std::allocator<T>,
        class Compare = std::less<typename T::first_type> >
    class redBlackTree
    {
    public:
        typedef typename T::first_type key_type;
        typedef typename T::second_type mapped_type;
        typedef T value_type;
        typedef Allocator allocator_type;
        typedef t_node<T, allocator_type> node_type;
        typedef size_t size_type;
        typedef map_iterator<T, allocator_type> iterator;
        typedef map_iterator<T, allocator_type> const_iterator;
        node_type *getRoot() const { return this->root; }

        /*
            Default Constructor of The Tree which
            sets the size to 0 and sets the root to poin on NULL
        */
        redBlackTree()
        {
            this->_size = 0;
            this->root = NULL;
        }

        /*
            copy constructor which copies the right handside tree object to
            left handside object (this) all the copy coping is deep copy
        */
        redBlackTree(const redBlackTree &tree)
        {
            root = deepCopy(tree.root, nullptr);
            this->_size = tree._size;
        }

        /*
            Destructor which deallocate all the Tree and
            sets root to point on NULL;
        */
        ~redBlackTree()
        {
            this->clear();
            _size = 0;
        }
        void swap(redBlackTree &x)
        {
            redBlackTree tmp(*this);
            *this = x;
            x = tmp;
        }
        
        const redBlackTree &operator=(const redBlackTree &rhs)
        {
            this->clear();
            root = deepCopy(rhs.root, NULL);
            this->_size = rhs._size;
            return *this;
        }

        void erase(const value_type &val)
        {
            node_type *z = search(val.first);
            if (z == NULL)
                return;
            node_type *y = z;
            node_type *x = NULL;
            bool y_original_color = y == NULL ? BLACK : y->color;
            if (z->leftChild == NULL)
            {
                x = z->rightChild;
                transplant(z, z->rightChild);
            }
            else if (z->rightChild == NULL)
            {
                x = z->leftChild;
                transplant(z, z->leftChild);
            }
            else
            {
                y = leftMostChild(z->rightChild);
                y_original_color = y == NULL ? BLACK : y->color;
                x = y->rightChild;
                if (y->parent == z)
                {
                    if (x)
                        x->parent = y;
                }
                else
                {
                    transplant(y, y->rightChild);
                    y->rightChild = z->rightChild;
                    y->rightChild->parent = y;
                }
                transplant(z, y);
                y->leftChild = z->leftChild;
                y->leftChild->parent = y;
                y->color = z->color;
            }
            delete z;
            if (y_original_color == BLACK)
            {
                deleteFixUP(x);
            }
            this->_size--;
        }

        /*
            search method which look for the given key in the tree
            if the element is found it returns a pointer to the node containing the element
            else it returns NULL to indicate that the element not found;
        */
        node_type *search(const key_type &key) const
        {
            node_type *current = this->root;
            while (current != NULL)
            {
                if (_comp(current->data.first, key))
                    current = current->rightChild;
                else if (current->data.first == key)
                    return current;
                else
                    current = current->leftChild;
            }
            return NULL;
        }

        /*
            searches the tree for element with key equivalent to k and
            returns the number of matches since the tree cannot have duplicated key
            the return value will always be one or zero
        */
        size_type count(const key_type &k) const
        {
            return search(k) == NULL ? 0 : 1;
        }

        iterator insert(const value_type &key)
        {
            node_type *node = makeNode(key);
            if (this->root == NULL)
            {
                this->root = node;
                this->root->color = BLACK;
                this->_size++;
                return iterator(this->root, this->root);
            }
            node_type *prev = NULL;
            node_type *temp = this->root;
            while (temp != NULL)
            {
                prev = temp;
                if (_comp(node->data.first, temp->data.first))
                    temp = temp->leftChild;
                else if (node->data == temp->data)
                {
                    delete node;
                    return iterator(temp, this->root);
                }
                else
                    temp = temp->rightChild;
            }
            node->parent = prev;
            if (prev == NULL)
                this->root = node;
            else if (_comp(node->data.first, prev->data.first))
                prev->leftChild = node;
            else
                prev->rightChild = node;
            fixViolations(node);
            this->_size++;
            return iterator(node, this->root);
        }

        iterator begin()
        {
            return iterator(leftMostChild(this->root), this->root);
        }

        iterator end()
        {
            return iterator(NULL, this->root);
        }
        iterator begin() const
        {
            return iterator(leftMostChild(this->root), this->root);
        }

        iterator end() const
        {
            return iterator(NULL, this->root);
        }
        /*
            returns whether the tree is empty (the size is 0)
        */
        bool empty() const
        {
            return this->_size == 0;
        }

        /*
            returns the Number of nodes in the Tree
        */
        size_t size() const { return this->_size; }

        /*
            deletes all the nodes of the tree and sets
            the size of it to 0
        */
        void clear()
        {
            clearTree(this->root);
            this->_size = 0;
            this->root = NULL;
        }

    private:
        /*
            loops throw the entire tree and calls delete on every node and set NULL to it;
        */
        void clearTree(node_type *_node)
        {
            if ((_node) != NULL)
            {
                clearTree((_node)->leftChild);
                clearTree((_node)->rightChild);
                delete (_node);
            }
            this->_size = 0;
        }
        node_type *deepCopy(node_type *root, node_type *parent)
        {
            if (!root)
                return NULL;
            node_type *newRoot = new node_type;
            newRoot->color = root->color;
            newRoot->data = root->data;
            newRoot->parent = parent;
            newRoot->leftChild = deepCopy(root->leftChild, newRoot);
            newRoot->rightChild = deepCopy(root->rightChild, newRoot);
            return newRoot;
        }
        /*
            finds the first node that will be printed if we used
            In Order Traversal on the treee
        */
        node_type *leftMostChild(node_type *_node) const
        {
            if (_node == NULL)
                return NULL;
            node_type *_begin = _node;
            while (_begin->leftChild)
                _begin = _begin->leftChild;
            return _begin;
        }

        node_type *rightMostChild(node_type *node)
        {
            if (node == NULL)
                return NULL;
            node_type *_end = node;
            while (_end->rightChild)
                _end = _end->rightChild;
            return _end;
        }

        node_type *makeNode(const value_type &key) const
        {
            node_type *_new = new node_type();
            _new->color = RED;
            _new->data = key;
            _new->rightChild = NULL;
            _new->leftChild = NULL;
            _new->parent = NULL;
            return _new;
        }

        void deleteFixUP(node_type *x)
        {
            node_type *w = NULL;
            while (x and x != this->root and x->color == BLACK)
            {
                if (x == x->parent->leftChild)
                {
                    w = x->parent->rightChild;
                    if (w->color == RED)
                    {
                        w->color = BLACK;
                        x->parent->color = RED;
                        leftRotate(x->parent);
                        w = x->parent->rightChild;
                    }
                    if ((w->leftChild == NULL or w->leftChild->color == BLACK) and
                        (w->rightChild == NULL or w->rightChild->color == BLACK))
                    {
                        w->color = RED;
                        x = x->parent;
                    }
                    else
                    {
                        if (w->rightChild or w->rightChild->color == BLACK)
                        {
                            if (w->leftChild)
                                w->leftChild->color = BLACK;
                            w->color = RED;
                            rightRotate(w);
                            w = x->parent->rightChild;
                        }
                        w->color = x->parent->color;
                        x->parent->color = BLACK;
                        if (w->rightChild)
                            w->rightChild->color = BLACK;
                        leftRotate(x->parent);
                        x = this->root;
                    }
                }
                else
                {
                    w = x->parent->leftChild;
                    if (w and w->color == RED)
                    {
                        w->color = BLACK;
                        x->parent->color = RED;
                        leftRotate(x->parent);
                        w = x->parent->leftChild;
                    }
                    if ((w->rightChild == NULL or w->rightChild->color == BLACK) and
                        (w->leftChild == NULL or w->leftChild->color == BLACK))
                    {
                        w->color = RED;
                        x = x->parent;
                    }
                    else
                    {
                        if (w->leftChild->color == BLACK)
                        {
                            w->rightChild->color = BLACK;
                            w->color = RED;
                            rightRotate(w);
                            w = x->parent->leftChild;
                        }
                        w->color = x->parent->color;
                        x->parent->color = BLACK;
                        w->leftChild->color = BLACK;
                        leftRotate(x->parent);
                        x = this->root;
                    }
                }
            }
            if (x != NULL)
                x->color = BLACK;
        }

        void transplant(node_type *u, node_type *v)
        {
            if (u->parent == NULL)
                this->root = v;
            else if (u == u->parent->leftChild)
                u->parent->leftChild = v;
            else
                u->parent->rightChild = v;
            if (v == NULL)
                u->parent = NULL;
            else
                v->parent = u->parent;
        }

        void fixViolations(node_type *z)
        {
            bool isRed;
            while (z->parent && z->parent->color == RED)
            {
                if (z->parent == z->parent->parent->leftChild)
                {
                    node_type *y = z->parent->parent->rightChild;
                    isRed = y != NULL and y->color == RED;
                    if (isRed)
                    {
                        z->parent->color = BLACK;
                        y->color = BLACK;
                        z->parent->parent->color = RED;
                        z = z->parent->parent;
                    }
                    else
                    {

                        if (z == z->parent->rightChild)
                        {
                            z = z->parent;
                            leftRotate(z);
                        }
                        z->parent->color = BLACK;
                        z->parent->parent->color = RED;
                        rightRotate(z->parent->parent);
                    }
                }
                else
                {
                    node_type *y = z->parent->parent->leftChild;
                    isRed = y != NULL && y->color == RED;
                    if (isRed)
                    {
                        z->parent->color = BLACK;
                        y->color = BLACK;
                        z->parent->parent->color = RED;
                        z = z->parent->parent;
                    }
                    else
                    {
                        if (z == z->parent->leftChild)
                        {
                            z = z->parent;
                            rightRotate(z);
                        }
                        z->parent->color = BLACK;
                        z->parent->parent->color = RED;
                        leftRotate(z->parent->parent);
                    }
                }
            }
            this->root->color = BLACK;
        }

        void leftRotate(node_type *x)
        {
            node_type *y = (x)->rightChild;
            (x)->rightChild = y->leftChild;
            if (y->leftChild != NULL)
            {
                y->leftChild->parent = (x);
            }
            y->parent = (x)->parent;
            if ((x)->parent == NULL)
                this->root = y;
            else if ((x) == (x)->parent->leftChild)
                (x)->parent->leftChild = y;
            else
                (x)->parent->rightChild = y;
            y->leftChild = (x);
            (x)->parent = y;
        }

        void rightRotate(node_type *x)
        {
            node_type *y = (x)->leftChild;
            (x)->leftChild = y->rightChild;
            if (y->rightChild)
            {
                y->rightChild->parent = (x);
            }
            y->parent = (x)->parent;
            if ((x)->parent == NULL)
                this->root = y;
            else if ((x) == (x)->parent->leftChild)
                (x)->parent->leftChild = y;
            else
                (x)->parent->rightChild = y;
            y->rightChild = (x);
            (x)->parent = y;
        }

        node_type *root;
        allocator_type _alloc;
        size_t _size;
        Compare _comp;
    };
};

#endif // RED_BLACK_HPP