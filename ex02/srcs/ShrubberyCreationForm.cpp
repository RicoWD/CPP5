/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:51:51 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/19 15:08:35 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
// 																			  //
// 						   ORTHODOX CANONICAL FORM							  //
//																	 		  //
/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm",  _GRADE_SIGN, _GRADE_EXEC), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy): AForm("ShrubberyCreationForm",  _GRADE_SIGN, _GRADE_EXEC), _target(cpy._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& cpy)
{
	if (this != &cpy)
		_target = cpy._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/* ************************************************************************** */
// 																			  //
// 						   		MEMBER FUNCTIONS							  //
//																	 		  //
/* ************************************************************************** */

void	ShrubberyCreationForm::execute(Bureaucrat& executor)
{
	(void)executor;
	std::string fileNameTree = _target;
	fileNameTree.append("_shrubbery");
	std::ofstream w(fileNameTree.c_str());
	if (w.is_open())
		w << TREE;
	w.close();
}