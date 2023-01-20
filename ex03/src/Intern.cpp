#include <Intern.hpp>

Intern::Intern( void )
{
}

Intern::Intern( Intern &i )
{
	(void) i;
}

Intern &Intern::operator=( Intern &i )
{
	(void) i;
	return(*this);
}

Intern::~Intern()
{
}

AForm*	Intern::newShrubbery( std::string target )
{
	return(new ShrubberyCreationForm(target));
}
AForm*	Intern::newPresidential( std::string target )
{
	return(new PresidentialPardonForm(target));
}
AForm*	Intern::newRobotomy( std::string target )
{
	return(new RobotomyRequestForm(target));
}

AForm*	Intern::makeForm( std::string form, std::string target )
{
	std::string	s[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*p[3])(std::string) = {&Intern::newShrubbery, &Intern::newRobotomy, &Intern::newPresidential};
	int i = 0;

	while (i < 4 && s[i].compare(form) != 0)
		i++;
	if (i < 3)
	{
		std::cout << "Intern creates " << s[i] << std::endl;
		return((this->*p[i])(target));
	}
	else
		std::cout << "Exception: " << form << " is not a valid name for a form!" << std::endl;
	return (NULL);
}