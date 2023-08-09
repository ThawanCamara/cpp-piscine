/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:41:45 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/07 17:58:03 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>

// Modified from cpp07/ex02 to work with iterators
template <typename T>
void printContainer(T &arr)
{	
	std::cout << "[ ";
	for (typename T::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		if (it != arr.begin())
			std::cout << ", ";
		std::cout << *it;
	}
	std::cout << " ]" << std::endl;
}

#endif