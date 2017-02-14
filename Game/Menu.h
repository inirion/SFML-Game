#pragma once
#include "SFML\Graphics.hpp"
#include "MenuView.h"
#include "Config.h"



class Menu : public sf::Drawable
{
private:
	std::map<std::string, MenuView> mv;
	MenuView *selected;
public:
	void update(sf::RenderWindow &rw);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const;
	Menu(sf::RenderWindow & rw);
	~Menu();
};

