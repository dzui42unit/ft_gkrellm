/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostName.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <arodiono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:03:17 by dzui              #+#    #+#             */
/*   Updated: 2017/11/11 21:20:48 by arodiono         ###   ########.fr       */
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