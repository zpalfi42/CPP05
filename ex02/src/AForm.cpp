#include <AForm.hpp>

AForm::AForm( void ): _name("Undefinded"), _sign(false), _gradeSign(1), _gradeExec(1)
{
}

AForm::AForm( const AForm &f ): _name(f._name), _sign(false), _gradeSign(f._gradeSign), _gradeExec(f._gradeExec)
{
}

AForm::AForm( std::string name, int gradeS, int gradeE): _name(name), _sign(false), _gradeSign(gradeS), _gradeExec(gradeE)
{
	if (gradeS < 1)
		throw (GradeTooHigh());
	if (gradeS > 150)
		throw(GradeTooLow());
	if (gradeE < 1)
		throw (GradeTooHigh());
	if (gradeE > 150)
		throw(GradeTooLow());
}

AForm	&AForm::operator=( const AForm &f )
{
	(void) f;
	return (*this);
}

AForm::~AForm()
{
}

std::string	AForm::getName( void ) const
{
	return(this->_name);
}

bool	AForm::getSign( void ) const
{
	return (this->_sign);
}

int		AForm::getGradeS( void ) const
{
	return (this->_gradeSign);
}

int		AForm::getGradeE( void ) const
{
	return (this->_gradeExec);
}

void	AForm::beSigned( const Bureaucrat &b)
{
	if (this->_gradeSign < b.getGrade())
		throw(AForm::GradeTooLow());
	this->_sign = true;
}

const char	*AForm::GradeTooHigh::what( void ) const throw()
{
	return ("Exception: Grade too high!");
}

const char	*AForm::GradeTooLow::what( void ) const throw()
{
	return ("Exception: Grade is too low!");
}

const char	*AForm::FormNotSigned::what( void ) const throw()
{
	return ("Exception: Form is not signed!");
}

const char	*AForm::FileNotOpen::what( void ) const throw()
{
	return ("Exception: File couldn't be opened!");
}

std::ostream	&operator<<( std::ostream &o, const AForm &f )
{
	o << "---------------- AForm: " << f.getName() << " ----------------" << std::endl;
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

void	AForm::checkExec(const Bureaucrat &executor ) const
{
	if (this->_sign == false)
		throw(AForm::FormNotSigned());
	if (executor.getGrade() > this->getGradeE())
		throw(AForm::GradeTooLow());
}