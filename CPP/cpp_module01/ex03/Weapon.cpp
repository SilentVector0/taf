/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 16:56:45 by msuter            #+#    #+#             */
/*   Updated: 2026/09/25 16:45:52 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string data) : _type(data){}

void	Weapon::setType(std::string Value)
{
	_type = Value;
}

const std::string &Weapon::getType() const
{
	return (_type);
}
