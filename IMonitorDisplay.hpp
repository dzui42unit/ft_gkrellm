/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:47:45 by dzui              #+#    #+#             */
/*   Updated: 2017/11/12 16:47:47 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

#include "IMonitorModule.hpp"
#include "HostName.hpp"
#include "OsModule.hpp"
#include "TimeModule.hpp"
#include "CpuModule.hpp"
#include "DiskModule.hpp"
#include "MemoryModule.hpp"
#include "NetwModule.hpp"

class 	IMonitorDisplay
{
protected:
	HostName 		*hn;
	OsModule 		*os;
	TimeModule 		*tm;
	CpuModule		*cp;
	MemoryModule 	*mm;
	NetwModule 		*nm;
public:
						IMonitorDisplay();
	virtual				~IMonitorDisplay();
	IMonitorDisplay 	&operator=(const IMonitorDisplay &im);
						IMonitorDisplay(const IMonitorDisplay &im);
};

#endif
