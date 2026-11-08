/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 12:00:05 by msuter            #+#    #+#             */
/*   Updated: 2026/11/08 13:01:12 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::cout << "Creation toto with randomChump (stack)\n";
	randomChump("toto");

	std::cout << "creation foo with newZombie (heap)\n";
	Zombie* Z2 = newZombie("foo");
	std::cout << "zombie foo has been created, we can now call the announce.\n";
	Z2->announce();
	std::cout << "deleting my zombie 2\n";
	delete Z2;
}
