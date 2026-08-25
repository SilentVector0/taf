/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:20:47 by msuter            #+#    #+#             */
/*   Updated: 2026/08/26 00:26:58 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//!SET_GET ───────────────────────────────────────────────────────────────

void	Zombie::SetName(std::string Value)
{
	Name = Value;
}

std::string	Zombie::GetName()
{
	return (Name);
}

void	Zombie::announce()
{
	std::cout << GetName() << ": BraiiiiiiinnnzzzZ...\n";
}
