#pragma once
#include<SFML/Graphics.hpp>
class Background
{
public:

	Background(sf::Texture* texture);
	void Draw(sf::RenderWindow& window);
	sf::Vector2f GetPosition() { return back.getPosition(); }

private:
	sf::RectangleShape back;
};

