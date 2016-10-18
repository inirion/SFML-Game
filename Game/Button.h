#pragma once
#include <SFML\Graphics.hpp>
class Button : public sf::Drawable
{
private:
	sf::Sprite buttonSprite;
	sf::Vector2f position;
	sf::Text buttonText;
	sf::Vector2f mousePressedPos;
	sf::Vector2f mouseReleasedPos;
	bool clickable;
	bool hovered;
	bool pressed;
	bool selected;
	bool checkEligible;
	std::string mvDirection;
	void hoverCheck(sf::RenderWindow &rw);
	void checkIfSelected(sf::RenderWindow &rw);
	sf::String textLang;

public:

	inline sf::String getTextLang() { return textLang; }
	void setTextLang(sf::String);
	void setButtonPos(sf::Vector2f pos);
	void setButtonText(std::string text);
	void setButtonSprite();
	void setButtonClickable(bool clickable);
	void setButtonMvDirection(sf::String mvDir);

	void update(sf::RenderWindow &rw);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const;
	Button();
	~Button();
};

