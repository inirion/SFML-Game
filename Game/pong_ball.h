#pragma once
#include "SFML\Graphics.hpp"
#include "Config.h"
#include "Positionable.h"
class pong_ball : public sf::Drawable, Positionable
{
private:
	sf::CircleShape ball;
	sf::Vector2f movingCoords;
	float speed;
	char maxspeed;
	float radius;
public:
	void update(sf::RenderWindow &rw);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const;
	inline void reset(sf::Vector2f pos) { setPosition(pos); speed = 5.f; movingCoords = sf::Vector2f(-1, 0); }
	inline sf::Vector2f getMovingCoords() { return movingCoords; }
	inline void setMovingCoords(sf::Vector2f coords) { movingCoords = coords; if(speed <= maxspeed) speed += 0.5; }
	inline sf::CircleShape getBall() { return ball; }
	inline sf::FloatRect getBallRect() { return ball.getGlobalBounds(); }
	inline float getSpeed() { return speed; }
	pong_ball();
	~pong_ball();
};

