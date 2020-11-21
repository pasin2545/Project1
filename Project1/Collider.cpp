#include "Collider.h"
#include "monster1.h"
int hpmon1 = 2;
int hpmon2 = 3;
int hpmon3 = 2;
int hpmon4 = 2;
int hpmon5 = 3;
int hpmon6 = 3;
int hpmon7 = 3;

Collider::Collider(sf::RectangleShape& body) :
	body(body)
{
}

Collider::~Collider()
{
}

bool Collider::CheckCollistionbull(Collider other, sf::Vector2f& direction, float push)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		other.SetPos(0.0f, 4000.0f);
		return true;
	}
	return false;
}
//***********************************************************************************************************************************
bool Collider::CheckCollistionbullmon(Collider other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		printf("%d\n", hpmon1);
		hpmon1 -= 1;
		if (hpmon1 == 0) {
			other.Move(0.0f, 1000.0f);
		}
		return true;
	}
	return false;
}

bool Collider::CheckCollistionbullmon2(Collider other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		printf("%d\n", hpmon2);
		hpmon2 -= 1;
		if (hpmon2 == 0) {
			other.SetPos(0.0f,1000.0f);
		}
		return true;
	}
	return false;
}
bool Collider::CheckCollistionbullmon3(Collider other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		printf("%d\n", hpmon2);
		hpmon3 -= 1;
		if (hpmon3 == 0) {
			other.SetPos(0.0f, 1000.0f);
		}
		return true;
	}
	return false;
}
bool Collider::CheckCollistionbullmon4(Collider other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		printf("%d\n", hpmon4);
		hpmon4 -= 1;
		if (hpmon4 == 0) {
			other.SetPos(0.0f, 1000.0f);
		}
		return true;
	}
	return false;
}
bool Collider::CheckCollistionbullmon5(Collider other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		printf("%d\n", hpmon5);
		hpmon5 -= 1;
		if (hpmon5 == 0) {
			other.SetPos(0.0f, 1000.0f);
		}
		return true;
	}
	return false;
}
bool Collider::CheckCollistionbullmon6(Collider other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		printf("%d\n", hpmon6);
		hpmon6 -= 1;
		if (hpmon6 == 0) {
			other.SetPos(0.0f, 1000.0f);
		}
		return true;
	}
	return false;
}
bool Collider::CheckCollistionbullmon7(Collider other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		printf("%d\n", hpmon7);
		hpmon7 -= 1;
		if (hpmon7 == 0) {
			other.SetPos(0.0f, 1000.0f);
		}
		return true;
	}
	return false;
}
//********************************************************************************************************************************************
bool Collider::CheckCollistion(Collider other, sf::Vector2f& direction, float push)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < -100.0f && intersectY < 0.0f) {
		push = std::min(std::max(push, 0.0f), 1.0f);
		if (intersectX > intersectY) {
			if (deltaX > 0.0f)
			{
				Move(intersectX * (1.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f);

				direction.x = 1.0f;
				direction.y = 0.0f;
			}
			else
			{
				Move(-intersectY * (1.0f - push), 0.0f);
				other.Move(intersectY * push, 0.0f);

				direction.x = -1.0f;
				direction.y = 0.0f;
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				Move(0.0f, intersectY * (1.0f - push));
				other.Move(0.0f, -intersectY * push);

				direction.x = 0.0f;
				direction.y = 1.0f;
			}
			else
			{
				Move(0.0f, -intersectY * (1.0f - push));
				other.Move(0.0f, intersectY * push);

				direction.x = 0.0f;
				direction.y = -1.0f;
			}
		}
		return true;
	}

	return false;
}