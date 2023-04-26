/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:48:30 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/24 13:27:07 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(std::string);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();

		Brain* getBrain();
		void makeSound();

	private:
		Brain *brain;
};

#endif
