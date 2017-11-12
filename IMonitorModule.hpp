/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:35:54 by dzui              #+#    #+#             */
/*   Updated: 2017/11/12 16:35:57 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

#include <iostream>
#include <unistd.h>
#include <sys/utsname.h>
#include <cassert>
#include <fstream>
#include <cstdlib>

#define BUFF_SIZE 	256

class 	IMonitorModule
{
protected:
	std::string		info;
	char 			buff[BUFF_SIZE];
	FILE			*pipe;
public:
					IMonitorModule();
					~IMonitorModule();
	IMonitorModule 	&operator=(const IMonitorModule &m);
					IMonitorModule(const IMonitorModule &m);
	std::string		getInfo() const;
	virtual void	parseInfo() = 0;
};

#endif

