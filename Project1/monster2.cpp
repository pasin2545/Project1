#include "monster2.h"
monster2::monster2(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speedm2 = speed;
	rowm2 = 0;
	faceRightm2 = true;

	bodym2.setSize(sf::Vector2f(240.0f/1.2, 160.0f/1.2));
	bodym2.setPosition(2400.0f, -138.0+26.0f);
	bodym2.setTexture(texture);
}

monster2::~monster2() {}
void monster2::Updatem2(float deltatimem1) {
	float x = bodym2.getPosition().x;
	float y = bodym2.getPosition().y;
	sf::Vector2f movement(0.0f, 0.0f);
	if (chk == 0) {
		movement.x -= speedm2 * deltatimem1;
		if (x <= 1800.0f) {
			chk = 1;
		}
	}
	if (chk == 1) {
		movement.x += speedm2 * deltatimem1;
		if (x >= 2600.0f) {
			chk = 0;
		}
	}

	rowm2 = 0;
	if (chk == 0) {
		faceRightm2 = true;
	}
	else {
		faceRightm2 = false;
	}

	animation.Update(rowm2, deltatimem1, faceRightm2);
	bodym2.setTextureRect(animation.uvRect);
	bodym2.move(movement);
}

void monster2::Draw(sf::RenderWindow& window)
{
	window.draw(bodym2);

}
