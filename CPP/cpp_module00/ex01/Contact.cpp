/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:57:26 by msuter            #+#    #+#             */
/*   Updated: 2026/08/25 15:47:36 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//!Set ───────────────────────────────────────────────────────────────

void			Contact::SetName(std::string Value)
{
	Name = Value;
}
void			Contact::SetNickName(std::string Value)
{
	Nickname = Value;
}
void			Contact::SetLastName(std::string Value)
{
	LastName = Value;
}
void			Contact::SetPhoneNumber(std::string Value)
{
	PhoneNumber = Value;
}
void			Contact::SetDarkestSecret(std::string Value)
{
	DarkestSecret = Value;
}

//!Get ───────────────────────────────────────────────────────────────

std::string		Contact::GetName() const
{
	return (Name);
}
std::string		Contact::GetNickName() const
{
	return (Nickname);
}
std::string		Contact::GetLastName() const
{
	return (LastName);
}
std::string		Contact::GetPhoneNumber() const
{
	return (PhoneNumber);
}
std::string		Contact::GetDarkestSecret() const
{
	return (DarkestSecret);
}
