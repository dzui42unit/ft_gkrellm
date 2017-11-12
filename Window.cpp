/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <arodiono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:23:37 by arodiono          #+#    #+#             */
/*   Updated: 2017/11/12 00:09:24 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"

Window::Window(){
}
Window::Window(sf::RenderWindow *win) : window(win) {
	font.loadFromFile("includes/fonts/helvetica.ttf");
	icon.loadFromFile("includes/icon.png");
	window->setIcon(512, 512, icon.getPixelsPtr());
}
Window::~Window() {}
