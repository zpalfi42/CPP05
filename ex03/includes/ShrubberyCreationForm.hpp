#ifndef	SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include <AForm.hpp>

class ShrubberyCreationForm: public AForm
{
private:
	const std::string	_target;
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( const ShrubberyCreationForm &s );
	ShrubberyCreationForm &operator=(ShrubberyCreationForm &s);
	~ShrubberyCreationForm();

	ShrubberyCreationForm( std::string target );

	void	execute( Bureaucrat const &executor ) const;
};

#endif