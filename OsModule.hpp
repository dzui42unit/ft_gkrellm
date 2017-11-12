/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OsModule.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:22:47 by dzui              #+#    #+#             */
/*   Updated: 2017/11/11 16:22:48 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSMODULE_HPP
#define OSMODULE_HPP

#include "IMonitorModule.hpp"

class 		OsModule : public IMonitorModule
{
public:
	void		parseInfo();
				OsModule();
	virtual		~OsModule();
				OsModule(const OsModule &os);
	OsModule 	&operator=(const OsModule &os);

};

#endif