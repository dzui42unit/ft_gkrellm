/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <arodiono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:46:09 by dzui              #+#    #+#             */
/*   Updated: 2017/11/12 02:04:36 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CpuModule.hpp"

CpuModule::CpuModule() {
	// loadUsr = sf::VertexArray(sf::LineStrip, 1000000);
	sf::VertexArray loadUsr(sf::LinesStrip, 3);

	// loadSys = sf::VertexArray(sf::LineStrip, 100);
	// loadIdl = sf::VertexArray(sf::LineStrip, 100);
}
CpuModule::~CpuModule() {}

void CpuModule::parseInfo()
{
	std::string temp;
	std::string temp_info;
	std::string token;
	size_t 		pos;
	int 		i;

	pos = 0;
	pipe = popen("system_profiler -detailLevel full SPHardwareDataType", "r");
	while (!feof(pipe))
	{
		if (fgets(buff, BUFF_SIZE, pipe) != NULL)
			info += buff;
	}
	pclose(pipe);
	pipe = popen("top -l 1 | grep \"CPU usage\"", "r");
	while (!feof(pipe))
	{
		if (fgets(buff, BUFF_SIZE, pipe) != NULL)
			temp += buff;
	}
	pclose(pipe);
	i = 0;
	while ((pos = temp.find(' ')) != std::string::npos)
	{
	    token = temp.substr(0, pos);
	    if (token.find('%') != std::string::npos)
	    {
	    	token[token.length() - 1] = '\0';
	    	load[i] = stof(token);
	    	i++;
	    }
	    temp.erase(0, pos + 1);
	}
	// if (loadUsr.size() > 100)
	// {
	// 	loadUsr.pop_back();
	// 	loadSys.pop_back();
	// 	loadIdl.pop_back();
	// }
	// loadUsr.resize(loadUsr.getVertexCount() + 1);
	// loadUsr[loadUsr.getVertexCount()].position = sf::Vector2f(10.0f, load[0] + 10);
	// loadUsr[loadUsr.getVertexCount()].position = sf::Vector2f(0, load[0]);
	// loadUsr[loadUsr.getVertexCount()].position = sf::Vector2f(0, load[0]);
	// loadUsr.resize(100);
	// loadSys.resize(100);
	// loadIdl.resize(100);
}

float	CpuModule::getLoadUsr() const
{
	return (load[0]);
}

float	CpuModule::getLoadSys() const
{
	return (load[1]);
}

float	CpuModule::getLoadIdl() const
{
	return (load[2]);
}

sf::VertexArray &CpuModule::render()
{
	loadUsr[0].position = sf::Vector2f(10.0f, load[0] + 10);
	loadUsr[1].position = sf::Vector2f(10.0f, load[0] + 20);
	loadUsr[2].position = sf::Vector2f(10.0f, load[0] + 30);

	loadUsr[0].color = sf::Color::Cyan;
	loadUsr[1].color = sf::Color::Yellow;
	loadUsr[2].color = sf::Color::Red;
	// loadUsr[3].color = sf::Color::White;
	// for (std::size_t i = 0; i < loadUsr.size(); i++)
	// {
	// window->draw(loadUsr);
	// }
	return loadUsr;
}