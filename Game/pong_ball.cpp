#include "pong_ball.h"
#include "Config.h"



void pong_ball::update(sf::RenderWindow & rw)
{
		move(movingCoords, speed);
		ball.setPosition(getPosition());
}

void pong_ball::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	
	target.draw(ball);
}

pong_ball::pong_ball()
{
	maxspeed = 14;
	radius = 5.5f;
	speed = 5.f;
	movingCoords = sf::Vector2f(-1, 0);
	ball.setRadius(radius);
	ball.setPosition(sf::Vector2f(10, 10));
}

pong_ball::~pong_ball()
{

}
