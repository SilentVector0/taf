/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 14:43:31 by msuter            #+#    #+#             */
/*   Updated: 2026/11/08 13:02:48 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	long i = 0;
	long N = 10;
	std::cout << "creation of my Horde with: " << N << " Zombies\n";
	Zombie *Z1 = zombieHorde(N, "toto");
	if (!Z1)
		return (1);
	std::cout << "starting my loop Announce\n";
	while (i != N)
	{
		std::cout << "Zombie " << i << " is talking\n";
		Z1[i].announce();
		i++;
	}
	std::cout << "Destruction of my Horde\n";
	delete[] Z1;
}
