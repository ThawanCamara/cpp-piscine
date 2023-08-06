/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:53:51 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/06 11:19:59 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <colors.hpp>
#include <Serializer.hpp>

void putHeader(std::string msg)
{
	std::cout << std::endl << "===== " <<  std::string(GOLD) << msg << RESET << " =====" << std::endl;
}

int main(void)
{
	Data *dataA = new Data;
	Data dataB;
	uintptr_t rawA;
	uintptr_t rawB;

	putHeader("Preparing Data Structure");
	dataA->name = "Duck";
	dataA->age = 7;
	dataA->money = 0.0f;
	dataB.name = "Shirley Tura";
	dataB.age = 82;
	dataB.money = 1440.23f;
	std::cout << GREEN << "Data A" << RESET << std::endl;
	std::cout << "Name:\t" << dataA->name << std::endl;
	std::cout << "Age:\t" << dataA->age << std::endl;
	std::cout << "Money:\t" << dataA->money << std::endl << std::endl;
	std::cout << BLUE << "Data B" << RESET << std::endl;
	std::cout << "Name:\t" <<dataB.name << std::endl;
	std::cout << "Age:\t" << dataB.age << std::endl;
	std::cout << "Money:\t" << dataB.money << std::endl;

	putHeader("Serializing Data A into Raw A");
	rawA = Serializer::serialize(dataA);
	
	putHeader("Serializing Data B into Raw B");
	rawB = Serializer::serialize(&dataB);

	putHeader("Displaying Serialized Data");
	std::cout << GREEN << "Raw Data A:\t" << RESET << rawA << std::endl;
	std::cout << GREEN << "Raw Data B:\t" << RESET << rawB << std::endl;

	putHeader("Deserializing Raw A into Data C");
	Data dataC = *Serializer::deserialize(rawA);
	
	putHeader("Deserializing Raw B into Data D");
	Data *dataD = Serializer::deserialize(rawB);

	putHeader("Displaying Deserialized Data");
	std::cout << GREEN << "Data C (Former A)" << RESET << std::endl;
	std::cout << "Name:\t" << dataC.name << std::endl;
	std::cout << "Age:\t" << dataC.age << std::endl;
	std::cout << "Money:\t" << dataC.money << std::endl << std::endl;
	std::cout << BLUE << "Data D (Former B)" << RESET << std::endl;
	std::cout << "Name:\t" <<dataD->name << std::endl;
	std::cout << "Age:\t" << dataD->age << std::endl;
	std::cout << "Money:\t" << dataD->money << std::endl;

	delete dataA;
	return (0);
}