#include "Menu.h"



void Menu::update(sf::RenderWindow & rw)
{
	selected = &mv[Config::activeMV];
	selected->update(rw);
}

void Menu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*selected, states);
}

Menu::Menu()
{
	MenuView mainMenu;
	MenuView newGame;
	MenuView options;
	MenuView help;
	MenuView exit;
	Button btn;
	//mainMenu view
	btn.setButtonPos(sf::Vector2f(400, 300));
	btn.setButtonText("New Game");
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_newgame);
	mainMenu.addButton(btn);

	btn.setButtonPos(sf::Vector2f(400, 350));
	btn.setButtonText("Options");
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_options);
	mainMenu.addButton(btn);

	btn.setButtonPos(sf::Vector2f(400, 400));
	btn.setButtonText("Help");
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_help);
	mainMenu.addButton(btn);

	btn.setButtonPos(sf::Vector2f(400, 450));
	btn.setButtonText("Exit");
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_exit);
	mainMenu.addButton(btn);

	mv[S::menu_main] = mainMenu;
	selected = &mv[Config::activeMV];
	//end of manMenu view

	//NewGame view
	btn.setButtonPos(sf::Vector2f(400, 300));
	btn.setButtonText("Test");
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_help);
	newGame.addButton(btn);

	btn.setButtonPos(sf::Vector2f(400, 350));
	btn.setButtonText("Return");
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_main);
	newGame.addButton(btn);

	mv[S::menu_newgame] = newGame;
	//end of NewGame view

	//Options view
	btn.setButtonPos(sf::Vector2f(400, 300));
	btn.setButtonText("Test");
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_options);
	options.addButton(btn);

	btn.setButtonPos(sf::Vector2f(400, 350));
	btn.setButtonText("Return");
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_main);
	options.addButton(btn);

	mv[S::menu_options] = options;
	//end of Options view

	//Help view
	btn.setButtonPos(sf::Vector2f(400, 300));
	btn.setButtonText("Test");
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_help);
	help.addButton(btn);

	btn.setButtonPos(sf::Vector2f(400, 350));
	btn.setButtonText("Return");
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_main);
	help.addButton(btn);

	mv[S::menu_help] = help;
	//end of Help view

	//Exit view
	btn.setButtonPos(sf::Vector2f(400, 300));
	btn.setButtonText("Yes");
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_exit_yes);
	exit.addButton(btn);

	btn.setButtonPos(sf::Vector2f(400, 350));
	btn.setButtonText("No");
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_main);
	exit.addButton(btn);

	mv[S::menu_exit] = exit;
	//end of Exit view
	
}


Menu::~Menu()
{
}
