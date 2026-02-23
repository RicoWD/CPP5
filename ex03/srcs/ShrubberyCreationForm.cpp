/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:51:51 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/19 19:38:24 by erpascua         ###   ########.fr       */
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

void	ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException(); 
	if (executor.getGrade() <= this->getGradeToExecute())
	{
		std::string fileNameTree = _target;
		fileNameTree.append("_shrubbery");
		std::ofstream w(fileNameTree.c_str());
		if (w.is_open())
		w << TREE;
		w.close();
		std::cout << "File " << fileNameTree << " has been created\n";
	}
	else
		throw AForm::GradeTooLowException();
}