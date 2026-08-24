/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:57:37 by msuter            #+#    #+#             */
/*   Updated: 2026/08/24 23:12:23 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <cstdlib>
#include <iomanip>

class PhoneBook
{
	private:
		Contact	C[8];
		int		pos;

	public:
		PhoneBook();
		void	Add();
		void	Search();
		void	Exit();
};
