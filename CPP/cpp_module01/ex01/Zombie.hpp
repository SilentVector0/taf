/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:08:00 by msuter            #+#    #+#             */
/*   Updated: 2026/11/12 13:48:11 by msuter           ###   ########.fr       */
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
		void		announce();
		std::string	GetName();
		void		SetName(std::string Value);
};

Zombie* newZombie( std::string name );
Zombie *zombieHorde(long N, std::string name );

#endif
