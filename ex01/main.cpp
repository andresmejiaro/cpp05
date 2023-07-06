/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:08:49 by amejia            #+#    #+#             */
/*   Updated: 2023/07/05 22:54:55 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void){
	
	std::cout << "---------Copy And Creation Tests ----------" << std::endl;
	Bureaucrat Conrad("Conrad", 34);
	Form Generic;
	Form Specific("Bussines Loan", 40, 33);
	Form NewForm;

	
	Conrad.signForm(Specific);
	NewForm = Specific;

	std::cout << Specific << std::endl;
	std::cout << NewForm << std::endl;

	Form Specific2("Accident Deductible Form", 24,23);

	Conrad.signForm(Specific2);
	Conrad.signForm(Specific);
	
	std::cout << "---------Exception Test  ----------" << std::endl;
		
	try{
	Form Wrong("Underwear Inspenction",0,123);
	}
	catch(const Form::GradeTooLowException &e){
		std::cout << "Exception Caught: " << e.what() << std::endl;
	}
	catch(const Form::GradeTooHighException &e){
		std::cout << "Exception Caught: " << e.what() << std::endl;
	}

	
	try{
	Form Wrong1("Underwear Protection",1,151);
	}
	catch(const Form::GradeTooLowException &e){
		std::cout << "Exception Caught: " << e.what() << std::endl;
	}
	catch(const Form::GradeTooHighException &e){
		std::cout << "Exception Caught: " << e.what() << std::endl;
	}
	
	
	return (0);
}
