/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:51:49 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/23 12:53:07 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	size = 0;
	oldest = 0;
}

void	PhoneBook::storeContact(Contact &newContact)
{
	if (this->size < 8)
	{
		this->contacts[this->size] = newContact;
		this->size++;
	}
	else
	{
		this->contacts[this->oldest] = newContact;
		this->oldest = (this->oldest + 1) % 8;
	}
}

void	PhoneBook::addContact()
{
	Contact		newContact;
	std::string	input;

	std::cout << "First Name: ";
	std::getline(std::cin, input);
	newContact.setFirstName(input);

	std::cout << "Last Name: ";
	std::getline(std::cin, input);
	newContact.setLastName(input);

	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	newContact.setNickname(input);

	std::cout << "Phone Number: ";
	std::getline(std::cin, input);
	newContact.setPhoneNbr(input);

	std::cout << "Darkest Secret: ";
	std::getline(std::cin, input);
	newContact.setSecret(input);

	if (!newContact.isValidEntry())
	{
		std::cout << "All fields must be filled. Contact not added." << std::endl;
		return ;
	}
	
	this->storeContact(newContact);
	std::cout << "Contact stored!" << std::endl;
}

static std::string	truncate(const std::string& str)
{
	if (str.length() <= 10)
		return (str);
	return (str.substr(0, 9) + ".");
}

void	PhoneBook::displayList() const
{
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;

	for (int i = 0; i < this->size; i++)
	{
		std::cout << std::setw(10) << i << "|" 
		<< std::setw(10) << truncate(this->contacts[i].getFirstName()) << "|"
		<< std::setw(10) << truncate(this->contacts[i].getLastName()) << "|"
		<< std::setw(10) << truncate(this->contacts[i].getNickname())
		<< std::endl;
	}
}

void	PhoneBook::displayContact(int index) const
{
	std::cout << this->contacts[index].getFirstName() << std::endl;
	std::cout << this->contacts[index].getLastName() << std::endl;
	std::cout << this->contacts[index].getNickname() << std::endl;
	std::cout << this->contacts[index].getPhoneNbr() << std::endl;
	std::cout << this->contacts[index].getSecret() << std::endl;
}

bool	PhoneBook::isValidIndex(const std::string& input, int& index) const
{
	std::stringstream ss(input);
	return (ss >> index && ss.eof() && index >= 0 &&
	index < this->size);
}

void	PhoneBook::searchContact() const
{
	int	index;

	this->displayList();
	std::cout << "Enter Contact Index: ";
	std::string input;
	std::getline(std::cin, input);
	
	if (isValidIndex(input, index))
		this->displayContact(index);
	else
		std::cout << "Invalid Index :(" << std::endl;
}
