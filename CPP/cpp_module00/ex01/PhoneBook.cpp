/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:57:35 by msuter            #+#    #+#             */
/*   Updated: 2026/08/25 15:52:14 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	pos = -1;
	n = 0;
}

//!ADD ───────────────────────────────────────────────────────────────

static std::string Loop(std::string input)
{
	std::string Value;
	int			i = 0;
	bool			Valid = true;

	std::cout << input;
	do
	{
		std::getline(std::cin, Value);
		if (Value.empty())
			std::cout << "Error, a saved contact can’t have empty fields\n" << input;
		else if (input == "Phone number\n")
		{
			Valid = true;
			i = 0;
			while (Value[i])
			{
				if (isdigit(Value[i]) == 0)
				{
					std::cout << "Error, wrong number\n";
					Valid = false;
					break;
				}
				i++;
			}
		}
	}
	while(Value.empty() || Valid == false);
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
	if (n < 8)
		n++;
	return;
}

//!SEARCH ───────────────────────────────────────────────────────────────

static std::string Truncat(std::string Value)
{
	int	len;

	len = Value.length();
	if (len > 9)
		Value = Value.substr(0, 9) + '.';
	return (Value);
}

static int VerifNumber(int num)
{
	int index;
	do
	{
		std::cout << "choose a contact from 0 to " << num << '\n';
		std::cin >> index;
		if (index < 0 || index > num)
			std::cout << "invalid index.\n";
	}
	while (index < 0 || index > num);
	return (index);
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
	while (i < n)
	{
		std::cout << '|' << std::setw(10) << i << '|';
		std::cout << std::setw(10) << Truncat(C[i].GetName()) << '|';
		std::cout << std::setw(10) << Truncat(C[i].GetLastName()) << '|';
		std::cout << std::setw(10) << Truncat(C[i].GetNickName()) << '|' << '\n';
		i++;
	}
	i = VerifNumber(n - 1);
	std::cout << C[i].GetName() << '|';
	std::cout << C[i].GetLastName() << '|';
	std::cout << C[i].GetNickName() << '|';
	std::cout << C[i].GetPhoneNumber() << '|';
	std::cout << C[i].GetDarkestSecret() << '|' << '\n';
}

//!EXIT ───────────────────────────────────────────────────────────────

void	PhoneBook::Exit()
{
	exit(0);
}
