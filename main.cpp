/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/19 16:44:59 by ytouate          ###   ########.fr       */
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
    // ft::vector<ft::pair<int, int> > vec;
    // vec.push_back(ft::make_pair<int, int> (10, 20));
    // ft::map<int, int> map(vec.begin(), vec.end());
    // inOrderTraversal();
    ft::vector<int> vec;
    vec.push_back(10);
    ft::vector<int>::iterator it = vec.begin();
    return it[0];
    system("leaks CONTAINERS.out");
}
