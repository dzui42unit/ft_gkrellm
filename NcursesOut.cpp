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
	hn->parseInfo();
	os->parseInfo();
	tm->parseInfo();
}

NcursesOut::~NcursesOut()
{

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

	getmaxyx(stdscr, max_y, max_x);
	for (int i = 0; i < max_x / 2; i++)
	{
		mvprintw(0, i, "-");
		mvprintw(max_y / 2, i, "-");
	}
	for (int i = 0; i < max_y / 2; i++)
	{
		mvprintw(i, 0, "|");
		mvprintw(i, max_x / 2, "|");
	}
	mvprintw(2, 4, "Host name / User name: %s", (hn->getInfo().c_str()));
	for (int i = 1; i < max_x / 2; i++)
		mvprintw(3, i, "-");

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
	mvprintw(10, 4, "Date / Time: %s", tm->getInfo().c_str());
	mvprintw(10, max_x / 2, "|");
	for (int i = 1; i < max_x / 2; i++)
	{
		mvprintw(11, i, "-");
	}
	refresh();
	while (1)
	{
		getch();
	}
 	endwin(); 
}