/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <arodiono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 22:05:24 by arodiono          #+#    #+#             */
/*   Updated: 2017/11/11 22:50:40 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SFML/Graphics.hpp>
#include "Module.hpp"
#include "HostName.hpp"
#include "OsModule.hpp"
#include "TimeModule.hpp"
#include "CpuModule.hpp"
#include "DiskModule.hpp"
#include "MemoryModule.hpp"
#include "NetwModule.hpp"

int		main(void)
{
	sf::RenderWindow win(sf::VideoMode(1000, 1000), "ft_gkrellm", sf::Style::Titlebar | sf::Style::Close);

	Window 			WIN(&win);
	HostName		hn;
	OsModule		os;
	TimeModule		tm;
	CpuModule		cp;
	DiskModule		dm;
	MemoryModule 	mm;
	NetwModule		nm;



	// sf::RenderWindow(win);

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


	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(100, 50));
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(10, 20);

	while (WIN.window->isOpen())
	{
		sf::Event event;
		while (WIN.window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				WIN.window->close();
		}
		WIN.window->clear(GRAY);

		hn.parseInfo();
		sf::Text text;
		text.setString(hn.getInfo());

		WIN.window->draw(text);
		WIN.window->display();
	}

	return (0);
}
