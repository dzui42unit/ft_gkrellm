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

#include "Module.hpp"

class 		DiskModule : public Module
{
public:
	void		parseInfo();
};

#endif