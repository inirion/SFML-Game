#include "Game.h"
#include "Config.h"
#include "S.h"
#include "Pong.h"
#include <iostream>



void Game::update(sf::RenderWindow & rw)
{
	if (Config::gameRun && Config::activeMV == S::pong_game) {
		pong->update(rw);
	}
	if (Config::gameRun && Config::activeMV == S::snake_game) {
		snake->update(rw);
	}
}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (Config::gameRun && Config::activeMV == S::pong_game) {
		target.draw(*pong);
	}
	if (Config::gameRun && Config::activeMV == S::snake_game) {
		target.draw(*snake);
	}
}

Game::Game(sf::RenderWindow & rw)
{
	pong = new Pong();
	snake = new Snake(rw);
	init = true;
}


Game::~Game()
{

}

void Game::gamecheck(sf::RenderWindow &rw)
{
	if (Config::activeMV == S::pong_game || Config::activeMV == S::snake_game) {
		Config::gameRun = true;
		init = true;
	}
	else {
		Config::gameRun = false;
	}
	if (Config::activeMV == S::menu_newgame) {
		Config::gamePause = false;
		Config::gamePause ? pong->setGameStatus(true) : pong->setGameStatus(false);
		Config::gamePause ? snake->setGameStatus(true) : snake->setGameStatus(false);
		if ((!snake->getGameStatus() || !pong->getGameStatus()) && init == true) {
			init = false;
			pong->reset(rw);
			snake->reset(rw);
		}
	}
	if (Config::activeMV == S::menu_main) init = true;
	
}
