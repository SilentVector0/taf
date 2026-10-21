/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 16:09:05 by msuter            #+#    #+#             */
/*   Updated: 2026/10/21 10:25:12 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/verif.hpp"

int	verif_possible()
{
	if (std::cin.fail() == true)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		return (1);
	}
	return (0);
}
