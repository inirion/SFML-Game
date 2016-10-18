#include <iostream>
#include <string>
#include <string.h>
#include <locale>
#include "Textures.h"
#include "Config.h"
#include "Menu.h"
#include "Lang.h"

int main() {
	Config::init();
	Textures::init();
	Lang::init();
	setlocale(LC_ALL, "");
	sf::RenderWindow window(sf::VideoMode(800,600), "SFML WORKS" /*,sf::Style::Fullscreen*/);
	Menu menu;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		if (Config::activeMV == S::menu_exit_yes) window.close();
		window.clear();
		window.draw(menu);
		menu.update(window);
		window.display();
	}
}