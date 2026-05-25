/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:03:38 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/15 13:51:10 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB 
{
private:
	std::string	name;
	Weapon*	weapon;
public:
	HumanB(std::string name);
	void	setWeapon(Weapon& weapon);
	void	removeWeapon();
	void	attack() const;
	~HumanB();
};

#endif	
