#pragma once
#include "SFML\Graphics.hpp"
#include "Config.h"
#include "Positionable.h"
#include <vector>
#include <iostream>

class apple : public sf::Drawable, Positionable
{
private :
	float delay;
	float lastFrameTime;
	sf::CircleShape app;
public:
	void update(sf::RenderWindow & rw);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const;
	void reset(sf::Vector2f pos);
	inline sf::CircleShape getApple() { return app; }
	apple(float size = 0);
	~apple();
};

