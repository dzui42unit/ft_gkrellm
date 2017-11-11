/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <arodiono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:23:40 by arodiono          #+#    #+#             */
/*   Updated: 2017/11/11 22:42:06 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#define GRAY sf::Color(236, 236, 236)

#include <SFML/Graphics.hpp>

class Window {

protected:
  sf::Font font;
  sf::Image icon;

public:
  sf::RenderWindow *window;
  Window();
  Window(sf::RenderWindow *win);
  virtual ~Window();

//   sf::RenderWindow &getWin();
};

#endif