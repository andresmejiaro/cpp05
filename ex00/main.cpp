/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:08:49 by amejia            #+#    #+#             */
/*   Updated: 2023/07/04 17:33:23 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureocrat.hpp"

int main(void){
	
	std::cout << "---------Copy Tests ----------" << std::endl;
	Bureocrat Conrad("Conrad", 34);
	Bureocrat Bureocrat1;
	Bureocrat Hermes(Conrad);
	Bureocrat Bureocrat2;
	Bureocrat2 = Hermes;
	std::cout << Conrad.getName() << std::endl;
	std::cout << Hermes.getName() << std::endl;
	std::cout << Bureocrat2.getName() << std::endl;
		
	std::cout << "---------Promote Demote Tests ----------" << std::endl;
	Bureocrat Beholder("Beholder Monster", 11);
	std::cout << Beholder << std::endl;
	std::cout << "Caught Sleeping on the Job!!!" << std::endl;
	Beholder.demote();
	std::cout << Beholder << std::endl;
	std::cout << "Restore Grade" << std::endl;
	Beholder.promote();
	std::cout << Beholder << std::endl;
	
	std::cout << "---------Exception Test  ----------" << std::endl;
		
	Bureocrat Vogel("Vogel", 0);

	return (0);
}
