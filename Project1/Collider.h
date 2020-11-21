#pragma once
#include<SFML/Graphics.hpp>
class Collider
{
public:
	Collider(sf::RectangleShape& body);
	~Collider();

	bool CheckCollistionbull(Collider other, sf::Vector2f& direction, float push);

	bool CheckCollistionbullmon(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullmon2(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullmon3(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullmon4(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullmon5(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullmon6(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullmon7(Collider other, sf::Vector2f& direction);

	void Move(float dx, float dy) { body.move(dx, dy); }

	void SetPos(float dx, float dy) { body.setPosition(dx, dy); }

	bool CheckCollistion(Collider other, sf::Vector2f& direction, float push);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

private:
	sf::RectangleShape& body;
};