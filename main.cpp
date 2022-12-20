/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/20 16:39:35 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.hpp"
#include <map>

template <typename T>
void inOrderTraversal(ft::t_node<T> *_node)
{
    if (_node == NULL)
    {
        return;
    }
    std::string color = _node->color == RED ? "RED" : "BLACK";
    inOrderTraversal(_node->leftChild);
    std::cout << _node->data.first << " " << _node->data.second << " "
              << "\n";
    inOrderTraversal(_node->rightChild);
}

int main(void)
{
    std::map<int, int> theirMap;

    theirMap.insert(std::make_pair<int, int>(10, 20));
    theirMap.insert(std::make_pair<int, int>(20, 20));
    theirMap.insert(std::make_pair<int, int>(30, 20));

    std::map<int, int>::iterator theirIt = theirMap.begin();

    // std::cout << theirIt-> << std::endl;
    // Mine
    std::vector<ft::pair<int, int> > vecOfPairs;
    vecOfPairs.push_back(ft::make_pair<int, int>(10, 20));
    vecOfPairs.push_back(ft::make_pair<int, int>(20, 20));
    vecOfPairs.push_back(ft::make_pair<int, int>(30, 20));
    
    // ft::map<int, int> myMap(vecOfPairs.begin(), vecOfPairs.end());
    ft::map<int, int> myMap;
    ft::map<int, int>::iterator myIt = myMap.begin();
    while (myIt != myMap.end())
    {
        std::cout << "am here\n";
        std::cout << (*myIt).first << std::endl;
        myIt++;

    }

    // myMap.insert(ft::make_pair<int, int>(10, 20));
    // myMap.insert(ft::make_pair<int, int>(20, 20));
    // myMap.insert(ft::make_pair<int, int>(30, 20));

    // inOrderTraversal(map.getTree());
}
