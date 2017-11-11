/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetwModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:47:32 by dzui              #+#    #+#             */
/*   Updated: 2017/11/11 18:47:34 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetwModule.hpp"

void	NetwModule::parseInfo()
{
	pipe = popen("top -l 1 | grep \"Networks:\"", "r");
	while (!feof(pipe))
	{
		if (fgets(buff, BUFF_SIZE, pipe) != NULL)
			info += buff;
	}
}