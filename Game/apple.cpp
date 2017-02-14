#include "apple.h"



void apple::update(sf::RenderWindow & rw)
{


}

void apple::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(app);
}

void apple::reset(sf::Vector2f pos)
{
	app.setPosition(pos);
}

apple::apple(float size)
{
	app.setRadius(size/2);
	app.setFillColor(sf::Color::Green);
	delay = 50.f;
	lastFrameTime = Config::clock.getElapsedTime().asMilliseconds();
}


apple::~apple()
{

}
