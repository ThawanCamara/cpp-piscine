/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:54:04 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/06 10:54:05 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

static int checkPseudo(const std::string input)
{
	const std::string pseudos[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 6; i++)
	{
		if (pseudos[i] == input)
			return (PSEUDO);
	}
	return (UNKNOWN);
}

static int getType(const std::string input)
{
	int len(input.length());

	if (len == 0
		|| (len > 1 && (input.at(len - 1) == '.' || input.at(0) == '.'))
		|| (len > 2 && (input.at(len - 1) == 'f' && input.at(len - 2) == '.'))
		|| (len > 2 && (input.at(1) == '.' && !isdigit(input.at(0)))))
		return (UNKNOWN);
	else if (len == 1 && !isdigit(input.at(0)) && isprint(input.at(0)))
		return (CHAR);

	int signal = input.at(0) == '+' || input.at(0) == '-';
	int floatCheck = input.at(len - 1) == 'f';
	int	dot = 0;

	len -= floatCheck;
	for (int i = signal; i < len; i++)
	{
		dot += input.at(i) == '.';
		// search until finding a char which is neither a digit, 'f' or '.'
		if ((!isdigit(input.at(i)) && input.at(i) != '.') || dot > 1)
			return (checkPseudo(input));
	}
	if (floatCheck)
		return (FLOAT);
	else if (dot)
		return (DOUBLE);
	else
		return (INT);
}

static int getPrecision(double number)
{
	int precision = 0;
	double fraction = std::abs(number - static_cast<long>(number));
	std::ostringstream ss;

	ss << fraction;
	if (fraction > 0)
	{
		std::string fractionalString = ss.str();
		size_t decimalPos = fractionalString.find('.');
		if (decimalPos != std::string::npos) {
			precision = fractionalString.length() - decimalPos - 1;	}
	}
	return (std::max(precision, 1));
}

static void resolveChar(std::string input, int type)
{
	int n;
	std::string value;
	
	if (type == CHAR)
		n = static_cast<int>(input.at(0));
	else
		n = std::atof(input.c_str());
	if (!isascii(n) || type  == PSEUDO)
		value = "impossible";
	else if (!isprint(n))
		value = "non displayable";
	else
		value = "'" + std::string(1, static_cast<char>(n)) + "'";
	std::cout << "char: " << value << std::endl;
}

static void resolveInt(std::string input, int type)
{
	int value;

	if (type == PSEUDO)
		std::cout << "int: " << "impossible" << std::endl;
	else
	{
		if (type == INT)
			value = std::atoi(input.c_str());
		else
		{
			if (type == CHAR)
				value = static_cast<int>(input.at(0));
			else
				value = std::atof(input.c_str());
		}
		std::cout << "int: " << value << std::endl;
	}
}

static void resolveFloat(std::string input, int type)
{
	float value;

	if (type == FLOAT)
		value = static_cast<float>(std::atof(input.c_str())); // explicit
	else
	{
		if (type == CHAR)
			value = static_cast<float>(input.at(0));
		else
			value = static_cast<float>(std::atof(input.c_str())); // explicit
	}
	int precision = getPrecision(value);
	std::cout << "float: " << std::fixed << std::setprecision(precision) << value << "f" << std::endl;
}

static void resolveDouble(std::string input, int type)
{
	double value;

	if (type == DOUBLE)
		value = static_cast<double>(std::atof(input.c_str())); // explicit
	else
	{
		if (type == CHAR)
			value = static_cast<double>(input.at(0));
		else
			value = static_cast<double>(std::atof(input.c_str())); // explicit
	}
	int precision = getPrecision(value);
	std::cout << "double: " << std::fixed << std::setprecision(precision) << value << std::endl;
}

int ScalarConverter::convert(const std::string input)
{
	const std::string types[] = {"char", "int", "float", "double", "pseudo", "unknown"};

	int type = getType(input);
	if (type == UNKNOWN)
		throw std::invalid_argument("Input is of unknown type");
	resolveChar(input, type);
	resolveInt(input, type);
	resolveFloat(input, type);
	resolveDouble(input, type);
	return (0);
}
