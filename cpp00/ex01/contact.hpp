#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	public:
		Contact() {};
		Contact(const Contact&);
		Contact& operator=(const Contact&);
		~Contact() {};

		std::string getFirstname() { return (firstname); };
		std::string getLastname() { return (lastname); };
		std::string getNickname() { return (nickname); };
		std::string getPhoneNumber() { return (phoneNumber); };
		std::string getDarkestSecret() { return (darkestSecret); };

		void setFirstname(std::string s) { firstname = s; };
		void setLastname(std::string s) { lastname = s; };
		void setNickname(std::string s) { nickname = s; };
		void setPhoneNumber(std::string s) { phoneNumber = s; };
		void setDarkestSecret(std::string s) { darkestSecret = s; };
	
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;		
};

#endif
