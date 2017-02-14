#include "Menu.h"
#include "Lang.h"
#include <iostream>

void Menu::update(sf::RenderWindow & rw)
{
	if(Config::activeMV != S::menu_lang)
		selected = &mv[Config::activeMV];
	if (Config::activeMV == S::menu_lang) {
		Lang::set2Next();
		for (auto &button : mv) {
			button.second.updateButtonText();
		}
		Config::activeMV = S::menu_options;
	}
	if (Config::gamePause && (Config::activeMV == S::menu_of_game_pong || Config::activeMV == S::menu_of_game_snake)) {
		mv[S::menu_of_game_pong].updateSelectedButton(S::game_start,S::lang_continue);
		mv[S::menu_of_game_pong].updateSelectedButton(S::game_start,S::lang_continue);
		mv[S::menu_of_game_pong].updateSelectedButton(S::lang_return,S::lang_exit);
		mv[S::menu_of_game_pong].updateSelectedButton(S::lang_return,S::lang_exit);

		mv[S::menu_of_game_snake].updateSelectedButton(S::game_start, S::lang_continue);
		mv[S::menu_of_game_snake].updateSelectedButton(S::game_start, S::lang_continue);
		mv[S::menu_of_game_snake].updateSelectedButton(S::lang_return, S::lang_exit);
		mv[S::menu_of_game_snake].updateSelectedButton(S::lang_return, S::lang_exit);
	}
	if(!Config::gamePause && (Config::activeMV == S::menu_of_game_pong || Config::activeMV == S::menu_of_game_snake)) {
		mv[S::menu_of_game_pong].updateSelectedButton(S::lang_continue,S::game_start);
		mv[S::menu_of_game_pong].updateSelectedButton(S::lang_continue,S::game_start);
		mv[S::menu_of_game_pong].updateSelectedButton(S::lang_exit,S::lang_return);
		mv[S::menu_of_game_pong].updateSelectedButton(S::lang_exit,S::lang_return);

		mv[S::menu_of_game_snake].updateSelectedButton(S::lang_continue, S::game_start);
		mv[S::menu_of_game_snake].updateSelectedButton(S::lang_continue, S::game_start);
		mv[S::menu_of_game_snake].updateSelectedButton(S::lang_exit, S::lang_return);
		mv[S::menu_of_game_snake].updateSelectedButton(S::lang_exit, S::lang_return);
	}
	selected->update(rw);
}

void Menu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*selected, states);
}

