/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:08:49 by amejia            #+#    #+#             */
/*   Updated: 2023/07/06 16:33:57 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

void leaks(){
	system("leaks central");
}


int main(void){
{
	//atexit(leaks);
	std::srand(std::time(0));
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	

	std::cout << "---Robotomy Testing---" << std::endl;
	
	Bureaucrat Conrad("Conrad", 34);
	Bureaucrat Beholder("Beholder", 11);

	
	(*rrf).beSigned(Conrad);
	try{
		(*rrf).execute(Conrad);
	}
	catch (const AForm::UnsignedException &e){
		std::cout << "Exception Caught: " << e.what() << std::endl;
	}
	(*rrf).beSigned(Conrad);
	try{
		Conrad.executeForm(*rrf);
		
	}
	catch (const AForm::GradeTooLowException &e){
		std::cout << "Exception Caught: " << e.what() << std::endl;
	}
	
	Conrad.executeForm(*rrf);
	delete rrf;
	return (0);
	}
}
