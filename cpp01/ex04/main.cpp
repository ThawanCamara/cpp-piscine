/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:55:33 by tde-souz          #+#    #+#             */
/*   Updated: 2023/04/22 10:55:34 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
	std::ifstream src;
	std::ofstream dst;
	std::string fileIn, fileOut, oldWord, newWord;

	if (argc != 4)
	{
		std::cout << "You've screwed up my args. Pleasing stop bitching me" << std::endl;
		return (1);
	}
	fileIn = argv[1];
	fileOut = fileIn;
	fileOut.append(".replace");
	
	std::cout << "\e[38;5;11mDebug:\e[0m\t" << "Reading from: " << fileIn << std::endl;
	std::cout << "\e[38;5;11mDebug:\e[0m\t" << "Reading to: " << fileOut << std::endl;
	src.open(fileIn.c_str(), std::ifstream::in);
	dst.open(fileOut.c_str(), std::ofstream::out);

	oldWord = argv[2];
	newWord = argv[3];
	
	if (!src.is_open())
	{
		std::cout << "\e[38;5;11mDebug:\e[0m\t" << "\e[38;5;9mFailed\e[0m to open: " << fileIn << std::endl;
		return (1);
	}

	std::string line;
	while (std::getline(src, line))
	{
		//std::cout << line << std::endl;
		size_t i = 0;
		while (1)
		{
			i = line.find(oldWord, i);
			if (i == std::string::npos)
				break ;
			line.erase(i, oldWord.length());
			line.insert(i, newWord);
			i += newWord.length();
		}
		dst << line << std::endl;
	}
	src.close();
	dst.close();
	return (0);
}
