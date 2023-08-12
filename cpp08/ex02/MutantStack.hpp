/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 07:12:19 by tde-souz          #+#    #+#             */
/*   Updated: 2023/08/09 07:57:27 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		// This is needed. It won't compile if typedef is not present. When searching
		// for iterators, they look for these exact names, unless otherwise stated.
		// Refer to the Manual for further info.
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		MutantStack() {};
		~MutantStack() {};
		MutantStack(const MutantStack& other) : std::stack<T>(other) {};
		MutantStack& operator=(const MutantStack& other)
		{
			if (this != *other)
			{
				std::stack<T>::operator=(other);
			}
			return (*this);
		};
		
		iterator begin() { return (this->c.begin()); };
		iterator end() { return (this->c.end()); };
		const_iterator begin() const { return ( this->c.begin()); };
		const_iterator end() const { return ( this->c.end()); };
};

#endif
