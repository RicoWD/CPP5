/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:58:23 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/19 18:57:36 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* ************************************************************************** */
// 																			  //
// 						   ORTHODOX CANONICAL FORM							  //
//																	 		  //
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", _GRADE_SIGN, _GRADE_EXEC), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy): AForm("RobotomyRequestForm", _GRADE_SIGN, _GRADE_EXEC), _target(cpy._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& cpy)
{
	if (this != &cpy)
		_target = cpy._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

/* ************************************************************************** */
// 																			  //
// 						   		MEMBER FUNCTIONS							  //
//																	 		  //
/* ************************************************************************** */

void	RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() <= this->getGradeToExecute())
	{
		if (std::rand() % 2 == 0)
			std::cout << _target << " has been robotomized succesfully !\n";
		else
			std::cout << "Ow... the robotomy of " << _target << " has failed\n";
	}
	else
		throw AForm::GradeTooLowException();
}
