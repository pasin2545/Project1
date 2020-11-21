#pragma once
#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include"Collider.h"
#include"Bullet.h"
#include"Bullet2.h"
class monster5
{
public:
	monster5(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~monster5();
	void Updatem5(float deltatimem1);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return bodym5.getPosition(); }
	Collider GetCollider() { return Collider(bodym5); }

private:
	sf::RectangleShape bodym5;
	Animation animation;
	unsigned int rowm5;
	float speedm5;
	bool faceRightm5;
	int chk = 0;
};



