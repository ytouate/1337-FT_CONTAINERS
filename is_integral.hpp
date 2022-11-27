/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:00:34 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/26 20:08:22 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IS_INTEGRAL)
#define IS_INTEGRAL

#include <iostream>

namespace ft
{
    template <typename> struct is_integral_base { static const int value = false;};
    template <> struct is_integral_base<int>{ static const int value = true;};
    template <> struct is_integral_base<char>{ static const int value = true;};
    template <> struct is_integral_base<char16_t>{ static const int value = true;};
    template <> struct is_integral_base<wchar_t> { static const int value = true; };
    template <> struct is_integral_base<signed char> { static const int value = true; };
    template <> struct is_integral_base<short int> { static const int value = true; };
    template <> struct is_integral_base<int long> { static const int value = true; };
    template <> struct is_integral_base<long long int> { static const int value = true; };
    template <> struct is_integral_base<unsigned char> { static const int value = true; };
    template <> struct is_integral_base<unsigned short int> { static const int value = true; };
    template <> struct is_integral_base<unsigned int> { static const int value = true;};
    template <> struct is_integral_base<unsigned long int>{ static const int value = true;};
    template <> struct is_integral_base<unsigned long long int>{ static const int value = true;};
    template <> struct is_integral_base<char32_t>{ static const int value = true;};
    template <> struct is_integral_base<bool>{ static const int value = true;};
};

namespace ft
{
    template <class T>
    struct is_integral
    {
        static const bool value = ft::is_integral_base<T>::value;
    };
};

#endif // IS_INTEGRAL
