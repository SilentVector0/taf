/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:09:40 by msuter            #+#    #+#             */
/*   Updated: 2026/08/28 15:19:30 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main ()
{
	std::string Value = "HI THIS IS BRAIN";
	std::string *stringPTR = &Value;
	std::string &stringREF = Value;
}
