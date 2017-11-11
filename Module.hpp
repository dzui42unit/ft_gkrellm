/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Module.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <arodiono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:54:06 by dzui              #+#    #+#             */
/*   Updated: 2017/11/11 22:41:52 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_HPP
#define MODULE_HPP

#include <iostream>
#include <unistd.h>
#include <sys/utsname.h>
#include <cassert>
#include <fstream>
#include <cstdlib>
#include "Window.hpp"

#define BUFF_SIZE 256

class 	Module : public Window
{
protected:
	std::string		info;
	char 			buff[BUFF_SIZE];
	FILE			*pipe;
public:
					Module();
					~Module();
	Module 			&operator=(const Module &m);
					Module(const Module &m);
	std::string		getInfo() const;
	virtual void	parseInfo() = 0;
};

#endif

