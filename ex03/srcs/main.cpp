/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 04:10:57 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/23 04:46:41 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Intern.hpp"

int main()
{
	srand(time(0));
	// 
	std::cout << "=== VALID: Shrubbery Creation Form ===\n";
	try
	{
		Intern 				minicube;
		AForm *form = minicube.makeForm("shrubbery creation", "fmotte");
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	// 
	std::cout << "\n=== VALID: Presidential Pardon Form ===\n";
	try
	{
		Intern 				laguigue;
		AForm *form = laguigue.makeForm("presidential pardon", "gpollast");
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	// 
	std::cout << "\n=== VALID: Robotomy Request Form ===\n";
	try
	{
		Intern 				sugerdaddy;
		AForm *form = sugerdaddy.makeForm("robotomy request", "bsuger");
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	// 
	std::cout << "\n=== INVALID: Form Does Not Exist ===\n";
	try
	{
		Intern 				tommassaint;
		AForm *form = tommassaint.makeForm("hum it doesn't exist", "tommassaint");
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}