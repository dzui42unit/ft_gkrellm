/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiskModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:36:16 by dzui              #+#    #+#             */
/*   Updated: 2017/11/11 17:36:17 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiskModule.hpp"

DiskModule::DiskModule()
{
	info = "";
}

DiskModule::~DiskModule()
{

}

DiskModule::DiskModule(const DiskModule &dm)
{
	this->info = dm.info;
}

DiskModule	&DiskModule::operator=(const DiskModule &dm)
{
	this->info = dm.info;
	return (*this);
}

void	DiskModule::parseInfo()
{
	info = "";
	pipe = popen("top -l 1 | grep \"Disks:\"", "r");
	while (!feof(pipe))
	{
		if (fgets(buff, BUFF_SIZE, pipe) != NULL)
			info += buff;
	}
	pclose(pipe);
}

