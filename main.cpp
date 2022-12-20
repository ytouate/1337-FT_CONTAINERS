/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/20 15:28:53 by ytouate          ###   ########.fr       */
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
    // ft::vector<ft::pair<int, int> > vec;
    // std::srand(time(NULL));
    // for (int i = 0; i < 100; i++)
    // {
    //     const int val = std::rand() % 100;
    //     vec.push_back(ft::make_pair<int, int> (val, val + 1));
    // }
    // vec.push_back(ft::make_pair<int, int>(55, 55));
    // ft::map<int, int> map(vec.begin(), vec.end());
    // std::map<int, int> m;
    // inOrderTraversal(map.getTree());
    ft::redBlackTree<ft::pair<int, int> > map;
    map.insert(ft::make_pair<int, int>(10, 20));
    map.insert(ft::make_pair<int, int>(20, 20));
    map.insert(ft::make_pair<int, int>(30, 20));
    map.insert(ft::make_pair<int, int>(40, 20));
    map.insert(ft::make_pair<int, int>(50, 20));

    std::map<int, int> m;
    
    m.insert(std::make_pair<int, int>(10, 20));
    m.insert(std::make_pair<int, int>(20, 20));
    m.insert(std::make_pair<int, int>(30, 20));
    m.insert(std::make_pair<int, int>(40, 20));
    m.insert(std::make_pair<int, int>(50, 20));
    std::map<int, int>::iterator mit = m.begin();
    ft::redBlackTree<ft::pair<int, int> >::iterator it = map.begin();

    std::cout << (*it).data.first << std::endl;
    it++;
    std::cout << (*it).data.first << std::endl;
    it++;
    std::cout << (*it).data.first << std::endl;
    it++;
    std::cout << (*it).data.first << std::endl;

    // inOrderTraversal(map.getTree());
}
