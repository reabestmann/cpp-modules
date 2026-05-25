/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:07:54 by rbestman          #+#    #+#             */
/*   Updated: 2026/02/11 18:45:26 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int params, char **argv)
{
	int	i;
	int	j;

	if (params > 1)
	{
		i = 1;
 		while(argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				std::cout << (char)std::toupper(argv[i][j]);
				j++;
				if (!argv[i][j])
					std::cout << " ";
			}
			i++;
		}
	}
	else
		std::cout << "*LOUD AND UNBEARABLE FEEDBACK NOISE*";
	std::cout << std::endl;
	return (0);
}
