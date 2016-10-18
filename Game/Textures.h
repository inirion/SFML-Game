#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "Config.h"

class Textures {
private:
	static std::map<std::string, sf::Texture> map;
	static bool inited;

public:
	static void init(bool force = false);
	static sf::Texture& get(std::string id);
};
