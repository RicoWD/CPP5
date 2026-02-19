/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:01:43 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/19 19:36:11 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"
# include "Bureaucrat.hpp"

#include <iostream>
#include <fstream>

#define TREE \
"               ,@@@@@@@,\n" \
"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n" \
"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n" \
"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n" \
"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n" \
"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n" \
"   `&%\\ ` /%&'    |.|        \\ '|8'\n" \
"       |o|        | |         | |\n" \
"       |.|        | |         | |\n" \
"\\/\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_=\n"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	_target;
	    static const int _GRADE_SIGN = 145;
        static const int _GRADE_EXEC = 137;

	public:
	// OCF
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& cpy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& cpy);
		~ShrubberyCreationForm();
		
	// MEMBER FUNCTIONS
		void	execute(Bureaucrat const & executor);
};