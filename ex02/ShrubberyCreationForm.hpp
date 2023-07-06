/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:56:30 by amejia            #+#    #+#             */
/*   Updated: 2023/07/06 02:11:04 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#ifndef ShubberyCreationForm_H
#define ShubberyCreationForm_H
#include <ctime>
#include <fstream>

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