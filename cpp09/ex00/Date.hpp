/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:11:37 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/11 16:14:43 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <string>

class Date
{
	public:
		Date();
		Date(int y, int m, int d);
		Date(std::string date);
		~Date();
		Date(const Date& other);
		Date& operator=(const Date& other);
		bool operator<(const Date& other) const;

		int compareDate(const Date &other) const;

		void setDate(const std::string date);
		void setDate(const int y, const int m, const int d);
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		int getLeapYear() const;

	private:
		int getMaxDays() const;
		int dayCheck(const std::string day) const;
		int monthCheck(const std::string month) const;
		int checkValue(const std::string in) const;
		int year;
		int month;
		int	day;
		bool leapYear;
};

std::ostream& operator<<(std::ostream& os, const Date& date);

#endif
