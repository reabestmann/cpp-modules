#include <AForm.hpp>
#include <Bureaucrat.hpp>

AForm::AForm(const std::string name, const int signGrade, const int exeGrade)
	: _name(name),
	_signGrade(validateGrade(signGrade)),
	_exeGrade(validateGrade(exeGrade)),
	_signed(false)
{
	std::cout << "AForm Parameterized Constructor called" << std::endl;
}

AForm::AForm(const AForm& other)
	: _name(other._name), 
	_signGrade(other._signGrade), 
	_exeGrade(other._exeGrade), 
	_signed(other._signed)
{
	std::cout << "AForm Copy Constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	std::cout << "AForm Copy assignment operator called" << std::endl;
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

const std::string	AForm::getName() const
{
	return _name;
}

int	AForm::getExeGrade() const
{
	return _exeGrade;
}

int	AForm::getSignGrade() const
{
	return _signGrade;
}

bool	AForm::getSigned() const
{
	return _signed;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "AForm " << form.getName() 
	<< ", sign grade " << form.getSignGrade()
	<< ", execution grade " << form.getExeGrade()
	<< ", signed status " << std::boolalpha << form.getSigned();
	
	return os;
}

int	AForm::validateGrade(const int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	
	return grade;
}

void	AForm::execute(const Bureaucrat& b) const
{
	if (!_signed)
		throw	FormNotSignedException();
	if (b.getGrade() > _exeGrade)
		throw	GradeTooLowException();

	executeAction();
}
