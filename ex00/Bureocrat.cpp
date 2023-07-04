/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureocrat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:34:35 by amejia            #+#    #+#             */
/*   Updated: 2023/07/04 17:34:05 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureocrat.hpp"

Bureocrat::Bureocrat(): _name("Bureaucrat #1"),_grade(150){
	std::cout << *this	<< " ready to serve the central Bureocracy!" 
		<< std::endl;
	this->_gradeChecker();
}

Bureocrat::Bureocrat(std::string name, int grade): _name(name),_grade(grade){
	std::cout << *this << " ready to serve the central Bureocracy!" 
		<< std::endl;
	this->_gradeChecker();
}

Bureocrat &Bureocrat::operator=(const Bureocrat & other){
	this->_name = other.getName();
	this->_grade = other.getGrade();
	this->_gradeChecker();
	return (*this);
}


std::string Bureocrat::getName() const{
	return(this->_name);
}

int	Bureocrat::getGrade() const{
	return(this->_grade);
}

Bureocrat::Bureocrat(const Bureocrat &other): _name(other.getName()),_grade(other.getGrade()){
	this->_gradeChecker();
	std::cout << *this	<< " ready to serve the central Bureocracy!"
		<< std::endl;
}

Bureocrat::~Bureocrat(){
	std::cout << *this	<< " has left the central Bureocracy!"
		<< std::endl;
}


std::ostream& operator<<(std::ostream &os, const Bureocrat &obj){
	os << obj.getName() + ", bureocrat grade " << obj.getGrade();
	return (os);
}

void Bureocrat::demote(){
	this->_grade++;
	this->_gradeChecker();
	std::cout << *this << " has been demoted" << std::endl;
}

void Bureocrat::promote(){
	this->_grade--;
	this->_gradeChecker();
	std::cout << *this << " has been promoted" << std::endl;
}

void Bureocrat::_gradeChecker(){
	if (this->_grade < 1)
		throw ("GradeTooHigh");
	if (this->_grade > 150)
		throw ("GradeTooLow");
}
