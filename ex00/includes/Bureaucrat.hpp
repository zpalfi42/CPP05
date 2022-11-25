#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat
{
private:
	std::string	const	_name;
	int					_grade;
public:
	/* Orthodoxal Canonical needs */
	Bureaucrat( void );
	Bureaucrat( const Bureaucrat &b );

	Bureaucrat	&operator=( const Bureaucrat &b );

	~Bureaucrat();

	/* Exercice needs */
	Bureaucrat( std::string name, int grade );

	class GradeTooHigh : public std::exception
	{
		public:
			const char	*what( void ) const throw();
	};
	
	class GradeTooLow : public	std::exception
	{
		public:
			const char	*what( void ) const throw();
	};

	const std::string	getName( void ) const;
	int					getGrade( void ) const;
	void				moveGrade( int n );
};

std::ostream	&operator<<( std::ostream &o, const Bureaucrat &b );

#endif