/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 23:16:43 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/12 14:51:23 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { (void)other;}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	// if (this != &other)
	// 	;
	return (*this);
}

static void putHeader(std::string msg)
{
	std::cout << std::endl << "===== " <<  std::string(GOLD) << msg << RESET << " =====" << std::endl;
}

static int checkValue(const std::string in)
{
	int len = in.length();
	
	if (len == 0 || len > 10)
		return (1);
	else if (len == 10)
	{
		std::string s = "2147483647";
		for (int i = 0; i < len; i++)
		{
			if (in.at(i) > s.at(i))
				return (1);
		}	
	}
	for (int i = 0; i < len; i++)
	{
		if (!isdigit(in.at(i)))
			return (1);
	}
	return (0);
}


static int checkArgs(char *argv[])
{
	for (int i = 0; argv[i]; i++)
	{
		if (checkValue(argv[i]))
			return (1);
	}
	return (0);
}

static void buildData(std::vector<int> &vec, std::deque<int> &deq, char *argv[], int debug)
{
	double dur;
	clock_t t;
	t = clock();
	for (int i = 0; argv[i]; i++)
		vec.push_back(std::atoi(argv[i]));
	dur = static_cast<double>(clock() - t) / CLOCKS_PER_SEC;
	if (debug)
		std::cout << "Time to arrange std::vector data: " << std::fixed << std::setprecision(8) << dur << " us" << std::endl;
	t = clock();
	for (int i = 0; argv[i]; i++)
		deq.push_back(std::atoi(argv[i]));
	dur = static_cast<double>(clock() - t) / CLOCKS_PER_SEC;
	if (debug)
		std::cout << "Time to arrange std::deque data: " << std::fixed << std::setprecision(8) << dur << " us" << std::endl;
}

void PmergeMe::evaluate(char *argv[])
{
	std::vector<int> oVec;
	std::deque<int> oDeq;
	std::vector<int> vec;
	std::deque<int> deq;
	double vecDur, vecTDur, deqDur, deqTDur;
	clock_t t;

	if (checkArgs(argv))
		throw std::invalid_argument("Invalid argument");

	buildData(vec, deq, argv, true);
	buildData(oVec, oDeq, argv, false);
	
	t = clock();
	vecFordMergeSort(vec, 0, vec.size() - 1);
	vecDur = static_cast<double>(clock() - t) / CLOCKS_PER_SEC;
	t = clock();
	deqFordMergeSort(deq, 0, deq.size() - 1);
	deqDur = static_cast<double>(clock() - t) / CLOCKS_PER_SEC;
	t = clock();
	fordMergeSort(vec, 0, vec.size() - 1);
	vecTDur = static_cast<double>(clock() - t) / CLOCKS_PER_SEC;
	t = clock();
	fordMergeSort(deq, 0, deq.size() - 1);
	deqTDur = static_cast<double>(clock() - t) / CLOCKS_PER_SEC;

	putHeader("Available Data");
	std::cout << "Before:\t" << std::flush;
	printMerge(oVec);
	std::cout << "After:\t" << std::flush;
	printMerge(vec);

	putHeader("Tests with separated functions");
	std::cout << "Time to process a range of "<< vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(8) << vecDur << " us" << std::endl;
	std::cout << "Time to process a range of "<< deq.size() << " elements with std::deque : " << std::fixed << std::setprecision(8) << deqDur << " us" << std::endl;
	putHeader("Tests with template functions");
	std::cout << "Time to process a range of "<< vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(8) << vecTDur << " us" << std::endl;
	std::cout << "Time to process a range of "<< deq.size() << " elements with std::deque : " << std::fixed << std::setprecision(8) << deqTDur << " us" << std::endl;
}

void PmergeMe::vecJohnsonInsert(std::vector<int>& arr, int start, int mid, int end) 
{
	std::vector<int> temp(end - start + 1);
	int i = start;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= end) {
		temp[k++] = arr[j++];
	}
	std::copy(temp.begin(), temp.end(), arr.begin() + start);
}

void PmergeMe::vecFordMergeSort(std::vector<int>& arr, int start, int end) {
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	vecFordMergeSort(arr, start, mid);
	vecFordMergeSort(arr, mid + 1, end);
	vecJohnsonInsert(arr, start, mid, end);
}

void PmergeMe::deqJohnsonInsert(std::deque<int>& arr, int start, int mid, int end) 
{
	std::deque<int> temp(end - start + 1);
	int i = start;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= end) {
		temp[k++] = arr[j++];
	}
	std::copy(temp.begin(), temp.end(), arr.begin() + start);
}

void PmergeMe::deqFordMergeSort(std::deque<int>& arr, int start, int end) {
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	deqFordMergeSort(arr, start, mid);
	deqFordMergeSort(arr, mid + 1, end);
	deqJohnsonInsert(arr, start, mid, end);
}
