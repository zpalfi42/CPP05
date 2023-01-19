#ifndef	FORM_HPP
# define FORM_HPP

# include	<Bureaucrat.hpp>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_sign;
	const int			_gradeSign;
	const int			_gradeExec;
public:
	/* Orthodoxal Canonical needs */
	Form( void );
	Form( const Form &f );

	Form	&operator=( const Form &f );

	~Form();

	/* Exercice needs */

	Form( std::string name, int gradeSing, int gradeExec);

	class GradeTooHigh : public std::exception
	{
		public:
			const char	*what( void ) const throw();
	};
	
	class GradeTooLow : public std::exception
	{
		public:
			const char	*what( void ) const throw();
	};

	std::string	getName( void ) const;
	bool		getSign( void ) const;
	int			getGradeS( void ) const;
	int			getGradeE( void ) const;

	void		beSigned( const Bureaucrat &b );
};

std::ostream	&operator<<( std::ostream &o, const Form &f );

#endif