#pragma once
#include<SFML/Graphics.hpp>
#include"Animation2.h"
#include"Collider.h"

class monster3
{
public:
	monster3(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~monster3();
	void Updatem3(float deltatimem1);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return bodym3.getPosition(); }
	Collider GetCollider() { return Collider(bodym3); }

private:
	sf::RectangleShape bodym3;
	Animation animation;
	unsigned int rowm3;
	float speedm3;
	bool faceRightm3;
	int chk = 0;
};

