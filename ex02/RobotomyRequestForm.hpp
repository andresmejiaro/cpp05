/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:41:39 by amejia            #+#    #+#             */
/*   Updated: 2023/07/06 16:30:01 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H
#include "AForm.hpp"
#include <ctime>
#include <cstdlib>  

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