/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:53:21 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/21 19:19:46 by ytouate          ###   ########.fr       */
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
        bool color;
        t_node *leftChild;
        t_node *rightChild;
        t_node *parent;
        T data;
    };

    template <
                class T, class _key, class mapped_type,
                class Compare = std::less<_key>,
                class Allocator = std::allocator< t_node<T> >
             >
    class redBlackTree
    {
    public:
        typedef bidirectional_iterator<t_node<T> > iterator;

        t_node<T> *getTree() const { return this->root; }

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
            this->root = cloneNode(tree.root);
            copyTree(tree.root, this->root);
            this->_alloc = tree._alloc;
            this->_size = tree._size;
        }

        /*
            Destructor which deallocate all the Tree and sets root to point on NULL;
        */
        ~redBlackTree()
        {
            if (_size == 0)
                this->root = NULL;
            else
            {
                clearTree(this->root);
            }
            _size = 0;
        }

        /*
            copy assignment operator which the following operations are done sequentially
                - check for self assignment ;
                - clear the tree of (this ) object { the object who called the operator }
                - clone the root of right handside object to this->root;
                - clone the other node of rightHandside object into the calling object;
                - set the size of the calling object to be equal to rhs.size;
                - copy the allocator of rhs to calling object
                - return a const_reference to the calling object
        */
        const redBlackTree &operator=(const redBlackTree &rhs)
        {
            if (this == &rhs)
                return *this;
            clearTree(this->root);

            this->root = cloneNode(rhs.root);
            copyTree(rhs.root, this->root);
            this->_alloc = rhs._alloc;
            this->_size = rhs._size;
            return *this;
        }

        void erase(const T &key)
        {
            t_node<T> *z = search(key);
            if (z == NULL)
                return;
            t_node<T> *y = z;
            t_node<T> *x = NULL;
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
                y = minimum(z->rightChild);
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
            this->_alloc.destroy(z);
            if (y_original_color == BLACK)
            {
                deleteFixUP(x);
            }
        }

        /*
            search method which look for the given key in the tree
            if the element is found it returns a pointer to the node containing the element
            else it returns NULL to indicate that the element not found;
        */
        t_node<T> *search(const T &key)
        {
            t_node<T> *current = this->root;
            while (current != NULL)
            {
                if (current->data.first < key)
                    current = current->rightChild;
                else if (current->data.first > key)
                    current = current->leftChild;
                else
                    return current;
            }
            return NULL;
        }

        void insert(const T &key)
        {
            t_node<T> *node = makeNode(key);
            if (this->root == NULL)
            {
                this->root = node;
                this->root->color = BLACK;
                this->_size++;
                return;
            }
            t_node<T> *prev = NULL;
            t_node<T> *temp = this->root;
            while (temp != NULL)
            {
                prev = temp;
                if (node->data.first < temp->data.first)
                    temp = temp->leftChild;
                else if (node->data.first == temp->data.first)
                {
                    this->_alloc.destroy(node);
                    return;
                }
                else
                    temp = temp->rightChild;
            }
            node->parent = prev;
            if (prev == NULL)
                this->root = node;
            else if (node->data.first < prev->data.first)
                prev->leftChild = node;
            else
                prev->rightChild = node;
            fixViolations(node);
            this->_size++;
        }

        /*
            returns the Number of nodes in the Tree
        */
        size_t size() const { return this->_size; }
        t_node<T> *findBegin()
        {
            if (this->root == NULL or this->_size == 0)
                return NULL;
            while (this->root->leftChild)
                this->root = this->root->leftChild;
            return this->root;
        }
        t_node<T> *findEnd()
        {
            if (this->root == NULL or this->_size == 0)
                return NULL;
            while (this->root->rightChild)
                this->root = this->root->rightChild;
            return this->root->rightChild;
        }

    private:
        t_node<T> *cloneNode(t_node<T> *_node)
        {
            if (_node != NULL)
            {
                t_node<T> *_newNode = this->_alloc.allocate(1);
                _newNode->color = _node->color;
                _newNode->data = _node->data;
                _newNode->leftChild = _node->leftChild;
                _newNode->rightChild = _node->rightChild;
                _newNode->parent = _node->parent;
                return _newNode;
            }
            return NULL;
        }

        void copyTree(t_node<T> *org, t_node<T> *copy)
        {
            if (org != NULL)
            {
                t_node<T> *newLeftNode = cloneNode(org->leftChild);
                if (copy->leftChild != NULL)
                    this->_alloc.destroy(copy->leftChild);
                copy->leftChild = newLeftNode;
                copyTree(org->leftChild, copy->leftChild);

                t_node<T> *newRightNode = cloneNode(org->rightChild);
                if (copy->rightChild != NULL)
                    this->_alloc.destroy(copy->rightChild);
                copy->rightChild = newRightNode;
                copyTree(org->rightChild, copy->rightChild);
            }
        }
        public:
        void clearTree(t_node<T> *_node)
        {
            if (_node != NULL)
            {
                clearTree(_node->leftChild);
                delete _node;
                // this->_alloc.deallocate(_node, 1);
                clearTree(_node->rightChild);
            }
            _node = NULL;
            this->_size = 0;
        }
        private:
        t_node<T> *makeNode(const T &key)
        {
            t_node<T> *_new = this->_alloc.allocate(1);
            _new->color = RED;
            _new->data = key;
            _new->rightChild = NULL;
            _new->leftChild = NULL;
            _new->parent = NULL;
            return _new;
        }

        void deleteFixUP(t_node<T> *x)
        {
            t_node<T> *w = NULL;
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

        void transplant(t_node<T> *u, t_node<T> *v)
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

        t_node<T> *minimum(t_node<T> *node)
        {
            while (node->leftChild != NULL)
                node = node->leftChild;
            return node;
        }

        void fixViolations(t_node<T> *z)
        {
            bool isRed;
            while (z->parent && z->parent->color == RED)
            {
                if (z->parent == z->parent->parent->leftChild)
                {
                    t_node<T> *y = z->parent->parent->rightChild;
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
                    t_node<T> *y = z->parent->parent->leftChild;
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

        void leftRotate(t_node<T> *x)
        {
            t_node<T> *y = (x)->rightChild;
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

        void rightRotate(t_node<T> *x)
        {
            t_node<T> *y = (x)->leftChild;
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

        t_node<T> *root;
        Allocator _alloc;
        size_t _size;
    };
};

#endif // RED_BLACK_HPP