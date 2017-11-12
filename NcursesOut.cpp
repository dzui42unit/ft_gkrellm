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
	attron(COLOR_PAIR(4));
	for (int i = 0; i < max_x; i++)
	{
		mvprintw(0, i, "-");
		mvprintw(max_y - 1, i, "-");
		 refresh();
	}
	for (int i = 0; i < max_y; i++)
	{
		mvprintw(i, 0, "|");
		mvprintw(i, max_x - 1, "|");
		 refresh();
	}
	refresh();
	while (1)
	{
		getch();
	}
 	endwin(); 
}