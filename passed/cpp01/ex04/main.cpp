/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:45:34 by rbestman          #+#    #+#             */
/*   Updated: 2026/03/24 12:19:55 by rbestman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

/* .c_str is used because c++98 expects a C-Style const char* */
/* ifstream/ofstream -> CLASS */
/* std::ifstream infile(filename.c_str) -> constructor of ifstream class object */

std::string	replaceLine(const std::string& line, const std::string& s1, const std::string& s2)
{
	std::string	res;

	for (size_t i = 0; i < line.length(); i++)
	{
		if (line.substr(i, s1.length()) == s1)
		{
			res += s2;
			i += s1.length() - 1;
		}
		else
			res += line[i];
	}		
	return (res);
}

int	main(int params, char **argv)
{
	if (params == 4)
	{
		std::string	filename = argv[1];
		std::string	s1 = argv[2];
		std::string	s2 = argv[3];

		std::ifstream infile(filename.c_str());
		if (!infile)
		{
			std::cerr << "Error opening file" << std::endl;
			return (1);
		}

		if (s1.empty())
		{
		std::cerr << "Error: S1 cannot be empty" << std::endl;
		return (1);
		}

		std::ofstream outfile((filename + ".replace").c_str());
		
		std::string	line;
		while (std::getline(infile, line))
		{
			std::string	newLine = replaceLine(line, s1, s2);
			outfile << newLine;

			if (!infile.eof())
				outfile << std::endl;
		}
	}
	else
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" 
		<< std::endl;
		return (1);
	}
	return (0);
}
