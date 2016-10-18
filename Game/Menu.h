#pragma once
#include "SFML\Graphics.hpp"
#include "MenuView.h"
#include "Config.h"
#include "S.h"

class Menu : public sf::Drawable
{
private:
	std::map<std::string, MenuView> mv;
	MenuView *selected;
public:
	void update(sf::RenderWindow &rw);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const;
	Menu();
	~Menu();
};

