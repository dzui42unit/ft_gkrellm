/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:31:48 by dzui              #+#    #+#             */
/*   Updated: 2017/11/11 16:31:49 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TimeModule.hpp"

void		TimeModule::parseInfo()
{
	time_t	time;

	info = "";
	time = std::time(0);
	info = ctime(&time);
}

TimeModule::TimeModule()
{
	info = "";
}

TimeModule::~TimeModule()
{

}

TimeModule::TimeModule(const TimeModule &tm)
{
	this->info = tm.info;
}

TimeModule	&TimeModule::operator=(const TimeModule &tm)
{
	this->info = tm.info;
	return (*this);
}