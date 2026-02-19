/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:02:24 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/19 03:44:52 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/* ************************************************************************** */
// 																			  //
// 						   ORTHODOX CANONICAL FORM							  //
//																	 		  //
/* ************************************************************************** */

Form::Form(): _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& cpy): _name(cpy._name), _isSigned(cpy._isSigned), _gradeToSign(cpy._gradeToSign), _gradeToExecute(cpy._gradeToExecute)
{
}

Form& Form::operator=(const Form& cpy)
{
	if (this != &cpy)
		_isSigned = cpy._isSigned;
	return (*this);
}

Form::~Form()
{
}

/* ************************************************************************** */
// 																			  //
// 						   			GETTERS									  //
//																	 		  //
/* ************************************************************************** */

const std::string Form::getName(void) const
{
	return (_name);
}

bool	Form::getIsSigned(void) const
{
	return (_isSigned);
}

unsigned int	Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

unsigned int	Form::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

/* ************************************************************************** */
// 																			  //
// 						   		MEMBER FUNCTIONS							  //
//																	 		  //
/* ************************************************************************** */

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_isSigned = true;
}


/* ************************************************************************** */
// 																			  //
// 						   			EXCEPTION								  //
//																	 		  //
/* ************************************************************************** */

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade Too Low Exception");
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade Too High Exception");
}

/* ************************************************************************** */
// 																			  //
// 						   			OVERLOAD								  //
//																	 		  //
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& os, const Form& rhs)
{
	os << "Form " << rhs.getName() << ", signed: " << (rhs.getIsSigned() ? "yes" : "no")
	   << ", grade to sign: " << rhs.getGradeToSign()
	   << ", grade to execute: " << rhs.getGradeToExecute();
	return (os);
}