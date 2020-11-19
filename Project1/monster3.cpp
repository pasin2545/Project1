#include "monster3.h"
monster3::monster3(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speedm3 = speed;
	rowm3 = 0;
	faceRightm3 = true;

	bodym3.setSize(sf::Vector2f(220.0f, 300.0f));
	bodym3.setPosition(3800.0f, -300.0f);
	bodym3.setTexture(texture);
}

monster3::~monster3() {}
void monster3::Updatem3(float deltatimem1) {
	float x = bodym3.getPosition().x;
	float y = bodym3.getPosition().y;
	sf::Vector2f movement(0.0f, 0.0f);
	if (chk == 0) {
		movement.x -= speedm3 * deltatimem1;
		if (x <= 3500.0f) {
			chk = 1;
		}
	}
	if (chk == 1) {
		movement.x += speedm3 * deltatimem1;
		if (x >= 4200.0f) {
			chk = 0;
		}
	}

	rowm3 = 0;
	if (chk == 0) {
		faceRightm3 = true;
	}
	else {
		faceRightm3 = false;
	}

	animation.Update(rowm3, deltatimem1, faceRightm3);
	bodym3.setTextureRect(animation.uvRect);
	bodym3.move(movement);
}

void monster3::Draw(sf::RenderWindow& window)
{
	window.draw(bodym3);

}
