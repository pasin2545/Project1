#include<SFML/Graphics.hpp>
#include<iostream>
#include"Animation.h"
#include"player.h"
#include<vector>
#include"monster1.h"
#include"Platform.h"
#include"Collider.h"

static const float VIEW_HEIGHT = 768.0f;
static const float VIEW_LENGTH = 1536.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_LENGTH * aspectRatio, VIEW_HEIGHT );
}

int main() {
	sf::RenderWindow window(sf::VideoMode(1536, 768), "2D Game", sf::Style::Close | sf::Style::Close);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_LENGTH, VIEW_HEIGHT));



	sf::Texture playerTexture;
	playerTexture.loadFromFile("image.png");
	Player player(&playerTexture, sf::Vector2u(8, 6), 0.3f, 250.0f, 200.0f);

	std::vector<Platform> platforms;

	//***********************Box*************************************************************
	//platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, -250.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 80.0f)));
	//***************************************************************************************

	/*sf::Texture monster1Texture;
	monster1Texture.loadFromFile("monster1.png");
	monster1 monster1(&monster1Texture, sf::Vector2u(8, 6), 0.3f, 50.0f);*/

	//***********************Background*******************************
	sf::RectangleShape bg(sf::Vector2f(1536.0f, 768.0f));
	sf::Texture bgTexture;
	bgTexture.loadFromFile("BackGround.png");
	bg.setTexture(&bgTexture);
	//****************************************************************

	//***********************Floor************************************
	platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(300.0f, 200.0f)));
	//****************************************************************

	float deltaTime = 1.0f;
	sf::Clock clock;

	while (window.isOpen()) {
		sf::Vector2f pos = player.GetPosition();
		printf("%f %f\n", pos.x, pos.y);
		bg.setPosition(pos.x-768, pos.y-384);
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			}
		}
		
		player.Update(deltaTime);

		sf::Vector2f direction;

		for (Platform& platform : platforms) 
			if (platform.GetCollider().CheckCollistion(player.GetCollider(), direction, 1.0f))
				player.OnCollistion(direction);
		
		view.setCenter(player.GetPosition());
		window.clear();
		window.draw(bg);
		window.setView(view);
		player.Draw(window);

		for (Platform& platform : platforms)
			platform.Draw(window);
		
		window.display();
	}
	return 0;
}