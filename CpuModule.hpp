/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <arodiono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:45:55 by dzui              #+#    #+#             */
/*   Updated: 2017/11/12 02:04:34 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_HPP
#define CPUMODULE_HPP

#include "Module.hpp"
#include <vector>

class 		CpuModule : public Module 
{
private:
	float	load[3];
	sf::VertexArray loadUsr;
	sf::VertexArray loadSys;
	sf::VertexArray loadIdl;

  public:
	CpuModule();
	~CpuModule();

	void parseInfo();
	float	getLoadUsr() const;
	float	getLoadSys() const;
	float	getLoadIdl() const;
	sf::VertexArray &render();
};

#endif

