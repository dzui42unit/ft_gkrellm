/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetwModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:47:23 by dzui              #+#    #+#             */
/*   Updated: 2017/11/11 18:47:24 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWMODULE_HPP
#define NETWMODULE_HPP

#include "IMonitorModule.hpp"

class 		NetwModule : public IMonitorModule
{
public:
	void		parseInfo();
				NetwModule();
	virtual		~NetwModule();
				NetwModule(const NetwModule &nm);
	NetwModule 	&operator=(const NetwModule &nm);
};

#endif