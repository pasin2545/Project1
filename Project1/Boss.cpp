#include "Boss.h"
#include"player.h"

Boss::Boss(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speedm1 = speed;
	rowm1 = 0;
	faceRightm1 = true;

	bodyBoss.setSize(sf::Vector2f(500.0f, 500.0f));
	bodyBoss.setTexture(texture);
}

Boss::~Boss() {}


//***************************************************Update***************************************
void Boss::UpdateBoss1(float deltatimem1) {
	bodyBoss.setPosition(sf::Vector2f(12400.0f, -1025.0f));
	float x = bodyBoss.getPosition().x;
	float y = bodyBoss.getPosition().y;
	sf::Vector2f movement(0.0f, 0.0f);
	
	rowm1 = 0;
		faceRightm1 = true;

	animation.Update(rowm1, deltatimem1, faceRightm1);
	bodyBoss.setTextureRect(animation.uvRect);
}

void Boss::UpdateBoss2(float deltatime)
{
	bodyBoss.setPosition(sf::Vector2f(11400.0f, -1025.0f));
	float x = bodyBoss.getPosition().x;
	float y = bodyBoss.getPosition().y;
	sf::Vector2f movement(0.0f, 0.0f);

	rowm1 = 0;
	faceRightm1 = false;

	animation.Update(rowm1, deltatime, faceRightm1);
	bodyBoss.setTextureRect(animation.uvRect);
}
//**********************************************************************************************

void Boss::Draw(sf::RenderWindow& window)
{
	window.draw(bodyBoss);
}
