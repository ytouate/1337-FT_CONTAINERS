/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:35:09 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/09 19:56:19 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(REVERSE_ITERATOR_HPP)
#define REVERSE_ITERATOR_HPP

// #include "iterator.hpp"

// template <class T>
// class reverse_iterator
// {
// public:
//     typedef std::random_access_iterator_tag iterator_category;
//     typedef ptrdiff_t difference_type;
//     typedef T &reference;
//     typedef T *pointer;
//     typedef T value_type;

//     reference operator
// private:
//     T *_ptr;
// }

template <class Iterator>
class reverse_iterator;

template <class Iterator>
bool operator==(
    const reverse_iterator<Iterator> &x,
    const reverse_iterator<Iterator> &y);

template <class Iterator>
bool operator<(
    const reverse_iterator<Iterator> &x,
    const reverse_iterator<Iterator> &y);

template <class Iterator>
bool operator!=(
    const reverse_iterator<Iterator> &x,
    const reverse_iterator<Iterator> &y);

template <class Iterator>
bool operator>(
    const reverse_iterator<Iterator> &x,
    const reverse_iterator<Iterator> &y);

template <class Iterator>
bool operator>=(
    const reverse_iterator<Iterator> &x,
    const reverse_iterator<Iterator> &y);

template <class Iterator>
bool operator<=(
    const reverse_iterator<Iterator> &x,
    const reverse_iterator<Iterator> &y);

template <class Iterator>
typename reverse_iterator<Iterator>::difference_type operator-(
    const reverse_iterator<Iterator> &x,
    const reverse_iterator<Iterator> &y);

template <class Iterator>
reverse_iterator<Iterator>
operator+(
    typename reverse_iterator<Iterator>::difference_type n,
    const reverse_iterator<Iterator> &x);

template <class Container>
class back_insert_iterator;
template <class Container>
back_insert_iterator<Container> back_inserter(Container &x);

template <class Container>
class front_insert_iterator;
template <class Container>
front_insert_iterator<Container> front_inserter(Container &x);

template <class Container>
class insert_iterator;
template <class Container, class Iterator>
insert_iterator<Container> inserter(Container &x, Iterator i);

#endif // REVERSE_ITERATOR_HPP
