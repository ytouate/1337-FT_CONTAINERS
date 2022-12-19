/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/19 19:32:18 by ytouate          ###   ########.fr       */
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
    std::cout << _node->data.first <<  " " << _node->data.second << " " << "\n";
    inOrderTraversal(_node->rightChild);
}

int main(void)
{
    ft::vector<ft::pair<int, int> > vec;
        std::srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        const int val = std::rand() % 100;
        vec.push_back(ft::make_pair<int, int> (val, val + 1));
    } 
    vec.push_back(ft::make_pair<int, int>(55, 55));
    ft::map<int, int> map(vec.begin(), vec.end());
    inOrderTraversal(map.getTree());
}
