#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	public:
		Contact();
		~Contact();

		std::string getFirstname() const;
		std::string getLastname() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;

		void setFirstname(const std::string s);
		void setLastname(const std::string s);
		void setNickname(const std::string s);
		void setPhoneNumber(const std::string s);
		void setDarkestSecret(const std::string s);
	
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;		
};

#endif
