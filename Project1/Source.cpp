#include<SFML/Graphics.hpp>
#include<iostream>
#include"Animation.h"
#include"player.h"
#include"monster1.h"
#include"Platform.h"

static const float VIEW_HEIGHT = 720.0f;
static const float VIEW_LENGTH = 1080.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_LENGTH * aspectRatio, VIEW_HEIGHT );
}

int main() {
	sf::RenderWindow window(sf::VideoMode(1080, 720), "2D Game", sf::Style::Close | sf::Style::Close);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_LENGTH, VIEW_HEIGHT));

	/*sf::RectangleShape collision(sf::Vector2f(100.0f, 100.0f));
	collision.setPosition({ 280.f, 335.f });
	collision.setFillColor(sf::Color::Red);

	sf::RectangleShape collision2(sf::Vector2f(100.0f, 100.0f));
	collision2.setPosition({ 850.f, 335.f });
	collision2.setFillColor(sf::Color::Red);*/

	sf::Texture playerTexture;
	playerTexture.loadFromFile("image.png");
	Player player(&playerTexture, sf::Vector2u(8, 6), 0.3f,50.0f);

	Platform platform1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
	Platform platform2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));

	/*sf::Texture monster1Texture;
	monster1Texture.loadFromFile("monster1.png");
	monster1 monster1(&monster1Texture, sf::Vector2u(8, 6), 0.3f, 50.0f);*/

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
		platform1.GetCollider().CheckCollistion(player.GetCollider(),0.0f);
		platform2.GetCollider().CheckCollistion(player.GetCollider(),1.0f);

		view.setCenter(player.GetPosition());
		window.clear();
		window.setView(view);
		//window.draw(collision);
		//window.draw(collision2);
		player.Draw(window);
		platform1.Draw(window);
		platform2.Draw(window);
		window.display();
	}
	return 0;
}

void monster1::Updatem1(float deltatimem1) {
	sf::Vector2f movement(0.0f, 0.0f);
	movement.x -= speedm1 * deltatimem1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		movement.x += speedm1 * deltatimem1;
	}

	if (movement.x == 0.0f) {
		rowm1 = 0;
	}
	else {
		rowm1 = 1;
		if (movement.x > 0.0f) {
			faceRightm1 = true;
		}
		else {
			faceRightm1 = false;
		}
	}

	animation.Update(rowm1, deltatimem1, faceRightm1);
	bodym1.setTextureRect(animation.uvRect);
	bodym1.move(movement);
}

void monster1::Draw(sf::RenderWindow& window)
{
	window.draw(bodym1);

}