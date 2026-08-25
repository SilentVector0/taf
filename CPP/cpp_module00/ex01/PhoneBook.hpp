/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:57:37 by msuter            #+#    #+#             */
/*   Updated: 2026/08/25 15:09:27 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

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
