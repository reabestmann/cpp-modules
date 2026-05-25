/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:21:30 by rbestman          #+#    #+#             */
/*   Updated: 2026/04/03 12:30:44 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) 
{
	Fixed a;                    	// -> Default constructor
	Fixed const b(10);           	// -> Int constructor
	Fixed const c(42.42f);       	// -> Float constructor
	Fixed const d(b);            	// -> Copy constructor
    
	a = Fixed(1234.4321f);       	// -> Float constructor + copy assignment
    
	std::cout << "a is " << a << std::endl;      // Uses operator<< overload for fixed
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    
	return 0;
}

