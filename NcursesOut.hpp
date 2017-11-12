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

#include "IMonitorDisplay.hpp"
#include <ncurses.h>

class 			NcursesOut : public IMonitorDisplay
{
private:
	WINDOW			*win;
	int				max_x;
	int				max_y;
public:
				NcursesOut();
				~NcursesOut();
	void		drawStats();
	void		printColumn(int y_start, int x_start, float load) const;
	void		printHostOs() const;
	void		printTime() const;
	void		printCPU() const;
	void		printMemNetw() const;
};

#endif 