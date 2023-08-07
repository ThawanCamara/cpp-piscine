/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:26:36 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/06 21:24:01 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName(void) const;
		unsigned int	getHealth(void) const;
		unsigned int	getEnergy(void) const;
		unsigned int	getDamage(void) const;
		unsigned int	getActionEnergyCost(void) const;
		
		void		setName(std::string name);
		void		setHealth(const int value);
		void		setEnergy(const int value);
		void		setDamage(const int value);

		int			tryPerformAction(std::string);

	private:
		std::string	name;
		unsigned int	health;
		unsigned int	energy;
		unsigned int	damage;
		static const int ACTION_ENERGY_COST = 1;
};

#endif
