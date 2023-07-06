/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:30:19 by amejia            #+#    #+#             */
/*   Updated: 2023/07/06 12:16:49 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern&);
	~Intern();
	Intern& operator=(const Intern&);
	AForm *makeForm(std::string, std::string);
  // TODO: Add public member functions

private:
	static AForm *newPresidentialPardonForm(std::string);
	static AForm *newRobotomyRequestForm(std::string);
	static AForm *newShubberyCreationForm(std::string);
  // TODO: Add private member variables
};

#endif // Intern_H