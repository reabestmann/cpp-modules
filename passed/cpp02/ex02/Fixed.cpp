/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:57:06 by rbestman          #+#    #+#             */
/*   Updated: 2026/04/03 13:04:55 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors/Destrutors

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
        std::cout << "Copy constructor called" << std::endl;
        this->_value = other._value;
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = intValue << this->_bits;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;

	this->_value = roundf(floatValue * (1 << this->_bits));
}

Fixed::~Fixed()
{
        std::cout << "Destructor called" << std::endl;
}

Fixed&  Fixed::operator=(const Fixed& other)
{
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other)
        {
                this->_value = other._value;
        }
        return  (*this);
}
 
// stream operator Overload (previous exercise)

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

// 6 comparison operator Overload

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->_value > other._value);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->_value < other._value);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->_value >= other._value);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->_value <= other._value);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->_value == other._value);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->_value != other._value);
}

/*	4 Arithmetic Operator Overload
	Return by value (new local object)
	Const Parameters = no modification of parameters
	trailing const = for this (-> object left of operator)
*/
Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;
	result._value = this->_value + other._value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;
	result._value = this->_value - other._value;
	return (result);
}

/*	Shift for * to avoid wrong scaling:
	e.g.: (a × 256) × (b × 256) = a × b × 256 × 256 
	-> 2 factors of 256 (only needs one)
	add right shift /256 : a x b x 256 x 256/256
						-> a x b x 256 
	to remove extra scale factor
*/
Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;
	result._value = (this->_value * other._value) >> this->_bits;
	return (result);
}

/*	Shift for / to avoid wrong scaling:
	e.g.: (a × 256) / (b × 256) = a / b 
	-> both scales cancel (one needed)
	add left shift *256 : (a x 256 x 256) / (b x 256)
						-> (a / b) * 256
	to restore scale factor
*/
Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;
	result._value = (this->_value << this->_bits) / other._value;
	return (result);
}

/* 4 Increment/decrement Operator Overload
	Pre-increment (++a -> calls operator++()): no parameter
	Post-increment (a++ -> calls operator++(0)): with int, parameter ignored
*/
Fixed&	Fixed::operator++()
{
	this->_value += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);
	this->_value += 1;
	return (old);
}

Fixed&	Fixed::operator--()
{
	this->_value -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);
	this->_value -= 1;
	return (old);
}

/* 4 static min/max functions
	Fixed& (non-const) -> you can modify the result
	const Fixed& -> you can't modify the result
*/
Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}



// functions of previous Exercises

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << this->_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_value / (1 << this->_bits));
}

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

