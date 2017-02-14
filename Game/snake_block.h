#pragma once
#include "SFML\Graphics.hpp"
#include "Config.h"
#include "Positionable.h"
#include <vector>
#include <iostream>
#include <deque>

class snake_block : public sf::Drawable, Positionable
{
private :
	int maxMovePatternElements;
	static float delay;
	int bodyPartNumber;
	float lastFrameTime;
	sf::RectangleShape block;
	sf::Vector2f lastPos;
	bool isHead;
	enum directions {UP,DOWN,RIGHT,LEFT,NONE};
	static std::deque<sf::Vector2f> movePattern;
	directions currentDirection;
public:
	void update(sf::RenderWindow & rw);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const;
	inline sf::RectangleShape getBlock() { return block; }
	inline sf::Vector2f getLastPos() { return lastPos; }
	snake_block(float size, sf::Vector2f pos, bool isHead,sf::Color, int number);
	inline void setMaxMovePatternElements(int x) { maxMovePatternElements = x; }
	inline static void speedUp() { if (delay >= 75.f)delay -= 5.f; }
	inline static void speedUpReset() {delay = 300.f; }
	void addPartToMovePattern(sf::Vector2f Position);
	inline static void resetMovePattern() { movePattern.clear(); }
	~snake_block();
};

