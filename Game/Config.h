#pragma once
#include <SFML\Graphics.hpp>
#define RUNFPSLIMIT 60
#define PAUSEFPSLIMIT 15

class Config { 

public:

	static float newzoom;

	static int dHeight;
	static int dWidth;

	static sf::Font fDJB;
	static sf::Clock clock;
	static sf::Clock FPSclock;
	static float dtime;

	static sf::Vector2f hoverPos;

	static bool gameRun;
	static bool gamePause;

	static float menuSoundVolume;
	static float gameSoundVolume;

	static sf::View vw;
	static std::string activeMV;

	static bool debugEnable;
	static bool windowFocused;

	static bool inited;
	static void init();

};

#define CLOCKASSEC Conf::clock.getElapsedTime().asSeconds()
#define CLOCKASMS Conf::clock.getElapsedTime().asMilliseconds()


