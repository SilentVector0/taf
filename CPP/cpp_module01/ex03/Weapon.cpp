/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 16:56:45 by msuter            #+#    #+#             */
/*   Updated: 2026/11/08 12:45:24 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type){}

void	Weapon::setType(std::string Value)
{
	_type = Value;
}

const std::string &Weapon::getType()
{
	return (_type);
}
