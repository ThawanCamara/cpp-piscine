#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const &other);
	
	std::string getTarget() const;
	void toExecute() const;
private: 
	std::string target;
};


#endif
