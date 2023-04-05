#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class Phonebook
{
	public:
		Phonebook(){};
		Phonebook(const Phonebook&);
		Phonebook& operator=(const Phonebook&);
		~Phonebook(){};

		void addList();
		void searchList();

		Contact* getList() { return (contactList); };

	private:
		Contact contactList[8];
};

#endif
