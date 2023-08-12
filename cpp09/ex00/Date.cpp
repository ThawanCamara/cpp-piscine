/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:22:26 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/12 14:52:25 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

// '-' at begin and end
// non-digits at middle
// '-' should appear 2 times (3 numbers)
// empty input between '-' (like "1---1")

Date::Date() {}

Date::Date(int y, int m, int d) : year(y), month(m), day(d) 
{
	leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	if (!(month > 0 && month <= 12))
		throw std::invalid_argument("Invalid date format");
	if (!(day > 0 && day <= getMaxDays()))
		throw std::invalid_argument("Invalid date format");
}

Date::Date(std::string date)
{
	setDate(date);
}

Date::~Date() {}

Date::Date(const Date& other) : year(other.year), month(other.month), day(other.day), leapYear(other.leapYear) {}

Date& Date::operator=(const Date& other)
{
	if (this != &other)
	{
		year = other.year;
		month = other.month;
		day = other.day;
		leapYear = other.leapYear;
	}
	return (*this);
}

bool Date::operator<(const Date& other) const
{
	if (year != other.year)
		return year < other.year;
	if (month != other.month)
		return month < other.month;
	return day < other.day;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	int day, month;
	
	day = date.getDay();
	month = date.getMonth();
	os << date.getYear() << "-";
	if (month < 10)
		os << "0";
	os << month << "-";
	if (day < 10)
		os << "0";
	os << day;
	return (os);
}

int Date::checkValue(const std::string in) const
{
	int len = in.length();
	
	if (len == 0 || len > 10)
		return (1);
	else if (len == 10)
	{
		std::string s = "2147483647";
		for (int i = 0; i < len; i++)
		{
			if (in.at(i) > s.at(i))
				return (1);
		}	
	}
	for (int i = 0; i < len; i++)
	{
		if (!isdigit(in.at(i)))
			return (1);
	}
	return (0);
}

int Date::monthCheck(const std::string month) const
{
	int value;
	int len = month.length();

	if (len	!= 2)
		return (1);
	value = std::atoi(month.c_str());
	return (!(value > 0 && value <= 12));
}

int Date::dayCheck(const std::string day) const
{
	int value;
	int len = day.length();

	if (len	!= 2)
		return (1);
	value = std::atoi(day.c_str());
	return (!(value > 0 && value <= getMaxDays()));
}

int Date::getMaxDays() const
{
	int maxDay = 30;

	if (month != 2)
	{
		if (month % 2 != 0)
			maxDay += month <= 7;
		else
			maxDay += month >= 8;
	}
	else
		maxDay = 28 + leapYear;
	return (maxDay);
}

int Date::compareDate(const Date &other) const
{
	int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int yA, mA, dA, yB, mB, dB;
	int oY, oM;
	int greater, lesser;
	int leapYears = 0;
	
	yA = year * 365;
	oY = other.getYear();
	yB = oY * 365;
	mA = 0;
	for (int i = 0; i < month - 1; i++)
		mA += monthDays[i];
	mB = 0;
	oM = other.getMonth();
	for (int i = 0; i < oM - 1; i++)
		mB += monthDays[i];
	dA = day + (leapYear * (month > 2));
	dB = other.getDay() + (other.getLeapYear() * (oM > 2));
	lesser = year;
	greater = oY;
	if (year > oY)
	{
		lesser = greater;
		greater = year;
	}
	for (int i = lesser; i < greater; i++)
		leapYears += (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0));
	return (yA + mA + dA - yB - mB - dB + leapYears);
}

void Date::setDate(const std::string date)
{
	std::stringstream ss(date);
	std::string ret;
	int len = date.length();
	int numberCount = 0;

	if (date.at(0) == '-' || date.at(len - 1) == '-')
		throw std::invalid_argument("Invalid date format");
	while (!ss.eof())
	{
		std::getline(ss, ret, '-');
		if (++numberCount > 3 || checkValue(ret))
			throw std::invalid_argument("Invalid date format");
		if (numberCount == 1)
		{
			year = std::atoi(ret.c_str());
			leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		}
		else if (numberCount == 2)
		{
			if (monthCheck(ret))
				throw std::invalid_argument("Invalid date format");
			else
				month = std::atoi(ret.c_str());
		}
		else if (numberCount == 3)
		{
			if (dayCheck(ret))
				throw std::invalid_argument("Invalid date format");
			else
				day = std::atoi(ret.c_str());
		}
	}
	if (numberCount != 3)
		throw std::invalid_argument("Invalid date format");
}

void Date::setDate(const int y, const int m, const int d)
{
	year = y;
	month = m;
	day = d;
	leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	if (!(month > 0 && month <= 12))
		throw std::invalid_argument("Invalid date format");
	if (!(day > 0 && day <= getMaxDays()))
		throw std::invalid_argument("Invalid date format");
}

int Date::getDay() const { return (day); }
int Date::getMonth() const { return (month); }
int Date::getYear() const { return (year); }
int Date::getLeapYear() const { return (leapYear); }