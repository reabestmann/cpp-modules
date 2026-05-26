#ifndef FORM_HPP
# define FORM_HPP

#include <Bureaucrat.hpp>

class Form
{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_exeGrade;
		bool				_signed;

		int	validateGrade(const int grade);

	public:
		Form();
		Form(const std::string name, const int signGrade, const int exeGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string	getName() const;
		int					getSignGrade() const;
		int					getExeGrade() const;
		bool				getSigned() const;			

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void	beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
