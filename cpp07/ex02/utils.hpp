/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:41:45 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/06 19:17:44 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include "Array.hpp"
# include <iostream>

template <typename T>
void printContainer(Array<T> arr)
{
	int len = arr.getLength();
	
	std::cout << "[ ";
	for (int i = 0; i < len ; i++)
	{
		if (i > 0)
			std::cout << ", ";
		std::cout << arr[i];
	}
	std::cout << " ]" << std::endl;
}

#endif