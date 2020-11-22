#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include"Collider.h"

	class monster2
	{
	public:
		monster2(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
		~monster2();
		void Updatem2(float deltatimem1);
		void Draw(sf::RenderWindow& window);

		sf::Vector2f GetPosition() { return bodym2.getPosition(); }
		Collider GetCollider() { return Collider(bodym2); }

	private:
		sf::RectangleShape bodym2;
		Animation animation;
		unsigned int rowm2;
		float speedm2;
		bool faceRightm2;
		int chk = 0;
	};


