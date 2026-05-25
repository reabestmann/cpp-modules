/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:33:33 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/24 11:04:10 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main (void)
{
        PhoneBook       PB;
        std::string    input;

        std::cout << "Hello user! This is phonebook...." << std::endl;

	while (1)
	{
		std::cout << "Type your Option: ADD, SEARCH or EXIT" << std::endl;
        std::cout << "What would you like to do?    >";
		std::getline(std::cin, input);
        
		if (input == "ADD")
                	PB.addContact();
        else if (input == "SEARCH")
                	PB.searchContact();
    	else if (input == "EXIT")
                	return (0);
	}
}

