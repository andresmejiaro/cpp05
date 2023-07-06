/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:02:29 by amejia            #+#    #+#             */
/*   Updated: 2023/07/06 01:49:37 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


const char *AForm::GradeTooHighException::what() const throw(){
	return ("Grade is too High!");
}

const char *AForm::GradeTooLowException::what() const throw(){
	return ("Grade is too Low!");
}

const char *AForm::UnsignedException::what() const throw(){
	return ("Order is unsigned!");
}

AForm::AForm(): _name("Empty"),_isSigned(false),_gradeToSign(150),
	_gradeToExecute(150){
	this->_gradeChecker();	
	std::cout << *this << " Created" <<std::endl;
}

AForm::~AForm(){
	std::cout << *this << " Destroyed" <<std::endl;
}

AForm::AForm(const AForm &other): _name(other.getName()),_isSigned(false),
	_gradeToSign(other.getGradeToSign()),
	_gradeToExecute(other.getGradeToExecute()){
	this->_gradeChecker();
}

AForm &AForm::operator=(const AForm &other){
	if (this != &other){
		this->_name = other.getName();
		this->_isSigned = other.getSigned();
		this->_gradeToSign = other.getGradeToSign();
		this->_gradeToExecute = other.getGradeToExecute();
	}
	this->_gradeChecker();
	return (*this);
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute): 
 _name(name),_isSigned(false),_gradeToSign(gradeToSign),
 _gradeToExecute(gradeToExecute){
	std::cout << *this << " Created" <<std::endl;
	this->_gradeChecker();	
}

std::string	AForm::getName() const{
	return (this->_name);
}

bool	AForm::getSigned() const{
	return (this->_isSigned);
}

int	AForm::getGradeToSign() const{
	return(this->_gradeToSign);
}

int AForm::getGradeToExecute() const{
	return(this->_gradeToExecute);
}

bool	AForm::beSigned(const Bureaucrat &officer){
	if (this->getGradeToSign() >= officer.getGrade() 
		&& this->getSigned() == false){
		this->_isSigned = true;
		return (true);
		}
	return (false);
}

std::ostream &operator<<(std::ostream &os, const AForm &form){
	os << "Form: " + form.getName() + " "  << 
		(form.getSigned() ? "Signed, " : "Unsigned, ") <<
		"level to sign: " << form.getGradeToSign() << 
		" level to execute: " << form.getGradeToExecute();  
	return (os);
	
}

void AForm::_gradeChecker(){
	if (this->_gradeToExecute < 1 || this->_gradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (this->_gradeToExecute > 150 || this->_gradeToSign > 150)
		throw AForm::GradeTooLowException();
}


bool AForm::gradeCheckerExecute(const Bureaucrat &executor) const{
	if (this->_gradeToExecute <= executor.getGrade())
		return (true);
	return(false);
}
