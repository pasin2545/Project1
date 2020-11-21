#include "monster5.h"
monster5::monster5(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speedm5 = speed;
	rowm5 = 0;
	faceRightm5 = true;

	bodym5.setSize(sf::Vector2f(240.0f, 160.0f));
	bodym5.setPosition(7900.0f, -138.0f);
	bodym5.setTexture(texture);
}

monster5::~monster5() {}
void monster5::Updatem5(float deltatimem1) {
	float x = bodym5.getPosition().x;
	float y = bodym5.getPosition().y;
	sf::Vector2f movement(0.0f, 0.0f);
	if (chk == 0) {
		movement.x -= speedm5 * deltatimem1;
		if (x <= 7550.0f) {
			chk = 1;
		}
	}
	if (chk == 1) {
		movement.x += speedm5 * deltatimem1;
		if (x >= 9200.0f) {
			chk = 0;
		}
	}

	rowm5 = 0;
	if (chk == 0) {
		faceRightm5 = true;
	}
	else {
		faceRightm5 = false;
	}

	animation.Update(rowm5, deltatimem1, faceRightm5);
	bodym5.setTextureRect(animation.uvRect);
	bodym5.move(movement);
}

void monster5::Draw(sf::RenderWindow& window)
{
	window.draw(bodym5);

}

