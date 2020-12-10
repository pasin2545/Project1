#pragma once
#include<SFML/Graphics.hpp>
class monster1;
class Collider
{
public:
	
	Collider(sf::RectangleShape& body);
	~Collider();

	bool CheckCollistionbull(Collider other, sf::Vector2f& direction, float push);
	bool CheckCollistionBossbull(Collider other, sf::Vector2f& direction, float push);
	bool CheckCollistionBossplay(Collider other, sf::Vector2f& direction);

	bool CheckCollistionbullmon(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullmon2(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullmon3(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullmon4(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullmon5(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullmon6(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullmon7(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullBoss(Collider other, sf::Vector2f& direction);
	bool CheckCollistionmonplay(Collider other, sf::Vector2f& direction);

	bool CheckCollistionsupbullmon(Collider other, sf::Vector2f& direction);
	bool CheckCollistionsupbullmon2(Collider other, sf::Vector2f& direction);
	bool CheckCollistionsupbullmon3(Collider other, sf::Vector2f& direction);
	bool CheckCollistionsupbullmon4(Collider other, sf::Vector2f& direction);
	bool CheckCollistionsupbullmon5(Collider other, sf::Vector2f& direction);
	bool CheckCollistionsupbullmon6(Collider other, sf::Vector2f& direction);
	bool CheckCollistionsupbullmon7(Collider other, sf::Vector2f& direction);
	bool CheckCollistionsupbullBoss(Collider other, sf::Vector2f& direction);

	bool CheckCollistionChest(Collider other);

	void Move(float dx, float dy) { body.move(dx, dy); }

	void SetPos(float dx, float dy) { body.setPosition(dx, dy); }

	bool CheckCollistion(Collider other, sf::Vector2f& direction, float push);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }
	sf::Vector2f GetThreeSize() { return body.getSize() / 5.5f; }
	sf::Vector2f GetFourSize() { return body.getSize() / 3.0f; }
	sf::Vector2f GetThreePointSize() { return body.getSize() / 3.5f; }
	sf::Vector2f GetHalfPointSize() { return body.getSize() / 2.5f; }

private:
	sf::RectangleShape& body;
};