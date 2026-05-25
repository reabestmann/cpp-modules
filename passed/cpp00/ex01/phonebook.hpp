/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:07:55 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/23 12:41:55 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

class	PhoneBook
{
private:
	Contact	contacts[8];
	int	size;
	int	oldest;

public:
	PhoneBook();

	bool	isValidIndex(const std::string& input, int& index) const;
	void	addContact();
	void	storeContact(Contact &newContact);
	void	searchContact() const;
	void	displayContact(int index) const;
	void	displayList() const;
	void	format(const std::string& str) const;
};

#endif
