#include "Pong.h"
#include <iostream>
#include "Lang.h"
#include <SFML\Audio.hpp>



void Pong::update(sf::RenderWindow & rw)
{
	rw.setMouseCursorVisible(false);
	Collision(rw);
	player->update(rw);
	ball->update(rw);
	ai->update(rw,true,ball->getBall().getPosition());
}

void Pong::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	
	target.draw(*player);
	target.draw(*ball);
	target.draw(score);
	target.draw(*ai);
}

void Pong::reset(sf::RenderWindow & rw)
{
	player->reset(sf::Vector2f(player->getSize().x, rw.getSize().y / 2));
	ai->reset(sf::Vector2f(rw.getSize().x - ai->getPaddle().getSize().x, rw.getSize().y / 2));
	ball->reset(sf::Vector2f(rw.getSize().x / 2 , rw.getSize().y / 2));
	score.setPosition(sf::Vector2f(rw.getSize().x / 2, 20));
	wchar_t *a = l(S::lang_score);
	std::wstring s(a);
	s += std::to_wstring(playerPoints) + L" - " + std::to_wstring(aiPoints);
	this->score.setString(s);
	delete a;
	
}

void Pong::Collision(sf::RenderWindow & rw)
{
	if (ball->getBallRect().intersects(player->getPaddleRect())) {
		
		float angle = 0.f;
		if (ball->getBall().getPosition().x <= player->getPaddle().getPosition().x + ball->getSpeed()) {
			if (ball->getBall().getPosition().y <= player->getPaddle().getPosition().y
				&& ball->getBall().getPosition().y >= player->getPaddle().getPosition().y - player->getSize().y) {
				std::cout << "top interact : " << std::endl;
				float lenghtOfUpperPaddle = player->getPaddle().getPosition().y - ball->getBall().getPosition().y;
				angle = lenghtOfUpperPaddle / 35.f*-1;
			}
			else if (ball->getBall().getPosition().y >= player->getPaddle().getPosition().y
				&& ball->getBall().getPosition().y <= player->getPaddle().getPosition().y + player->getSize().y) {
				std::cout << "bottom interact : " << std::endl;
				float lenghtOfUpperPaddle = player->getPaddle().getPosition().y - ball->getBall().getPosition().y;
				angle = lenghtOfUpperPaddle / 35.f*-1;
			}
			ball->setMovingCoords(sf::Vector2f(1, angle));
			paddleHit.play();
		}
		
	}
	if (ball->getBallRect().intersects(ai->getPaddleRect())) {
		
		float angle = 0.f;
		if (ball->getBall().getPosition().x >= player->getPaddle().getPosition().x -ball->getSpeed()) {
			if (ball->getBall().getPosition().y <= ai->getPaddle().getPosition().y
				&& ball->getBall().getPosition().y >= ai->getPaddle().getPosition().y - ai->getSize().y) {
				float lenghtOfUpperPaddle = ai->getPaddle().getPosition().y - ball->getBall().getPosition().y;
				angle = lenghtOfUpperPaddle / 35.f *-1;
			}
			else if (ball->getBall().getPosition().y >= ai->getPaddle().getPosition().y
				&& ball->getBall().getPosition().y <= ai->getPaddle().getPosition().y + ai->getSize().y) {
				float lenghtOfUpperPaddle = ai->getPaddle().getPosition().y - ball->getBall().getPosition().y;
				angle = lenghtOfUpperPaddle / 35.f *-1;
			}
			std::cout << "ai interact : " << std::endl;
			ball->setMovingCoords(sf::Vector2f(-1, angle));
			paddleHit.play();
		}
	}
	if (ball->getBall().getPosition().x >= rw.getSize().x) {
		playerPoints++;
		reset(rw);
	}
	if (ball->getBall().getPosition().x <= 0) {
		aiPoints++;
		reset(rw);
	}
	if (ball->getBall().getPosition().y <= 0) {
		ball->setMovingCoords(sf::Vector2f(ball->getMovingCoords().x, ball->getMovingCoords().y*-1.f));
	}
	if (ball->getBall().getPosition().y >= rw.getSize().y) {
		ball->setMovingCoords(sf::Vector2f(ball->getMovingCoords().x, ball->getMovingCoords().y*-1.f));
	}
}

Pong::Pong()
{
	paddleHit.setBuffer(Sounds::get(S::sound_pong_paddle));
	playerPoints = 0;
	aiPoints = 0;
	wchar_t *a = l(S::lang_score);
	std::wstring s(a);
	s += std::to_wstring(playerPoints) + L" - " + std::to_wstring(aiPoints);
	this->score.setString(s);
	delete a;
	score.setPosition(0,0);
	score.setCharacterSize(25);
	score.setFont(Config::fDJB);
	score.setColor(sf::Color::Blue);
	score.setOrigin(score.getGlobalBounds().width / 2, score.getGlobalBounds().height / 8);
	
	setGameStatus(true);
	player = new pong_paddle();
	ai = new pong_paddle();
	ball = new pong_ball();
}


Pong::~Pong()
{
	delete player;
	delete ai;
	delete ball;
}
