/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:57:37 by msuter            #+#    #+#             */
/*   Updated: 2026/10/19 10:24:08 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <sstream>

class PhoneBook
{
	private:
		Contact	C[8];
		int		pos;
		int		n;

	public:
		PhoneBook();
		void	Add();
		void	Search();
		void	Exit();
};

#endif
