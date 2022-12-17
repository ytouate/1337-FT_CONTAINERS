/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/17 19:09:58 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.hpp"

template <typename T>
void inOrderTraversal(ft::t_node<T> *_node)
{
    if (_node == NULL)
        return ;
    std::string color = _node->color == RED ? "RED" : "BLACK";
    inOrderTraversal(_node->leftChild);
    std::cout << _node->data << " " << color << std::endl;
    inOrderTraversal(_node->rightChild);
}
int main(void)
{

    ft::redBlackTree<int> tree;
    std::srand(time(nullptr));

    for (int i = 0; i < 5; i++)
    {
        int val = std::rand();
        if (tree.search(i) == NULL)
        {
            tree.insert(i);
            tree.insert(-i);
        }
    }
    inOrderTraversal(tree.getTree());
}
