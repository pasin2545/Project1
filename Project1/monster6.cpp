#include"monster6.h"
monster6::monster6(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speedm6 = speed;
	rowm6 = 0;
	faceRightm6 = true;

	bodym6.setSize(sf::Vector2f(240.0f / 1.2, 160.0f / 1.2));
	bodym6.setPosition(8100.0f, -138.0+26.0f);
	bodym6.setTexture(texture);
}

monster6::~monster6() {}
void monster6::Updatem6(float deltatimem1) {
	float x = bodym6.getPosition().x;
	float y = bodym6.getPosition().y;
	sf::Vector2f movement(0.0f, 0.0f);
	if (chk == 1) {
		movement.x -= speedm6 * deltatimem1;
		if (x <= 7800.0f) {
			chk = 0;
		}
	}
	if (chk == 0) {
		movement.x += speedm6 * deltatimem1;
		if (x >= 8600.0f) {
			chk = 1;
		}
	}

	rowm6 = 0;
	if (chk == 1) {
		faceRightm6 = true;
	}
	else {
		faceRightm6 = false;
	}

	animation.Update(rowm6, deltatimem1, faceRightm6);
	bodym6.setTextureRect(animation.uvRect);
	bodym6.move(movement);
}

void monster6::Draw(sf::RenderWindow& window)
{
	window.draw(bodym6);

}

