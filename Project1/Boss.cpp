#include "Boss.h"
#include"player.h"

float clockbpn;
sf::Clock Bullpn;

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

sf::Texture* BULLETBOSS;
class BulletBoss {
public:
	sf::RectangleShape bulletboss1;

	void set(float x, float y)
	{
		bulletboss1.setTexture(BULLETBOSS);
		bulletboss1.setSize(sf::Vector2f(30.0f, 90.0f));
		bulletboss1.setPosition(x, y);
	}

	sf::Vector2f GetPosition() { return bulletboss1.getPosition(); }
	Collider GetCollider() { return Collider(bulletboss1); }
};

BulletBoss bulletboss1[3];


//***************************************************Update***************************************
void Boss::UpdateBoss1(float deltatimem1) {
	float x = bodyBoss.getPosition().x;
	float y = bodyBoss.getPosition().y;
	sf::Vector2f movement(0.0f, 0.0f);
	bodyBoss.setPosition(12200.0f, -1025.0f);
	clockbpn = Bullpn.getElapsedTime().asMilliseconds();

	/*printf("%f\n", clockbpn);
	printf("****************\n");*/

		shootR1(x, y);
		shotR1(x, y);
	
	rowm1 = 0;
		faceRightm1 = true;

	animation.Update(rowm1, deltatimem1, faceRightm1);
	bodyBoss.setTextureRect(animation.uvRect);
	bodyBoss.move(movement);
}
//**********************************************************************************************

void Boss :: shootR1(float x, float y) {
	end = clock();
	float dif = (float)(end - start) / CLOCKS_PER_SEC;
	if (clockbpn > 500.0f && dif > 0.5) {
		for (int i = 0; i < 3; i++) {
			if (chk_1[i] != 1) {
				bulletboss1[i].set(x - 20.0f, y + 400.0f);
				chk_1[i] = 1;
				start = clock();
				break;
			}
		}
		Bullpn.restart();
	}
}

void Boss::shotR1(float x, float y)
{
	for (int i = 0; i < 3; i++) {
		if (chk_1[i] == 1) {
			float speed = 2.0f;
			bulletboss1[i].bulletboss1.move(-speed, 0);
			if (bulletboss1[i].bulletboss1.getPosition().x < x - 820 || bulletboss1[i].bulletboss1.getPosition().x > x + 820) {
				chk_1[i] = 0;
			}
		}
	}
}

void Boss::DrawBR1(sf::RenderWindow& window) {
	for (int i = 0; i < 3; i++) {
		if (chk_1[i] == 1) {
			window.draw(bulletboss1[i].bulletboss1);
		}
	}
}

void Boss::Draw(sf::RenderWindow& window)
{
	window.draw(bodyBoss);
}
