/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:35:36 by amejia            #+#    #+#             */
/*   Updated: 2023/07/06 16:18:47 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern(){

}

Intern::~Intern(){
	
}

Intern& Intern::operator=(const Intern&other)
{
	(void) other;
	return(*this);
}

Intern::Intern(const Intern& other){
	(void) other;
}

AForm *Intern::newPresidentialPardonForm(std::string target){
	AForm *request = new PresidentialPardonForm(target);	
	return (request);
}

AForm *Intern::newShubberyCreationForm(std::string target){
	AForm *request = new ShubberyCreationForm(target);	
	return (request);
}

AForm *Intern::newRobotomyRequestForm(std::string target){
	AForm *request = new RobotomyRequestForm(target);	
	return (request);
}

AForm * Intern::makeForm(std::string formString,std::string target){
	std::string formNames[] = {"presidential pardon", "robotomy request", "shubbery creation"};
	AForm* (Intern::*formConstructors[])(std::string) = {
        &Intern::newPresidentialPardonForm, 
        &Intern::newRobotomyRequestForm, 
        &Intern::newShubberyCreationForm
    };
		
	for (unsigned int i = 0; i < sizeof(formNames)/sizeof(*formNames); i++){
		if (formString == formNames[i]){
			std::cout << "Intern creates " << formNames[i] << std::endl;
			return (this->*formConstructors[i])(target);
		}
	}
	std::cout << "Intern failed to create anything " << std::endl;
	return (NULL);		
}


