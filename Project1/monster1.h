#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
class monster1
{
public:
	monster1(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~monster1();
	void Updatem1(float deltatimem1);
	void Draw(sf::RenderWindow& window);

private:
	sf::RectangleShape bodym1;
	Animation animation;
	unsigned int rowm1;
	float speedm1;
	bool faceRightm1;
};

