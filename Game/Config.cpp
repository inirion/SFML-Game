#include<SFML\Graphics.hpp>
#include "Config.h"
#include "S.h"

float Config::newzoom = 1.0f;

int Config::dHeight = 800;
int Config::dWidth = 480;

sf::Vector2f Config::hoverPos;

sf::Font Config::fDJB;
sf::Clock Config::clock;
sf::Clock Config::FPSclock;
float Config::dtime = 0.0f;

bool Config::inited = false;
bool Config::gameRun = false;
bool Config::gamePause = false;
bool Config::debugEnable = true;
bool Config::windowFocused = false;

float Config::menuSoundVolume = 100.0f;
float Config::gameSoundVolume = 100.0f;

sf::View Config::vw;
std::string Config::activeMV = S::menu_main;

void Config::init() {
	if (!inited) {
		inited = true;
		fDJB.loadFromFile("font/DJB.ttf");
	}
}
