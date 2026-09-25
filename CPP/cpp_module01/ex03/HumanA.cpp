/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:16:23 by msuter            #+#    #+#             */
/*   Updated: 2026/09/25 16:49:46 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& W) : _weapon(W), _name(name){}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << '\n';
}
