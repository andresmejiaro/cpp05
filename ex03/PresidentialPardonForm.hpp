/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:41:39 by amejia            #+#    #+#             */
/*   Updated: 2023/07/06 11:11:31 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H
#include "AForm.hpp"
#include <ctime>

class PresidentialPardonForm:public AForm {
private:
	std::string		_target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm&);
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm&);
	virtual bool	execute(Bureaucrat const & executor) const;
	std::string getTarget() const;

};

#endif // PresidentialPardonForm_H