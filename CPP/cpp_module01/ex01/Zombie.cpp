/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:20:47 by msuter            #+#    #+#             */
/*   Updated: 2026/08/27 13:48:08 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::SetName(std::string Value)
{
	Name = Value;
}

std::string	Zombie::GetName()
{
	return (Name);
}

void	Zombie::Announce()
{
	std::cout << GetName() << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
	std::cout << GetName() << " has been destroyed !\n";
}
