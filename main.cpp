/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:09:39 by dzui              #+#    #+#             */
/*   Updated: 2017/11/12 12:09:40 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcursesOut.hpp"

int		main(void)
{
	NcursesOut 	nc_out;

	nc_out.HostNameWin();
	return (0);
}


	// HostName		hn;
	// OsModule		os;
	// TimeModule		tm;
	// CpuModule		cp;
	// DiskModule		dm;
	// MemoryModule 	mm;
	// NetwModule		nm;


	// std::cout << std::endl;
	// std::cout << "HOST NAME / USER NAME:" << std::endl;
	// hn.parseInfo();
	// std::cout << hn.getInfo() << std::endl << std::endl;

	// os.parseInfo();
	// std::cout << "OS INFORMATION:" << std::endl;
	// std::cout << os.getInfo() << std::endl << std::endl;

	// tm.parseInfo();
	// std::cout << "TIME INFORMATION:" << std::endl;
	// std::cout << tm.getInfo() << std::endl;

	// cp.parseInfo();
	// std::cout << "CPU INFORMATION:" << std::endl;
	// std::cout << cp.getInfo() << std::endl;
	// std::cout << "User load: " << cp.getLoadUsr() << std::endl;
	// std::cout << "System load: " << cp.getLoadSys() << std::endl;
	// std::cout << "Idle load: " << cp.getLoadIdl() << std::endl << std::endl;

	// dm.parseInfo();
	// std::cout << "DISK INFO:" << std::endl;
	// std::cout << dm.getInfo() << std::endl << std::endl;

	// mm.parseInfo();
	// std::cout << "MEMORY INFO:" << std::endl;
	// std::cout << mm.getInfo() << std::endl;
	// std::cout << "Total: " << mm.getTotal() << std::endl;
	// std::cout << "Used: " << mm.getUsed() << std::endl;
	// std::cout << "Unused: " << mm.getUnused() << std::endl;

	// nm.parseInfo();
	// std::cout << "NETWORK MODULE:" << std::endl;
	// std::cout << nm.getInfo() << std::endl << std::endl;
