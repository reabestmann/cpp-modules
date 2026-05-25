/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:08:04 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/14 17:33:25 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon), name(name)
{
}

void	HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() 
	<< std::endl;
}

HumanA::~HumanA()
{}

