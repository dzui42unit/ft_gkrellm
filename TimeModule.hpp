/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:31:41 by dzui              #+#    #+#             */
/*   Updated: 2017/11/11 16:31:42 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMEMODULE_HPP
#define TIMEMODULE_HPP

#include "IMonitorModule.hpp"

class 		TimeModule : public IMonitorModule
{
public:
	void		parseInfo();
				TimeModule();
	virtual		~TimeModule();
				TimeModule(const TimeModule &tm);
	TimeModule 	&operator=(const TimeModule &tm);
};

#endif 