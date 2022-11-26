#ifndef	FORM_HPP
# define FORM_HPP

# include	<Bureaucrat.hpp>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_sign;
	const int			_gradeS;
	const int			_gradeE;
public:
	/* Orthodoxal Canonical needs */
	Form( void );
	Form( const Form &f );

	Form	&operator=( const Form &f );

	~Form();

	/* Exercice needs */

	Form( std::string name, int gradeS, int gradeE);

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

	void		beSigned( Bureaucrat &b);
};

std::ostream	&operator<<( std::ostream &o, const Form &f );

#endif