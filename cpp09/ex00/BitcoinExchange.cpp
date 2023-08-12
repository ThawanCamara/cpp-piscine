/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:56:30 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/12 14:53:14 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string dataFile)
{
	createDatabase(dataFile);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : dataBase(other.dataBase) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		dataBase = other.dataBase;
	return (*this);
}

static int checkDouble(const std::string in)
{
	int len = in.length();
	int dotCount = 0;
	
	if (in.at(0) == '-')
		return (2);
	if (in.at(0) == '.' || in.at(len - 1) == '.')
		return (1);
	for (int i = 0; i < len; i++)
	{
		if (!isdigit(in.at(i)))
		{
			if (in.at(i) == '.' && dotCount == 0)
				dotCount++;
			else
				return (1);
		}
	}
	if (std::atof(in.c_str()) > 2147483647)
		return (3);
	return (0);
}

void BitcoinExchange::createDatabase(std::string dataFile)
{
	std::ifstream inFile(dataFile.c_str());
	std::string line;

	if (!inFile.is_open())
		throw std::invalid_argument("Database file not found");
	std::getline(inFile, line);
	if (line != "date,exchange_rate")
		throw std::invalid_argument("Invalid header format");
	while (std::getline(inFile, line))
	{
		std::stringstream ss(line);
		std::string strDate;
		std::string strValue;
		
		if (std::getline(ss, strDate, ','))
		{
			Date date(strDate);
			double value;

			if (std::getline(ss, strValue))
			{
				if (checkDouble(strValue))
					throw std::invalid_argument("Invalid bitcoin format");
				value = std::atof(strValue.c_str());
			}
			dataBase[date] = value;
		}
	}
}

int BitcoinExchange::isEmpty() const
{
	return (dataBase.empty());
}

void BitcoinExchange::printDatabase() const
{
	for (std::map<Date, double>::const_iterator it = dataBase.begin(); it != dataBase.end(); ++it)
		std::cout << it->first << " -> " << it->second << std::endl;
}

static std::string trimString(const std::string s)
{
	std::string ret = "";
	int len = s.length();

	for (int i = 0; i < len; i++)
	{
		if (!isspace(static_cast<unsigned char>(s.at(i))))
			ret += s.at(i);
	}
	return (ret);
}

void BitcoinExchange::makeExchange(std::string in) const
{
	std::string errors[] = {"bad format", "not a positive number", "too large a number"};
	std::ifstream inFile(in.c_str());
	std::string line;

	if (!inFile.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
	}
	std::getline(inFile, line);
	if (line != "date | value")
		throw std::invalid_argument("Invalid header format");
	while (std::getline(inFile, line))
	{
		std::stringstream ss(line);
		std::string strDate;
		std::string strValue;
		
		Date date;
		std::string trimmedDate;
		double value;
		if (std::getline(ss, strDate, '|'))
		{
			strDate = trimString(strDate);
			try
			{
				date.setDate(strDate);
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error: bad input => " << strDate << std::endl;
				continue ;
			}
			
		}
		if (std::getline(ss, strValue))
		{
			strValue = trimString(strValue);
			int er = checkDouble(strValue);
			if (er)
			{
				std::cerr << "Error: " << errors[er - 1] << std::endl;
				continue ;
			}
			value = std::atof(strValue.c_str());
		}
		std::cout << date << " => " << value << " = " << (getNearestValue(date) * value) << std::endl;
	}
}

double BitcoinExchange::getNearestValue(const Date date) const
{
	Date temp;
	std::map<Date, double>::const_iterator ret;

	if (isEmpty())
		return (-1);
	ret = dataBase.begin();
	for (std::map<Date, double>::const_iterator it = dataBase.begin(); it != dataBase.end(); ++it)
	{
		if (it != dataBase.begin())
		{
			temp = it->first;
			if (date < temp)
				break ;
		}
		ret = it;
	}
	return (ret->second);
}
