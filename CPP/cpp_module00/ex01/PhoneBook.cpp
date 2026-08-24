/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:57:35 by msuter            #+#    #+#             */
/*   Updated: 2026/08/24 23:43:19 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	pos = -1;
}

static std::string Loop(std::string input)
{
	std::string Value;

	std::cout << input;
	do
	{
		std::getline(std::cin, Value);
		if (Value.empty())
			std::cout << "Error, a saved contact can’t have empty fields\n" << input;
	}
	while(Value.empty());
	return (Value);
}

void PhoneBook::Add()
{
	std::string Value;

	if (pos == -1)
		pos++;
	if (pos >= 8)
		pos = 0;
	Value = Loop("Name\n");
	C[pos].SetName(Value);
	Value = Loop("Last Name\n");
	C[pos].SetLastName(Value);
	Value = Loop("Nickname\n");
	C[pos].SetNickName(Value);
	Value = Loop("Phone number\n");
	C[pos].SetPhoneNumber(Value);
	Value = Loop("Darkest secret\n");
	C[pos].SetDarkestSecret(Value);
	pos++;
	return;
}


static std::string Truncat(std::string Value)
{
	int	len;

	len = Value.length();
	if (len > 9)
		Value = Value.substr(0, 9) + '.';
	return (Value);
}

static int VerifNumber(int pos)
{
	int index;
	do
	{
		std::cout << "choose a contact from 0 to " << pos << '\n';
		std::cin >> index;
		if (index < 0 || index > pos)
			std::cout << "wrong index.\n";
	}
	while (index < 0 || index > pos);
}

void	PhoneBook::Search()
{
	int	i = 0;
	if (pos == -1)
	{
		std::cout << "No contact for the moment.\n";
		return;
	}
	std::cout << std::right;
	while (i < pos)
	{
		std::cout << '|' << std::setw(10) << i << '|';
		std::cout << std::setw(10) << Truncat(C[i].GetName()) << '|';
		std::cout << std::setw(10) << Truncat(C[i].GetLastName()) << '|';
		std::cout << std::setw(10) << Truncat(C[i].GetNickName()) << '|' << '\n';
		i++;
	}
	i = VerifNumber(pos);
	
}
