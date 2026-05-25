/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:33:58 by rbestman          #+#    #+#             */
/*   Updated: 2026/04/03 12:31:41 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	_value;
	static const int	_bits = 8;

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	Fixed(const int intValue);
	Fixed(const float floatValue);

	float	toFloat(void) const;
	int		toInt(void) const;

	int		getRawBits() const;
	void	setRawBits(int const raw);
};

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);

#endif
