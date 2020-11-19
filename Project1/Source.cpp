#include<SFML/Graphics.hpp>
#include<iostream>
#include"Animation.h"
#include"player.h"
#include<vector>
#include"monster1.h"
#include"Platform.h"
#include"Collider.h"
#include"Bullet.h"
#include"Bullet2.h"

static const float VIEW_HEIGHT = 768.0f;
static const float VIEW_LENGTH = 1536.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_LENGTH * aspectRatio, VIEW_HEIGHT);
}

int main() {
	sf::RenderWindow window(sf::VideoMode(1536, 768), "2D Game", sf::Style::Close | sf::Style::Close);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_LENGTH, VIEW_HEIGHT));

	sf::Texture BulletTexture;
	std::vector<Bullet> bulletVec1;
	std::vector<Bullet2> bulletVec2;
	bool isFiring = false;
	Bullet newBullet1(&BulletTexture);
	Bullet2 newBullet2(&BulletTexture);

	sf::Texture playerTexture;
	playerTexture.loadFromFile("image.png");
	Player player(&playerTexture, sf::Vector2u(8, 6), 0.2f, 250.0f, 200.0f);

	std::vector<Platform> platforms;

	sf::Clock BULLET;
	float bull;

	//***********************Box*************************************************************
	platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 350.0f), sf::Vector2f(600.0f, 0.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 350.0f), sf::Vector2f(1450.0f, 0.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(200.0f, 350.0f), sf::Vector2f(6850.0f, 0.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(300.0f, 400.0f), sf::Vector2f(7400.0f, -175.0f)));
	//***************************************************************************************


	//*********************************Brick*************************************************
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(3050.0f, 0.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(3350.0f, 0.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(3650.0f, 0.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(4200.0f, 0.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5300.0f, -25.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5400.0f, -25.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5400.0f, -125.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5500.0f, -25.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5500.0f, -125.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5500.0f, -225.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6000.0f, -225.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6000.0f, -125.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6000.0f, -25.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6100.0f, -125.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6100.0f, -25.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6200.0f, -25.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(8500.0f, -180.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(8800.0f, -180.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(9100.0f, -180.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(8800.0f, -310.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(9700.0f, -25.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(10000.0f, -125.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(10300.0f, -225.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(10700.0f, -350.0f)));
	//***************************************************************************************


	//*********************************Floor*************************************************
	platforms.push_back(Platform(nullptr, sf::Vector2f(2500.0f, 350.0f), sf::Vector2f(300.0f, 200.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 350.0f), sf::Vector2f(2350.0f, 200.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 350.0f), sf::Vector2f(5050.0f, 200.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 350.0f), sf::Vector2f(6450.0f, 200.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(2200.0f, 350.0f), sf::Vector2f(8350.0f, 200.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(2000.0f, 350.0f), sf::Vector2f(12000.0f, -375.0f)));
	//***************************************************************************************

	sf::Texture monster1Texture;
	monster1Texture.loadFromFile("monster1.png");
	monster1 monster1(&monster1Texture, sf::Vector2u(5, 1), 0.3f, 200.0f);

	//***********************Background*******************************
	sf::RectangleShape bg(sf::Vector2f(1536.0f, 768.0f));
	sf::Texture bgTexture;
	bgTexture.loadFromFile("BackGround.png");
	bg.setTexture(&bgTexture);
	//****************************************************************

	float deltaTime = 1.0f;
	sf::Clock clock;

	while (window.isOpen()) {
		sf::Vector2f pos = player.GetPosition();
		//printf("%f %f\n", pos.x, pos.y);
		bull = BULLET.getElapsedTime().asMilliseconds();
		bg.setPosition(pos.x - 768, pos.y - 384);
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
		monster1.Updatem1(deltaTime);
		sf::Vector2f direction;


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && bull > 250) {
			isFiring = true;
			BULLET.restart();
		}
		for (Platform& platform : platforms) {
			if (platform.GetCollider().CheckCollistion(player.GetCollider(), direction, 1.0f)) {
				player.OnCollistion(direction);
			}
			platform.GetCollider().CheckCollistionmon(monster1.GetCollider(), direction, 1.0f);

			for (int i = 0; i < bulletVec1.size(); i++) {
				for (Bullet& Bu : bulletVec1) {
					platform.GetCollider().CheckCollistionbull(Bu.GetCollider(), direction, 1.0f);
				}
			}
			for (int i = 0; i < bulletVec2.size(); i++) {
				for (Bullet2& Bu2 : bulletVec2) {
					platform.GetCollider().CheckCollistionbull(Bu2.GetCollider(), direction, 1.0f);
				}
			}

		}

		view.setCenter(player.GetPosition());
		window.clear();
		window.draw(bg);
		window.setView(view);
		player.Draw(window);
		monster1.Draw(window);
		//*********************************Draw Bullet*************************************
		if (isFiring == true) {
			if (player.faceRight == true) {
				newBullet1.setPos(sf::Vector2f(player.GetPosition().x + 100, player.GetPosition().y));
				bulletVec1.push_back(newBullet1);
				isFiring = false;
			}
			if (player.faceRight == false) {
				newBullet2.setPos(sf::Vector2f(player.GetPosition().x - 100, player.GetPosition().y));
				bulletVec2.push_back(newBullet2);
				isFiring = false;
			}
		}
		for (int i = 0; i < bulletVec1.size(); i++) {
			bulletVec1[i].draw(window);
			bulletVec1[i].fire(3);
		}
		for (int i = 0; i < bulletVec1.size(); i++) {
			monster1.checkColl(bulletVec1[i]);
		}
		for (int i = 0; i < bulletVec2.size(); i++) {
			bulletVec2[i].draw(window);
			bulletVec2[i].fire(-3);
		}
		for (int i = 0; i < bulletVec2.size(); i++) {
			monster1.checkColl(bulletVec2[i]);
		}
		//********************************************************************************


		for (Platform& platform : platforms)
			platform.Draw(window);

		window.display();
	}
	return 0;
}