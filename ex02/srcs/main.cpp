/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:03:36 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/19 20:09:06 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

int main()
{
	srand(time(0));
	// 

	std::cout << "=== VALID: Shrubbery Creation Form ===\n";
	try
	{
		Bureaucrat 				florentMotte("Billy", 20);
		ShrubberyCreationForm	fmotte("fmottefmotte");
		fmotte.beSigned(florentMotte);
		fmotte.execute(florentMotte);
		std::cout << "Grade to sign: " << fmotte.getGradeToSign() << "\nGrade to exec: " << fmotte.getGradeToExecute() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	// 
	std::cout << "\n=== VALID: Robotomy Request Form ===\n";
	try
	{
		Bureaucrat				guillaumePollastri("Billy", 20);
		RobotomyRequestForm		gpollast("La Pollast");
		gpollast.beSigned(guillaumePollastri);
		gpollast.execute(guillaumePollastri);
		std::cout << "Grade to sign: " << gpollast.getGradeToSign() << "\nGrade to exec: " << gpollast.getGradeToExecute() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// 
	std::cout << "\n=== VALID: Presidential Pardon Form ===\n";
	try
	{
		Bureaucrat				tomLorette("Tommy", 5);
		PresidentialPardonForm	tlorette("La Lorette");
		tlorette.beSigned(tomLorette);
		tlorette.execute(tomLorette);
		std::cout << "Grade to sign: " << tlorette.getGradeToSign() << "\nGrade to exec: " << tlorette.getGradeToExecute() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// 
	std::cout << "\n=== INVALID: Presidential Pardon Form ===\n";
	try
	{
		Bureaucrat				benSuger("Benjy", 18);
		PresidentialPardonForm	bSuger("La Lorette");
	
		bSuger.beSigned(benSuger);
		bSuger.execute(benSuger);
		std::cout << "Grade to sign: " << bSuger.getGradeToSign() << "\nGrade to exec: " << bSuger.getGradeToExecute() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	} 
}
