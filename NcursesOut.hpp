/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesOut.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:17:09 by dzui              #+#    #+#             */
/*   Updated: 2017/11/12 12:17:10 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSESOUT
#define NCURSESOUT

#define HNW_H 40

#include "IMonitorModule.hpp"
#include "HostName.hpp"
#include "OsModule.hpp"
#include "TimeModule.hpp"
#include "CpuModule.hpp"
#include "DiskModule.hpp"
#include "MemoryModule.hpp"
#include "NetwModule.hpp"

#include <ncurses.h>

class 			NcursesOut
{
private:
	WINDOW			*win;
	HostName 		*hn;
	OsModule 		*os;
	TimeModule 		*tm;
	CpuModule		*cp;
	MemoryModule 	*mm;
	NetwModule 		*nm;
	int				max_x;
	int				max_y;
public:
				NcursesOut();
				~NcursesOut();
	void		HostNameWin();
};

#endif 