/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notes.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:53:27 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/26 12:12:27 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// substitution failure is not an error refers to a situation in c++ where an invalid substitution of template
// prameters is not in itself an error, David Vandevoorde first introduced the
// acronym sifnae to describe related programmming techniques
// in c++ the compiler goes through a process in order for it to find the right function overload these steps are
/*
- 1 name lookup
- 2 ADL (argument dependent lookup)
- 3 template argument deduction
- 4 template function substitution
- 5 overload resoulution
*/

/*
    SFINAE applies during overload resolution of function templates: when subsituting the explicitly specified or deduced type for the template paramter fails 
    specialization is discarded from the overload set, instead of causing a compile error
*/