/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 03:04:30 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/18 19:20:41 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <exception>
# include <iostream>
# include <string>
# include "Form.hpp"

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;
		
	public:
		// OCF
		Bureaucrat();
		Bureaucrat(const std::string& name, unsigned int grade);
		Bureaucrat(const Bureaucrat& cpy);
		Bureaucrat& operator=(const Bureaucrat& cpy);
		~Bureaucrat();

		// Getters
		std::string		getName(void) const;
		unsigned int	getGrade(void) const;

		// Member Functions
		void			increment(void);
		void			decrement(void);
		void			signForm(Form& form);

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};
	
// Overload
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& rhs);