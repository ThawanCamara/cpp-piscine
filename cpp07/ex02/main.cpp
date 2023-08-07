/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:53:51 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/07 14:27:45 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "colors.hpp"
#include "Array.hpp"
#include "Matrix.hpp"
#include "utils.hpp"
#include <stdint.h>

void putHeader(std::string msg)
{
	std::cout << std::endl << "===== " <<  std::string(GOLD) << msg << RESET << " =====" << std::endl;
}

typedef struct data
{
	int id;
	uintptr_t data;
}	data;

int main(void)
{
	putHeader("Available Data");
	Array<std::string> arrayString(3);
	Array<int> arrayInt(4);
	Array<float> arrayFloat(3);
	Array<data> arrayData(3);

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
	arrayData[0].id = 0;
	arrayData[1].id = 1;
	arrayData[2].id = 2;
	arrayData[0].data = reinterpret_cast<uintptr_t>(&arrayString[0]);
	arrayData[1].data = reinterpret_cast<uintptr_t>(&arrayString[1]);
	arrayData[2].data = reinterpret_cast<uintptr_t>(&arrayString[2]);

	printContainer(arrayString);
	printContainer(arrayInt);
	printContainer(arrayFloat);
	std::cout << "[ ";
	for (int i = 0; i < 3; i++)
	{
		if (i > 0)
			std::cout << ", ";
		std::cout << "{" << arrayData[i].id << " - " << arrayData[i].data << "(" << *reinterpret_cast<std::string *>(arrayData[i].data) << ")" << "}";
	}
	std::cout << " ]" << std::endl;
	

	putHeader("Get the second data of every container");

	std::cout << ORANGE << "Strings: " << RESET << arrayString[1] << std::endl;
	std::cout << BLUE << "Int: " << RESET << arrayInt[1] << std::endl;
	std::cout << PINK << "Float: " << RESET << arrayFloat[1] << std::endl;
	std::cout << GREEN << "Data: " << RESET << "{" << arrayData[1].id << " - " << arrayData[1].data << "(" << *reinterpret_cast<std::string *>(arrayData[1].data) << ")" << "}" << std::endl;

	putHeader("Show the containers' sizes");
	std::cout << ORANGE << "Strings: " << RESET << arrayString.size() << std::endl;
	std::cout << BLUE << "Int: " << RESET << arrayInt.size() << std::endl;
	std::cout << PINK << "Float: " << RESET << arrayFloat.size() << std::endl;
	std::cout << GREEN << "Data: " << RESET << arrayData.size() << std::endl;
	
	// Array<Array<int> > arrayMatrix(4);
	// Matrix<int> matrix(4, 4);
	// for (int i = 0; i < 4; i++)
	// 	arrayMatrix[i] = Array<int>(3);

	// arrayMatrix[0][0] = 1;
	// matrix(0,0) = 33;
	// matrix[0][1] = 4;
	// matrix[1][0] = 12;
	// matrix[1][0] = 3;

	// std::cout << arrayMatrix[0][0] << std::endl;
	// std::cout << arrayMatrix[0][1] << std::endl;
	// std::cout << matrix(0,0) << std::endl;
}
