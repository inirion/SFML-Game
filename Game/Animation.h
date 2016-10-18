#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Textures.h"

class Animation : public sf::Drawable {
protected:
	std::string texName;
	sf::Texture* texture;
	sf::Vector2f position;
	sf::RectangleShape rect;
	sf::Vector2f frameDimension;
	int rows;
	int cols;
	int currentFrame;
	int maxFrames;
	float delay;
	int lastTime;
	bool oneTime;
public:
	Animation(int rows, int cols, std::string texId, float delay) :
		rows(rows),
		cols(cols),
		currentFrame(0),
		maxFrames(rows * cols),
		delay(delay),
		lastTime(CLOCKASMS),
		oneTime(false) {
		setTexture(texId);
		refreshTexture();
		rect.setSize(sf::Vector2f(frameDimension.x, frameDimension.y));
	}

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	virtual void update();
	virtual void refreshTexture();
	virtual void setTexture(std::string tex);
	sf::RectangleShape& getRect() { return rect; }
	const sf::RectangleShape& getRect()const { return rect; }
	inline sf::Vector2f getFrameDimension()const { return frameDimension; }
	inline int getMaxFrames()const { return maxFrames; }
	inline void setFrameDimension(sf::Vector2f v) { frameDimension = v; }
	inline void setRowsAndCols(int r, int c) { rows = r; cols = c; maxFrames = r*c; refreshTexture(); }
	inline void setFrame(int f) { currentFrame = f; rect.setTextureRect(getFrameRect(currentFrame)); }
	inline void setRandomFrame() { currentFrame = rand() % maxFrames; rect.setTextureRect(getFrameRect(currentFrame)); }
	virtual inline void setPosition(sf::Vector2f val) { position = val; rect.setPosition(position); }
	virtual inline void move(sf::Vector2f val, float mul = 1.0f) { position += val*mul; rect.setPosition(position); }
	inline int getCols()const { return cols; }
	inline int getRows()const { return rows; }
	sf::IntRect getFrameRect(int frame)const;
	inline void setOneTime(bool v) { oneTime = v; }
	inline void setDelay(float d) { delay = d; }
	inline int getCurrentFrame()const { return currentFrame; }
	inline bool isLastFrame()const { return currentFrame >= maxFrames - 1; }
	inline void start() { currentFrame = 0; lastTime = CLOCKASMS; }
	inline void setTextureOld(std::string texId) { texName = texId; texture = &Textures::get(texId); }
};

