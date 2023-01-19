#include <Bureaucrat.hpp>
#include <Form.hpp>

int	main( void )
{
	Bureaucrat a;
	std::cout << "Created " << a << std::endl;
	Bureaucrat b("b", 150);
	std::cout << "Created " << b << std::endl;
	std::cout << std::endl;

	Form	FormA("FormA", 75, 75);
	Form	FormB("FormB", 75, 75);

	std::cout << a << std::endl << "Tried to sign" << std::endl << std::endl << FormA << std::endl;
	a.signForm(FormA);
	std::cout << "And the result was: " << FormA.getSign() << std::endl << std::endl;

	std::cout << b << std::endl << "Tried to sign" << std::endl << std::endl << FormB << std::endl;
	std::cout << "And the result was:" << std::endl;
	b.signForm(FormB);

	try
	{
		std::cout << "Trying to create a Form with too high grade Sign:" << std::endl;
		Form	tooHigh("TooHigh", 0, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}

	try
	{
		std::cout << "Trying to create a Form with too high grade Execution:" << std::endl;
		Form	tooHigh("TooHigh", 10, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}

	try
	{
		std::cout << "Trying to create a Form with too low grade Sign:" << std::endl;
		Form	tooLow("TooLow", 151, 140);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n' << std::endl;
	}

	try
	{
		std::cout << "Trying to create a Form with too low grade Execution:" << std::endl;
		Form	tooLow("TooLow", 130, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}