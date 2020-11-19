#pragma once
#include"SFML/Graphics.hpp"
#include"Collider.h"
class Bullet2
{
public:
	Bullet2(sf::Texture* texture) {
		bullet2.setSize(sf::Vector2f(100.0f, 100.0f));
		bullet2.setTexture(texture);
		bullet2.setOrigin(sf::Vector2f(100.0f, 100.0f) / 2.0f);
	}

	Collider GetCollider() { return Collider(bullet2); }

	void fire(int speed) {
		bullet2.move(speed, 0);
	}
	void draw(sf::RenderWindow& window) {
		window.draw(bullet2);
	}

	void setPos(sf::Vector2f newPos) {
		bullet2.setPosition(newPos);
	}
private:
	sf::RectangleShape bullet2;
};