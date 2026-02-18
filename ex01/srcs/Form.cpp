/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:02:24 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/18 19:12:48 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ************************************************************************** */
// 																			  //
// 						   ORTHODOX CANONICAL FORM							  //
//																	 		  //
/* ************************************************************************** */

Form::Form(): _name("default") 
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{

}

Form::Form(const Form& cpy)
{
	if (this != &cpy)
		_name = cpy._name;
}

Form& Form::operator=(const Form& cpy)
{
	_name		= cpy._name;
	_isSigned	= cpy._isSigned;
}

Form::~Form()
{
}

/* ************************************************************************** */
// 																			  //
// 						   			GETTERS									  //
//																	 		  //
/* ************************************************************************** */

const std::string Form::getName(void)
{
	return (_name);
}

bool	Form::getIsSigned(void)
{
	return (_isSigned);
}

const int	Form::getGradeToSign(void)
{
	return (_gradeToSign);
}

const int	Form::getGradeToExecute(void)
{
	return (_gradeToExecute);
}

/* ************************************************************************** */
// 																			  //
// 						   		MEMBER FUNCTIONS							  //
//																	 		  //
/* ************************************************************************** */

void	Form::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << 
	}
	catch
	{

	}
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

std::ostream& operator<<(std::ostream& os, Form& rhs)
{
	os << rhs.getName() << ""
}