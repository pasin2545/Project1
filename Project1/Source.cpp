#include<SFML/Graphics.hpp>
#include<iostream>
#include"Animation.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1080, 720), "2D Game", sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(290.0f, 250.0f));
	player.setPosition(206.0f, 206.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Idle.png");
	player.setTexture(&playerTexture);

	/*sf::Vector2u textureSize = playerTexture.getSize();
	textureSize.x /= 6;
	textureSize.y /= 1;

	player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 0, textureSize.x, textureSize.y));*/
	Animation animation(&playerTexture, sf::Vector2u(6, 1), 0.3f);

	float deltaTime = 0.0f;
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
			/*case sf::Event::Resized:
				//printf_s("New window width : %i New window height : %i \n,evnt.size.width,evnt.size.height");
				break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128) {
					printf("%c", evnt.text.unicode);
				}*/
			}
		}
		animation.Update(0, deltaTime);
		player.setTextureRect(animation.uvRect);
		//keyboard
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			player.move(-0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			player.move(0.0f, -0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			player.move(0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			player.move(0.0f,0.1f);
		}
		//Mouse
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		}

		window.clear();
		window.draw(player);
		window.display();
	}
	return 0;
}