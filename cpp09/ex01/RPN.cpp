/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:53:49 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/12 14:48:05 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// RPN::RPN(std::string in)
// {
// 	buildStack(in);
// }

// RPN::~RPN() {}

// RPN::RPN(const RPN& other) : stkNumber(other.stkNumber), stkOperator(other.stkOperator) {}

// RPN& RPN::operator=(const RPN& other)
// {
// 	if (this != &other)
// 	{
// 		stkNumber = other.stkNumber;
// 		stkOperator = other.stkOperator;
// 	}
// 	return (*this);
// }

static int isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

// void RPN::buildStack(std::string in)
// {
// 	int len = in.length();

// 	for (int i = 0; i < len; i++)
// 	{
// 		if (!(isdigit(in.at(i)) || isOperator(in.at(i)) || in.at(i) == ' '))
// 			throw std::invalid_argument("Invalid characters");
// 		if (isdigit(in.at(i)))
// 			stkNumber.push(in.at(i) - 48);
// 		else if (isOperator(in.at(i)))
// 			stkOperator.push(in.at(i));
// 	}
// }

static int rpnSum(int a, int b)
{
	return (a + b);
}

static int rpnSub(int a, int b)
{
	return (a - b);
}

static int rpnMul(int a, int b)
{
	return (a * b);
}

static int rpnDiv(int a, int b)
{
	return (a / b);
}

static int getOperator(char c)
{
	if (c == '+')
		return (0);
	if (c == '-')
		return (1);
	if (c == '*')
		return (2);
	if (c == '/')
		return (3);
	return (-1);
}

int RPN::evaluateStack(std::string in)
{
	int len = in.length();
	std::stack<int> stk;

	int (*f[4])(int, int) = {rpnSum, rpnSub, rpnMul, rpnDiv};
	int a, b, r;

	{
		int op = 0;
		int nb = 0;
		for (int i = 0; i < len; i++)
		{
			if (!(isdigit(in.at(i)) || isOperator(in.at(i)) || in.at(i) == ' '))
				throw std::invalid_argument("Invalid characters");
			op += isOperator(in.at(i));
			nb += isdigit(in.at(i));
			if (nb <= op)
				throw std::invalid_argument("Not solvable");
		}
	}

	for (int i = 0; i < len; i++)
	{
		if (isdigit(in.at(i)))
			stk.push(in.at(i) - 48);
		else if (isOperator(in.at(i)))
		{
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();
			r = f[getOperator(in.at(i))](b, a);
			stk.push(r);
		}
	}
	return (stk.top());
}