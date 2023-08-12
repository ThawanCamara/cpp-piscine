/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 23:16:46 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/12 14:37:17 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <vector>
# include <deque>
# include <cstdlib>
# include "utils.hpp"
# include "colors.hpp"

class PmergeMe
{
	public:
		static void evaluate(char *argv[]);

	private:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		template <typename T>
		static void johnsonInsert(T& arr, int start, int mid, int end) {
			T temp(end - start + 1);
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

		template <typename T>
		static void fordMergeSort(T& arr, int start, int end) {
			if (start >= end) {
				return;
			}
			int mid = (start + end) / 2;
			fordMergeSort(arr, start, mid);
			fordMergeSort(arr, mid + 1, end);
			johnsonInsert(arr, start, mid, end);
		}

		static void vecJohnsonInsert(std::vector<int>& arr, int start, int mid, int end);
		static void vecFordMergeSort(std::vector<int>& arr, int start, int end);
		static void deqJohnsonInsert(std::deque<int>& arr, int start, int mid, int end);
		static void deqFordMergeSort(std::deque<int>& arr, int start, int end);

		template <typename T>
		static void printMerge(const T& arr)
		{
			if (arr.size() <= 8)
				printContainer(arr);
			else
			{
				int quartile = arr.size() / 4;
				std::cout << "[ " << std::flush;
				std::cout << arr.front() << " ... " << std::flush;
				std::cout << arr[quartile] << " ... " << std::flush;
				std::cout << arr[quartile * 2] << " ... " << std::flush;
				std::cout << arr[quartile * 3] << " ... " << std::flush;
				// for (typename T::const_iterator it = arr.begin(); it != arr.end(); it += step)
				// {
				// 	if (it != arr.begin())
				// 		std::cout << "... ";
				// 	std::cout << *it;
				// }
				std::cout << arr.back() << std::flush;
				std::cout << " ]" << std::endl;
			}
		}
};

#endif
