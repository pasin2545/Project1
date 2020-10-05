#include<SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(512, 512), "2D Game", sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setFillColor(sf::Color::Blue);
	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				printf_s("New window width : %i New window height : %i \n,evnt.size.width,evnt.size.height");
				break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128) {
					printf("%c", evnt.text.unicode);
				}
			}
		}
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