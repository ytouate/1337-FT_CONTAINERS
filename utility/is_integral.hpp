/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:00:34 by ytouate           #+#    #+#             */
/*   Updated: 2022/12/02 19:52:22 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IS_INTEGRAL)
#define IS_INTEGRAL

#include "../inc.hpp"

namespace ft
{
    template <typename> struct is_integral_base { static const int value = false;};
    template <> struct is_integral_base<const int>{ static const int value = true;};
    template <> struct is_integral_base<const char>{ static const int value = true;};
    template <> struct is_integral_base<const wchar_t> { static const int value = true; };
    template <> struct is_integral_base<const signed char> { static const int value = true; };
    template <> struct is_integral_base<const short int> { static const int value = true; };
    template <> struct is_integral_base<const int long> { static const int value = true; };
    template <> struct is_integral_base<const long long int> { static const int value = true; };
    template <> struct is_integral_base<const unsigned char> { static const int value = true; };
    template <> struct is_integral_base<const unsigned short int> { static const int value = true; };
    template <> struct is_integral_base<const unsigned int> { static const int value = true;};
    template <> struct is_integral_base<const unsigned long int>{ static const int value = true;};
    template <> struct is_integral_base<const unsigned long long int>{ static const int value = true;};
    template <> struct is_integral_base<const bool>{ static const int value = true;};
    
    template <> struct is_integral_base<int>{ static const int value = true;};
    template <> struct is_integral_base< char>{ static const int value = true;};
    template <> struct is_integral_base< wchar_t> { static const int value = true; };
    template <> struct is_integral_base< signed char> { static const int value = true; };
    template <> struct is_integral_base< short int> { static const int value = true; };
    template <> struct is_integral_base< int long> { static const int value = true; };
    template <> struct is_integral_base< long long int> { static const int value = true; };
    template <> struct is_integral_base< unsigned char> { static const int value = true; };
    template <> struct is_integral_base< unsigned short int> { static const int value = true; };
    template <> struct is_integral_base< unsigned int> { static const int value = true;};
    template <> struct is_integral_base< unsigned long int>{ static const int value = true;};
    template <> struct is_integral_base< unsigned long long int>{ static const int value = true;};
    template <> struct is_integral_base< bool>{ static const int value = true;};
    
    template <> struct is_integral_base<const volatile int>{ static const int value = true;};
    template <> struct is_integral_base<const volatile char>{ static const int value = true;};
    template <> struct is_integral_base<const volatile wchar_t> { static const int value = true; };
    template <> struct is_integral_base<const volatile signed char> { static const int value = true; };
    template <> struct is_integral_base<const volatile short int> { static const int value = true; };
    template <> struct is_integral_base<const volatile int long> { static const int value = true; };
    template <> struct is_integral_base<const volatile long long int> { static const int value = true; };
    template <> struct is_integral_base<const volatile unsigned char> { static const int value = true; };
    template <> struct is_integral_base<const volatile unsigned short int> { static const int value = true; };
    template <> struct is_integral_base<const volatile unsigned int> { static const int value = true;};
    template <> struct is_integral_base<const volatile unsigned long int>{ static const int value = true;};
    template <> struct is_integral_base<const volatile unsigned long long int>{ static const int value = true;};
    template <> struct is_integral_base<const volatile bool>{ static const int value = true;};

    template <> struct is_integral_base<volatile int>{ static const int value = true;};
    template <> struct is_integral_base<volatile char>{ static const int value = true;};
    template <> struct is_integral_base<volatile wchar_t> { static const int value = true; };
    template <> struct is_integral_base<volatile signed char> { static const int value = true; };
    template <> struct is_integral_base<volatile short int> { static const int value = true; };
    template <> struct is_integral_base<volatile int long> { static const int value = true; };
    template <> struct is_integral_base<volatile long long int> { static const int value = true; };
    template <> struct is_integral_base<volatile unsigned char> { static const int value = true; };
    template <> struct is_integral_base<volatile unsigned short int> { static const int value = true; };
    template <> struct is_integral_base<volatile unsigned int> { static const int value = true;};
    template <> struct is_integral_base<volatile unsigned long int>{ static const int value = true;};
    template <> struct is_integral_base<volatile unsigned long long int>{ static const int value = true;};
    template <> struct is_integral_base<volatile bool>{ static const int value = true;};
    
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
