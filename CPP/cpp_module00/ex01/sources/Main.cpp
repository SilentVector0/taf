/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:08:37 by msuter            #+#    #+#             */
/*   Updated: 2026/10/21 10:26:30 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include "../includes/verif.hpp"

int main ()
{
	PhoneBook p;
	std::string input;

	std::cout << "Welcome to your phonebook. Available commands: ADD, SEARCH, EXIT.\n";
	while (1)
	{
		std::cout << '>';
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << "You pressed ctrl + d, end of program\n";
			exit(1);
		}
		if (input == "ADD")
			p.Add();
		else if (input == "SEARCH")
			p.Search();
		else if (input == "EXIT")
			p.Exit();
	}
}
