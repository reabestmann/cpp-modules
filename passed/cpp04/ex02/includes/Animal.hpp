/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:49:26 by rbestman          #+#    #+#             */
/*   Updated: 2026/05/15 17:08:50 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

/* Polymorphism: "many forms" -> one function works with different types of objects.
*/
class Animal
{
protected:
	std::string	_type;
public:
	Animal();
	Animal(const Animal& cpy);
	Animal& operator = (const Animal& other);
	virtual ~Animal();

	std::string	getType() const;

	virtual void	makeSound() const = 0;
};

#endif
