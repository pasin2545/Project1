#pragma once
#include<SFML/Graphics.hpp>
#include"Collider.h"
#include"Animation.h"
class Chest
{
public:
	Chest(sf::Texture* texture);
	~Chest();
	void Update();
	void randitem();

	void Super();

	sf::Vector2f GetPosition() { return chest.getPosition(); }
	Collider GetCollider() { return Collider(chest); }

	bool chest_open = false, have_chest = false;
	bool superPower = false, use_superpower = false;


private:
	sf::RectangleShape chest;
	int random_item;
};

