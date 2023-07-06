/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:51:57 by amejia            #+#    #+#             */
/*   Updated: 2023/07/06 02:09:38 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"
# include <string>

class AForm
{
private:
	std::string	_name;
	bool		_isSigned;
	int			_gradeToSign;
	int			_gradeToExecute;
	void		_gradeChecker();
public:
	class GradeTooHighException: public std::exception{
	public:
		const char* what() const throw();
	};
	class GradeTooLowException: public std::exception{
	public:
		const char* what() const throw();
	};
	class UnsignedException: public std::exception{
	public:
		const char* what() const throw();
	};
	bool		gradeCheckerExecute(const Bureaucrat &executor) const;
	AForm();
	~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	AForm(const std::string name,int gradeToSign, int gradeToExecute);
	std::string		getName() const;
	bool			getSigned() const;
	int				getGradeToSign() const;
	int				getGradeToExecute() const;
	bool			beSigned(const Bureaucrat &officer);
	virtual bool	execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif