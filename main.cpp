/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <arodiono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 22:05:24 by arodiono          #+#    #+#             */
/*   Updated: 2017/11/12 02:18:16 by arodiono         ###   ########.fr       */
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
#include <ctime>

int		main(void)
{
	int w = 2500, h = 2000;
	sf::RenderWindow win(sf::VideoMode(w, h), "ft_gkrellm", sf::Style::Titlebar | sf::Style::Close);
	Window 				WIN(&win);
	HostName			hn;
	OsModule			os;
	TimeModule			tm;
	CpuModule			cp;
	DiskModule			dm;
	MemoryModule 		mm;
	NetwModule			nm;

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


	sf::RectangleShape header;
	header.setSize(sf::Vector2f(w, 100));
	header.setOutlineThickness(10);
	header.setPosition(0, 0);

	// sf::RectangleShape info;
	// info.setSize(sf::Vector2f(2000, 400));
	// info.setOutlineThickness(10);
	// info.setPosition(250, 250);

	// sf::RectangleShape cpu;
	// cpu.setSize(sf::Vector2f(2000, 400));
	// cpu.setOutlineThickness(10);
	// cpu.setPosition(250, 800);
	
	sf::Font font;
	font.loadFromFile("includes/fonts/helvetica.ttf");
	
	// hn.parseInfo();
	// sf::Text hnInfo(hn.getInfo(), font);
	// hnInfo.setFillColor(sf::Color::Black);
	// hnInfo.setCharacterSize(30);
	// hnInfo.setPosition(150, 150);

	// // os.parseInfo();
	// sf::Text osInfo(os.getInfo(), font);
	// osInfo.setFillColor(sf::Color::Black);
	// osInfo.setCharacterSize(30);
	// osInfo.setPosition(150, 350);

	// // tm.parseInfo();
	// sf::Text tmInfo(tm.getInfo(), font);
	// tmInfo.setFillColor(sf::Color::Black);
	// tmInfo.setCharacterSize(30);
	// tmInfo.setPosition(150, 550);
	sf::Text osInfo(os.getInfo(), font);

	while (WIN.window->isOpen())
	{
		sf::Event event;
		while (WIN.window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				WIN.window->close();
		}
		WIN.window->clear();
		WIN.window->clear(GRAY);
		WIN.window->draw(header);

		// hn.parseInfo();
		// sf::Text hnInfo(hn.getInfo(), font);
		// hnInfo.setFillColor(sf::Color::Black);
		// hnInfo.setCharacterSize(30);
		// hnInfo.setPosition(150, 150);

		os.parseInfo();
		osInfo.setString(os.getInfo());
		osInfo.setFillColor(sf::Color::Black);
		osInfo.setCharacterSize(30);
		osInfo.setPosition(150, 350);

		tm.parseInfo();
		sf::Text tmInfo(tm.getInfo(), font);
		tmInfo.setFillColor(sf::Color::Black);
		tmInfo.setCharacterSize(30);
		tmInfo.setPosition(150, 550);

		WIN.window->draw(osInfo);
		WIN.window->draw(tmInfo);
		// WIN.window->draw(hnInfo);

		// WIN.window->draw(cp.render());

		WIN.window->display();
		usleep(1000000);
	}

	return (0);
}