Menu::Menu(sf::RenderWindow & rw)
{
	MenuView pongGame;
	MenuView snakeGame;
	MenuView mainMenu;
	MenuView newGame;
	MenuView options;
	MenuView help;
	MenuView exit;
	Button btn;
	float yoffset = 50;
	//mainMenu view
	//Text 
	
	btn.setButtonPos(sf::Vector2f(rw.getSize().x / 2, rw.getSize().y / 5));
	btn.setButtonText(S::text_mainmenu);
	btn.setButtonClickable(false);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_main);
	btn.setTextLang(S::text_mainmenu);
	mainMenu.addButton(btn);
	//end Text
	//Buttons
	btn.setButtonPos(sf::Vector2f(rw.getSize().x / 2, rw.getSize().y / 2.5 + yoffset));
	yoffset += 50;
	btn.setButtonText(S::lang_newgame);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_newgame);
	btn.setTextLang(S::lang_newgame);
	mainMenu.addButton(btn);

	btn.setButtonPos(sf::Vector2f(rw.getSize().x / 2, rw.getSize().y / 2.5 + yoffset));
	yoffset += 50;
	btn.setButtonText(S::lang_options);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_options);
	btn.setTextLang(S::lang_options);
	mainMenu.addButton(btn);

	btn.setButtonPos(sf::Vector2f(rw.getSize().x / 2, rw.getSize().y / 2.5 + yoffset));
	yoffset += 50;
	btn.setButtonText(S::lang_help);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_help);
	btn.setTextLang(S::lang_help);
	mainMenu.addButton(btn);

	btn.setButtonPos(sf::Vector2f(rw.getSize().x / 2, rw.getSize().y / 2.5 + yoffset));
	yoffset += 50;
	btn.setButtonText(S::lang_exit);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_exit);
	btn.setTextLang(S::lang_exit);
	mainMenu.addButton(btn);
	//edn Buttons
	mv[S::menu_main] = mainMenu;
	selected = &mv[Config::activeMV];
	
	//end of manMenu view
	yoffset = 0;
	//NewGame view
	//Buttons
	btn.setButtonPos(sf::Vector2f(rw.getSize().x / 2, rw.getSize().y / 2.5 + yoffset));
	yoffset += 50;
	btn.setButtonText(S::lang_pong_game);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_of_game_pong);
	btn.setTextLang(S::lang_pong_game);
	newGame.addButton(btn);

	btn.setButtonPos(sf::Vector2f(rw.getSize().x / 2, rw.getSize().y / 2.5 + yoffset));
	yoffset += 50;
	btn.setButtonText(S::lang_snake_game);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_of_game_snake);
	btn.setTextLang(S::lang_snake_game);
	newGame.addButton(btn);

	btn.setButtonPos(sf::Vector2f(rw.getSize().x / 2, rw.getSize().y / 2.5 + yoffset));
	yoffset += 50;
	btn.setButtonText(S::lang_return);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_main);
	btn.setTextLang(S::lang_return);
	newGame.addButton(btn);
	//edn Buttons

	mv[S::menu_newgame] = newGame;
	//end of NewGame view
	yoffset = 0;
	//Pong view
	//Buttons
	btn.setButtonPos(sf::Vector2f(rw.getSize().x / 2, rw.getSize().y / 2.5 + yoffset));
	yoffset += 50;
	btn.setButtonText(S::game_start);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::pong_game);
	btn.setTextLang(S::game_start);
	pongGame.addButton(btn);

	btn.setButtonPos(sf::Vector2f(rw.getSize().x / 2, rw.getSize().y / 2.5 + yoffset));
	yoffset += 50;
	btn.setButtonText(S::lang_return);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_newgame);
	btn.setTextLang(S::lang_return);
	pongGame.addButton(btn);
	//edn Buttons

	mv[S::menu_of_game_pong] = pongGame;

	//End of pong View
	yoffset = 0;
	//Snake view
	//Buttons
	btn.setButtonPos(sf::Vector2f(rw.getSize().x / 2, rw.getSize().y / 2.5 + yoffset));
	yoffset += 50;
	btn.setButtonText(S::game_start);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::snake_game);
	btn.setTextLang(S::game_start);
	snakeGame.addButton(btn);

	btn.setButtonPos(sf::Vector2f(rw.getSize().x / 2, rw.getSize().y / 2.5 + yoffset));
	yoffset += 50;
	btn.setButtonText(S::lang_return);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_newgame);
	btn.setTextLang(S::lang_return);
	snakeGame.addButton(btn);
	//edn Buttons

	mv[S::menu_of_game_snake] = snakeGame;

	//End of snake View
	yoffset = 0;
	//Options view
	//Buttons
	btn.setButtonPos(sf::Vector2f(rw.getSize().x / 2, rw.getSize().y / 2.5 + yoffset));
	yoffset += 50;
	btn.setButtonText(S::lang_changelang);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_lang);
	btn.setTextLang(S::lang_changelang);
	options.addButton(btn);

	btn.setButtonPos(sf::Vector2f(rw.getSize().x / 2, rw.getSize().y / 2.5 + yoffset));
	yoffset += 50;
	btn.setButtonText(S::lang_return);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_main);
	btn.setTextLang(S::lang_return);
	options.addButton(btn);
	//edn Buttons
	mv[S::menu_options] = options;
	//end of Options view
	yoffset = 0;
	//Help view
	//Buttons
	btn.setButtonPos(sf::Vector2f(rw.getSize().x / 2, rw.getSize().y / 2.5 + yoffset));
	yoffset += 50;
	btn.setButtonText(S::lang_test);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_help);
	btn.setTextLang(S::lang_test);
	help.addButton(btn);

	btn.setButtonPos(sf::Vector2f(rw.getSize().x / 2, rw.getSize().y / 2.5 + yoffset));
	yoffset += 50;
	btn.setButtonText(S::lang_return);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_main);
	btn.setTextLang(S::lang_return);
	help.addButton(btn);
	//edn Buttons
	mv[S::menu_help] = help;
	//end of Help view
	yoffset = 0;
	//Exit view
	//Buttons
	btn.setButtonPos(sf::Vector2f(rw.getSize().x / 2, rw.getSize().y / 2.5 + yoffset));
	yoffset += 50;
	btn.setButtonText(S::lang_yes);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_exit_yes);
	btn.setTextLang(S::lang_yes);
	exit.addButton(btn);

	btn.setButtonPos(sf::Vector2f(rw.getSize().x / 2, rw.getSize().y / 2.5 + yoffset));
	yoffset += 50;
	btn.setButtonText(S::lang_no);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_main);
	btn.setTextLang(S::lang_no);
	exit.addButton(btn);
	//edn Buttons
	mv[S::menu_exit] = exit;
	//end of Exit view
	yoffset = 0;
	
}


Menu::~Menu()
{
}
