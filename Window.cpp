/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <arodiono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:23:37 by arodiono          #+#    #+#             */
/*   Updated: 2017/11/11 22:41:50 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"

// static sf::Window const window(sf::VideoMode(1000, 1000), "ft_gkrellm", sf::Style::Titlebar | sf::Style::Close);

Window::Window(){
}
Window::Window(sf::RenderWindow *win) : window(win) {
	// font.loadFromFile("includes/fonts/helvetica.ttf");
	// icon.loadFromFile("includes/icon.png");
	// window.setIcon(512, 512, icon.getPixelsPtr());
}
Window::~Window() {}
// sf::RenderWindow &Window::getWin() {
// 	return window;
// }
