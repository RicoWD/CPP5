/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:03:36 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/19 14:55:35 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
// #include "../includes/PresidentialPardonForm.hpp"
// #include "../includes/RobotomyRequestForm.hpp"

int main()
{
	
	Bureaucrat 				florentMotte;
	ShrubberyCreationForm	fmotte("fmottefmotte");

	fmotte.execute(florentMotte);
}