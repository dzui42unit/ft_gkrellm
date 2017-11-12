/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:45:55 by dzui              #+#    #+#             */
/*   Updated: 2017/11/11 16:45:56 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_HPP
#define CPUMODULE_HPP

#include "IMonitorModule.hpp"

class 			CpuModule : public IMonitorModule 
{
private:
	float		load[3];
public:
	void		parseInfo();
	float		getLoadUsr() const;
	float		getLoadSys() const;
	float		getLoadIdl() const;
				CpuModule();
				~CpuModule();
				CpuModule(const CpuModule &cm);
	CpuModule 	&operator=(const CpuModule &cm);
};

#endif

