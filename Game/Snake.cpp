#include "Snake.h"
#include "Lang.h"


void Snake::update(sf::RenderWindow & rw)
{
	rw.setMouseCursorVisible(false);
	if (gameOver && !selfColided && !wallColided) {
		text.setPosition(rw.getSize().x/2, rw.getSize().y/2);
		text.setCharacterSize(25);
		text.setFont(Config::fDJB);
		text.setColor(sf::Color::Blue);
		text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 8);
		wchar_t *a = l(S::snake_start_text);
		std::wstring s(a);
		text.setString(s);
		delete a;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			gameOver = false;
		}
	}
	else if (gameOver && (selfColided || wallColided)) {
		text.setPosition(rw.getSize().x / 2, rw.getSize().y / 2);
		text.setCharacterSize(25);
		text.setFont(Config::fDJB);
		text.setColor(sf::Color::Blue);
		text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 8);
		wchar_t *a = l(S::snake_gameover_text);
		std::wstring s(a);
		text.setString(s);
		delete a;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			gameOver = false;
		}
	}
	
	if (!gameOver) {
		scoreUpdate(rw);
		snakeBody[0].update(rw);
		for (int i = 1; i < snakeBody.size(); i++) {
			snakeBody[i].update(rw);
		}
		_apple->update(rw);
		appleCollide(snakeBody[0], *_apple);
		selfCollide(snakeBody[0], snakeBody,rw);
		barrierCollide(snakeBody[0], rw);
	}

}

void Snake::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (!gameOver) {
		for (auto &grid : mapTiles) {
			target.draw(grid);
		}
		for (auto &snake : snakeBody) {
			target.draw(snake);
		}
		target.draw(*_apple);
		target.draw(score);
	}
	else {
		target.draw(text);
	}

}

void Snake::reset(sf::RenderWindow & rw)
{
	points = 0;
	snakeBody[0].resetMovePattern();
	snakeBody.clear();
	srand(time(NULL));
	int randx, randy;
	bool randxTrue = false;
	bool randyTrue = false;
	bool go = true;
	randx = rand()% (int)(mapBounds.width / tileSize) ;
	randy = rand() % (int)(mapBounds.height / tileSize) ;
	std::cout << randx << " " << randy << std::endl;
	while (go) {
		if ((randx <= 3 || randx >= (mapBounds.width / tileSize) - 3) && !randxTrue) {
			randx = rand() % (int)(mapBounds.width / tileSize);
		}
		else {
			randxTrue = true;
		}
		if ((randy <= 3 || randy >= (mapBounds.height / tileSize) - 3) && !randyTrue) {
			randy = rand() % (int)(mapBounds.height / tileSize);
		}
		else {
			randyTrue = true;
		}
		if (randxTrue && randyTrue) go = false;
	}
	sf::Vector2f randomPos = sf::Vector2f(randx, randy) * tileSize;

	snakeBody.push_back(snake_block(tileSize, randomPos, true,sf::Color::Magenta,0));
	snakeBody[0].setMaxMovePatternElements((int)(mapBounds.width / tileSize) * (int)(mapBounds.height / tileSize));

	randomPos = sf::Vector2f(rand() % (int)(mapBounds.width / tileSize), rand() % (int)(mapBounds.height / tileSize)) * tileSize;
	_apple->reset(randomPos);
	snake_block::speedUpReset();

}

void Snake::appleCollide(snake_block head, apple &_apple)
{
	srand(time(NULL));
	if (head.getBlock().getPosition() == _apple.getApple().getPosition()) {
		sf::Vector2f randomPos = sf::Vector2f(rand() % (int)((mapBounds.width / tileSize)-1), rand() % (int)(mapBounds.height / tileSize)) * tileSize;
		int i = 0;
		bool run = true;
		while (run) {
			for (auto &body : snakeBody) {
				if (randomPos == body.getBlock().getPosition())
				{
					randomPos = sf::Vector2f(rand() % (int)((mapBounds.width / tileSize) - 1), rand() % (int)(mapBounds.height / tileSize)) * tileSize;
				}
				else {
					i++;
				}
			}
			if (i != snakeBody.size()) i = 0;
			if (i == snakeBody.size()) run = false;
		}
		_apple.reset(randomPos);
		appleCollideSound.play();
		points++;
		snakeBody.push_back(snake_block(tileSize, snakeBody[snakeBody.size()-1].getLastPos(),false, (snakeBody.size() - 1) % 2 ?sf::Color(0, 0, 255,255) : sf::Color(0, 255, 255, 255),snakeBody.size()));
		snake_block::speedUp();
	}
}

void Snake::selfCollide(snake_block head, std::vector<snake_block> snakeBody, sf::RenderWindow & rw)
{
	for (int i = 1; i < snakeBody.size(); i++) {
		if (head.getBlock().getPosition() == snakeBody[i].getBlock().getPosition()) {
			gameOver = true;
			selfColided = true;
			reset(rw);
		}
	}
	
}

void Snake::barrierCollide(snake_block head, sf::RenderWindow & rw)
{
	if (head.getBlock().getPosition().x >= mapBounds.width || head.getBlock().getPosition().x < 0 || head.getBlock().getPosition().y >= mapBounds.height || head.getBlock().getPosition().y < 0) {
		gameOver = true;
		wallColided = true;
		reset(rw);
	}
}

Snake::Snake(sf::RenderWindow & rw)
{
	appleCollideSound.setBuffer(Sounds::get(S::sound_snake_applecollide));
	wallColided = false;
	selfColided = false;
	points = 0;
	wchar_t *a = l(S::lang_score);
	std::wstring s(a);
	s += std::to_wstring(points);
	this->score.setString(s);
	delete a;
	score.setPosition(0, 0);
	score.setCharacterSize(25);
	score.setFont(Config::fDJB);
	score.setColor(sf::Color::Blue);
	score.setOrigin(score.getGlobalBounds().width / 2, score.getGlobalBounds().height / 8);

	gameOver = true;
	srand(time(NULL));
	tileSize = rw.getSize().x/20;
	mapBounds = sf::FloatRect(0, 0, rw.getSize().x - rw.getSize().x / 5, rw.getSize().y - tileSize/2);
	for (int j = 0; j < mapBounds.width / tileSize; j++)
		for (int i = 0; i < mapBounds.height / tileSize; i++)
		{
			sf::RectangleShape square;
			square.setSize(sf::Vector2f(tileSize, tileSize));
			square.setFillColor(sf::Color::Black);
			square.setOutlineThickness(-1.f);
			square.setOutlineColor(sf::Color(55, 55, 55));
			square.setPosition(sf::Vector2f(j*tileSize, i*tileSize));
			mapTiles.push_back(square);
		}

	_apple = new apple(tileSize);
}

void Snake::scoreUpdate(sf::RenderWindow &rw)
{
	wchar_t *a = l(S::lang_score);
	std::wstring s(a);
	s += std::to_wstring(points);
	this->score.setString(s);
	delete a;
	score.setPosition(sf::Vector2f(rw.getSize().x - score.getGlobalBounds().width, 20));
}


Snake::~Snake()
{
	
}
