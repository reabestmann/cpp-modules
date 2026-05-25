/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:07:55 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/24 11:12:26 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstring>

class	Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNbr;
	std::string	secret;

public:
	Contact();

	void	setFirstName(std::string& str);
	void	setLastName(std::string& str);
	void	setNickname(std::string& str);
	void	setPhoneNbr(std::string& str);
	void	setSecret(std::string& str);

	const std::string&	getFirstName() const;
	const std::string&	getLastName() const;
	const std::string&	getNickname() const;
	const std::string&	getPhoneNbr() const;
	const std::string&	getSecret() const;

	bool	isValidEntry() const;
};

#endif
