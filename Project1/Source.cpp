#include<SFML/Graphics.hpp>
#include<iostream>
#include"Animation.h"
#include"player.h"
#include<vector>
#include"monster1.h"
#include"monster2.h"
#include"monster3.h"
#include"monster4.h"
#include"monster5.h"
#include"monster6.h"
#include"monster7.h"
#include"Platform.h"
#include"Collider.h"
#include"Boss.h"
#include"Chest.h"


int chk_1[6] = { 0 };
int pst = 0;
int pst1[6];

int chksup_1[1] = { 0 };
int pst1sup[1];

clock_t start=-0.2,end = 0;

static const float VIEW_HEIGHT = 768.0f;
static const float VIEW_LENGTH = 1536.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_LENGTH * aspectRatio, VIEW_HEIGHT);
}

sf::Texture ChestTexture;
Chest chest(&ChestTexture);

void shoot(float, float);
void shot(float,float);
void shootsuper(float, float);
void shotsuper(float, float);

sf::Texture* BULLET;
sf::Texture* superBULLET;
	class Bulleted {
	public:
		sf:: RectangleShape bullet;

		void set(float x, float y)
		{
				bullet.setTexture(BULLET);
				bullet.setSize(sf::Vector2f(30.0f, 30.0f));
				bullet.setPosition(x, y);
		}

		sf::Vector2f GetPosition() { return bullet.getPosition(); }
		Collider GetCollider() { return Collider(bullet); }

	};

	class superBulleted {
	public:
		sf::RectangleShape superbullet;

		void set(float x, float y)
		{
			superbullet.setTexture(superBULLET);
			superbullet.setSize(sf::Vector2f(50.0f, 50.0f));
			superbullet.setPosition(x, y);
		}

		sf::Vector2f GetPosition() { return superbullet.getPosition(); }
		Collider GetCollider() { return Collider(superbullet); }

	};



	superBulleted superbullet[1];
	Bulleted bullet[6];

int main() {
	sf::RenderWindow window(sf::VideoMode(1536, 768), "2D Game", sf::Style::Close | sf::Style::Close);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_LENGTH, VIEW_HEIGHT));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("image.png");
	Player player(&playerTexture, sf::Vector2u(8, 6), 0.2f, 250.0f, 200.0f);

	std::vector<Platform> platforms;


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
	
	//**************************************Tower**********************************************************
	platforms.push_back(Platform(nullptr, sf::Vector2f(300.0f, 1000.0f), sf::Vector2f(11200.0f, -725.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(300.0f, 1000.0f), sf::Vector2f(12850.0f, -725.0f)));
	//*****************************************************************************************************

	sf::Texture monster1Texture;
	monster1Texture.loadFromFile("monster1.png");
	monster1 monster1(&monster1Texture, sf::Vector2u(5, 1), 0.3f, 200.0f);
	sf::Texture monster2Texture;
	monster2Texture.loadFromFile("monster2.png");
	monster2 monster2(&monster2Texture, sf::Vector2u(4, 1), 0.3f, 200.0f);
	sf::Texture monster3Texture;
	monster3Texture.loadFromFile("monster3.png");
	monster3 monster3(&monster3Texture, sf::Vector2u(7, 1), 0.3f, 200.0f);
	monster4 monster4(&monster1Texture, sf::Vector2u(5, 1), 0.3f, 200.0f);
	monster5 monster5(&monster2Texture, sf::Vector2u(4, 1), 0.3f, 200.0f);
	monster6 monster6(&monster2Texture, sf::Vector2u(4, 1), 0.3f, 200.0f);
	monster7 monster7(&monster2Texture, sf::Vector2u(4, 1), 0.3f, 200.0f);
	sf::Texture BossTexture;
	BossTexture.loadFromFile("Boss.png");
	Boss Boss(&BossTexture, sf::Vector2u(6, 1), 0.3f, 200.0f);

	//***********************Background*******************************
	sf::RectangleShape bg(sf::Vector2f(1536.0f, 768.0f));
	sf::Texture bgTexture;
	bgTexture.loadFromFile("BackGround.png");
	bg.setTexture(&bgTexture);
	//****************************************************************

	float deltaTime = 1.0f;
	sf::Clock clock;
	float bosshit;
	sf::Clock bossht;

	while (window.isOpen()) {
		sf::Vector2f pos = player.GetPosition();
		//printf("%f\n", pos.x);

		if (player.faceRight == false) {
			pst = 1;
		}
		if (player.faceRight == true) {
			pst = 2;
		}

		shoot(pos.x, pos.y);
		shot(pos.x, pos.y);
		shootsuper(pos.x, pos.y);
		shotsuper(pos.x, pos.y);
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
		monster2.Updatem2(deltaTime);
		monster3.Updatem3(deltaTime);
		monster4.Updatem4(deltaTime);
		monster5.Updatem5(deltaTime);
		monster6.Updatem6(deltaTime);
		monster7.Updatem7(deltaTime);
		Boss.UpdateBoss1(deltaTime);
		sf::Vector2f direction;

		int v = 0;
		if (player.GetPosition().x > 11200) {
			bosshit = bossht.getElapsedTime().asMilliseconds();
			v = 0;
		}
		else v = 2;

		for (int i = 0; i < platforms.size() - v; i++)
		{
			if (platforms[i].GetCollider().CheckCollistion(player.GetCollider(), direction, 1.0f))
				player.OnCollistion(direction);
			platforms[i].GetCollider().CheckCollistion(player.GetCollider(), direction, 1.0f);

			for (int j = 0; j < 6; j++) {
				platforms[i].GetCollider().CheckCollistionbull(bullet[j].GetCollider(), direction, 1.0f);
				bullet[j].GetCollider().CheckCollistionbullmon(monster1.GetCollider(), direction);
				bullet[j].GetCollider().CheckCollistionbullmon2(monster2.GetCollider(), direction);
				bullet[j].GetCollider().CheckCollistionbullmon3(monster3.GetCollider(), direction);
				bullet[j].GetCollider().CheckCollistionbullmon4(monster4.GetCollider(), direction);
				bullet[j].GetCollider().CheckCollistionbullmon5(monster5.GetCollider(), direction);
				bullet[j].GetCollider().CheckCollistionbullmon6(monster6.GetCollider(), direction);
				bullet[j].GetCollider().CheckCollistionbullmon7(monster7.GetCollider(), direction);
				monster1.GetCollider().CheckCollistionbull(bullet[j].GetCollider(), direction, 1.0f);				
				monster2.GetCollider().CheckCollistionbull(bullet[j].GetCollider(), direction, 1.0f);
				monster3.GetCollider().CheckCollistionbull(bullet[j].GetCollider(), direction, 1.0f);
				monster4.GetCollider().CheckCollistionbull(bullet[j].GetCollider(), direction, 1.0f);
				monster5.GetCollider().CheckCollistionbull(bullet[j].GetCollider(), direction, 1.0f);
				monster6.GetCollider().CheckCollistionbull(bullet[j].GetCollider(), direction, 1.0f);
				monster7.GetCollider().CheckCollistionbull(bullet[j].GetCollider(), direction, 1.0f);
			}
		}
		//*************************************************************************************************************************
		/*if (.monster1_die == true) {
			chest.Update();
		}*/
		if ((sf::Mouse::isButtonPressed(sf::Mouse::Right)) && chest.GetCollider().CheckCollistionChest(player.GetCollider())) {
				chest.randitem();
		}
		view.setCenter(player.GetPosition());
		window.clear();

		window.draw(bg);
		window.setView(view);
		for (int i = 0; i < 6; i++) {
			if (chk_1[i] == 1) {
				window.draw(bullet[i].bullet);
			}
		}
		if (chest.use_superpower == true) {
			for (int i = 0; i < 1; i++) {
				if (chksup_1[i] == 1) {
					window.draw(superbullet[i].superbullet);
				}
			}
		}
		
		player.Draw(window);
		monster1.Draw(window);
		monster2.Draw(window);
		monster3.Draw(window);
		monster4.Draw(window);
		monster5.Draw(window);
		monster6.Draw(window);
		monster7.Draw(window);
		Boss.Draw(window);
		Boss.DrawBR1(window);
		for (int i = 0; i < platforms.size() - v; i++)
		{
			platforms[i].Draw(window);
		}

		window.display();
	}
	return 0;
}

