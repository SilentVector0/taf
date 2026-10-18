/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:57:37 by msuter            #+#    #+#             */
/*   Updated: 2026/10/18 16:17:38 by msuter           ###   ########.fr       */
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
