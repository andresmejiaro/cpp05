/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:41:39 by amejia            #+#    #+#             */
/*   Updated: 2023/07/06 10:52:47 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H
#include "AForm.hpp"
#include <ctime>

class RobotomyRequestForm:public AForm {
private:
	std::string		_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm&);
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm&);
	virtual bool	execute(Bureaucrat const & executor) const;
	std::string getTarget() const;

};

#endif // RobotomyRequestForm_H