/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Module.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <arodiono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:56:47 by dzui              #+#    #+#             */
/*   Updated: 2017/11/11 21:20:42 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Module.hpp"

Module::Module() : info(""), pipe(NULL)
{

}

Module::~Module()
{

}

Module		&Module::operator=(const Module &m)
{
	info = m.info;
	pipe = m.pipe;
	strcpy(buff, m.buff);
	return (*this);
}

Module::Module(const Module &m)
{
	info = m.info;
	pipe = m.pipe;
	strcpy(buff, m.buff);
}

std::string		Module::getInfo() const
{
	return (info);
}
