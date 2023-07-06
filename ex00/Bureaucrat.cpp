/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:34:35 by amejia            #+#    #+#             */
/*   Updated: 2023/07/05 17:39:41 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Bureaucrat #1"),_grade(150){
	std::cout << *this	<< " ready to serve the central Bureocracy!" 
		<< std::endl;
	this->_gradeChecker();
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name),_grade(grade){
	std::cout << *this << " ready to serve the central Bureocracy!" 
		<< std::endl;
	this->_gradeChecker();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat & other){
	if (this != &other){
		this->_name = other.getName();
		this->_grade = other.getGrade();
		this->_gradeChecker();
	}
	return (*this);
}


std::string Bureaucrat::getName() const{
	return(this->_name);
}

int	Bureaucrat::getGrade() const{
	return(this->_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other.getName()),_grade(other.getGrade()){
	this->_gradeChecker();
	std::cout << *this	<< " ready to serve the central Bureocracy!"
		<< std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << *this	<< " has left the central Bureocracy!"
		<< std::endl;
}


std::ostream& operator<<(std::ostream &os, const Bureaucrat &obj){
	os << obj.getName() + ", Bureaucrat grade " << obj.getGrade();
	return (os);
}

void Bureaucrat::demote(){
	this->_grade++;
	this->_gradeChecker();
	std::cout << *this << " has been demoted" << std::endl;
}

void Bureaucrat::promote(){
	this->_grade--;
	this->_gradeChecker();
	std::cout << *this << " has been promoted" << std::endl;
}

void Bureaucrat::_gradeChecker(){
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}


const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade is too High!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade is too Low!");
}