/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:51:57 by amejia            #+#    #+#             */
/*   Updated: 2023/07/06 21:42:36 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <string>

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	void				_gradeChecker();
public:
	class GradeTooHighException: public std::exception{
	public:
		const char* what() const throw();
	};
	class GradeTooLowException: public std::exception{
	public:
		const char* what() const throw();
	};
	Form();
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);
	Form(const std::string name,int gradeToSign, int gradeToExecute);
	std::string	getName() const;
	bool		getSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;
	bool		beSigned(const Bureaucrat &officer);
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif