#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_exeGrade;
		bool				_signed;

		int	validateGrade(const int grade);

	public:

		AForm(const std::string name, const int signGrade, const int exeGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void	beSigned(const Bureaucrat& b);
		void	execute(const Bureaucrat& b) const; // checks grade & form signed

		virtual void executeAction() const = 0; // actually executes, called by execute
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
