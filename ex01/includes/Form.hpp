/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:08:44 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/17 20:46:08 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream> 

class Form
{
	private:
		const std::string 	_name;
		bool				_isSigned;
		const int			_sign;
		const int			_execute;
	
	public:
		// OCF
		Form();
		Form(const std::string name);
		Form(const Form& cpy);
		~Form();
		
		// GETTERS
		const std::string	getName(void);
		bool				getIsSigned(void);
		const int			getSign(void);
		const int			getExecute(void);
};