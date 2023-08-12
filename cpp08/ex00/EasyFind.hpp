/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:32:51 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/09 07:05:09 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <vector>
# include <algorithm>

// Work end varying both container types (vectors, lists) and also the type
// of their contents (int, float, strings)
template <typename T, typename TValue>
typename T::const_iterator easyfind(const T &array, const TValue &value)
{
	typename T::const_iterator it = std::find(array.begin(), array.end(), value);
	if (it != array.end())
		return (it);
	else
		throw std::invalid_argument("Value does not exist");
}

#endif