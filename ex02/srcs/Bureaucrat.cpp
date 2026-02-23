/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 03:44:05 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/23 05:25:15 by erpascua         ###   ########.fr       */
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
	if (this != &cpy)
		this->_grade = cpy._grade;
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

void	Bureaucrat::signForm(AForm& form)
{
	if (form.getIsSigned())
	{
		std::cout << _name << " cannot sign " << form.getName() << " because it's already signed\n";
		return;
	}
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.what() << "\n";
	}
	
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't execute " << form.getName() << " because " << e.what() << "\n";
	}
}

/* ************************************************************************** */
// 																			  //
// 							 		 EXCEPTION								  //
//																	 		  //
/* ************************************************************************** */

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: Grade Too High Exception");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: Grade Too Low Exception");
}

/* ************************************************************************** */
// 																			  //
// 								OPERATOR OVERLOAD							  //
//																			  //
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (os);
}
