#include "monster1.h"
monster1::monster1(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speedm1 = speed;
	rowm1 = 0;
	faceRightm1 = true;

	bodym1.setSize(sf::Vector2f(290.0f, 250.0f));
	bodym1.setPosition(206.0f, 206.0f);
	bodym1.setTexture(texture);
}
monster1::~monster1(){}
/*void monster1::Updatem1(float deltatimem1) {
	sf::Vector2f movement(0.0f, 0.0f);
		movement.x -= speedm1 * deltatimem1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		movement.x += speedm1 * deltatimem1;
	}

	if (movement.x == 0.0f) {
		rowm1 = 0;
	}
	else {
		rowm1 = 1;
		if (movement.x > 0.0f) {
			faceRightm1 = true;
		}
		else {
			faceRightm1 = false;
		}
	}

	animation.Update(rowm1, deltatimem1, faceRightm1);
	bodym1.setTextureRect(animation.uvRect);
	bodym1.move(movement);
}

void monster1::Draw(sf::RenderWindow& window)
{
	window.draw(bodym1);

}*/
