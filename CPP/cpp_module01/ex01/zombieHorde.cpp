/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 14:03:28 by msuter            #+#    #+#             */
/*   Updated: 2026/11/08 12:42:10 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(long N, std::string name )
{
	long	i = 0;
	if (N <= 0)
	{
		std::cout << "error, a zombie Horde cant be empty or negative\n";
		return (NULL);
	}
	if (N > 100000)
	{
		std::cout << "error, too big number, please respect my computer\n";
		return (NULL);
	}
	Zombie *Horde = new Zombie[N];
	if (!Horde)
	{
		std::cout << "error during the allocation\n";
		return (NULL);
	}
	while (i != N)
	{
		Horde[i].SetName(name);
		i++;
	}
	return (Horde);
}
