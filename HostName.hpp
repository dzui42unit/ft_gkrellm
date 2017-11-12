/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostName.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:53:01 by dzui              #+#    #+#             */
/*   Updated: 2017/11/11 15:53:03 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAME_HPP
#define HOSTNAME_HPP

#include "IMonitorModule.hpp"

class 			HostName : public IMonitorModule
{
public:
	void		parseInfo();
				HostName();
	virtual		~HostName();
				HostName(const HostName &hn);
	HostName 	&operator=(const HostName &hn);
};

#endif
