#include <Form.hpp>

Form::Form( void ): _name("Undefinded"), _sign(false), _gradeS(1), _gradeE(1)
{
}

Form::Form( const Form &f ): _name(f._name), _sign(false), _gradeS(f._gradeS), _gradeE(f._gradeE)
{
}

Form::Form( std::string name, int gradeS, int gradeE): _name(name), _sign(false), _gradeS(gradeS), _gradeE(gradeE)
{
}

Form	&Form::operator=( const Form &f )
{
	(void) f;
	return (*this);
}

Form::~Form()
{
}

std::string	Form::getName( void ) const
{
	return(this->_name);
}

bool	Form::getSign( void ) const
{
	return (this->_sign);
}

int		Form::getGradeS( void ) const
{
	return (this->_gradeS);
}

int		Form::getGradeE( void ) const
{
	return (this->_gradeE);
}

void	Form::beSigned( Bureaucrat &b)
{
	if (this->_gradeS < b.getGrade())
		throw(Form::GradeTooLow());
	this->_sign = true;
}

const char	*Form::GradeTooHigh::what( void ) const throw()
{
	return ("Exception: Grade too high!");
}

const char	*Form::GradeTooLow::what( void ) const throw()
{
	return ("grade is too low!");
}

std::ostream	&operator<<( std::ostream &o, const Form &f )
{
	o << "---------------- Form: " << f.getName() << " ----------------" << std::endl;
	o << "Signed: " ;
	if (f.getSign() == 0)
		o << "false" << std::endl;
	else
		o << "true" << std::endl;
	o << "Minimum grade to be signed: " << f.getGradeS() << std::endl;
	o << "Minimum grade to be executed: " << f.getGradeE() << std::endl;
	o << "------------------------------------------------" << std::endl;
	return (o);
}