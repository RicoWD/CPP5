/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:02:24 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/19 11:59:48 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* ************************************************************************** */
// 																			  //
// 						   ORTHODOX CANONICAL FORM							  //
//																	 		  //
/* ************************************************************************** */

AForm::AForm(): _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& cpy): _name(cpy._name), _isSigned(cpy._isSigned), _gradeToSign(cpy._gradeToSign), _gradeToExecute(cpy._gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& cpy)
{
	if (this != &cpy)
		_isSigned = cpy._isSigned;
	return (*this);
}

AForm::~AForm()
{
}

/* ************************************************************************** */
// 																			  //
// 						   			GETTERS									  //
//																	 		  //
/* ************************************************************************** */

const std::string AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getIsSigned(void) const
{
	return (_isSigned);
}

unsigned int	AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

unsigned int	AForm::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

/* ************************************************************************** */
// 																			  //
// 						   		MEMBER FUNCTIONS							  //
//																	 		  //
/* ************************************************************************** */

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

void	AForm::apply(Bureaucrat& executor)
{
	
}


/* ************************************************************************** */
// 																			  //
// 						   			EXCEPTION								  //
//																	 		  //
/* ************************************************************************** */

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("AForm: Grade Too Low Exception");
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("AForm: Grade Too High Exception");
}

const char	*AForm::NotSignedException::what() const throw()
{
	return ("AForm: Not Signed Exception");
}

/* ************************************************************************** */
// 																			  //
// 						   			OVERLOAD								  //
//																	 		  //
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& os, const AForm& rhs)
{
	os << "AForm " << rhs.getName() << ", signed: " << (rhs.getIsSigned() ? "yes" : "no")
	   << ", grade to sign: " << rhs.getGradeToSign()
	   << ", grade to execute: " << rhs.getGradeToExecute();
	return (os);
}