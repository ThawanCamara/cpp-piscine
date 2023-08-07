/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:53:51 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/06 20:03:12 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "colors.hpp"
#include "Array.hpp"
#include "Matrix.hpp"
#include "utils.hpp"

void putHeader(std::string msg)
{
	std::cout << std::endl << "===== " <<  std::string(GOLD) << msg << RESET << " =====" << std::endl;
}

int main(void)
{
	std::string input;
	
	putHeader("Available Data");
	Array<int> arrayInt(4);
	Array<float> arrayFloat(3);
	Array<std::string> arrayString(3);
	// Array<Array<int> > arrayMatrix(4);
	// Matrix<int> matrix(4, 4);

	arrayString[0] = "ola";
	arrayString[1] = "mundo";
	arrayString[2] = "doido";
	arrayInt[0] = 42;
	arrayInt[1] = 10;
	arrayInt[2] = 303;
	arrayInt[3] = -4;
	arrayFloat[0] = 42.0f;
	arrayFloat[1] = 303.333f;
	arrayFloat[2] = -5.924f;
	
	// for (int i = 0; i < 4; i++)
		// arrayMatrix[i] = Array<int>(3);

	// arrayMatrix[0][0] = 1;
	// matrix(0,0) = 33;
	// matrix[0][1] = 4;
	// matrix[1][0] = 12;
	// matrix[1][0] = 3;

	// std::cout << arrayMatrix[0][0] << std::endl;
	// std::cout << arrayMatrix[0][1] << std::endl;
	// std::cout << matrix(0,0) << std::endl;

	printContainer(arrayString);
	printContainer(arrayInt);
	printContainer(arrayFloat);
}
