/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/21 19:27:13 by ytouate          ###   ########.fr       */
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
    std::vector<std::pair<std::string, int> > vec;
    vec.push_back(std::make_pair<std::string, int>("DSad", 20));
    vec.push_back(std::make_pair<std::string, int>("aDa", 20));
    vec.push_back(std::make_pair<std::string, int>("3dsa0", 20));

    std::map<std::string, int> theirMap(vec.begin(), vec.end());

    theirMap.clear();
    std::map<std::string, int>::iterator theirIt = theirMap.begin();

    while (theirIt != theirMap.end())
    {
        std::cout << theirIt->first << " ";
        theirIt++;
    }
    std::cout << "\n";
    // Mine
    std::vector<ft::pair<std::string, int> > vecOfPairs;
    vecOfPairs.push_back(ft::make_pair<std::string, int>("DSad", 20));
    vecOfPairs.push_back(ft::make_pair<std::string, int>("aDa", 20));
    vecOfPairs.push_back(ft::make_pair<std::string, int>("3dsa0", 20));

    ft::map<std::string, int> myMap(vecOfPairs.begin(), vecOfPairs.end());
    // myMap.clear();
    myMap.erase("DSad");
    myMap.count("DSad");
    ft::map<std::string, int>::iterator myIt = myMap.begin();

    while (myIt != myMap.end())
    {

        std::cout << myIt->first << " ";
        myIt++;
    }
    std::cout << "\n";

    // myMap.insert(ft::make_pair<int, int>(10, 20));
    // myMap.insert(ft::make_pair<int, int>(20, 20));
    // myMap.insert(ft::make_pair<int, int>(30, 20));

    // inOrderTraversal(map.getTree());
}
