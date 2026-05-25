/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:20:01 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/15 13:52:06 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::removeWeapon()
{
	if (this->weapon)
	{
		std::cout << name << " lost their " << weapon->getType()
		<< std::endl;
		this->weapon = NULL;
	}
}

void	HumanB::attack() const
{
	if (this->weapon)
	{
		std::cout << name << " attacks with their " << weapon->getType()
		<< std::endl;
	}
	else
		std::cout << name << " attacks with their bare hands (no weapon set)" 
		<< std::endl;
}

HumanB::~HumanB()
{}
