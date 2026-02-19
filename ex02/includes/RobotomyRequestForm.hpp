/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:23:10 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/19 11:35:17 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class	RobotomyRequestForm: public AForm
{
	// OCF
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string name);
		RobotomyRequestForm(const RobotomyRequestForm& cpy);
		RobotomyRequestForm operator=(const RobotomyRequestForm& cpy);
		~RobotomyRequestForm();
		
	// MEMBER FUNCTIONS
		void	makeNoise(void);

	// EXCEPTION
	class RobotomyFailed: public std::exception
	{
		public:
			const char* what() const throw();
	};
};