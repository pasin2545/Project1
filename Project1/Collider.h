#pragma once
#include<SFML/Graphics.hpp>
class monster1;
class Collider
{
public:
	
	Collider(sf::RectangleShape& body);
	~Collider();

	bool CheckCollistionbull(Collider other, sf::Vector2f& direction, float push);
	bool CheckCollistionBossbull1(Collider other, sf::Vector2f& direction, float push);
	bool CheckCollistionBossbull2(Collider other, sf::Vector2f& direction, float push);
	bool CheckCollistionBossbull3(Collider other, sf::Vector2f& direction, float push);
	bool CheckCollistionBossbull4(Collider other, sf::Vector2f& direction, float push);
	bool CheckCollistionBosssupbull1(Collider other, sf::Vector2f& direction, float push);
	bool CheckCollistionBosssupbull2(Collider other, sf::Vector2f& direction, float push);
	bool CheckCollistionBosssupbull3(Collider other, sf::Vector2f& direction, float push);
	bool CheckCollistionBosssupbull4(Collider other, sf::Vector2f& direction, float push);
	bool CheckCollistionBossplayAct1(Collider other, sf::Vector2f& direction);
	bool CheckCollistionBossplayAct3(Collider other, sf::Vector2f& direction);
	bool CheckCollistionBossplayAct2(Collider other, sf::Vector2f& direction);
	bool CheckCollistionBossplayAct4(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbulletBossplayer2(Collider other, sf::Vector2f& direction, float push);
	bool CheckCollistionbulletBossplayer1(Collider other, sf::Vector2f& direction, float push);

	bool CheckCollistionbullmon(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullmon2(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullmon3(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullmon4(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullmon5(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullmon6(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullmon7(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullBoss1(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullBoss2(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullBoss3(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullBoss4(Collider other, sf::Vector2f& direction);
	bool CheckCollistionmonplaydog(Collider other, sf::Vector2f& direction);
	bool CheckCollistionmonplayhorse(Collider other, sf::Vector2f& direction);

	bool CheckCollistionsupbullmon(Collider other, sf::Vector2f& direction);
	bool CheckCollistionsupbullmon2(Collider other, sf::Vector2f& direction);
	bool CheckCollistionsupbullmon3(Collider other, sf::Vector2f& direction);
	bool CheckCollistionsupbullmon4(Collider other, sf::Vector2f& direction);
	bool CheckCollistionsupbullmon5(Collider other, sf::Vector2f& direction);
	bool CheckCollistionsupbullmon6(Collider other, sf::Vector2f& direction);
	bool CheckCollistionsupbullmon7(Collider other, sf::Vector2f& direction);
	bool CheckCollistionsupbullBoss1(Collider other, sf::Vector2f& direction);
	bool CheckCollistionsupbullBoss2(Collider other, sf::Vector2f& direction);
	bool CheckCollistionsupbullBoss3(Collider other, sf::Vector2f& direction);
	bool CheckCollistionsupbullBoss4(Collider other, sf::Vector2f& direction);
	bool CheckCollistionbullhouse(Collider other, sf::Vector2f& direction, float push);

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
	sf::Vector2f GetFullSize() { return body.getSize() / 1.5f; }

private:
	sf::RectangleShape& body;
};