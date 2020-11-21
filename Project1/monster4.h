#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include"Collider.h"
#include"Bullet.h"
#include"Bullet2.h"
class monster4
{
public:
	monster4(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~monster4();
	void Updatem4(float deltatimem1);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return bodym4.getPosition(); }
	Collider GetCollider() { return Collider(bodym4); }

private:
	sf::RectangleShape bodym4;
	Animation animation;
	unsigned int rowm4;
	float speedm4;
	bool faceRightm4;
	int chk = 0;
};

