/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 14:00:59 by rbestman          #+#    #+#             */
/*   Updated: 2026/05/15 16:51:37 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class Brain;

class WrongCat: public WrongAnimal
{
	private:
		Brain*	_brain;
	public:
		WrongCat();
		WrongCat(const WrongCat& cpy);
		WrongCat& operator = (const WrongCat& other);
		~WrongCat();

	void	makeSound() const;
	Brain*	getBrain() const;
};

#endif
