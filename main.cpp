/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:26 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/27 12:54:10 by ytouate          ###   ########.fr       */
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

// std::map<int, int> m;
// m.insert(std::make_pair<int, int>(10, 10));
// m.insert(std::make_pair<int, int>(20, 10));
// m.insert(std::make_pair<int, int>(30, 10));
// m.insert(std::make_pair<int, int>(40, 10));
// m.insert(std::make_pair<int, int>(50, 10));
// m.insert(std::make_pair<int, int>(60, 10));
// m.insert(std::make_pair<int, int>(70, 10));
// m.insert(std::make_pair<int, int>(80, 10));
// m.insert(std::make_pair<int, int>(45, 10));

int main(void)
{
    std::vector<ft::pair<const int, int> > vec;
    // std::vector<std::pair<const int, int> > _vec;
    
    // _vec.push_back(std::make_pair<const int, int>(10, 10));
    // _vec.push_back(std::make_pair<const int, int>(20, 10));
    // _vec.push_back(std::make_pair<const int, int>(30, 10));
    // _vec.push_back(std::make_pair<const int, int>(40, 10));
    // _vec.push_back(std::make_pair<const int, int>(50, 10));
    vec.push_back(ft::make_pair<const int, int>(10, 10));
    vec.push_back(ft::make_pair<const int, int>(20, 10));
    vec.push_back(ft::make_pair<const int, int>(30, 10));
    vec.push_back(ft::make_pair<const int, int>(40, 10));
    vec.push_back(ft::make_pair<const int, int>(50, 10));
    
    ft::map<int, int> map(vec.begin(), vec.end());
    ft::map<int, int>::iterator it = map.begin();
    std::cout << (*it).first << std::endl;
    
}
