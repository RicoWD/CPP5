/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:23:10 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/19 18:44:26 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"
# include "Bureaucrat.hpp"

# include <cstdlib>
# include <ctime>

class	RobotomyRequestForm: public AForm
{
	private:
		std::string _target;
	    static const int _GRADE_SIGN	= 72;
        static const int _GRADE_EXEC	= 45;

	public:
	// OCF
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& cpy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& cpy);
		~RobotomyRequestForm();
		
	// MEMBER FUNCTIONS
		void	execute(Bureaucrat const & executor) const;

	// EXCEPTION
	class RobotomyFailed: public std::exception
	{
		public:
			const char* what() const throw() {return "Robotomy Failed Exception";};
	};
};