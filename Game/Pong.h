#pragma once
#include "SFML\Graphics.hpp"
#include "Sounds.h"
#include "Config.h"
#include "Positionable.h"
#include "pong_paddle.h"
#include "pong_ball.h"

class Pong : public sf::Drawable, Positionable
{
private:
	bool freshGame;
	pong_paddle *player;
	pong_paddle *ai;
	pong_ball *ball;
	sf::Text score;
	int playerPoints;
	int aiPoints;
	sf::Sound paddleHit;

public:
	void update(sf::RenderWindow &rw);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const;
	void reset(sf::RenderWindow & rw);
	inline bool getGameStatus() { return freshGame; }
	inline void setGameStatus(bool status) {freshGame = status; }
	void Collision(sf::RenderWindow & rw);
	Pong();
	~Pong();
};

