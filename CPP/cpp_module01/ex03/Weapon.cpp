/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 16:56:45 by msuter            #+#    #+#             */
/*   Updated: 2026/09/30 14:57:49 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type){}

void	Weapon::setType(std::string Value)
{
	_type = Value;
}

const std::string &Weapon::GetType()
{
	return (_type);
}
