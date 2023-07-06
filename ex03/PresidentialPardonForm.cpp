/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:56:30 by amejia            #+#    #+#             */
/*   Updated: 2023/07/06 10:55:48 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): 
	AForm("Presidential Pardon Form", 25, 5),_target("No one"){
	
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): 
	AForm("Presidential Pardon Form", 25, 5),_target(target){
	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
	AForm(other),_target(other.getTarget()){
		
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	if (this != &other){
		AForm::operator=(other);
		this->_target = other.getTarget();
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
	
}

std::string	PresidentialPardonForm::getTarget() const{
	return (this->_target);
}

bool PresidentialPardonForm::execute(Bureaucrat const &executor) const{
	if (this->gradeCheckerExecute(executor) && this->getSigned() == true){
		std::cout << _target + " has been pardoned by Zaphod Beeblebrox\n";
	}
	else if (!this->getSigned()){
		throw (AForm::UnsignedException());
	}
	else 
		throw (AForm::GradeTooLowException());
	return (false);
}

