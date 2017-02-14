
#include "Sounds.h"
#include "S.h"
#include <exception>
#include <iostream>

std::map<std::string, sf::SoundBuffer> Sounds::map;
bool Sounds::inited = false;

void Sounds::init(bool force)
{
	if (!inited || force) {

		map.clear();
		try {
			map[S::null];
			map[S::sound_pong_paddle].loadFromFile("sound\\pong\\paddle_hit.wav");
			map[S::sound_snake_applecollide].loadFromFile("sound\\snake\\apple_collide.wav");
			inited = true;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

sf::SoundBuffer & Sounds::get(std::string id)
{
	if (map.find(id) != map.end()) {
		return map.at(id);
	}
	else {
		return map["unknown"];
	}
}

