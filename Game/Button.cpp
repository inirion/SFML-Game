#include "Button.h"
#include "Textures.h"
#include "Config.h"
#include <iostream>

#include "Lang.h"



void Button::hoverCheck(sf::RenderWindow &rw)
{
		sf::Vector2f p = rw.mapPixelToCoords(sf::Mouse::getPosition(rw));
		if (buttonText.getGlobalBounds().contains(p)) {
			hovered = true;
		}
		else hovered = false;
}

void Button::checkIfSelected(sf::RenderWindow & rw)
{
	hoverCheck(rw);
	if (hovered && clickable) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !pressed && checkEligible) {
			pressed = true;
			std::cout << "lmb pressed" << std::endl;
		}
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && pressed) {
			std::cout << "lmb released" << std::endl;
			pressed = false;
			selected = true;
		}
	}
	else pressed = false;
	if (!hovered && sf::Mouse::isButtonPressed(sf::Mouse::Left)) checkEligible = false;
	else if(hovered && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) checkEligible = true;
}

void Button::setTextLang(sf::String textLang)
{
	this->textLang = textLang;
}

void Button::setButtonPos(sf::Vector2f pos)
{
	this->position = pos;
}

void Button::setButtonText(std::string text)
{
	wchar_t *a = l(text);
	this->buttonText.setString(a);
	this->buttonText.setFont(Config::fDJB);
	this->buttonText.setCharacterSize(25);
	this->buttonText.setColor(sf::Color::Red);
	this->buttonText.setOrigin(buttonText.getGlobalBounds().width / 2, buttonText.getGlobalBounds().height / 2);
	this->buttonText.setPosition(position);
}

void Button::setButtonSprite()
{
	this->buttonSprite.setTexture(Textures::get(S::texture_buttonHover));
	this->buttonSprite.setOrigin(buttonSprite.getGlobalBounds().width / 2, buttonSprite.getGlobalBounds().height / 2);
	this->buttonSprite.setPosition(position.x, position.y - buttonText.getCharacterSize() / 4);
}

void Button::setButtonClickable(bool clickable)
{
	this->clickable = clickable;
}

void Button::setButtonMvDirection(sf::String mvDir)
{
	this->mvDirection = mvDir;
}


void Button::update(sf::RenderWindow & rw)
{
	checkIfSelected(rw);
	if (selected) {
		std::cout << "viev to = " << mvDirection << std::endl;
		Config::activeMV = mvDirection;
	}
	selected = false;
	
}

void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (hovered && clickable) {
		target.draw(buttonSprite, states);
	}
	target.draw(buttonText, states);
}

Button::Button()
{
	this->selected = false;
	this->pressed = false;
	this->hovered = false;
	this->checkEligible = false;
}


Button::~Button()
{
}
