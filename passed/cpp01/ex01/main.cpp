/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 14:50:48 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/14 15:33:27 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "Calling zombieHorde to create a Horde of 10 Zombies:"
	<< std::endl;
	Zombie*	horde = zombieHorde(10, "Hordy");
	
	std::cout << "Showing you my Zombies..." << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Calling announce on Zombie " << i << std::endl;
		horde[i].announce();
	}

	std::cout << "Deleting the entire horde..." << std::endl;
	delete[] horde;

	/*std::cout << "Trying a Horde of 0 now:" << std::endl;
	Zombie* emptyHorde = zombieHorde(0, "Empty");
	delete[] emptyHorde;*/

	return (0);
}

