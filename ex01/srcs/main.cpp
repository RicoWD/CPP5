/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 03:02:18 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/19 03:44:13 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main()
{
	std::cout << "\n=== Valid (good grades) ===\n";
	try
	{
		Form form1("FormyOk_1", 50, 25);
		std::cout << form1 << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << "\n=== Invalid (grade 0) ===\n";
	try
	{
		Form form2("FormyKO_1", 0, 50);
		std::cout << form2 << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << "\n=== Invalid (grade 200) ===\n";
	try
	{
		Form form3("FormyKO_2", 50, 200);
		std::cout << form3 << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << "\n=== Valid (grade > gradeToSign) ===\n";
	try
	{
		Bureaucrat guendoLyhn("Guendo-Lyhn", 30);
		Form form4("FormOK_2", 50, 25);
		std::cout << "Before sign: " << form4 << "\n";
		guendoLyhn.signForm(form4);
		std::cout << "After sign: " << form4 << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << "\n=== Invalid (grade < gradeToSign) ===\n";
	try
	{
		Bureaucrat meauxNik("Meaux-Nik", 100);
		Form form5("FormKO_3", 50, 25);
		std::cout << "Before sign: " << form5 << "\n";
		meauxNik.signForm(form5);
		std::cout << "After sign: " << form5 << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << "\n=== Valid (grade == gradeToSign) ===\n";
	try
	{
		Bureaucrat guyHeaume("Guy-Heaume", 75);
		Form form6("FormOK_3", 75, 50);
		std::cout << "Before sign: " << form6 << "\n";
		guyHeaume.signForm(form6);
		std::cout << "After sign: " << form6 << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << "\n=== Invalid (grade > gradeToSign & isSign true) ===\n";
	try
	{
		Bureaucrat benDjamHun("Ben-Djam-Hun", 1);
		Form form7("FormOK_4", 100, 50);
		std::cout << form7 << "\n";
		benDjamHun.signForm(form7);
		std::cout << form7 << "\n";
		benDjamHun.signForm(form7);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	return 0;
}