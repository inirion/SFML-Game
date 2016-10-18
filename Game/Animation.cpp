#include "Animation.h"

void Animation::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(rect, states);
}
void Animation::update() {
	int diff = Config::clock.getElapsedTime().asMilliseconds() - lastTime;
	if (diff >= delay) {
		rect.setTextureRect(getFrameRect(currentFrame));
		currentFrame += (int)(diff / delay);
		if (currentFrame >= maxFrames) {
			if (oneTime) {
				currentFrame = maxFrames - 1;
			}
			else {
				currentFrame = 0;
			}
		}
		lastTime = Config::clock.getElapsedTime().asMilliseconds();
	}
}
sf::IntRect Animation::getFrameRect(int frame)const {
	return sf::IntRect(
		frame / rows * (int)frameDimension.x,
		frame % rows * (int)frameDimension.y,
		(int)frameDimension.x,
		(int)frameDimension.y
		);
}
void Animation::refreshTexture() {
	setTextureOld(texName);
	rect.setTexture(texture);
	frameDimension.x = (float)texture->getSize().x / cols;
	frameDimension.y = (float)texture->getSize().y / rows;
}
void Animation::setTexture(std::string tex) {
	texName = tex;
	refreshTexture();
}
