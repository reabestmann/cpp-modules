#include <Form.hpp>

Form::Form()
	: _name("defaultForm"), 
	_signGrade(75), 
	_exeGrade(75),
	_signed(false)
{
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int exeGrade)
	: _name(name),
	_signGrade(validateGrade(signGrade)),
	_exeGrade(validateGrade(exeGrade)),
	_signed(false)
{
	std::cout << "Form Parameterized Constructor called" << std::endl;
}

Form::Form(const Form& other)
	: _name(other._name), 
	_signGrade(other._signGrade), 
	_exeGrade(other._exeGrade), 
	_signed(other._signed)
{
	std::cout << "Form Copy Constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	std::cout << "Form Copy assignment operator called" << std::endl;
	return *this;
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

const std::string	Form::getName() const
{
	return _name;
}

int	Form::getExeGrade() const
{
	return _exeGrade;
}

int	Form::getSignGrade() const
{
	return _signGrade;
}

bool	Form::getSigned() const
{
	return _signed;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName() 
	<< ", sign grade " << form.getSignGrade()
	<< ", execution grade " << form.getExeGrade()
	<< ", signed status " << std::boolalpha << form.getSigned();
	
	return os;
}

int	Form::validateGrade(const int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	
	return grade;
}
