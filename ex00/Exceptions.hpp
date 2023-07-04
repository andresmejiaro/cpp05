/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:45:23 by amejia            #+#    #+#             */
/*   Updated: 2023/07/04 17:50:16 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

class BaseExeption: public std::exception
{
	public:
		const char *what() const noexcept override;	
};

class GradeTooHigh: public BaseExeption
{
	public:
		const char *what() const noexcept override;	
};

class GradeTooLow: public BaseExeption
{
	
	public:
		const char *what() const noexcept override;	
};