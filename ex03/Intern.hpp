/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:30:19 by amejia            #+#    #+#             */
/*   Updated: 2023/07/06 21:40:13 by amejia           ###   ########.fr       */
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

private:
	AForm *newPresidentialPardonForm(std::string);
	AForm *newRobotomyRequestForm(std::string);
	AForm *newShubberyCreationForm(std::string);
};

#endif // Intern_H