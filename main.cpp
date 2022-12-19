/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/19 13:37:51 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.hpp"
#include <map>

template <typename T>
void inOrderTraversal(ft::t_node<T> *_node)
{
    
    if (_node == NULL)
    {
        return ;
    }
    std::string color = _node->color == RED ? "RED" : "BLACK";
    inOrderTraversal(_node->leftChild);
    std::cout << _node->data << " " << color << "\n";
    inOrderTraversal(_node->rightChild);
}

int main(void)
{
    ft::redBlackTree<int> a;
    a.insert(10);
    a.insert(20);

    a.insert(30);
    a.insert(40);

    a.insert(50);
    a.insert(-421);
    // a.insert(10);
    a.insert(70);
    a.insert(110);
    a.insert(80);
    a.insert(-13);
    a.insert(90);
    a.insert(-43);
    
    a.erase(-42);
    inOrderTraversal(a.getTree());
    std::cout << "\n";
    ft::redBlackTree<int> b(a);
    inOrderTraversal(b.getTree());

    // system("leaks CONTAINERS.out");
}
