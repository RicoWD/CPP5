/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:40:29 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/19 18:15:43 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* ************************************************************************** */
// 																			  //
// 						   ORTHODOX CANONICAL FORM							  //
//																	 		  //
/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", _GRADE_SIGN, _GRADE_EXEC), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy): AForm("PresidentialPardonForm", _GRADE_SIGN, _GRADE_EXEC), _target(cpy._target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& cpy)
{
	if (this != &cpy)
		_target = cpy._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

/* ************************************************************************** */
// 																			  //
// 						   		MEMBER FUNCTIONS							  //
//																	 		  //
/* ************************************************************************** */

void	PresidentialPardonForm::execute(Bureaucrat const & executor)
{
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() <= this->getGradeToExecute())
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
	else
		throw AForm::GradeTooLowException();
}
