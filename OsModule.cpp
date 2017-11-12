/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsModule.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:22:56 by dzui              #+#    #+#             */
/*   Updated: 2017/11/11 16:22:57 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OsModule.hpp"

void	OsModule::parseInfo()
{
	info = "";
	pipe = popen("sw_vers", "r");
	while (!feof(pipe))
	{
		if (fgets(buff, BUFF_SIZE, pipe) != NULL)
			info += buff;
	}
	pclose(pipe);
}

OsModule::OsModule()
{
	info = "";
}

OsModule::~OsModule()
{

}

OsModule::OsModule(const OsModule &os)
{
	this->info = os.info;
}

OsModule	&OsModule::operator=(const OsModule &os)
{
	this->info = os.info;
	return (*this);
}
