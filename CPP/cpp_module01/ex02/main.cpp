/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 15:09:40 by msuter            #+#    #+#             */
/*   Updated: 2026/08/28 16:54:13 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main ()
{
	std::string Value = "HI THIS IS BRAIN";
	std::string *stringPTR = &Value;
	std::string &stringREF = Value;

	std::cout << "printing adress of my string: " << &Value << '\n';
	std::cout << "printing adress of my stringPTR " << stringPTR << '\n';
	std::cout << "printing adress of my stringREF " << &stringREF << '\n';

	std::cout << "printing the value of my string " << Value << '\n';
	std::cout << "printing the value of my stringPTR " << *stringPTR << '\n';
	std::cout << "printing the value of my stringREF " << stringREF << '\n';
}
