#pragma once

#include <SFML/Graphics.hpp>

class player {
public:
	
	sf::RectangleShape main;
	sf::RectangleShape top, left, right, bottom;

	int w = 85;
	int l = 13;

	player(double x, double y) {

		main.setPosition(sf::Vector2f(x, y));
		main.setSize(sf::Vector2f(l, w));
		main.setFillColor(sf::Color::White);

		left.setPosition(sf::Vector2f(x, y));
		left.setSize(sf::Vector2f(2, w));
		left.setFillColor(sf::Color::Magenta);

		right.setSize(sf::Vector2f(2, w + 2));
		right.setPosition(main.getPosition().x + main.getSize().x, main.getPosition().y);
		right.setFillColor(sf::Color::Yellow);

		top.setSize(sf::Vector2f(l, 2));
		top.setPosition(sf::Vector2f(x, y));
		top.setFillColor(sf::Color::Red);

		bottom.setPosition(main.getPosition().x, main.getPosition().y + main.getSize().y);
		bottom.setFillColor(sf::Color::Cyan);
		bottom.setSize(sf::Vector2f(l, 2));

	}

	enum CollisionDirection {LEFT, RIGHT, TOP, BOTTOM, NONE };

	CollisionDirection collision(sf::RectangleShape rectangle) {


		if (!main.getGlobalBounds().intersects(rectangle.getGlobalBounds())) {
			return CollisionDirection::NONE;
		}
		else {
			if (top.getGlobalBounds().intersects(rectangle.getGlobalBounds())) { return CollisionDirection::TOP; }
			if (bottom.getGlobalBounds().intersects(rectangle.getGlobalBounds())) { return CollisionDirection::BOTTOM; }
			if (left.getGlobalBounds().intersects(rectangle.getGlobalBounds())) { return CollisionDirection::LEFT; }
			if (right.getGlobalBounds().intersects(rectangle.getGlobalBounds())) { return CollisionDirection::RIGHT; }

		}
	}

};