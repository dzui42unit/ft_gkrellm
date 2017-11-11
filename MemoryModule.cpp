/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MemoryModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:14:27 by dzui              #+#    #+#             */
/*   Updated: 2017/11/11 18:14:28 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MemoryModule.hpp"

int		MemoryModule::getTotal() const
{
	return (mem[0]);
}

int		MemoryModule::getUsed() const
{
	return (mem[1]);
}

int		MemoryModule::getUnused() const
{
	return (mem[2]);
}

void	MemoryModule::parseInfo()
{
	size_t		pos;
	int			i;
	std::string token;
	std::string temp;

	pipe = popen("top -l 1 | grep \"PhysMem:\"", "r");
	while (!feof(pipe))
	{
		if (fgets(buff, BUFF_SIZE, pipe) != NULL)
			info += buff;
	}
	std::cout << info << std::endl;
	i = 0;
	pos = 0;
	temp = info;
	while ((pos = temp.find(' ')) != std::string::npos)
	{
	    token = temp.substr(0, pos);
	    if (token.find('M') != std::string::npos)
	    {
	    	token[token.length() - 1] = '\0';
	    	if (token[0] == '(')
	    		token[0] = '0';
	    	if (token[0] >= '0' && token[0] <= '9')
	    	{
	    		mem[i] = stoi(token);
	    		i++;
	    	}
	    }
	    temp.erase(0, pos + 1);
	}
	pclose(pipe);
	mem[0] += mem[2];
}
