/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:30:37 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/19 15:02:56 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
	    static const int _GRADE_SIGN = 25;
        static const int _GRADE_EXEC = 5;

	public:
	// OCF
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string name);
		PresidentialPardonForm(const PresidentialPardonForm& cpy);
		PresidentialPardonForm operator=(const PresidentialPardonForm& cpy);
		~PresidentialPardonForm();
		
	// MEMBER FUNCTIONS
		void	execute(Bureaucrat& executor);
};