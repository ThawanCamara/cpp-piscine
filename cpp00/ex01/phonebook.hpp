#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{
	public:
		Phonebook();
		~Phonebook();

		void addList();
		void searchList();

		Contact*	getList();
		int			getAmountOfContacts();
		void		increaseAmountOfContacts();

	private:
		Contact contactList[8];
		int		amountOfContacts;
};

#endif
