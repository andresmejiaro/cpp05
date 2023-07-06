/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:08:49 by amejia            #+#    #+#             */
/*   Updated: 2023/07/06 16:36:52 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void){
	{
	std::srand(std::time(0));
	std::cout << "---Park Testing---" << std::endl;
	
	ShubberyCreationForm Park("Park");
	Bureaucrat Conrad("Conrad", 34);
	Bureaucrat Loser("Loser", 150);
	
	Park.beSigned(Loser);
	try{
		Park.execute(Conrad);
	}
	catch (const AForm::UnsignedException &e){
		std::cout << "Exception Caught: " << e.what() << std::endl;
	}
	Park.beSigned(Conrad);
	try{
	Loser.executeForm(Park);
		
	}
	catch (const AForm::GradeTooLowException &e){
		std::cout << "Exception Caught: " << e.what() << std::endl;
	}
	
	Conrad.executeForm(Park);
	}
	{
	std::cout << "---Robotomy Testing---" << std::endl;
	std::srand(std::time(0));
	RobotomyRequestForm RBender("Bender");
	Bureaucrat Conrad("Conrad", 34);
	Bureaucrat Beholder("Beholder", 11);

	
	RBender.beSigned(Conrad);
	try{
		RBender.execute(Conrad);
	}
	catch (const AForm::UnsignedException &e){
		std::cout << "Exception Caught: " << e.what() << std::endl;
	}
	RBender.beSigned(Conrad);
	try{
		Conrad.executeForm(RBender);
		
	}
	catch (const AForm::GradeTooLowException &e){
		std::cout << "Exception Caught: " << e.what() << std::endl;
	}
	
	Conrad.executeForm(RBender);
	}
	{
	std::cout << "---Presidential Pardon Testing---" << std::endl;
	
	PresidentialPardonForm Zapp("Zapp");
	Bureaucrat One("One", 1);
	Bureaucrat Beholder("Beholder", 11);
	Bureaucrat Conrad("Conrad", 34);
	
	Zapp.beSigned(Conrad);
	try{
		Zapp.execute(Beholder);
	}
	catch (const AForm::UnsignedException &e){
		std::cout << "Exception Caught: " << e.what() << std::endl;
	}
	Beholder.signForm(Zapp);
	try{
		Conrad.executeForm(Zapp);
		
	}
	catch (const AForm::GradeTooLowException &e){
		std::cout << "Exception Caught: " << e.what() << std::endl;
	}
	
	One.executeForm(Zapp);
	}
	return (0);
}
