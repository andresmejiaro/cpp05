/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:08:49 by amejia            #+#    #+#             */
/*   Updated: 2023/07/05 18:06:32 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void){
	
	std::cout << "---------Copy Tests ----------" << std::endl;
	Bureaucrat Conrad("Conrad", 34);
	Bureaucrat Bureaucrat1;
	Bureaucrat Hermes(Conrad);
	Bureaucrat Bureaucrat2;
	Bureaucrat2 = Hermes;
	std::cout << Conrad.getName() << std::endl;
	std::cout << Hermes.getName() << std::endl;
	std::cout << Bureaucrat2.getName() << std::endl;
		
	std::cout << "---------Promote Demote Tests ----------" << std::endl;
	Bureaucrat Beholder("Beholder Monster", 11);
	std::cout << Beholder << std::endl;
	std::cout << "Caught Sleeping on the Job!!!" << std::endl;
	Beholder.demote();
	std::cout << Beholder << std::endl;
	std::cout << "Restore Grade" << std::endl;
	Beholder.promote();
	std::cout << Beholder << std::endl;
	
	std::cout << "---------Exception Test  ----------" << std::endl;
		
	try{
		Bureaucrat Vogel("Vogel", 0);
	}
	catch(const Bureaucrat::GradeTooHighException &e){
		std::cerr << "Exception caught: " << e.what() << "\n";
	}
	catch(const Bureaucrat::GradeTooLowException &e){
		std::cerr << "Exception caught: " << e.what() << "\n";
	}
	
	try{
		Bureaucrat Loser("Loser", 150);
		Loser.demote();
	}
	catch(const Bureaucrat::GradeTooHighException &e){
		std::cerr << "Exception caught: " << e.what() << "\n";
	}
	catch(const Bureaucrat::GradeTooLowException &e){
		std::cerr << "Exception caught: " << e.what() << "\n";
	}

	return (0);
}
