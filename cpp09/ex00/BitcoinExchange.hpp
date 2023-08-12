/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:51:50 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/11 17:10:53 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <cstdlib>
# include <iomanip>
# include <cmath>
# include "Date.hpp"

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string dataFile);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		void makeExchange(std::string in) const;
		double getNearestValue(const Date date) const;
		int isEmpty() const;
		void printDatabase() const;

	private:
		BitcoinExchange();
		void createDatabase(std::string dataFile);
		std::map<Date, double> dataBase;
};

#endif
