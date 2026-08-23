/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:57:31 by msuter            #+#    #+#             */
/*   Updated: 2026/08/23 15:57:32 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact
{
private:
	std::string Name;
	std::string Nickname;
	std::string LastName;
	std::string PhoneNumber;
	std::string DarkestSecret;

public:
	void			SetName(std::string Value);
	void			SetNickName(std::string Value);
	void			SetLastName(std::string Value);
	void			SetPhoneNumber(std::string Value);
	void			SetDarkestSecret(std::string Value);
	std::string		GetName()			const;
	std::string		GetNickName()		const;
	std::string		GetLastName()		const;
	std::string		GetPhoneNumber()	const;
	std::string		GetDarkestSecret()	const;
};
