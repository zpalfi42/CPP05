#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

# include "Form.hpp"

class	Form;

class Bureaucrat
{
private:
	std::string	const	_name;
	int					_grade;
	int	static const	_minGrade = 150;
	int	static const	_maxGrade = 1;
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

	void				signForm( Form &f ) const;
	const std::string	getName( void ) const;
	int					getGrade( void ) const;
	void				upGrade( void );
	void				downGrade( void );
};

std::ostream	&operator<<( std::ostream &o, const Bureaucrat &b );

#endif