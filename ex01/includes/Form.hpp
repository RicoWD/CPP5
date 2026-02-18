/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:08:44 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/18 16:44:42 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream> 
# include <exception>

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string 	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	
	public:
		// OCF
		Form();
		Form(const std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form& cpy);
		~Form();
		
		// GETTERS
		const std::string	getName(void);
		bool				getIsSigned(void);
		const int			getGradeToSign(void);
		const int			getGradeToExecute(void);
		
		// MEMBER FUNCTION
		void beSigned(Bureaucrat& bureaucrat); 

		// Exceptions
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException
		{
			public:
				const char* what() const throw();
		};
};

// Overload
std::ostream&	operator<<(std::ostream& os, Bureaucrat& rhs);