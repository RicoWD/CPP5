/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:18:02 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/16 15:10:13 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main()
{
	std::cout << "\nGuendo-Lynh\n";

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

	std::cout << "\nMeaux-nik\n";

	try
	{
		Bureaucrat bureaucrat2("Meaux-nik", 152);
		std::cout << bureaucrat2.getName() << " is grade " << bureaucrat2.getGrade() << "\n";
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
}