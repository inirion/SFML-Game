#include "Menu.h"
#include "Lang.h"

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
	//Text 
	btn.setButtonPos(sf::Vector2f(400, 100));
	btn.setButtonText(S::text_mainmenu);
	btn.setButtonClickable(false);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_main);
	btn.setTextLang(S::text_mainmenu);
	mainMenu.addButton(btn);
	//end Text
	//Buttons
	btn.setButtonPos(sf::Vector2f(400, 300));
	btn.setButtonText(S::lang_newgame);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_newgame);
	btn.setTextLang(S::lang_newgame);
	mainMenu.addButton(btn);

	btn.setButtonPos(sf::Vector2f(400, 350));
	btn.setButtonText(S::lang_options);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_options);
	btn.setTextLang(S::lang_options);
	mainMenu.addButton(btn);

	btn.setButtonPos(sf::Vector2f(400, 400));
	btn.setButtonText(S::lang_help);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_help);
	btn.setTextLang(S::lang_help);
	mainMenu.addButton(btn);

	btn.setButtonPos(sf::Vector2f(400, 450));
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

	//NewGame view
	//Buttons
	btn.setButtonPos(sf::Vector2f(400, 300));
	btn.setButtonText(S::lang_test);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_newgame);
	btn.setTextLang(S::lang_test);
	newGame.addButton(btn);

	btn.setButtonPos(sf::Vector2f(400, 350));
	btn.setButtonText(S::lang_return);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_main);
	btn.setTextLang(S::lang_return);
	newGame.addButton(btn);
	//edn Buttons

	mv[S::menu_newgame] = newGame;
	//end of NewGame view

	//Options view
	//Buttons
	btn.setButtonPos(sf::Vector2f(400, 300));
	btn.setButtonText(S::lang_test);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_lang);
	btn.setTextLang(S::lang_test);
	options.addButton(btn);

	btn.setButtonPos(sf::Vector2f(400, 350));
	btn.setButtonText(S::lang_return);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_main);
	btn.setTextLang(S::lang_return);
	options.addButton(btn);
	//edn Buttons
	mv[S::menu_options] = options;
	//end of Options view

	//Help view
	//Buttons
	btn.setButtonPos(sf::Vector2f(400, 300));
	btn.setButtonText(S::lang_test);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_help);
	btn.setTextLang(S::lang_test);
	help.addButton(btn);

	btn.setButtonPos(sf::Vector2f(400, 350));
	btn.setButtonText(S::lang_return);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_main);
	btn.setTextLang(S::lang_return);
	help.addButton(btn);
	//edn Buttons
	mv[S::menu_help] = help;
	//end of Help view

	//Exit view
	//Buttons
	btn.setButtonPos(sf::Vector2f(400, 300));
	btn.setButtonText(S::lang_yes);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_exit_yes);
	btn.setTextLang(S::lang_yes);
	exit.addButton(btn);

	btn.setButtonPos(sf::Vector2f(400, 350));
	btn.setButtonText(S::lang_no);
	btn.setButtonClickable(true);
	btn.setButtonSprite();
	btn.setButtonMvDirection(S::menu_main);
	btn.setTextLang(S::lang_no);
	exit.addButton(btn);
	//edn Buttons
	mv[S::menu_exit] = exit;
	//end of Exit view
	
}


Menu::~Menu()
{
}
