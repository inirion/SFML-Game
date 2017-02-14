#include "snake_block.h"

float snake_block::delay = 200.f;
std::deque<sf::Vector2f> snake_block::movePattern;


void snake_block::update(sf::RenderWindow & rw)
{
	if (isHead) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (currentDirection != directions::UP && currentDirection != directions::DOWN&& lastPos.x != getPosition().x) {
				currentDirection = directions::UP;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (currentDirection != directions::UP && currentDirection != directions::DOWN&& lastPos.x != getPosition().x) {
				currentDirection = directions::DOWN;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if (currentDirection != directions::LEFT && currentDirection != directions::RIGHT && lastPos.y != getPosition().y) {
				currentDirection = directions::LEFT;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if (currentDirection != directions::LEFT && currentDirection != directions::RIGHT && lastPos.y != getPosition().y) {
				currentDirection = directions::RIGHT;
			}
		}
	}
	if (isHead) {
		if (Config::clock.getElapsedTime().asMilliseconds() - lastFrameTime >= delay) {
			lastPos = getPosition();
			if (currentDirection == directions::UP) {
				addPartToMovePattern(getPosition());
				move(sf::Vector2f(0, -1), block.getSize().x);
			}
			if (currentDirection == directions::DOWN) {
				addPartToMovePattern(getPosition());
				move(sf::Vector2f(0, 1), block.getSize().x);
			}
			if (currentDirection == directions::LEFT) {
				addPartToMovePattern(getPosition());
				move(sf::Vector2f(-1, 0), block.getSize().x);
			}
			if (currentDirection == directions::RIGHT) {
				addPartToMovePattern(getPosition());
				move(sf::Vector2f(1, 0), block.getSize().x);
			}
			lastFrameTime = Config::clock.getElapsedTime().asMilliseconds();
		}
	}
	else {
		std::cout << movePattern.size() << std::endl;
		setPosition(movePattern[bodyPartNumber - 1]);

	}
	block.setPosition(getPosition());


}

void snake_block::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(block);
}

snake_block::snake_block(float size, sf::Vector2f poss, bool isHead, sf::Color color, int number)
{
	if (isHead)
	{
		this->isHead = isHead;
		setPosition(poss);
		currentDirection = directions::RIGHT;
	}
	else
	{
		lastPos = sf::Vector2f(-size, -size);
		setPosition(lastPos);
		this->isHead = false;
	}
	bodyPartNumber = number;
	lastFrameTime = Config::clock.getElapsedTime().asMilliseconds();
	block.setSize(sf::Vector2f(size, size));
	block.setFillColor(sf::Color::Red);
	block.setPosition(poss);
	block.setFillColor(color);

}


void snake_block::addPartToMovePattern(sf::Vector2f Position)
{
	movePattern.push_front(Position);
	if (movePattern.size() >= maxMovePatternElements) {
		movePattern.pop_back();
	}
}

snake_block::~snake_block()
{

}
