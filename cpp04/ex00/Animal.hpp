/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:40:27 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/23 00:05:11 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		virtual void makeSound();

		std::string getType() const;

	protected:
		std::string type;
};

#endif
