/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 16:56:35 by msuter            #+#    #+#             */
/*   Updated: 2026/11/08 12:45:33 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	public:
							Weapon(std::string type);
		void				setType(std::string Value);
		const std::string	&getType();

	private:
		std::string _type;
};

#endif
