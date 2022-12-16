/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:53:21 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/16 23:32:48 by ytouate          ###   ########.fr       */
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
        t_node(T &_data)
        {
            this->data = _data;
            this->color = RED;
            this->leftChild = NULL;
            this->rightChild = NULL;
            this->parent = NULL;
            this->isLeftChild = false;
        }
        void print(t_node<T> *_node)
        {
            if (_node == NULL)
                return;
            print(_node->leftChild);
            std::cout << "The Node data is == " << _node->data << " color == " << _node->color << std::endl;
            print(_node->rightChild);
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

        t_node<T> *search(T &_data)
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

        void insert(T &_data)
        {
            t_node<T> *node = new t_node<T>(_data);
            if (this->root == NULL)
            {
                this->root = node;
                this->root->color = BLACK;
                this->_size++;
                return;
            }
            add(this->root, node);
            this->_size++;
        }

    private:
        void add(t_node<T> *_root, t_node<T> *newNode)
        {
            if (newNode->data > _root->data)
            {
                if (_root->rightChild == NULL)
                {
                    _root->rightChild = newNode;
                    newNode->parent = _root;
                    newNode->isLeftChild = false;
                    return;
                }
                return add(_root->rightChild, newNode);
            }
            else if (newNode->data < _root->data)
            {
                if (_root->leftChild == NULL)
                {
                    _root->leftChild = newNode;
                    newNode->parent = _root;
                    newNode->isLeftChild = true;
                    return;
                }
                return add(_root->leftChild, newNode);
            }
        }

        void leftRotate(t_node<T> *&_node);
        void rightRotate(t_node<T> *&_node);
        void leftRightRotate(t_node<T> *&_node);
        void rightLeftRotate(t_node<T> *&_node);
        void fixViolations(t_node<T> *&_node);
        size_t getHeight();
        size_t size();
        
        t_node<T> *root;
        size_t _size;
    };
};

#endif // RED_BLACK_HPP
