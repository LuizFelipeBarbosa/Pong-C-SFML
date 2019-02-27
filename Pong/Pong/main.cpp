#include <SFML/Graphics.hpp>
#include <stdlib.h> 
#include <string>
#include <random>
#include "middleline.h"
#include "player.h"

int main()
{

	enum level {
		MAIN,
		GAME
	};

	level level = MAIN;

	float movespeed = 0.27;

	float botmovespeed = 0.27;

	float ballmovespeed = 0.1;

	int start = 1;

	int x = 1;

	bool bot1v1 = false;
	bool human1v1 = false;
	bool humanvsbot = false;

	bool goo = true;

	bool up1 = false;
	bool down1 = false;

	bool up2 = false;
	bool down2 = false;

	int pointsp1 = 0;
	int pointsp2 = 0;

	sf::RenderWindow window(sf::VideoMode(900, 600), "Pong");

	sf::Event event;

	sf::Vector2f direc(sf::Vector2f(0,0));

	sf::Vector2f direc2(sf::Vector2f(0, 0));

	sf::Vector2f velocity(sf::Vector2f(0, 0));

	sf::RectangleShape ball(sf::Vector2f(10,10));
	ball.setFillColor(sf::Color::White);

	mid line[20];

	//Players

	player p1(100,215);
	player p2(800,215);

	//Text points

	sf::Font font;
	font.loadFromFile("font/HELR45W.ttf");

	sf::Text bruno2;
	sf::Text bruno;

	bruno2.setFont(font);
	bruno2.setPosition(630, 50);
	bruno2.setScale(4, 4);
	bruno2.setFillColor(sf::Color::White);

	bruno.setFont(font);
	bruno.setPosition(170, 50);
	bruno.setScale(4,4);
	bruno.setFillColor(sf::Color::White);

	//Text main menu

	sf::Text main;

	main.setFont(font);
	main.setPosition(285, 50);
	main.setScale(4, 4);
	main.setFillColor(sf::Color::White);

	main.setString("PONG");

	sf::Text regular;

	regular.setFont(font);
	regular.setPosition(145, 250);
	regular.setFillColor(sf::Color::White);

	regular.setString("Regular");

	sf::Text vsBot;

	vsBot.setFont(font);
	vsBot.setPosition(405, 250);
	vsBot.setFillColor(sf::Color::White);

	vsBot.setString("vsBot");

	sf::Text bot;

	bot.setFont(font);
	bot.setPosition(650, 250);
	bot.setFillColor(sf::Color::White);

	bot.setString("Bot1v1");

	//Main Menu objects

	sf::CircleShape cir;
	sf::CircleShape cir2;
	sf::CircleShape cir3;

	cir.setRadius(75);
	cir2.setRadius(75);
	cir3.setRadius(75);

	cir.setFillColor(sf::Color::White);
	cir2.setFillColor(sf::Color::White);
	cir3.setFillColor(sf::Color::White);

	cir.setPosition(125, 300);
	cir2.setPosition(375, 300);
	cir3.setPosition(625, 300);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		switch (level)
		{
			case MAIN:
				
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					if (sf::Mouse::getPosition(window).x > 125 && sf::Mouse::getPosition(window).x < 275 && sf::Mouse::getPosition(window).y > 300 && sf::Mouse::getPosition(window).y < 450) {
						human1v1 = true;
						bot1v1 = false;
						humanvsbot = false;

						level = GAME;
					}
					if (sf::Mouse::getPosition(window).x > 375 && sf::Mouse::getPosition(window).x < 525 && sf::Mouse::getPosition(window).y > 300 && sf::Mouse::getPosition(window).y < 450) {
						human1v1 = false;
						bot1v1 = false;
						humanvsbot = true;

						level = GAME;
					}
					if (sf::Mouse::getPosition(window).x > 675 && sf::Mouse::getPosition(window).x < 725 && sf::Mouse::getPosition(window).y > 300 && sf::Mouse::getPosition(window).y < 450) {
						human1v1 = false;
						bot1v1 = true;
						humanvsbot = false;

						level = GAME;
					}
				}

				window.draw(cir);
				window.draw(cir2);
				window.draw(cir3);

				window.draw(main);

				window.draw(regular);
				window.draw(vsBot);
				window.draw(bot);

				window.display();
				window.clear();
				break;

			case GAME:

				if (bot1v1 == true) {
					botmovespeed = 10;
				}

				bruno.setString(std::to_string(pointsp1));
				bruno2.setString(std::to_string(pointsp2));

				if (goo) {

					ball.setPosition(450, 300);

					p1.main.setPosition(100, 215);

					p1.right.setPosition(p1.main.getPosition().x + p1.main.getSize().x, p1.main.getPosition().y);

					p1.top.setPosition(p1.main.getPosition().x, p1.main.getPosition().y);

					p1.bottom.setPosition(p1.main.getPosition().x, p1.main.getPosition().y + p1.main.getSize().y);

					p2.main.setPosition(800, 215);

					p2.left.setPosition(p2.main.getPosition().x, p2.main.getPosition().y);

					p2.top.setPosition(p2.main.getPosition().x, p2.main.getPosition().y);

					p2.bottom.setPosition(p2.main.getPosition().x, p2.main.getPosition().y + p2.main.getSize().y);

					if (x % 2 == 0) {
						velocity.x = -ballmovespeed;
						velocity.y = 0.1;
					}
					else {
						velocity.x = ballmovespeed;
						velocity.y = 0.1;
					}

					goo = false;
					x++;
				}

				for (int i = 0; i < 20; i++) {

					line[i].line.setPosition(445, 15 + i * 40);

				}

				if (human1v1 == true || humanvsbot == true) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
						direc.y = -movespeed;
						up1 = true;

					}

					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
						direc.y = movespeed;
						down1 = true;

					}
					else {

						up1 = false;
						down1 = false;

						direc.y = 0;
					}

					if (p1.main.getPosition().y < 1) {

						direc.y = 0;

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
							direc.y = movespeed;
						}
					}
					if (p1.main.getPosition().y > 599 - p1.main.getSize().y) {

						direc.y = 0;

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
							direc.y = -movespeed;

						}

					}

				}


				if (bot1v1 == true) {
					if (ball.getPosition().x > 450) {
						if (ball.getPosition().y < p1.main.getPosition().y + p1.main.getSize().y / 2) {

							direc.y = -botmovespeed / 10;

						}
						else if (ball.getPosition().y > p1.main.getPosition().y) {

							direc.y = botmovespeed / 10;
						}

					}

					else {

						if (ball.getPosition().y < p1.main.getPosition().y + p1.main.getSize().y / 2) {

							direc.y = -botmovespeed;
							up1 = true;

						}
						else if (ball.getPosition().y > p1.main.getPosition().y) {

							direc.y = botmovespeed;
							down1 = true;

						}
						else {

							up1 = false;
							down1 = false;

							direc.y = 0;
						}
					}
				}

				p1.main.move(direc.x, direc.y);

				p1.right.move(direc.x, direc.y);

				p1.top.move(direc.x, direc.y);

				p1.bottom.move(direc.x, direc.y);

				if (human1v1 == true) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

						direc2.y = -movespeed;
						up2 = true;


					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

						direc2.y = movespeed;
						down2 = true;

					}
					else {

						up2 = false;
						down2 = false;

						direc2.y = 0;

					}
					if (p2.main.getPosition().y < 1) {

						direc2.y = 0;

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
							direc2.y = movespeed;
						}
					}
					if (p2.main.getPosition().y > 599 - p2.main.getSize().y) {

						direc2.y = 0;

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
							direc2.y = -movespeed;

						}

					}
				}

				if (bot1v1 == true || humanvsbot == true) {
					if (ball.getPosition().x < 450) {
						if (ball.getPosition().y < p2.main.getPosition().y + p2.main.getSize().y / 2) {

							direc2.y = -botmovespeed / 10;

						}
						if (ball.getPosition().y > p2.main.getPosition().y) {

							direc2.y = botmovespeed / 10;

						}

					}
					else {

						if (ball.getPosition().y < p2.main.getPosition().y + p2.main.getSize().y / 2) {

							direc2.y = -botmovespeed;
							up2 = true;



						}
						else if (ball.getPosition().y > p2.main.getPosition().y) {

							direc2.y = botmovespeed;
							down2 = true;



						}
						else {

							up2 = false;
							down2 = false;



							direc2.y = 0;
						}

					}

				}

				p2.main.move(direc2.x, direc2.y);

				p2.left.move(direc2.x, direc2.y);

				p2.top.move(direc2.x, direc2.y);

				p2.bottom.move(direc2.x, direc2.y);

				switch (p1.collision(ball)) {

				case player::CollisionDirection::RIGHT:

					ball.setPosition(p1.right.getPosition().x + ball.getSize().x + 10, ball.getPosition().y);

					ball.move(0, 0);

					if (up1) {

						velocity.y = -ballmovespeed - velocity.y;

					}
					else if (down1) {

						velocity.y = ballmovespeed + velocity.y;

					}

					else {

						velocity.y = velocity.y;

					}

					velocity.x = -velocity.x;

					break;

				case player::CollisionDirection::BOTTOM:

					ball.setPosition(ball.getPosition().x, p1.bottom.getPosition().y + ball.getSize().y + 10);

					ball.move(0, 0);

					if (start == 1) {

						velocity.y = ballmovespeed;

						start++;
					}

					velocity.x = ballmovespeed;

					velocity.y = -velocity.y;

					break;

				case player::CollisionDirection::TOP:

					ball.setPosition(ball.getPosition().x, p1.top.getPosition().y - ball.getSize().y - 10);

					ball.move(0, 0);

					if (start == 1) {

						velocity.y = ballmovespeed;

						start++;
					}

					velocity.x = ballmovespeed;

					velocity.y = -velocity.y;

					break;

				}

				switch (p2.collision(ball)) {

				case player::CollisionDirection::LEFT:

					ball.setPosition(p2.left.getPosition().x - ball.getSize().x - 10, ball.getPosition().y);

					ball.move(0, 0);

					if (up1) {

						velocity.y = ballmovespeed + velocity.y;

					}

					else if (down1) {

						velocity.y = -ballmovespeed - velocity.y;

					}

					else {

						velocity.y = velocity.y;

					}

					velocity.x = -velocity.x;

					break;

				case player::CollisionDirection::BOTTOM:

					ball.setPosition(ball.getPosition().x, p2.bottom.getPosition().y + ball.getSize().y + 10);

					ball.move(0, 0);

					if (start == 1) {

						velocity.y = -ballmovespeed;

						start++;
					}

					velocity.x = -ballmovespeed;

					velocity.y = -velocity.y;

					break;

				case player::CollisionDirection::TOP:

					ball.setPosition(ball.getPosition().x, p2.top.getPosition().y - ball.getSize().y - 10);

					ball.move(0, 0);

					if (start == 1) {

						velocity.y = -ballmovespeed;

						start++;
					}

					velocity.x = -ballmovespeed;

					velocity.y = -velocity.y;
					break;

				}

				if (ball.getPosition().y < 0) {

					ball.move(0, 0);

					velocity.y = -velocity.y;

				}
				if (ball.getPosition().y > 600 - ball.getSize().y) {

					ball.move(0, 0);

					velocity.y = -velocity.y;

				}
				else if (goo == false) {


					if (bot1v1 == true) {
						velocity.x += velocity.x / 2000;
						velocity.y += velocity.y / 2000;
					}
					else {
						velocity.x += velocity.x / 70000;
						velocity.y += velocity.y / 70000;
					}

				}

				ball.move(velocity.x, velocity.y);

				if (ball.getPosition().x < 0) {

					goo = true;

					pointsp2++;

				}
				if (ball.getPosition().x > 900) {

					goo = true;

					pointsp1++;
				}

				if (ball.getPosition().y < -13 || ball.getPosition().y > 613) {

					goo = true;

				}

				window.clear();
				for (int i = 0; i < 20; i++) {
					window.draw(line[i].line);
				}

				window.draw(p1.main);
				window.draw(p2.main);

				window.draw(bruno);
				window.draw(bruno2);

				window.draw(ball);
				window.display();
				break;	
		}
	}
}