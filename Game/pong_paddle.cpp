#include "pong_paddle.h"
#include <iostream>



void pong_paddle::update(sf::RenderWindow & rw,bool isAi,sf::Vector2f ball)
{
	if (!isAi) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (getPosition().y - paddle.getSize().y / 2 >= 0) {
				move(sf::Vector2f(0, -1), 8);
			}

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (getPosition().y + paddle.getSize().y / 2 <= rw.getSize().y) {
				move(sf::Vector2f(0, +1), 8);
			}

		}
	}
	else {
		if(getPosition().y < ball.y && getPosition().y + paddle.getSize().y / 2 <= rw.getSize().y) move(sf::Vector2f(0, +1), 12);
		if (getPosition().y > ball.y && getPosition().y - paddle.getSize().y / 2 >= 0) move(sf::Vector2f(0, -1), 12);
	}
	paddle.setPosition(getPosition());
}


void pong_paddle::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::CircleShape circle;
	circle.setPosition(paddle.getPosition());
	circle.setRadius(1);
	circle.setFillColor(sf::Color::Red);
	target.draw(paddle,states);
	target.draw(circle, states);
}

pong_paddle::pong_paddle()
{
	paddle.setFillColor(sf::Color::Blue);
	paddle.setSize(sf::Vector2f(10.f, 100.f));
	paddle.setOrigin(sf::Vector2f(paddle.getSize().x/2, paddle.getSize().y/2));
	
}


pong_paddle::~pong_paddle()
{
}
