#include<SFML/Graphics.hpp>
#include<iostream>
#include"Animation.h"
#include"player.h"
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

	//sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("image.png");
	sf::Texture bgTexture;
	bgTexture.loadFromFile("BackGround.png");
	Player player(&playerTexture,&bgTexture, sf::Vector2u(8, 6), 0.3f,50.0f);

	//***********************Box*************************************************************
	//Platform platform1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));
	Platform platform2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
	//***************************************************************************************

	/*sf::Texture monster1Texture;
	monster1Texture.loadFromFile("monster1.png");
	monster1 monster1(&monster1Texture, sf::Vector2u(8, 6), 0.3f, 50.0f);*/

	//***********************Background*******************************
	//****************************************************************

	float deltaTime = 1.0f;
	sf::Clock clock;

	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();
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
		player.Update(1.0);
		//platform1.GetCollider().CheckCollistion(player.GetCollider(),0.0f);
		//platform2.GetCollider().CheckCollistion(player.GetCollider(),1.0f);
		view.setCenter(player.GetPosition());
		window.clear();
		window.setView(view);
		player.Draw(window);
		//platform1.Draw(window);
		//platform2.Draw(window);
		
		window.display();
	}
	return 0;
}