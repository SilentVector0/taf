/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 14:43:31 by msuter            #+#    #+#             */
/*   Updated: 2026/08/28 15:03:55 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int i = 0;
	int N = 5;
	std::cout << "creation of my Horde with: " << N << " Zombies\n";
	Zombie *Z1 = zombieHorde(N, "toto");
	std::cout << "starting my loop Announce\n";
	while (i != N)
	{
		std::cout << "Zombie " << i << " is talking\n";
		Z1[i].Announce();
		i++;
	}
	std::cout << "Destruction of my Horde\n";
	delete[] Z1;
}
