/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:58:07 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/23 04:05:44 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
	public:
		// OCF
		Intern();
		Intern(const Intern& cpy);
		Intern& operator=(const Intern& cpy);
		~Intern();

		// Member Functions
		AForm *makeForm(std::string formName, std::string formTarget);
};