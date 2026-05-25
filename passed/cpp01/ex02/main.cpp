/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:42:40 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/14 15:59:57 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string	Val = "HI THIS IS BRAIN";
	std::string*	stringPTR = &Val;
	std::string&	stringREF = Val;

	std::cout << "memory address of string variable: "
	<< &Val << std::endl;
	std::cout << "memory address held by stringPTR: "
	<< stringPTR << std::endl;
	std::cout << "memory address held by stringREF: "
	<< &stringREF << std::endl;

	std::cout << "value of string variable: "
	<< Val << std::endl;
	std::cout << "value pointed to by stringPTR: "
	<< *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF: "
	<< stringREF << std::endl;

	return (0);
}

