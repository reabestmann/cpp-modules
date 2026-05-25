#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	_brain = new Brain(*cpy._brain);
	std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
        Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	std::cout << "Cat Copy assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat Virtual Destructor Called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "*miaumiaumiau*" << std::endl;
}

Brain*	Cat::getBrain() const
{
	return	_brain;
}
