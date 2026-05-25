/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:57:06 by rbestman          #+#    #+#             */
/*   Updated: 2026/04/03 12:31:48 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = intValue << this->_bits;
}

/*	1 << this_bits(8) = 256 
	uses roundf() which rounds to the nearest whole number 
	to minimize precision loss when converting from float to fixed */
Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;

	this->_value = roundf(floatValue * (1 << this->_bits));
}

/* Operator Overload (stream insertion operator)
	Sends a Fixed type into an outstream object.
	Returns the object so that more operands can be chained.

	Example:
	 std::cout << a << b 
	 = (std::cout << a) << b  	// left-associate
	 = std::cout << b 			// first << returns cout

 	-> works with any object that is an ostream (std::cout, std::cerr)
	or inherits from it (std::ofstream, std::stringstream).
	Note: We only need to handle Fixed, other types (int, char, float etc.)
	are handled by <iostream>'s builtin operator << overloads. */

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

/* (float) keeps fraction */
float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << this->_bits));
}

/* truncates fraction */
int	Fixed::toInt(void) const
{
	return (this->_value / (1 << this->_bits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_value = other._value;
	}
	return	(*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/* retrieves unscaled integer data stored in fixed */
int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}


