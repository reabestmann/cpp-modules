/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:38:16 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/24 11:13:12 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact() : firstName(), lastName(), nickname(), phoneNbr(), secret()
{
}

void	Contact::setFirstName(std::string& str)
{
	this->firstName = str;
}

void	Contact::setLastName(std::string& str)
{
	this->lastName = str;
}

void	Contact::setNickname(std::string& str)
{
	this->nickname = str;
}

void	Contact::setPhoneNbr(std::string& str)
{
	this->phoneNbr = str;
}

void	Contact::setSecret(std::string& str)
{
	this->secret = str;
}

const std::string&	Contact::getFirstName() const
{
	return (this->firstName);
}

const std::string&	Contact::getLastName() const
{
	return (this->lastName);
}

const std::string&	Contact::getNickname() const
{
	return (this->nickname);
}

const std::string&	Contact::getPhoneNbr() const
{
	return (this->phoneNbr);
}

const std::string&	Contact::getSecret() const
{
	return (this->secret);
}

bool	Contact::isValidEntry() const
{
	return (!firstName.empty() && !lastName.empty() &&
			!nickname.empty() && !phoneNbr.empty() &&
			!secret.empty());
}
