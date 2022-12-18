/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:53:21 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/18 10:59:27 by ytouate          ###   ########.fr       */
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
        t_node(const T &_data)
        {
            this->data = _data;
            this->color = RED;
            this->leftChild = NULL;
            this->rightChild = NULL;
            this->parent = NULL;
            this->isLeftChild = false;
        }
        bool color;
        bool isLeftChild;
        t_node *leftChild;
        t_node *rightChild;
        t_node *parent;
        T data;
    };

    template <class T>
    class redBlackTree
    {
    public:
        t_node<T> *getTree() const { return this->root; }
        redBlackTree()
        {
            this->_size = 0;
            this->root = NULL;
        }
        redBlackTree(T &_data)
        {
            this->root = new t_node<T>(_data);
        }

        t_node<T> *search(const T &_data)
        {
            t_node<T> *current = this->root;
            while (current != NULL)
            {
                if (current->data < _data)
                    current = current->rightChild;
                else if (current->data > _data)
                    current = current->leftChild;
                else
                    return current;
            }
            return NULL;
        }

        void insert(const T &_data)
        {
            t_node<T> *node = new t_node<T>(_data);
            if (this->root == NULL)
            {
                this->root = node;
                this->root->color = BLACK;
                return;
            }
            t_node<T> *prev = NULL;
            t_node<T> *temp = this->root;
            while (temp != NULL)
            {
                prev = temp;
                if (node->data < temp->data)
                    temp = temp->leftChild;
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

        void debugMessage(const char *s)
        {
            std::cerr << s << "\n";
            exit(1);
        }
        void fixViolations(t_node<T> *z)
        {
            bool isRed;
            while (z->parent && z->parent->color == RED)
            {
                if (z->parent == z->parent->parent->leftChild) // z parent is leftChild;
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
        size_t size() const { return this->_size; }

    private:

        size_t getHeight();

        t_node<T> *root;
        size_t _size;
    };
};

#endif // RED_BLACK_HPP