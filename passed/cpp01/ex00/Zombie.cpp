/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:18:17 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/14 14:28:12 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string newName) : name(newName)
{
}

Zombie::~Zombie()
{
	std::cout << name << " destroyed. RIP !" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiinnnzzzZ..." << std::endl;
}

