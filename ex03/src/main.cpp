#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <Intern.hpp>

int	main( void )
{
	Intern	someRandomIntern;
	AForm		*shrub;
	shrub	= someRandomIntern.makeForm("shrubbery creation", "home");
	Bureaucrat	corr("Correcteur", 1);
	Bureaucrat	me("Lucie", 140);

	corr.executeForm(*shrub);
	std::cout << std::endl;
	corr.signForm(*shrub);
	std::cout << *shrub << std::endl;
	std::cout << corr << std::endl;
	corr.executeForm(*shrub);
	me.executeForm(*shrub);
	delete shrub;

	std::cout << std::endl;
	std::cout << std::endl;

	AForm		*robotomy;
	robotomy	= someRandomIntern.makeForm("robotomy request", "home");
	Bureaucrat	me2("Lucie", 1);

	me2.executeForm(*robotomy);
	me2.signForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	delete robotomy;
	
	std::cout << std::endl;
	std::cout << std::endl;

	Intern	someRandomIntern2;
	AForm		*presidential;
	presidential	= someRandomIntern2.makeForm("presidential pardon", "home");
	Bureaucrat	me3("Lucie", 6);

	me3.executeForm(*presidential);
	me3.signForm(*presidential);
	me3.executeForm(*presidential);
	me3.upGrade();
	me3.executeForm(*presidential);
	delete presidential;

	return (0);
}