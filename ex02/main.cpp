/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:08:49 by amejia            #+#    #+#             */
/*   Updated: 2023/07/06 02:10:39 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void){
	
	std::cout << "---ParkTesting---" << std::endl;
	
	ShubberyCreationForm Park("Park");
	Bureaucrat Conrad("Conrad", 34);
	Bureaucrat Loser("Loser", 150);
	
	Park.beSigned(Loser);
	Park.beSigned(Conrad);
	Loser.executeForm(Park);
	
	return (0);
}
