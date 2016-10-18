#include "MenuView.h"
#include "Lang.h"



void MenuView::update(sf::RenderWindow & rw)
{
	for (auto &button : mvbuttons) {
		button.update(rw);
	}
}

void MenuView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (const auto &button : mvbuttons) {
		target.draw(button, states);
	}
}

void MenuView::addButton(Button b)
{
	mvbuttons.push_back(b);
}

void MenuView::updateButtonText()
{
	for (auto &button : mvbuttons) {
		button.setButtonText(button.getTextLang());
	}
}

MenuView::MenuView()
{
}


MenuView::~MenuView()
{
}
