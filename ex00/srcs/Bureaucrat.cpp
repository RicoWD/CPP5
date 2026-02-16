/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 03:44:05 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/16 04:13:32 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

/* ************************************************************************** */
// 																			  //
// 						   ORTHODOX CANONICAL FORM							  //
//																	 		  //
/* ************************************************************************** */

Bureaucrat::Bureaucrat(): _name("?"), _grade(150)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade): _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy): _name(cpy._name), _grade(cpy._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& cpy)
{
	this->_name = &cpy._name;
	this->_grade = &cpy._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

/* ************************************************************************** */
// 																			  //
// 							   		GETTERS									  //
//																	 		  //
/* ************************************************************************** */

std::string		Bureaucrat::getName(void) const
{
	return (_name);
}


unsigned int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

/* ************************************************************************** */
// 																			  //
// 							   MEMBER FUNCTIONS								  //
//																	 		  //
/* ************************************************************************** */

void	Bureaucrat::increment()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrement()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

/* ************************************************************************** */
// 																			  //
// 							 		 EXCEPTION								  //
//																	 		  //
/* ************************************************************************** */

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	std::cerr	<< Bureaucrat::getName() <<	" bureaucrat grade " << getGrade() << "\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	std::cerr	<< Bureaucrat::getName() <<	" bureaucrat grade " << getGrade() << "\n";
}