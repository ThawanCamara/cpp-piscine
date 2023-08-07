/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:53:51 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/06 18:10:13 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "colors.hpp"
#include "iter.hpp"

void putHeader(std::string msg)
{
	std::cout << std::endl << "===== " <<  std::string(GOLD) << msg << RESET << " =====" << std::endl;
}

void doubleIntValue(int &value)
{
	value *= 2;
}

void doubleFloatValue(float &value)
{
	value *= 2;
}

void reverseString(std::string &str)
{
	int len = str.length();
	for (int i = 0; i < len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - i - 1 ];
		str[len - i - 1] = temp;
	}
}

int main(void)
{
	std::string input;
	
	putHeader("Available Data");
	int intArray[] = {42, 10, 77, -5};
	float floatArray[] = {42.0f, 10.0f, 303.333, -5.920};
	std::string stringArray[] = {"ola", "adeus", "AARD", "Firaga"};
	printArray(intArray, sizeof(intArray) / sizeof(intArray[0]));
	printArray(floatArray, sizeof(floatArray) / sizeof(floatArray[0]));
	printArray(stringArray, sizeof(stringArray) / sizeof(stringArray[0]));
	putHeader("Funtion: Iter");
	std::cout << LIGHTSTEEL << "ints and floats will be doubled" << RESET << std::endl;
	std::cout << LIGHTSTEEL << "strings will be reversed" << RESET << std::endl << std::endl;
	::iter(intArray, sizeof(intArray) / sizeof(intArray[0]), doubleIntValue);
	::iter(floatArray, sizeof(floatArray) / sizeof(floatArray[0]), doubleFloatValue);
	::iter(stringArray, sizeof(stringArray) / sizeof(stringArray[0]), reverseString);
	printArray(intArray, sizeof(intArray) / sizeof(intArray[0]));
	printArray(floatArray, sizeof(floatArray) / sizeof(floatArray[0]));
	printArray(stringArray, sizeof(stringArray) / sizeof(stringArray[0]));

}
