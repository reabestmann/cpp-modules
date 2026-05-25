/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:03:38 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/15 15:49:37 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
private:
	void	debug();
	void	info();
	void	warning();
	void	error();

	int		getLevelIndex(std::string level);
public:
	void	complain(std::string level);
};

#endif	
