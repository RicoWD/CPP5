/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:44:25 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/23 04:47:59 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ************************************************************************** */
// 																			  //
// 						   ORTHODOX CANONICAL FORM							  //
//																	 		  //
/* ************************************************************************** */

Intern::Intern()
{	
}

Intern::Intern(const Intern& cpy)
{
	(void)cpy;
}

Intern& Intern::operator=(const Intern& cpy)
{
	(void)cpy;
	return (*this);
}

Intern::~Intern()
{	
}

/* ************************************************************************** */
// 																			  //
// 						   		MEMBER FUNCTIONS							  //
//																	 		  //
/* ************************************************************************** */

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string	formNames[3] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			switch (i)
			{
				case 0:
				{
					std::cout << "Intern creates " << formName << "\n";	
					return (new RobotomyRequestForm(formTarget));
				}
				case 1:
				{
					std::cout << "Intern creates " << formName << "\n";
					return (new PresidentialPardonForm(formTarget));
				}
				case 2:
				{
					std::cout << "Intern creates " << formName << "\n";
					return (new ShrubberyCreationForm(formTarget));
				}
			}
		}
	}
	std::cout << "Ow... The form that you are looking for does not exist... Try again!\n";
	return (NULL);
}
