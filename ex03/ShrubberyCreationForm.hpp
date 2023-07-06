/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:56:30 by amejia            #+#    #+#             */
/*   Updated: 2023/07/06 10:46:33 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ShubberyCreationForm_H
#define ShubberyCreationForm_H
#include <ctime>
#include <fstream>
#include "AForm.hpp"

class ShubberyCreationForm: public AForm {
private:
	std::string		_target;
	std::string		_getTree() const;
public:
	ShubberyCreationForm();
	ShubberyCreationForm(std::string target);
	ShubberyCreationForm(const ShubberyCreationForm&);
	~ShubberyCreationForm();
	std::string getTarget() const;
  	ShubberyCreationForm& operator=(const ShubberyCreationForm&);
	virtual bool	execute(Bureaucrat const & executor) const;
};

#endif // ShubberyCreationForm_H