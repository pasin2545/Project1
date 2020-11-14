#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include"Collider.h"
#include"Bullet.h"
class monster1
{
public:
	monster1(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~monster1();
	void Updatem1(float deltatimem1);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return bodym1.getPosition(); }
	Collider GetCollider() { return Collider(bodym1); }

	void checkColl(Bullet bullet) {
		if (bullet.getRight() > bodym1.getPosition().x &&  
			bullet.getTop()< bodym1.getPosition().y + bodym1.getSize().y
			&& bullet.getBottom() > bodym1.getPosition().y) {
			bodym1.setPosition(800.0f, 1000.0f);
		}
	}

private:
	sf::RectangleShape bodym1;
	Animation animation;
	unsigned int rowm1;
	float speedm1;
	bool faceRightm1;
};

