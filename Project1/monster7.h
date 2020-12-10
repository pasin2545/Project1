#pragma once
#include<SFML/Graphics.hpp>
#include"Animation2.h"
#include"Collider.h"

class monster7
{
public:
	monster7(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~monster7();
	void Updatem7(float deltatimem1);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return bodym7.getPosition(); }
	Collider GetCollider() { return Collider(bodym7); }

private:
	sf::RectangleShape bodym7;
	Animation animation;
	unsigned int rowm7;
	float speedm7;
	bool faceRightm7;
	int chk = 0;
};


