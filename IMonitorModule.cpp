/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:35:47 by dzui              #+#    #+#             */
/*   Updated: 2017/11/12 16:35:48 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorModule.hpp"

IMonitorModule::IMonitorModule() : info(""), pipe(NULL)
{

}

IMonitorModule::~IMonitorModule()
{

}

IMonitorModule		&IMonitorModule::operator=(const IMonitorModule &m)
{
	info = m.info;
	pipe = m.pipe;
	strcpy(buff, m.buff);
	return (*this);
}

IMonitorModule::IMonitorModule(const IMonitorModule &m)
{
	info = m.info;
	pipe = m.pipe;
	strcpy(buff, m.buff);
}

std::string		IMonitorModule::getInfo() const
{
	return (info);
}
