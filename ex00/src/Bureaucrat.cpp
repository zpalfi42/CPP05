#include <Bureaucrat.hpp>

const char	*Bureaucrat::GradeTooHigh::what( void ) const throw()
{
	return ("Exception: Grade too high!");
}

const char	*Bureaucrat::GradeTooLow::what( void ) const throw()
{
	return ("Exception: Grade too low!");
}

const std::string	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int		Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

void	Bureaucrat::moveGrade( int n )
{
	if (this->_grade + n > 150)
		throw (GradeTooHigh());
	if (this->_grade + n < 1)
		throw (GradeTooLow());
	this->_grade += n;
}

Bureaucrat::Bureaucrat( void ): _name("Undefined"), _grade(1)
{
}

Bureaucrat::Bureaucrat( std::string name, int grade ): _name(name)
{
	if (grade < 1)
		throw (GradeTooLow());
	if (grade > 150)
		throw(GradeTooHigh());
	this->_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat &b ): _name(b._name), _grade(b._grade)
{
}

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat &b )
{
	if (this != &b)
	{
		this->_grade = b._grade;
		return (*this);
	}
	return (*this);
}

std::ostream	&operator<<( std::ostream &o, const Bureaucrat &b )
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (o);
}

Bureaucrat::~Bureaucrat()
{
}