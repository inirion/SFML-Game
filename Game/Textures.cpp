#include "Textures.h"
#include "S.h"
#include <exception>
#include <iostream>

std::map<std::string, sf::Texture> Textures::map;
bool Textures::inited = false;

void Textures::init(bool force) {
	if (!inited || force) {

		map.clear();
		try {
			map[S::null];
			map[S::texture_hoveranim].loadFromFile("img\\anim\\hoveranim.png");
			map[S::texture_hoveranim].setSmooth(true);

			inited = true;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

sf::Texture& Textures::get(std::string id) {
	if (map.find(id) != map.end()) {
		return map.at(id);
	}
	else {
		return map["unknown"];
	}
}