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

void	HostName::parseInfo()
{
	gethostname(buff, BUFF_SIZE);
	info = buff;
	info += " / ";
	getlogin_r(buff, BUFF_SIZE);
	info += buff;
}