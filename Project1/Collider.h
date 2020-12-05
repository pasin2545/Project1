#pragma once
#include<SFML/Graphics.hpp>
class monster1;
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

	bool CheckCollistionChest(Collider other);

	void Move(float dx, float dy) { body.move(dx, dy); }

	void SetPos(float dx, float dy) { body.setPosition(dx, dy); }

	bool CheckCollistion(Collider other, sf::Vector2f& direction, float push);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

	bool monster1_die = false;
	bool monster2_die = false;
	bool monster3_die = false;
	bool monster4_die = false;
	bool monster5_die = false;
	bool monster6_die = false;
	bool monster7_die = false;

private:
	sf::RectangleShape& body;
	monster1* Monster1;
};