/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:02:29 by amejia            #+#    #+#             */
/*   Updated: 2023/07/05 22:52:14 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


const char *Form::GradeTooHighException::what() const throw(){
	return ("Grade is too High!");
}

const char *Form::GradeTooLowException::what() const throw(){
	return ("Grade is too Low!");
}

Form::Form(): _name("Empty"),_isSigned(false),_gradeToSign(150),
	_gradeToExecute(150){
	this->_gradeChecker();	
	std::cout << *this << " Created" <<std::endl;
}

Form::~Form(){
	std::cout << *this << " Destroyed" <<std::endl;
}

Form::Form(const Form &other): _name(other.getName()),_isSigned(false),
	_gradeToSign(other.getGradeToSign()),
	_gradeToExecute(other.getGradeToExecute()){
	this->_gradeChecker();
}

Form &Form::operator=(const Form &other){
	if (this != &other){
		this->_name = other.getName();
		this->_isSigned = other.getSigned();
		this->_gradeToSign = other.getGradeToSign();
		this->_gradeToExecute = other.getGradeToExecute();
	}
	this->_gradeChecker();
	return (*this);
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute): 
 _name(name),_isSigned(false),_gradeToSign(gradeToSign),
 _gradeToExecute(gradeToExecute){
	std::cout << *this << " Created" <<std::endl;
	this->_gradeChecker();	
}

std::string	Form::getName() const{
	return (this->_name);
}

bool	Form::getSigned() const{
	return (this->_isSigned);
}

int	Form::getGradeToSign() const{
	return(this->_gradeToSign);
}

int Form::getGradeToExecute() const{
	return(this->_gradeToExecute);
}

bool	Form::beSigned(const Bureaucrat &officer){
	if (this->getGradeToSign() >= officer.getGrade() 
		&& this->getSigned() == false){
		this->_isSigned = true;
		return (true);
		}
	return (false);
}

std::ostream &operator<<(std::ostream &os, const Form &form){
	os << "Form: " + form.getName() + " "  << 
		(form.getSigned() ? "Signed, " : "Unsigned, ") <<
		"level to sign: " << form.getGradeToSign() << 
		" level to execute: " << form.getGradeToExecute();  
	return (os);
	
}

void Form::_gradeChecker(){
	if (this->_gradeToExecute < 1 || this->_gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeToExecute > 150 || this->_gradeToSign > 150)
		throw Form::GradeTooLowException();
}
