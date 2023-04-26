/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 09:34:11 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/24 08:43:31 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		void makeMyMind(const std::string idea);
		void readMyMind() const;

		const std::string* getIdeas() const;
		int	getTotalIdeas() const;

	private:
		std::string ideas[100];
		int totalIdeas;
};

#endif
