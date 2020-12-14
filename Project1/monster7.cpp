#include "monster7.h"
monster7::monster7(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speedm7 = speed;
	rowm7 = 0;
	faceRightm7 = true;

	bodym7.setSize(sf::Vector2f(240.0f / 1.2, 160.0f / 1.2));
	bodym7.setPosition(8900.0f, -138.0+26.0f);
	bodym7.setTexture(texture);
}

monster7::~monster7() {}
void monster7::Updatem7(float deltatimem1) {
	float x = bodym7.getPosition().x;
	float y = bodym7.getPosition().y;
	sf::Vector2f movement(0.0f, 0.0f);
	if (chk == 0) {
		movement.x -= speedm7 * deltatimem1;
		if (x <= 8300.0f) {
			chk = 1;
		}
	}
	if (chk == 1) {
		movement.x += speedm7 * deltatimem1;
		if (x >= 9000.0f) {
			chk = 0;
		}
	}

	rowm7 = 0;
	if (chk == 0) {
		faceRightm7 = true;
	}
	else {
		faceRightm7 = false;
	}

	animation.Update(rowm7, deltatimem1, faceRightm7);
	bodym7.setTextureRect(animation.uvRect);
	bodym7.move(movement);
}

void monster7::Draw(sf::RenderWindow& window)
{
	window.draw(bodym7);

}