void shoot(float x, float y) {
	end = clock();
	float dif = (float)(end - start) / CLOCKS_PER_SEC;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&& dif >0.5) {
		for (int i = 0; i < 6; i++) {
			if (chk_1[i] == 0) {
				if (pst == 1) {
					bullet[i].set(x - 20.0f, y + 30.0f);
				}
				if (pst == 2) {
					bullet[i].set(x + 60.0f, y + 30.0f);
				}
				pst1[i] = pst;
				chk_1[i] = 1;
				start = clock();
				break;
			}
		}
	}
}

void shot(float x, float y) {
	for (int i = 0; i < 6; i++) {
		if (chk_1[i] == 1) {
			float speed = 3.0f;
			if (pst1[i] == 1) {
				bullet[i].bullet.move(-speed, 0);
			}
			if (pst1[i] == 2) {
				bullet[i].bullet.move(speed, 0);
			}
			if (bullet[i].bullet.getPosition().x < x - 1920 || bullet[i].bullet.getPosition().x > x + 1920) {
				chk_1[i] = 0;

			}
		}
	}
}

void shootsuper(float x, float y) {
	end = clock();
	float dif = (float)(end - start) / CLOCKS_PER_SEC;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && dif > 0.5 && chest.superPower == true) {
		chest.use_superpower == true;
		for (int i = 0; i < 1; i++) {
			if (chksup_1[i] == 0) {
				if (pst == 1) {
					superbullet[i].set(x - 20.0f, y + 30.0f);
				}
				if (pst == 2) {
					superbullet[i].set(x + 60.0f, y + 30.0f);
				}
				pst1sup[i] = pst;
				chksup_1[i] = 1;
				chest.superPower == false;
				start = clock();
				break;
			}
		}
	}
}

void shotsuper(float x, float y) {
	if (chest.use_superpower == true) {
		for (int i = 0; i < 1; i++) {
			if (chksup_1[i] == 1) {
				float speed = 1.0f;
				if (pst1sup[i] == 1) {
					superbullet[i].superbullet.move(-speed, 0);
				}
				if (pst1sup[i] == 2) {
					superbullet[i].superbullet.move(speed, 0);
				}
				if (superbullet[i].superbullet.getPosition().x < x - 1920 || superbullet[i].superbullet.getPosition().x > x + 1920) {
					chksup_1[i] = 0;
					chest.use_superpower == false;
				}
			}
		}
	}
}


