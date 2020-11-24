#include "Boss.h"
#include"player.h"
Boss::Boss(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speedm1 = speed;
	rowm1 = 0;
	faceRightm1 = true;

	bodyBoss.setSize(sf::Vector2f(470.0f, 470.0f));
	bodyBoss.setTexture(texture);
}

Boss::~Boss() {}
void Boss::UpdateBoss1(float deltatimem1) {
	float x = bodyBoss.getPosition().x;
	float y = bodyBoss.getPosition().y;
	sf::Vector2f movement(0.0f, 0.0f);
	bodyBoss.setPosition(12200.0f, -1025.0f);

	
	rowm1 = 0;
	if (chk == 0) {
		faceRightm1 = true;
	}
	else {
		faceRightm1 = false;
	}

	animation.Update(rowm1, deltatimem1, faceRightm1);
	bodyBoss.setTextureRect(animation.uvRect);
	bodyBoss.move(movement);
}

void Boss::Draw(sf::RenderWindow& window)
{
	window.draw(bodyBoss);

}
