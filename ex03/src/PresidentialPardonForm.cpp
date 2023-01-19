#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm( void ): AForm("PresidentialPardon", 25, 5), _target("Undefined")
{
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm &p ): AForm(p.getName(), p.getGradeS(), p.getGradeE()), _target(p._target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm &p )
{
	(void) p;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ): AForm("PresidentialPardon", 25, 5), _target(target)
{
}

void	PresidentialPardonForm::execute( const Bureaucrat &executor ) const
{
	this->AForm::checkExec(executor);
	std::cout << "Estimated " << this->_target << ", we inform you that you have been pardoned by Zaphod Beeblerox." << std::endl;
}