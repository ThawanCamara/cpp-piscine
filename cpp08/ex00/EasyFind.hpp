/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:32:51 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/07 17:59:55 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <vector>
# include <algorithm>

// Work end varying both container types (vectors, lists) and also the type
// of their contents (int, float, strings)
template <typename T, typename TValue>
typename T::iterator easyfind(T &array, const TValue &value)
{
	typename T::iterator it = std::find(array.begin(), array.end(), value);
	if (it != array.end())
		return (it);
	else
		throw std::invalid_argument("Value does not exist");
}

#endif