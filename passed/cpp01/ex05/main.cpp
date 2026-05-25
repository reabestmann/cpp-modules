/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:00:56 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/15 17:14:29 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	test;

	std::cout << "[DEBUG] :" << std::endl;
	test.complain("DEBUG");
	std::cout << "[INFO] :" << std::endl;
	test.complain("INFO");
	std::cout << "[WARNING] :" << std::endl;
	test.complain("WARNING");
	std::cout << "[ERROR] :" << std::endl;
	test.complain("ERROR");
	std::cout << "[INVALID]:" << std::endl;
	test.complain("INVALID");

	return (0);
}

