/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:03:38 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/14 17:09:46 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA 
{
private:
	Weapon&	weapon;
	std::string	name;
public:
	HumanA(std::string name, Weapon& weapon);
	void	attack() const;
	~HumanA();
};

#endif	
