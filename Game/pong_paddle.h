#pragma once
#include "SFML\Graphics.hpp"
#include "Config.h"
#include "Positionable.h"
class pong_paddle : public sf::Drawable, Positionable
{
private :
	sf::RectangleShape paddle;
public:
	void update(sf::RenderWindow &rw,bool isAi = false, sf::Vector2f ball = sf::Vector2f(0,0));
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const;
	void reset(sf::Vector2f pos) { setPosition(pos); }
	inline sf::Vector2f getSize() { return paddle.getSize(); }
	inline sf::RectangleShape getPaddle() { return paddle; }
	inline sf::FloatRect getPaddleRect() {
		return paddle.getGlobalBounds();
	}
	pong_paddle();
	~pong_paddle();
};

