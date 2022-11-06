/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <touateyoussef2003@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:53:58 by ytouate           #+#    #+#             */
/*   Updated: 2022/11/06 14:58:05 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(VECTOR)
#define VECTOR
#include <memory>

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
    private:
        
    public:
        vector();
        ~vector();
    };
    
}

#endif // VECTOR
