#include <iostream>
#include <string>
#include <string.h>
#include <locale>
#include "Textures.h"
#include "Sounds.h"
#include "Config.h"
#include "Menu.h"
#include "Lang.h"
#include "Game.h"

int main() {
	Config::init();
	Textures::init();
	Sounds::init();
	Lang::init();
	setlocale(LC_ALL, "");
	//sf::VideoMode::getDesktopMode()
	//sf::Style::Fullscreen
	//sf::VideoMode(800, 600)
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML WORKS", sf::Style::Fullscreen);
	window.setPosition(sf::Vector2i(0,0));
	window.setFramerateLimit(RUNFPSLIMIT);
	Menu menu(window);
	Game game(window);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::LostFocus: {
				Config::gamePause = true;
				if(Config::activeMV == S::pong_game)
					Config::activeMV = S::menu_of_game_pong;
				if(Config::activeMV == S::snake_game)
					Config::activeMV = S::menu_of_game_snake;
				break;
			}
			case sf::Event::KeyPressed: {
				if (event.key.code == sf::Keyboard::Escape)
				{
					if (Config::gameRun && Config::activeMV == S::pong_game) {
						Config::gamePause = true;
						window.setMouseCursorVisible(true);
						Config::activeMV = S::menu_of_game_pong;
					}	
					if (Config::gameRun && Config::activeMV == S::snake_game) {
						Config::gamePause = true;
						window.setMouseCursorVisible(true);
						Config::activeMV = S::menu_of_game_snake;
					}
				}
				break;
			}
			}
		}
		if (Config::activeMV == S::menu_exit_yes) window.close();
		window.clear();
		game.gamecheck(window);
		if (!Config::gameRun) {
			menu.update(window);
			window.draw(menu);
		}
		else if (Config::gameRun) {
			game.update(window);
			window.draw(game);
		}
		
		
		window.display();
	}
}