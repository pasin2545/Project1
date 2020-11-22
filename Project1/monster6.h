#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include"Collider.h"

class monster6
{
public:
	monster6(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~monster6();
	void Updatem6(float deltatimem1);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return bodym6.getPosition(); }
	Collider GetCollider() { return Collider(bodym6); }

private:
	sf::RectangleShape bodym6;
	Animation animation;
	unsigned int rowm6;
	float speedm6;
	bool faceRightm6;
	int chk = 0;
};

