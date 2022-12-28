/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:53:21 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/28 16:20:22 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(RED_BLACK_HPP)
#define RED_BLACK_HPP

#include "../inc.hpp"
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
    template <class T>
    struct t_node
    {
        typedef T value_type;
        typedef T &reference;
        typedef const T &const_reference;
        typedef T *pointer;

        reference operator*()
        {
            return data;
        }
        pointer operator->()
        {
            return &data;
        }

        bool color;
        t_node *leftChild;
        t_node *rightChild;
        t_node *parent;
        T data;
    };

    template <
        class Key,
        class Allocator = std::allocator<Key>,
        class Compare = std::less<Key> >
    class redBlackTree
    {
    public:
        typedef Key value_type;
        typedef typename Allocator::value_type pair_type;
        typedef typename pair_type::first_type _key;
        typedef typename pair_type::second_type _value;
        typedef bidirectional_iterator<value_type> iterator;
        typedef r_bidirectional_iterator<iterator> reverse_iterator;
        typedef typename Allocator::size_type size_type;
        value_type *getTree() const { return this->root; }

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
            copyTree(tree.root, &this->root);
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

        const redBlackTree &operator=(const redBlackTree &rhs)
        {
            this->clear();
            copyTree(rhs.root, &this->root);
            this->_size = rhs._size;
            return *this;
        }

        // void erase(const T &key)
        // {
        //     value_type *z = search(key);
        //     if (z == NULL)
        //         return;
        //     value_type *y = z;
        //     value_type *x = NULL;
        //     bool y_original_color = y == NULL ? BLACK : y->color;
        //     if (z->leftChild == NULL)
        //     {
        //         x = z->rightChild;
        //         transplant(z, z->rightChild);
        //     }
        //     else if (z->rightChild == NULL)
        //     {
        //         x = z->leftChild;
        //         transplant(z, z->leftChild);
        //     }
        //     else
        //     {
        //         y = leftMostChild(z->rightChild);
        //         y_original_color = y == NULL ? BLACK : y->color;
        //         x = y->rightChild;
        //         if (y->parent == z)
        //         {
        //             if (x)
        //                 x->parent = y;
        //         }
        //         else
        //         {
        //             transplant(y, y->rightChild);
        //             y->rightChild = z->rightChild;
        //             y->rightChild->parent = y;
        //         }
        //         transplant(z, y);
        //         y->leftChild = z->leftChild;
        //         y->leftChild->parent = y;
        //         y->color = z->color;
        //     }
        //     delete z;
        //     if (y_original_color == BLACK)
        //     {
        //         deleteFixUP(x);
        //     }
        // }

        /*
            search method which look for the given key in the tree
            if the element is found it returns a pointer to the node containing the element
            else it returns NULL to indicate that the element not found;
        */
        value_type *search(const _key &key) const
        {
            value_type *current = this->root;
            while (current != NULL)
            {
                // current->data < key
                if (_comp(current->data.first, key))
                    current = current->rightChild;
                else if (current->data.first > key)
                    current = current->leftChild;
                else
                    return current;
            }
            return NULL;
        }

        /*
            searches the tree for element with key equivalent to k and
            returns the number of matches since the tree cannot have duplicated key
            the return value will always be one or zero
        */
        size_type count(const _key &k) const
        {
            return search(k) == NULL ? 0 : 1;
        }

        void insert(const pair_type &key)
        {
            value_type *node = makeNode(key);
            if (this->root == NULL)
            {
                this->root = node;
                this->root->color = BLACK;
                this->_size++;
                return;
            }
            value_type *prev = NULL;
            value_type *temp = this->root;
            while (temp != NULL)
            {
                prev = temp;
                if (node->data < temp->data)
                    temp = temp->leftChild;
                else if (node->data == temp->data)
                {
                    delete node;
                    return;
                }
                else
                    temp = temp->rightChild;
            }
            node->parent = prev;
            if (prev == NULL)
                this->root = node;
            else if (node->data < prev->data)
                prev->leftChild = node;
            else
                prev->rightChild = node;
            fixViolations(node);
            this->_size++;
        }

        iterator begin()
        {
            return iterator(leftMostChild());
        }

        iterator end()
        {
            return iterator(NULL);
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(iterator(rightMostChild()));
        }
        reverse_iterator rend()
        {
            return reverse_iterator(iterator(NULL));
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
        /*
            loops throw the entire tree and calls delete on every node and set NULL to it;
        */
        void clearTree(value_type *_node)
        {
            if ((_node) != NULL)
            {
                clearTree((_node)->leftChild);
                delete (_node);
                clearTree((_node)->rightChild);
            }
            this->_size = 0;
        }

    private:
        /*
            finds the first node that will be printed if we used
            In Order Traversal on the treee
        */
        value_type *leftMostChild() const
        {
            if (this->root == NULL)
                return NULL;
            value_type *_begin = this->root;
            while (_begin->leftChild)
                _begin = _begin->leftChild;
            return _begin;
        }

        value_type *rightMostChild()
        {
            if (this->root == NULL)
                return NULL;
            value_type *_end = this->root;
            while (_end->rightChild)
                _end = _end->rightChild;
            return _end;
        }

        void copyTree(value_type *src, value_type **dst)
        {
            if (src == NULL)
                (*dst) = NULL;
            else
            {
                (*dst) = new value_type;
                (*dst)->data = src->data;
                (*dst)->color = src->color;
                (*dst)->parent = src->parent;
                copyTree(src->leftChild, &(*dst)->leftChild);
                copyTree(src->rightChild, &(*dst)->rightChild);
            }
        }

        value_type *makeNode(const pair_type &key)
        {
            value_type *_new = new value_type;
            _new->color = RED;
            _new->data = key;
            _new->rightChild = NULL;
            _new->leftChild = NULL;
            _new->parent = NULL;
            return _new;
        }

        void deleteFixUP(value_type *x)
        {
            value_type *w = NULL;
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
                    if (w->leftChild->color == BLACK and w->rightChild->color == BLACK)
                    {
                        w->color = RED;
                        x = x->parent;
                    }
                    else
                    {

                        if (w->rightChild->color == BLACK)
                        {
                            w->leftChild->color = BLACK;
                            w->color = RED;
                            rightRotate(w);
                            w = x->parent->rightChild;
                        }
                        w->color = x->parent->color;
                        x->parent->color = BLACK;
                        w->rightChild->color = BLACK;
                        leftRotate(x->parent);
                        x = this->root;
                    }
                }
                else
                {
                    w = x->parent->leftChild;
                    if (w->color == RED)
                    {
                        w->color = BLACK;
                        x->parent->color = RED;
                        leftRotate(x->parent);
                        w = x->parent->leftChild;
                    }
                    if (w->rightChild->color == BLACK and w->leftChild->color == BLACK)
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

        void transplant(value_type *u, value_type *v)
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

        void fixViolations(value_type *z)
        {
            bool isRed;
            while (z->parent && z->parent->color == RED)
            {
                if (z->parent == z->parent->parent->leftChild)
                {
                    value_type *y = z->parent->parent->rightChild;
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
                    value_type *y = z->parent->parent->leftChild;
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

        void leftRotate(value_type *x)
        {
            value_type *y = (x)->rightChild;
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

        void rightRotate(value_type *x)
        {
            value_type *y = (x)->leftChild;
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

        value_type *root;
        Allocator _alloc;
        size_t _size;
        Compare _comp;
    };
};

#endif // RED_BLACK_HPP