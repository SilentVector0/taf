/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:57:35 by msuter            #+#    #+#             */
/*   Updated: 2026/08/23 18:26:59 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	pos = 0;
}

static std::string loop()
{
	std::string value;

	
}

void PhoneBook::Add()
{
	std::string Value;

	std::cout << "Name:\n";
	std::getline(std::cin, Value);
	C[pos].SetName(Value);
	std::cout << " Last Name:\n";
	std::getline(std::cin, Value);
	C[pos].SetLastName(Value);
	std::cout << "Nickname:\n";
	std::getline(std::cin, Value);
	C[pos].SetNickName(Value);
	std::cout << "Phone Number:\n";
	std::getline(std::cin, Value);
	C[pos].SetPhoneNumber(Value);
	std::cout << "darkest secret:\n";
	std::getline(std::cin, Value);
	C[pos].SetDarkestSecret(Value);
	return;
}
