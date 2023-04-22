#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::getFirstname() const
{
	return (firstname);
}

std::string Contact::getLastname() const
{
	return (lastname);
}

std::string Contact::getNickname() const
{
	return (nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (darkestSecret);
}

void Contact::setFirstname(const std::string s)
{
	firstname = s;
}

void Contact::setLastname(const std::string s)
{
	lastname = s;
}

void Contact::setNickname(const std::string s)
{
	nickname = s;
}

void Contact::setPhoneNumber(const std::string s)
{
	phoneNumber = s;
}

void Contact::setDarkestSecret(const std::string s)
{
	darkestSecret = s;
}
