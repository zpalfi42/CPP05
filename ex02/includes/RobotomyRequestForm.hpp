#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <AForm.hpp>

class RobotomyRequestForm: public AForm
{
private:
	const std::string	_target;
public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( RobotomyRequestForm &r );
	RobotomyRequestForm &operator=( RobotomyRequestForm &r );
	~RobotomyRequestForm();

	RobotomyRequestForm( std::string target );

	void	execute( Bureaucrat const &executor ) const;
};

#endif