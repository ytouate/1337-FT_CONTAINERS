/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/22 13:00:27 by ytouate          ###   ########.fr       */
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
    std::vector<std::pair<int, int> > vec;
    vec.push_back(std::make_pair<int, int>(1, 20));
    vec.push_back(std::make_pair<int, int>(2, 20));
    vec.push_back(std::make_pair<int, int>(3, 20));

    std::map<int, int> theirMap(vec.begin(), vec.end());

    std::map<int, int>::iterator theirIt = theirMap.begin();


    theirIt++;
    // --theirIt;
    //std::cout << theirIt->first << std::endl;
    // Mine
    std::vector<ft::pair<int, int> > vecOfPairs;
    vecOfPairs.push_back(ft::make_pair<int, int>(1, 20));
    vecOfPairs.push_back(ft::make_pair<int, int>(2, 20));
    vecOfPairs.push_back(ft::make_pair<int, int>(3, 20));

    ft::map<int, int> myMap(vecOfPairs.begin(), vecOfPairs.end());
    ft::map<int, int>::iterator myIt = myMap.begin();

    ++myIt;
    if (myIt == NULL)
        
    return 0;
    // --myIt;
    std::cout << myIt->first << " ";
    std::cout << "\n" << std::flush;
}
