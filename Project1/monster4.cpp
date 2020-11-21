#include "monster4.h"
monster4::monster4(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speedm4 = speed;
	rowm4 = 0;
	faceRightm4 = true;

	bodym4.setSize(sf::Vector2f(140.0f, 60.0f));
	bodym4.setPosition(6400.0f, -40.0f);
	bodym4.setTexture(texture);
}

monster4::~monster4() {}
void monster4::Updatem4(float deltatimem1) {
	float x = bodym4.getPosition().x;
	float y = bodym4.getPosition().y;
	sf::Vector2f movement(0.0f, 0.0f);
	if (chk == 0) {
		movement.x -= speedm4 * deltatimem1;
		if (x <= 6200.0f) {
			chk = 1;
		}
	}
	if (chk == 1) {
		movement.x += speedm4 * deltatimem1;
		if (x >= 6600.0f) {
			chk = 0;
		}
	}

	rowm4 = 0;
	if (chk == 0) {
		faceRightm4 = true;
	}
	else {
		faceRightm4 = false;
	}

	animation.Update(rowm4, deltatimem1, faceRightm4);
	bodym4.setTextureRect(animation.uvRect);
	bodym4.move(movement);
}

void monster4::Draw(sf::RenderWindow& window)
{
	window.draw(bodym4);

}

