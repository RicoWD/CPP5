/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:08:44 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/23 05:12:09 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream> 
# include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string 	_name;
		bool				_isSigned;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;
	
	public:
		// OCF
		AForm();
		AForm(const std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
		AForm(const AForm& cpy);
		AForm& operator=(const AForm& cpy);
		virtual ~AForm();
		
		// GETTERS
		const std::string	getName(void) const;
		bool				getIsSigned(void) const;
		unsigned int		getGradeToSign(void) const;
		unsigned int		getGradeToExecute(void) const;
		
		// MEMBER FUNCTION
		void			beSigned(Bureaucrat& bureaucrat);
		virtual void	execute(Bureaucrat const & executor) = 0;

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
		class NotSignedException: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

// Overload
std::ostream&	operator<<(std::ostream& os, const AForm& rhs);