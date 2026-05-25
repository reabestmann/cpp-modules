/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:19:03 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/14 15:28:52 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string> 

class Zombie
{
private:
	std::string	name;
public:
	Zombie();
	void	setName(std::string name);
	void	announce(void);
	~Zombie();
};

Zombie*	zombieHorde(int N, std::string name);

#endif
