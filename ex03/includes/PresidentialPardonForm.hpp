#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <AForm.hpp>

class PresidentialPardonForm: public AForm
{
private:
	const std::string	_target;
public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( PresidentialPardonForm &p );
	PresidentialPardonForm	&operator=( PresidentialPardonForm &p );
	~PresidentialPardonForm();

	PresidentialPardonForm( std::string target );

	void	execute( Bureaucrat const &executor ) const;
};

#endif