/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:18:30 by amejia            #+#    #+#             */
/*   Updated: 2023/07/05 17:43:29 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class AForm;
class Bureaucrat
{
private:
	std::string _name;
	int			_grade;
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
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat(std::string name, int grade);
	Bureaucrat &operator=(const Bureaucrat &other);
	std::string	getName() const;
	int			getGrade() const;
	void		promote();
	void		demote();
	void		signForm(AForm &toSign);
	void		executeForm(AForm &toExecute);
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &obj);

#endif