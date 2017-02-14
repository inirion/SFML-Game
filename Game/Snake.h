#pragma once
#include "SFML\Graphics.hpp"
#include "Config.h"
#include "Positionable.h"
#include "snake_block.h"
#include "apple.h"
#include "Sounds.h"
#include <vector>

class Snake : public sf::Drawable, Positionable
{
private :
	bool freshGame;
	std::vector <sf::RectangleShape> mapTiles;
	float tileSize;
	sf::FloatRect mapBounds;
	std::vector <snake_block> snakeBody;
	apple *_apple;
	bool gameOver,selfColided,wallColided;
	sf::Text text;
	sf::Text score;
	int points;
	sf::Sound appleCollideSound;

public:
	void update(sf::RenderWindow &rw);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const;
	void reset(sf::RenderWindow & rw);
	inline bool getGameStatus() { return freshGame; }
	inline void setGameStatus(bool status) { freshGame = status; }
	void appleCollide(snake_block head, apple &_apple);
	void selfCollide(snake_block head, std::vector <snake_block> snakeBody, sf::RenderWindow & rw);
	void barrierCollide(snake_block head, sf::RenderWindow & rw);
	Snake(sf::RenderWindow & rw);
	void scoreUpdate(sf::RenderWindow &rw);
	~Snake();
};

