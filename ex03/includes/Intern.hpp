#ifndef	INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <AForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>

class Intern
{
private:
	/* data */
public:
	Intern( void );
	Intern( Intern &i );
	Intern &operator=( Intern &i );
	~Intern();

	AForm*	makeForm( std::string form, std::string target );
	AForm*	newShrubbery( std::string target );
	AForm*	newPresidential( std::string target );
	AForm*	newRobotomy( std::string target );
};

#endif