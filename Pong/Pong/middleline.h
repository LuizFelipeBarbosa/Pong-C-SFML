#pragma once
#include <SFML/Graphics.hpp>

class mid {
	public:
		sf::RectangleShape line;
		mid(){

			line.setSize(sf::Vector2f(5, 15));
			line.setFillColor(sf::Color::White);

		}

};