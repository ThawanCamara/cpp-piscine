/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:11:29 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/07 13:54:11 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <iostream>
# include "colors.hpp"

template <typename T>
class Matrix
{
	public:
		Matrix() : matrix(NULL), cols(0), rows(0) {};
		Matrix(unsigned int rows, unsigned int cols) : cols(cols), rows(rows)
		{
			matrix = new T*[rows];
			for (int i = 0; i < static_cast<int>(rows); i++)
				matrix[i] = new T[cols];
		};
		~Matrix()
		{ 
			for (int i = 0; i < cols; i++)
				delete matrix[i];
			delete[] matrix;
		};
		Matrix(const Matrix& other) : cols(other.getColumns()), rows(other.getRows())
		{
			matrix = dupMatrix(other.matrix, other.getColumns());
		};
		Matrix& operator=(const Matrix& other)
		{
			for (int i = 0; i < cols; i++)
				delete matrix[i];
			delete[] matrix;
			cols = other.getColumns();
			rows = other.getRows();
			matrix = dupMatrix(other.matrix, other.getColumns());
			return (*this);
		};
		
		int	getRows(void) const { return (rows); };
		int	getColumns(void) const { return (cols); };
		
		T **dupMatrix(const T *matrix, const int rows, const int cols)
		{
			T **ret = new T*[rows];
			for (int i = 0; i < rows; i++)
			{
				matrix[i] = new T[cols];
				for (int j = 0; j < cols; j++)
					ret[i][j] = matrix[i][j];
			}
			return (ret);
		}
		
		// Array-like access
		T& operator[](int index)
		{
			if (index < 0 || index >= cols)
				throw std::out_of_range("Index out of range");
			return (matrix[index]);
		}
		
		T& operator()(int row, int col)
		{
			if (row < 0 || row >= rows || col < 0 || col >= cols)
				throw std::out_of_range("Index out of range");
			return (matrix[row][col]);
		}

	private:
		T **matrix;
		int cols;
		int rows;
};

#endif
