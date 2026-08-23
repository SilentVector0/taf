/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:57:37 by msuter            #+#    #+#             */
/*   Updated: 2026/08/23 16:36:27 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <cstdlib>

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
