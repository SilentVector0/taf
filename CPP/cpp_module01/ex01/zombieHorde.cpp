/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 14:03:28 by msuter            #+#    #+#             */
/*   Updated: 2026/08/28 14:42:28 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name )
{
	int	i = 0;
	Zombie *Horde = new Zombie[N];

	while (i != N)
	{
		Horde[i].SetName(name);
		i++;
	}
	return (Horde);
}
