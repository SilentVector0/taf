/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:08:00 by msuter            #+#    #+#             */
/*   Updated: 2026/08/28 14:50:13 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string Name;

	public:
					~Zombie();
		void		Announce();
		std::string	GetName();
		void		SetName(std::string Value);
};

Zombie* newZombie( std::string name );
void randomChump(std::string name);
Zombie *zombieHorde( int N, std::string name );

#endif
