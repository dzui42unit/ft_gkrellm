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

NcursesOut::NcursesOut() : IMonitorDisplay()
{

}

NcursesOut::~NcursesOut()
{
	
}

void	NcursesOut::printColumn(int y_start, int x_start, float load) const
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

void	NcursesOut::printHostOs() const
{
	attron(COLOR_PAIR(5));
	mvprintw(2, 4, "Host name / User name: %s", (hn->getInfo().c_str()));
	attron(COLOR_PAIR(5));
	attron(COLOR_PAIR(4));
	for (int i = 1; i < max_x / 2; i++)
		mvprintw(3, i, "-");
	attroff(COLOR_PAIR(4));

	//

	//	print OS info

	size_t 		pos;
	std::string temp = os->getInfo();
	std::string token;
	int 		j;

	j = 0;
	pos = 0;
	attron(COLOR_PAIR(6));
	mvprintw(5, 4, "Information about Operating System:");
	while ((pos = temp.find('\n')) != std::string::npos)
	{
	    token = temp.substr(0, pos);
	    mvprintw(7 + j, 4, "%s", token.c_str());
	    temp.erase(0, pos + 1);
	    j++;
	}
	attron(COLOR_PAIR(6));
	attron(COLOR_PAIR(4));
	for (int i = 1; i < max_x / 2; i++)
		mvprintw(9, i, "-");
	attroff(COLOR_PAIR(4));
	// 
}

void		NcursesOut::printTime() const
{
		tm->parseInfo();
		attron(COLOR_PAIR(7));
		mvprintw(10, 4, "Date / Time: %s", tm->getInfo().c_str());
		attron(COLOR_PAIR(7));
		attron(COLOR_PAIR(4));
		mvprintw(10, max_x / 2, "|");
		for (int i = 1; i < max_x / 2; i++)
			mvprintw(11, i, "-");
		attroff(COLOR_PAIR(4));
}

void		NcursesOut::printCPU() const
{
	size_t 		pos;
	std::string temp = os->getInfo();
	std::string token;
	int 		j;

	pos = 0;
	j = 0;
	temp = cp->getInfo();
	attron(COLOR_PAIR(5));
	mvprintw(12, 4, "Cpu information:");
	while ((pos = temp.find('\n')) != std::string::npos)
	{
	    token = temp.substr(0, pos);
	    mvprintw(13 + j, 4, "%s", token.c_str());
	    temp.erase(0, pos + 1);
	    j++;
	}
	attroff(COLOR_PAIR(5));
	attron(COLOR_PAIR(4));
	for (int i = 1; i < max_x / 2; i++)
		mvprintw(30, i, "-");
	attroff(COLOR_PAIR(4));

	cp->parseInfo();
	attron(COLOR_PAIR(1));
	mvprintw(31, 4, "Processor usage:\t\t\tSystem: %f\t\t\tUser: %f\t\t\tIdle: %f", cp->getLoadSys(), cp->getLoadUsr(), cp->getLoadIdl());
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(6));
	printColumn(32, 45, cp->getLoadSys());
	printColumn(32, 85, cp->getLoadUsr());
	printColumn(32, 117, cp->getLoadIdl());
	attroff(COLOR_PAIR(6));
	attron(COLOR_PAIR(4));
	for (int i = 1; i < max_x / 2; i++)
		mvprintw(50, i, "-");
	attroff(COLOR_PAIR(4));
}

void		NcursesOut::printMemNetw() const
{
	mm->parseInfo();
	attron(COLOR_PAIR(7));
	mvprintw(51, 4, "%s", mm->getInfo().c_str());
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(4));
	mvprintw(51, max_x / 2, "|");
	attroff(COLOR_PAIR(4));
	attron(COLOR_PAIR(7));
	mvprintw(53, 4, "Memory usage:\t\t\t\t\tTotal: %d\t\t\tUsed: %d\t\t\tFree: %d", mm->getTotal(), mm->getUsed(), mm->getUnused());
	attroff(COLOR_PAIR(7));
	attron(COLOR_PAIR(4));
	for (int i = 1; i < max_x / 2; i++)
		mvprintw(54, i, "-");
	attroff(COLOR_PAIR(4));
	nm->parseInfo();
	attron(COLOR_PAIR(6));
	mvprintw(55, 4,"%s", nm->getInfo().c_str());
	attroff(COLOR_PAIR(6));
	attron(COLOR_PAIR(4));
	mvprintw(55, max_x / 2, "|");
	attroff(COLOR_PAIR(4));
}


void	NcursesOut::drawStats()
{
	win = NULL;

	initscr();
	noecho();
	curs_set(FALSE);
	start_color();
 	refresh();

 	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_RED);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);

	attron(COLOR_PAIR(4));
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
	attroff(COLOR_PAIR(4));

	printHostOs();

	while (1)
	{
		printTime();
		printCPU();
		printMemNetw();
		refresh();
		sleep(1);

	}
	endwin(); 
}