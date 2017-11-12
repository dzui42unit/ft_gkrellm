/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostName.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:03:17 by dzui              #+#    #+#             */
/*   Updated: 2017/11/11 16:03:19 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostName.hpp"

HostName::HostName()
{
	info = "";
}

HostName::~HostName()
{

}

HostName 	&HostName::operator=(const HostName &hn)
{
	this->info = hn.info;
	return (*this);
}

HostName::HostName(const HostName &hn)
{
	this->info = hn.info;
}

void	HostName::parseInfo()
{
	info = "";
	gethostname(buff, BUFF_SIZE);
	info = buff;
	info += " / ";
	getlogin_r(buff, BUFF_SIZE);
	info += buff;
}