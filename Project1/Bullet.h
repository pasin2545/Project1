#pragma once
#include<SFML/Graphics.hpp>
#include"Collider.h"
class Bullet
{
public:
	Bullet(sf::Texture* texture) {
		bullet.setSize(sf::Vector2f(100.0f, 100.0f));
		bullet.setTexture(texture);
		bullet.setOrigin(sf::Vector2f(100.0f, 100.0f) / 2.0f);
	}

	sf::Vector2f GetPosition() { return bullet.getPosition(); }
	Collider GetCollider() { return Collider(bullet); }

	void fire(int speed) {
		bullet.move(speed, 0);
	}

	int getRight() {
		return bullet.getPosition().x + bullet.getSize().x;
	}
	int getLeft() {
		return bullet.getPosition().x;
	}
	int getTop() {
		return bullet.getPosition().y;
	}
	int getBottom() {
		return bullet.getPosition().y + bullet.getSize().y;
	}
	void draw(sf::RenderWindow& window) {
		window.draw(bullet);
	}

	void setPos(sf::Vector2f newPos) {
		bullet.setPosition(newPos);
	}
private:
	sf::RectangleShape bullet;
};
