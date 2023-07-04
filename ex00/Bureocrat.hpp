/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureocrat.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:18:30 by amejia            #+#    #+#             */
/*   Updated: 2023/07/04 17:26:25 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREOCRAT_HPP
# define BUREOCRAT_HPP

#include <string>
#include <iostream>

class Bureocrat
{
private:
	std::string _name;
	int			_grade;
	void		_gradeChecker();
public:
	Bureocrat();
	~Bureocrat();
	Bureocrat(const Bureocrat &other);
	Bureocrat(std::string name, int grade);
	Bureocrat &operator=(const Bureocrat &other);
	std::string	getName() const;
	int getGrade() const;
	void promote();
	void demote();

};

std::ostream& operator<<(std::ostream &os, const Bureocrat &obj);

#endif