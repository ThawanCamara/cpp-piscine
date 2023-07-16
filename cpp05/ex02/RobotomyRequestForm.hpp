#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &other);
		RobotomyRequestForm& operator=(RobotomyRequestForm const &other);
		
		std::string getTarget() const;
		void toExecute() const;
	private: 
		std::string target;
};

#endif
