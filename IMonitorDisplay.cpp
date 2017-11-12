/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:47:51 by dzui              #+#    #+#             */
/*   Updated: 2017/11/12 16:47:53 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay() 
{
	hn = new HostName();
	os = new OsModule();
	tm = new TimeModule();
	cp = new CpuModule();
	mm = new MemoryModule();
	nm = new NetwModule();
	hn->parseInfo();
	os->parseInfo();
	tm->parseInfo();
	cp->parseInfo();
	mm->parseInfo();
}

			IMonitorDisplay::~IMonitorDisplay()
{
	delete hn;
	delete os;
	delete tm;
	delete cp;
	delete mm;
	delete nm;
}

IMonitorDisplay 	&IMonitorDisplay::operator=(const IMonitorDisplay &im)
{
	*(this->hn) = *(im.hn);
	*(this->os) = *(im.os);
	*(this->tm) = *(im.tm);
	*(this->cp) = *(im.cp);
	*(this->mm) = *(im.mm);
	*(this->nm) = *(im.nm);
	return (*this);
}

IMonitorDisplay::IMonitorDisplay(const IMonitorDisplay &im)
{
	*(this->hn) = *(im.hn);
	*(this->os) = *(im.os);
	*(this->tm) = *(im.tm);
	*(this->cp) = *(im.cp);
	*(this->mmm) = *(im.mm);
	*(this->nm) = *(im.nm);
}
