#include "monster1.h"
monster1::monster1(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speedm1 = speed;
	rowm1 = 0;
	faceRightm1 = true;

	bodym1.setSize(sf::Vector2f(140.0f, 60.0f));
	bodym1.setPosition(1100.0f, -40.0f);
	bodym1.setTexture(texture);
}

monster1::~monster1() {}
void monster1::Updatem1(float deltatimem1) {
	float x = bodym1.getPosition().x;
	float y = bodym1.getPosition().y;
	sf::Vector2f movement(0.0f, 0.0f);
	if (chk == 0) {
		movement.x -= speedm1 * deltatimem1;
		if (x <= 700.0f) {
			chk = 1;
		}
	}
	if (chk == 1) {
		movement.x += speedm1 * deltatimem1;
		if (x >= 1200.0f) {
			chk = 0;
		}
	}

	rowm1 = 0;
	if (chk == 0) {
		faceRightm1 = true;
	}
	else {
		faceRightm1 = false;
	}

	animation.Update(rowm1, deltatimem1, faceRightm1);
	bodym1.setTextureRect(animation.uvRect);
	bodym1.move(movement);
}

void monster1::Draw(sf::RenderWindow& window)
{
	window.draw(bodym1);

}