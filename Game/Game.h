#pragma once
#include "SFML\Graphics.hpp"
#include "Config.h"
#include "Pong.h"
#include "Snake.h"

class Game : public sf::Drawable
{
private:
	Pong *pong;
	Snake *snake;
	bool init;
public:
	void update(sf::RenderWindow &rw);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const;
	Game(sf::RenderWindow & rw);
	~Game();
	void gamecheck(sf::RenderWindow &rw);
};

