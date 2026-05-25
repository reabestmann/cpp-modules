/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:04:22 by rbestman          #+#    #+#             */
/*   Updated: 2026/05/15 16:33:15 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Brain;

class Dog: public Animal
{
	private:
		Brain*	_brain;
		
	public:
		Dog();
		Dog(const Dog& cpy);
		Dog& operator = (const Dog& other);
		~Dog();

		void	makeSound() const;
		Brain*	getBrain() const;
};

#endif
