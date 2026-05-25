#include "Animal.hpp"

Animal::Animal()
{
	_type = "Animal";
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal &cpy) : _type(cpy._type)
{
	std::cout << "Animal Copy Constructor called" << std::endl;
}

Animal	&Animal::operator=(const Animal &other)
{
	if (this != &other)
        _type = other._type;
	std::cout << "Animal Copy assignment operator called" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Virtual Destructor Called" << std::endl;
}

std::string	Animal::getType() const
{
	return _type;
}

void Animal::makeSound() const
{
	std::cout << "*generic Animal sound*" << std::endl;
}

