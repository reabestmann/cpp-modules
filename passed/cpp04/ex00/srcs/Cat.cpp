#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	_type = cpy._type;
	std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
        _type = other._type;
	std::cout << "Cat Copy assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Virtual Destructor Called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "*miaumiaumiau*" << std::endl;
}

