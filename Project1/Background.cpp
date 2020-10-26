#include "Background.h"

Background::Background(sf::Texture* texture)
{
	back.setSize(sf::Vector2f(1536.0f, 768.0f));
	back.setOrigin(back.getSize() / 3.0f);
	back.setPosition(0.0f, 0.0f);
	back.setTexture(texture);
}
void Background::Draw(sf::RenderWindow& window)
{
	window.draw(back);

}
