#pragma once
#include <SFML\Graphics.hpp>
#include "Button.h"

class MenuView: public sf::Drawable
{
private:
	std::vector<Button> mvbuttons;
public:
	void update(sf::RenderWindow &rw);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const;
	void addButton(Button b);
	MenuView();
	~MenuView();
};

