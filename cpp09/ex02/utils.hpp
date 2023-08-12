/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:41:45 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/12 13:05:27 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>

// Modified from cpp08/ex00 to work with const iterators
template <typename T>
void printContainer(const T &arr)
{	
	std::cout << "[ " << std::flush;
	for (typename T::const_iterator it = arr.begin(); it != arr.end(); ++it)
	{
		if (it != arr.begin())
			std::cout << ", ";
		std::cout << *it;
	}
	std::cout << " ]" << std::endl;
}

#endif