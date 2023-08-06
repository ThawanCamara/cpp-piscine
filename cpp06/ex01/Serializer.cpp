/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:54:25 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/06 11:23:33 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer& other) {(void)other;}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	std::cout << LIGHTSTEEL << "*** Serializing data ***" << RESET << std::endl;
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	std::cout << CORNSILK << "*** Deserializing data ***" << RESET << std::endl;
	return (reinterpret_cast<Data *>(raw));
}