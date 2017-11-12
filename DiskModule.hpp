/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiskModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:36:08 by dzui              #+#    #+#             */
/*   Updated: 2017/11/11 17:36:10 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISKMODULE_HPP
#define DISKMODULE_HPP

#include "IMonitorModule.hpp"

class 		DiskModule : public IMonitorModule
{
public:
	void		parseInfo();
				DiskModule();
	virtual		~DiskModule();
				DiskModule(const DiskModule &dm);
	DiskModule 	&operator=(const DiskModule &dm);
};

#endif