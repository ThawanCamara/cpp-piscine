/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:20:52 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/08 20:23:31 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <set>
# include <stdexcept>
# include <algorithm>
# include <ctime>
# include "utils.hpp"

class Span
{
	public:
		Span(unsigned int n);
		~Span();
		Span(const Span& other);
		Span& operator=(const Span& other);

		void addNumber(const int n);
		int shortestSpan();
		int longestSpan() const;
		void fillSpan();

		void print() const;

		unsigned int getSlots() const;

	private:
		Span();
		std::vector<int> array;
		unsigned int slots;
};

#endif
