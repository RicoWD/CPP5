/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:30:37 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/19 11:30:56 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
	// OCF
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string name);
		PresidentialPardonForm(const PresidentialPardonForm& cpy);
		PresidentialPardonForm operator=(const PresidentialPardonForm& cpy);
		~PresidentialPardonForm();
		
	// MEMBER FUNCTIONS
		void	createFile(void);
		void	createASCIITree(void);
};