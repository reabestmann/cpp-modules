/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:00:59 by rbestman          #+#    #+#             */
/*   Updated: 2026/05/15 16:33:05 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class	Brain;

class Cat: public Animal
{
	private:
		Brain*	_brain;
	
	public:
		Cat();
		Cat(const Cat& cpy);
		Cat&	operator = (const Cat& other);
		~Cat();

		void	makeSound() const;
		Brain*	getBrain() const;
};

#endif
