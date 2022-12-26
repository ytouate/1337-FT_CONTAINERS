/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/26 14:19:09 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.hpp"
#include <map>

template <typename T>
void inOrderTraversal(ft::t_node<T> *_node)
{
    if (_node == NULL)
        return;
    std::string color = _node->color == RED ? "RED" : "BLACK";
    inOrderTraversal(_node->leftChild);
    std::cout << _node->data << " " << color << " "
              << "\n";
    inOrderTraversal(_node->rightChild);
}
ft::t_node<int> *leftMostDescendant(ft::t_node<int> *node)
{
    while (node->leftChild)
        node = node->leftChild;
    return node;
}
ft::t_node<int> *rightMostDescendant(ft::t_node<int> *node)
{
    while (node->rightChild)
        node = node->rightChild;
    return node;
}
template <class T>
ft::t_node<T> *next(ft::t_node<T> *current)
{
    if (current->rightChild)
    {
        return leftMostDescendant(current->rightChild);
    }
    else
    {
        while (current->parent != NULL &&
               current->parent->rightChild == current)
        {
            current = current->parent;
        }
        return current->parent;
    }
}

int main(void)
{
    ft::redBlackTree<int, int, std::allocator<int> > tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);
    tree.insert(70);
    tree.insert(80);
    tree.insert(45);

    ft::redBlackTree<int, int, std::allocator<int> >::iterator it = tree.begin();

    // ft::t_node<int> *root = tree.getTree();
    while (it.hasNext())
    {
        std::cout << it->data << std::endl;
        it = it.next();
    }
    // std::cout << it.next()->data << std::endl;
    // std::cout << it.next().next()->data << std::endl;
    // std::cout << it.next().next().next()->data << std::endl;
}
