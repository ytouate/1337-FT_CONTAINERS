/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/23 19:18:41 by ytouate          ###   ########.fr       */
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
    std::cout << _node->data << " " << _node->data << " "
              << "\n";
    inOrderTraversal(_node->rightChild);
}

int main(void)
{
    ft::redBlackTree<int, int, std::allocator<int> > tree;
    tree.insert(10);
    tree.insert(20);
    std::cout << tree.count(20) << std::endl;
    tree.insert(30);

    ft::redBlackTree<int, int, std::allocator<int> > b(tree);
    inOrderTraversal(tree.getTree());
    std::cout << "\n";
    inOrderTraversal(tree.getTree());
}
