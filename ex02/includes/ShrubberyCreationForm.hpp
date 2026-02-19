/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:01:43 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/19 11:30:00 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
	// OCF
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string name);
		ShrubberyCreationForm(const ShrubberyCreationForm& cpy);
		ShrubberyCreationForm operator=(const ShrubberyCreationForm& cpy);
		~ShrubberyCreationForm();
		
	// MEMBER FUNCTIONS
		void	createFile(void);
		void	createASCIITree(void);
};