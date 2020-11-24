#pragma once
#include<SFML/Graphics.hpp>
#include"Collider.h"
#include"Animation.h"
class Boss
{
public:
	Boss(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Boss();
	void UpdateBoss1(float deltatimem1);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return bodyBoss.getPosition(); }
	Collider GetCollider() { return Collider(bodyBoss); }

private:
	sf::RectangleShape bodyBoss;
	Animation animation;
	unsigned int rowm1;
	float speedm1;
	bool faceRightm1;
	int chk = 0;
};

