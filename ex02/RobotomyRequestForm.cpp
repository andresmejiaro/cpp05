/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:56:30 by amejia            #+#    #+#             */
/*   Updated: 2023/07/06 16:36:31 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): 
	AForm("Robotomy Request Form", 72, 45),_target("No one"){
	
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): 
	AForm("Robotomy Request Form", 72, 45),_target(target){
	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
	AForm(other),_target(other.getTarget()){
		
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	if (this != &other){
		AForm::operator=(other);
		this->_target = other.getTarget();
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
	
}

std::string	RobotomyRequestForm::getTarget() const{
	return (this->_target);
}

bool RobotomyRequestForm::execute(Bureaucrat const &executor) const{
	if (this->gradeCheckerExecute(executor) && this->getSigned() == true){
		std::cout << "* Drilling Noises * \n";
		if (std::rand() % 2){
			std::cout << _target + " has been robotomized\n";
			return (true);
		}
		else
		std::cout << "robotomy failed\n";
		return (true);
	}
	else if (!this->getSigned()){
		throw (AForm::UnsignedException());
	}
	else 
		throw (AForm::GradeTooLowException());
	return (false);
}

