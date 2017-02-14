#pragma once
#include <SFML\Graphics.hpp>
#include "Button.h"
#include <string>
#include <iostream>

class MenuView: public sf::Drawable
{
private:
	std::vector<Button> mvbuttons;
public:
	void update(sf::RenderWindow &rw);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const;
	void addButton(Button b);
	void updateButtonText();
	inline void updateSelectedButton(std::string oldGetTextLang, std::string newGetTextLang){
		for (auto &button : mvbuttons) {
			if (button.getTextLang() == oldGetTextLang) {
				button.setButtonText(newGetTextLang);
				button.setTextLang(newGetTextLang);
			}
		}
	}
	MenuView();
	~MenuView();
};

