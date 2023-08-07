/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:44:54 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/06 17:03:54 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *a, int len, void (*f)(T &))
{
	for (int i = 0; i < len; i++)
		f(a[i]);
}

template <typename T>
void printArray(T *a, int len)
{
	
	std::cout << "[ ";
	for (int i = 0; i < len; i++)
	{
		if (i > 0)
			std::cout << ", ";
		std::cout << a[i];
	}
	std::cout << " ]" << std::endl;
}

#endif
