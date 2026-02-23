/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:40:29 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/23 05:30:31 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* ************************************************************************** */
// 																			  //
// 						   ORTHODOX CANONICAL FORM							  //
//																	 		  //
/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", _GRADE_SIGN, _GRADE_EXEC), _target("default")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", _GRADE_SIGN, _GRADE_EXEC), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy): AForm(cpy), _target(cpy._target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& cpy)
{
	if (this != &cpy)
	{
		AForm::operator=(cpy);
		_target = cpy._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

/* ************************************************************************** */
// 																			  //
// 						   		MEMBER FUNCTIONS							  //
//																	 		  //
/* ************************************************************************** */

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}
