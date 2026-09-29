/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 10:50:27 by msuter            #+#    #+#             */
/*   Updated: 2026/09/08 11:19:29 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main (int argc, char **argv)
{
	int i = 1;
	int j = 0;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			std::cout << (char)std::toupper(argv[i][j]);
			j++;
		}
		i++;
	}
	std::cout << '\n';
	return(0);
}
