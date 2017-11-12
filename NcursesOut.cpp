/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesOut.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:16:37 by dzui              #+#    #+#             */
/*   Updated: 2017/11/12 12:16:46 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcursesOut.hpp"

NcursesOut::NcursesOut()
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

NcursesOut::~NcursesOut()
{

}

void	printColumn(int y_start, int x_start, float load)
{
	int y_end;

	y_end = y_start + 15;
	for (int j = y_start; j < y_end + 1; j++)
	{
		for (int k = x_start; k < x_start + 5; k++)
			mvprintw(j, k, " ");
	}
	y_start += static_cast<double>(15.0 - (15.0 * load) / 100.0);
	for ( ; y_end != y_start; y_end--)
	{
		for (int i = x_start; i < x_start + 5; i++)
			mvprintw(y_end, i, "*");
	}
}

void	NcursesOut::HostNameWin()
{
	win = NULL;

	initscr(); 			// Initialize the window
	noecho(); 			// Don't echo any keypresses
	curs_set(FALSE); 	// Don't display a cursor

 	refresh();

 	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_RED);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);


	// print frame of table

	getmaxyx(stdscr, max_y, max_x);
	max_y = max_y / 2 + max_y / 5;
	for (int i = 0; i < max_x / 2; i++)
	{
		mvprintw(0, i, "-");
		mvprintw(max_y - 1, i, "-");
	}
	for (int i = 0; i < max_y; i++)
	{
		mvprintw(i, 0, "|");
		mvprintw(i, max_x / 2, "|");
	}

	//

	// print host name

	mvprintw(2, 4, "Host name / User name: %s", (hn->getInfo().c_str()));
	for (int i = 1; i < max_x / 2; i++)
		mvprintw(3, i, "-");

	//

	//	print OS info

	size_t 		pos;
	std::string temp = os->getInfo();
	std::string token;
	int 		j;

	j = 0;
	pos = 0;
	mvprintw(5, 4, "Information about Operating System:");
	while ((pos = temp.find('\n')) != std::string::npos)
	{
	    token = temp.substr(0, pos);
	    mvprintw(7 + j, 4, "%s", token.c_str());
	    temp.erase(0, pos + 1);
	    j++;
	}
	for (int i = 1; i < max_x / 2; i++)
		mvprintw(9, i, "-");

	// // 

	while (1)
	{
	// 	// print date time

		tm->parseInfo();
		mvprintw(10, 4, "Date / Time: %s", tm->getInfo().c_str());
		mvprintw(10, max_x / 2, "|");
		for (int i = 1; i < max_x / 2; i++)
			mvprintw(11, i, "-");
		pos = 0;
		j = 0;
		temp = cp->getInfo();

		//

		// print CPU information

		mvprintw(12, 4, "Cpu information:");
		while ((pos = temp.find('\n')) != std::string::npos)
		{
		    token = temp.substr(0, pos);
		    mvprintw(13 + j, 4, "%s", token.c_str());
		    temp.erase(0, pos + 1);
		    j++;
		}
		for (int i = 1; i < max_x / 2; i++)
			mvprintw(30, i, "-");

		// print CPU load information

		cp->parseInfo();
		mvprintw(31, 4, "Processor usage:\t\t\tSystem: %f\t\t\tUser: %f\t\t\tIdle: %f", cp->getLoadSys(), cp->getLoadUsr(), cp->getLoadIdl());
		printColumn(32, 45, cp->getLoadSys());
		printColumn(32, 85, cp->getLoadUsr());
		printColumn(32, 117, cp->getLoadIdl());
		for (int i = 1; i < max_x / 2; i++)
			mvprintw(50, i, "-");

		// print MEMORY INFO

		mm->parseInfo();
		mvprintw(51, 4, "%s", mm->getInfo().c_str());
		mvprintw(51, max_x / 2, "|");
		mvprintw(53, 4, "Memory usage:\t\t\t\t\tTotal: %d\t\t\tUsed: %d\t\t\tFree: %d", mm->getTotal(), mm->getUsed(), mm->getUnused());
		for (int i = 1; i < max_x / 2; i++)
			mvprintw(54, i, "-");
		nm->parseInfo();
		mvprintw(55, 4,"%s", nm->getInfo().c_str());
		mvprintw(55, max_x / 2, "|");
		refresh();
		sleep(1);

	}
	endwin(); 
}