
#pragma once
#include <SFML\Audio.hpp>
#include <map>
#include <string>
#include "Config.h"
class Sounds
{
private:
	static std::map<std::string, sf::SoundBuffer> map;
	static bool inited;
public:
	static void init(bool force = false);
	static sf::SoundBuffer& get(std::string id);
};


