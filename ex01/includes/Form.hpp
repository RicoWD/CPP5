/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:08:44 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/19 03:00:09 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream> 
# include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string 	_name;
		bool				_isSigned;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;
	
	public:
		// OCF
		Form();
		Form(const std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
		Form(const Form& cpy);
		Form& operator=(const Form& cpy);
		~Form();
		
		// GETTERS
		const std::string	getName(void) const;
		bool				getIsSigned(void) const;
		unsigned int		getGradeToSign(void) const;
		unsigned int		getGradeToExecute(void) const;
		
		// MEMBER FUNCTION
		void beSigned(Bureaucrat& bureaucrat); 

		// EXCEPTIONS
		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

// Overload
std::ostream&	operator<<(std::ostream& os, const Form& rhs);