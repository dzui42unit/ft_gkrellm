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

int		main(int argc, char **argv)
{
	NcursesOut 	nc_out;
	std::string	inp;
	if (argc == 2)
	{
		inp = argv[1];
		if (inp == "-n")
			nc_out.drawStats();
		else if (inp == "-v")
		{

		}
		else
		{
			std::cout << "Usage: -n for ncurses output, -v for visual output.\n";
			return (0);
		}

	}
	else
		std::cout << "Usage: -n for ncurses output, -v for visual output.\n";
	return (0);
}