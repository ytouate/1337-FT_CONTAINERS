/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_s_redBlackTree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:23:36 by ytouate           #+#    #+#             */
/*   Updated: 2023/01/06 18:26:19 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(S_RED_BLACK_TREE)
#define S_RED_BLACK_TREE

#include "../inc.hpp"

namespace ft
{

    template <
        class T,
        class Allocator = std::allocator<T>,
        class Compare = std::less<T> >
    class s_redBlackTree
    {
    public:
        typedef T key_type;
        typedef T value_type;
        typedef Allocator allocator_type;
        typedef t_node<T, allocator_type> node_type;
        typedef size_t size_type;
        typedef map_iterator<T, allocator_type> iterator;
        typedef map_iterator<T, allocator_type> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

        /*
            returns s_redBlackTree::node_type pointer
            which point to the root of the tree;
        */
        node_type *getRoot() const { return this->root; }

        /*
            Default Constructor of The Tree which
            sets the size to 0 and sets the root to poin on NULL
        */
        s_redBlackTree()
        {
            this->_size = 0;
            this->root = NULL;
        }

        /*
            copy constructor which copies the right handside tree object to
            left handside object (this) all the copying is deep copy
        */
        s_redBlackTree(const s_redBlackTree &tree)
        {
            root = deepCopy(tree.root, nullptr);
            this->_size = tree._size;
        }

        /*
            Destructor which deallocate all the Tree and
            sets root to point on NULL;
        */
        ~s_redBlackTree() { this->clear(); }

        /*
            swaps the private attributes of the calling object
            with the private attributes of x
        */
        void swap(s_redBlackTree &x)
        {
            ft::ftSwap(x._size, this->_size);

            ft::ftSwap(this->root, x.root);
        }

        /*
            copy assignment operator which clears the left hand-side object
            before copying the content of rhs to it;
        */
        const s_redBlackTree &operator=(const s_redBlackTree &rhs)
        {
            this->clear();
            root = deepCopy(rhs.root, NULL);
            this->_size = rhs._size;
            return *this;
        }

        /*
            delete the node in the tree which has a data equal to val;
            notice: the tree is balanced and all the violations caused by
            the call to this method are fixed
        */
        void erase(const value_type &val)
        {
            node_type *z = search(val);
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
            _alloc.destroy(z->data);
            _alloc.deallocate(z->data, 1);
            node_allocator.deallocate(z, 1);
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
                if (_comp(*current->data, key))
                    current = current->rightChild;
                else if (*current->data == key)
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

        /*
            insert a node with the data of the node sat to key
            in its right position keeping the tree sorted when
            traversed inOrder
        */
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
                if (_comp(*node->data, *temp->data))
                    temp = temp->leftChild;
                else if (*node->data == *temp->data)
                {
                    _alloc.destroy(node->data);
                    _alloc.deallocate(node->data, 1);
                    node_allocator.deallocate(node, 1);
                    return iterator(temp, this->root);
                }
                else
                    temp = temp->rightChild;
            }
            node->parent = prev;

            if (prev == NULL)
                this->root = node;
            else if (_comp(*node->data, *prev->data))
                prev->leftChild = node;
            else
                prev->rightChild = node;
            fixViolations(node);
            this->_size++;
            return iterator(node, this->root);
        }

        iterator begin() { return iterator(leftMostChild(this->root), this->root); }
        iterator end() { return iterator(NULL, this->root); }
        reverse_iterator rbegin() { return reverse_iterator(end()); }
        reverse_iterator rend() { return reverse_iterator(begin()); }
        const_reverse_iterator rbegin() const { return reverse_iterator(end()); }
        const_reverse_iterator rend() const { return reverse_iterator(begin()); }
        const_iterator begin() const { return iterator(leftMostChild(this->root), this->root); }
        const_iterator end() const { return iterator(NULL, this->root); }

        /*
            returns a boolean indicating whether the tree is empty (the size is 0)
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
                _alloc.destroy(_node->data);
                _alloc.deallocate(_node->data, 1);
                node_allocator.deallocate(_node, 1);
            }
            this->_size = 0;
        }

        /*
            creates a new tree which its content is the same as root
            and returns a pointer to its root;
        */
        node_type *deepCopy(node_type *root, node_type *parent)
        {
            if (!root)
                return NULL;
            node_type *dst = node_allocator.allocate(1);
            dst->color = root->color;
            dst->data = _alloc.allocate(1);
            _alloc.construct(dst->data, *root->data);
            dst->parent = parent;
            dst->leftChild = deepCopy(root->leftChild, dst);
            dst->rightChild = deepCopy(root->rightChild, dst);
            return dst;
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

        /*
            returns the largest element in tree
            which will be the last element printed
            inOrderTraversal
        */
        node_type *rightMostChild(node_type *node)
        {
            if (node == NULL)
                return NULL;
            node_type *_end = node;
            while (_end->rightChild)
                _end = _end->rightChild;
            return _end;
        }

        /*
            returns a pointer to a newly created node
            the allocation is done using the given allocator
        */
        node_type *makeNode(const value_type &key)
        {
            node_type *node = node_allocator.allocate(1);
            node->color = RED;
            node->data = _alloc.allocate(1);
            _alloc.construct(node->data, key);
            node->rightChild = NULL;
            node->leftChild = NULL;
            node->parent = NULL;
            return node;
        }

        /*
            Fix the violations caused by the erase method
        */
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
                    break;
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

        /*
            insert the v node to its right position
            after the node u
        */
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

        /*
            fix the violations caused by the insert method;
        */
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

        /*
            applies left rotation on the given node
        */
        void leftRotate(node_type *x)
        {
            node_type *y = x->rightChild;
            x->rightChild = y->leftChild;
            if (y->leftChild != NULL)
                y->leftChild->parent = x;
            y->parent = x->parent;
            if (x == this->root)
                this->root = y;
            else if (x == x->parent->leftChild)
                x->parent->leftChild = y;
            else
                x->parent->rightChild = y;
            y->leftChild = (x);
            x->parent = y;
        }

        /*
            applies right rotation on the given node
        */
        void rightRotate(node_type *x)
        {
            node_type *y = x->leftChild;
            x->leftChild = y->rightChild;
            if (y->rightChild)
            {
                y->rightChild->parent = x;
            }
            y->parent = x->parent;
            if (x == this->root)
                this->root = y;
            else if (x == x->parent->leftChild)
                x->parent->leftChild = y;
            else
                x->parent->rightChild = y;
            y->rightChild = x;
            x->parent = y;
        }
        typename allocator_type::template rebind<node_type>::other node_allocator;
        node_type *root;
        allocator_type _alloc;
        size_t _size;
        Compare _comp;
    };
};

#endif // S_RED_BLACK_TREE
