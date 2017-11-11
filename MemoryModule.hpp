/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MemoryModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:13:55 by dzui              #+#    #+#             */
/*   Updated: 2017/11/11 18:14:24 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORYMODULE_HPP
#define MEMORYMODULE_HPP

#include "Module.hpp"

class 		MemoryModule : public Module
{
private:
	int		mem[3];
public:
	void	parseInfo();
	int		getTotal() const;
	int		getUsed() const;
	int		getUnused() const;
};

#endif
