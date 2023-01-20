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
	Bureaucrat	you("You", 1);
	Bureaucrat	me("Me", 140);

	you.executeForm(*shrub);
	std::cout << std::endl;
	you.signForm(*shrub);
	std::cout << *shrub << std::endl;
	std::cout << you << std::endl;
	you.executeForm(*shrub);
	me.executeForm(*shrub);
	delete shrub;

	std::cout << std::endl;
	std::cout << std::endl;

	AForm		*robotomy;
	robotomy	= someRandomIntern.makeForm("robotomy request", "You");
	Bureaucrat	me2("Me", 1);

	me2.executeForm(*robotomy);
	me2.signForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	delete robotomy;
	
	std::cout << std::endl;
	std::cout << std::endl;

	AForm		*presidential;
	presidential	= someRandomIntern.makeForm("presidential pardon", "You");
	Bureaucrat	me3("Me", 6);

	me3.executeForm(*presidential);
	me3.signForm(*presidential);
	me3.executeForm(*presidential);
	me3.upGrade();
	me3.executeForm(*presidential);
	delete presidential;

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Trying to create a Form that doesn't exist. Result:" << std::endl;
	try
	{
		Intern	someRandomIntern2;
		AForm		*presidential;
		presidential	= someRandomIntern2.makeForm("Some thing that doesnt work", "You");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	

	return (0);
}