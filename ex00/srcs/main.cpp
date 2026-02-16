/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:18:02 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/16 22:50:32 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main()
{
	std::cout << "\n=== Valid (grade 1) ===\n";
	try
	{
		Bureaucrat bureaucrat1("Guendo-Lynh", 1);
		std::cout << bureaucrat1.getName() << " is grade " << bureaucrat1.getGrade() << "\n";
		bureaucrat1.increment();
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n=== Invalid (grade 152) ===\n";
	try
	{
		Bureaucrat bureaucrat2("Meaux-nyk", 152);
		std::cout << bureaucrat2 << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	std::cout << "\n=== Invalid (grade 0) ===\n";
	try
	{
		Bureaucrat bureaucrat3("Kha-reaulle", 0);
		std::cout << bureaucrat3 << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	std::cout << "\n=== Invalid (grade 150 and decrement) ===\n";
	try
	{
		Bureaucrat bureaucrat4("Bain-Djam-Hun", 150);
		std::cout << bureaucrat4 << "\n";
		std::cout << "Attempting to decrement...\n";
		bureaucrat4.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	std::cout << "\n=== Valid increment/decrement ===\n";
	try
	{
		Bureaucrat bureaucrat5("Guy-Heaumme", 75);
		std::cout << bureaucrat5 << "\n";
		std::cout << "Incrementing...\n";
		bureaucrat5.increment();
		std::cout << bureaucrat5 << "\n";
		std::cout << "Decrementing...\n";
		bureaucrat5.decrement();
		std::cout << bureaucrat5 << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	std::cout << "\n";
	return (0);
}