#include "player.h"
#include "Animation.h"
Player::Player(sf::Texture* texture, sf::Texture* bgtexture, sf::Vector2u imageCount, float switchTime, float speed):
	animation(texture,imageCount,switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(290.0f, 230.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(206.0f, 206.0f);
	body.setTexture(texture);
	bg.setSize(sf::Vector2f(1536.0f, 768.0f));
	bg.setOrigin(bg.getSize() / 2.0f);
	bg.setPosition(206.0f, 206.0f);
	bg.setTexture(bgtexture);
}

Player::~Player()
{
}

void Player::Update(float deltatme)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		movement.x -= speed * deltatme;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		movement.x += speed * deltatme;
	}

	if (movement.x == 0.0f) {
		row = 0;
	}
	else {
		row = 1;
		if (movement.x > 0.0f) {
			faceRight = true;
		}
		else {
			faceRight = false;
		}
	}

	animation.Update(row, deltatme, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
	bg.move(movement);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(bg);
	window.draw(body);
}
