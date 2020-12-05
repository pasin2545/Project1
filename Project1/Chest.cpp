#include "Chest.h"
#include<stdlib.h>
#include<time.h>

Chest::Chest(sf::Texture* texture)
{
	chest.setTexture(texture);
	chest.setSize(sf::Vector2f(70.0f, 70.0f));
}

Chest::~Chest()
{
}

void Chest::Update()
{
	srand(time(NULL));
	have_chest = rand() % 2;
}

void Chest::randitem() 
{
	srand(time(NULL));
	chest_open = true;
	random_item = rand() % 5;
}

void Chest::Super() 
{
	superPower == true;
}
