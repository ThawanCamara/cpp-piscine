/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:11:29 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/07 14:20:10 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include "colors.hpp"

template <typename T>
class Array
{
	public:
		Array() : array(NULL), cols(0) {};
		Array(unsigned int n) : cols(n) { array = new T[n]; };
		~Array() { delete[] array; };
		Array(const Array& other) : cols(other.size())
		{
			array = dupArray(other.array, other.size());
		};
		Array& operator=(const Array& other)
		{
			delete[] array;
			cols = other.size();
			array = dupArray(other.array, other.size());
			return (*this);
		};
		
		int	size(void) const { return (cols); };
		
		
		// Array-like access
		T& operator[](int index)
		{
			if (index < 0 || index >= cols)
				throw std::out_of_range("Index out of range");
			return (array[index]);
		}

	private:
		T *array;
		int cols;

		T *dupArray(const T *array, const int length)
		{
			T *ret = new T[length];
			for (int i = 0; i < length; i++)
				ret[i] = array[i];
			return (ret);
		}
};

#endif
