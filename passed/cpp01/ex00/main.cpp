/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:19:03 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/14 14:27:03 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "Calling newZombie to allocate a Zombie on the Heap..."
	 << std::endl;
	Zombie*	z = newZombie("Heapy");
	
	std::cout << "Calling announce on Zombie......" << std::endl;
	z->announce();
	
	std::cout << "Calling delete on heap Zombie." << std::endl;
	delete z;

	std::cout << "Calling randomChump to create a Zombie on the Stack..." 
	<< std::endl;
	randomChump("Stackie");

	return (0);
}

