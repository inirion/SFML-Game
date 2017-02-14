#pragma once
#include <SFML/Graphics.hpp>
class Positionable {
protected:
	sf::Vector2f position;
public:
	virtual ~Positionable() {}

	virtual inline sf::Vector2f getPosition() const { return position; }
	virtual inline void setPosition(sf::Vector2f val) { position = val; }
	virtual inline void move(sf::Vector2f val, float mul = 1.0f) { position += val*mul; }
};

