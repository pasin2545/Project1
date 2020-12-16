#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include"Animation2.h"
#include"player.h"
#include<vector>
#include<utility>
#include<algorithm>
#include<string>
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
#include"Textbox.h"
using namespace sf;
using namespace std;


int chk_1[6] = { 0 };
int pst = 0;
int pst1[6];

int chksup_1[1] = { 0 };
int pst1sup[1];

int chkboss_1[3] = { 0 };
int chkboss_3[3] = { 0 };

bool chest_open = false;
bool superPower = false;
bool use_superpower = false;
bool chest_dis1 = false;
bool chest_dis2 = false;
bool chest_dis3 = false;
bool hp_canDown = true;
bool BurnTime = true;
bool Potion = false;
bool showIcon = false;
bool GetBossfight = false;

bool EndBossAction = true;
bool ActBoss1 = false;
bool ActBoss2 = false;
bool ActBoss3 = false;
bool ActBoss4 = false;

int PlayerHP = 3;
int hpmon1 = 2;
int hpmon2 = 3;
int hpmon3 = 3;
int hpmon4 = 2;
int hpmon5 = 5;
int hpmon6 = 5;
int hpmon7 = 5;
int hpBoss = 30;
int TM=0;
int PTM = 0;
int sample = 0;
int sample2 = 0;
int startBossStage = 0;
int state;

int randomActBoss;

clock_t start=-0.2,endd = 0;
clock_t startboss = -0.2, endboss = 0;
clock_t startboss2 = -0.2, endboss2 = 0;

static const float VIEW_HEIGHT = 768.0f;
static const float VIEW_LENGTH = 1536.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_LENGTH * aspectRatio, VIEW_HEIGHT);
}


void shoot(float, float);
void shot(float,float);
void shootsuper(float, float);
void shotsuper(float, float);
void HitTimecount();
void HealTimecount();
void UsePotion();
void shootBullBossR1(float, float);
void shotBullBossR1(float, float);
void ActionBoss1(float, float);
void randActBoss();
void ActionBoss2();
void shootBullBossR3(float, float);
void shotBullBossR3(float, float);
void ActionBoss3(float, float);
void ActionBoss4();


//***********************************************class PlayerBullet**********************************
sf::Texture* superBULLET;

	class Bulleted {
	public:
		sf:: RectangleShape bullet;
		sf::Texture BULLET;
		void set(float x, float y)
		{
			BULLET.loadFromFile("bullet2.png");
			bullet.setTexture(&BULLET);
			bullet.setSize(sf::Vector2f(30.0f, 30.0f));
			bullet.setPosition(x, y);
		}

		sf::Vector2f GetPosition() { return bullet.getPosition(); }
		Collider GetCollider() { return Collider(bullet); }

	};

	class superBulleted {
	public:
		sf::RectangleShape superbullet;
		sf::Texture superBULLET;
		void set(float x, float y)
		{
			superBULLET.loadFromFile("superbullet.png");
			superbullet.setTexture(&superBULLET);
			superbullet.setSize(sf::Vector2f(50.0f, 50.0f));
			superbullet.setPosition(x, y);
		}

		sf::Vector2f GetPosition() { return superbullet.getPosition(); }
		Collider GetCollider() { return Collider(superbullet); }

	};
//********************************************************************************************
	
//****************************************class Bossbullet******************************************
	//sf::Texture* BULLETBOSS;
	class BulletBoss {
	public:
		sf::RectangleShape bulletboss1;
		sf::Texture BULLETBOSS;
		void set(float x, float y)
		{
			BULLETBOSS.loadFromFile("fireBoss.png");
			bulletboss1.setTexture(&BULLETBOSS);
			bulletboss1.setSize(sf::Vector2f(95.0f, 50.0f));
			bulletboss1.setPosition(x, y);
		}

		sf::Vector2f GetPosition() { return bulletboss1.getPosition(); }
		Collider GetCollider() { return Collider(bulletboss1); }
	};
//********************************************************************************************

//******************************************class Bossbullet2*********************************
	class BulletBoss2 {
	public:
		sf::RectangleShape bulletboss2;
		sf::Texture BULLETBOSS;
		void set(float x, float y)
		{
			BULLETBOSS.loadFromFile("fireBoss2.png");
			bulletboss2.setTexture(&BULLETBOSS);
			bulletboss2.setSize(sf::Vector2f(95.0f, 50.0f));
			bulletboss2.setPosition(x, y);
		}

		sf::Vector2f GetPosition() { return bulletboss2.getPosition(); }
		Collider GetCollider() { return Collider(bulletboss2); }
	};
//*********************************************************************************************

//*******************************************class Chest********************************************************
	class Chest
	{
	public:
		Chest(sf::Texture* texture,sf::Vector2f position);
		~Chest();
		void randitem();
		void Draw(sf::RenderWindow& window);

		sf::Vector2f GetPosition() { return chest.getPosition(); }
		Collider GetCollider() { return Collider(chest); }

		sf::RectangleShape chest;

	private:
		int random_item;
	};
//**************************************************************************************************************

//*************************************************Class Boss2*******************************************************
	class Boss2
	{
	public:
		Boss2(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
		~Boss2();
		void UpdateBoss1(float deltatimem1);
		void UpdateBoss2(float deltatimem1);
		void Draw(sf::RenderWindow& window);

		sf::Vector2f GetPosition() { return bodyBoss.getPosition(); }
		Collider GetCollider() { return Collider(bodyBoss); }

	private:
		sf::RectangleShape bodyBoss;
		Animation animation;
		unsigned int rowboss;
		float speedboss;
		bool faceRightboss;
	};
//******************************************************************************************************************
	class BossAct1
	{
		public:
			BossAct1(sf::Vector2f position);
			sf::RectangleShape Bossact1;
			void Draw(sf::RenderWindow& window);

			sf::Vector2f GetPosition() { return Bossact1.getPosition(); }
			Collider GetColliderAct1() { return Collider(Bossact1); }
	};
	class BossAct2
	{
	public:
		BossAct2(sf::Vector2f position);
		sf::RectangleShape Bossact2;
		void Draw(sf::RenderWindow& window);

		sf::Vector2f GetPosition() { return Bossact2.getPosition(); }
		Collider GetColliderAct2() { return Collider(Bossact2); }
	};

	string totime(int x)
	{

		int _min, _sec, _mill;
		_min = x / 6000;
		x = x % 6000;
		_sec = x / 100;
		x = x % 100;
		_mill = x;

		string _0min = "", _0sec = "", _0mill = "";
		if (_min < 10)_0min = "0";
		if (_sec < 10)_0sec = "0";
		if (_mill < 10)_0mill = "0";
		string _time = _0min + to_string(_min) + ":" + _0sec + to_string(_sec) + ":" + _0mill + to_string(_mill);
		return _time;

	}
	int mins = 0, secs = 0;
	void showTime(int x, int y, float mills, sf::RenderWindow& window, sf::Font* font)
	{
		mills = int(mills);
		secs = (int(mills) / 100) % 60;
		mins = (int(mills) / 100) / 60 % 60;
		mills = int(mills) % 100;
		int mills2 = int(mills);
		String _secs, _mins;
		if (secs < 10)_secs = "0";
		else _secs = "";
		if (mins < 10)_mins = "0";
		else _mins = "";
		String word = _mins + to_string(mins) + ":" + _secs + to_string(secs) + ":" + to_string(mills2);

		sf::Text text;
		text.setFont(*font);
		text.setPosition(x, y);
		text.setString(word);
		text.setCharacterSize(75);


		window.draw(text);
	}
	void showcount(int x, int y, int count, sf::RenderWindow& window, sf::Font* font)
	{

		sf::Text text;
		text.setFont(*font);
		text.setPosition(x, y);
		text.setString(to_string(count));
		text.setCharacterSize(60);
		text.setFillColor(Color::Black);
		window.draw(text);
	}
	void showHighScore(int x, int y, string word, sf::RenderWindow& window, sf::Font* font)
	{

		sf::Text text;
		text.setFont(*font);
		text.setPosition(x, y);
		text.setString(word);
		if (word == "HIGHSCORE")
			text.setCharacterSize(120);
		else
			text.setCharacterSize(50);
		window.draw(text);

	}

	superBulleted superbullet[1];
	Bulleted bullet[6];
	BulletBoss bulletboss1[3];
	BulletBoss2  bulletboss3[3];

	float hitchk;
	sf::Clock crash;
	float Potionchk;
	sf::Clock Heal;
	float clockbpn;
	sf::Clock Bullpn;
	float clockbpn2;
	sf::Clock Bullpn2;
	float Framechk;
	sf::Clock FrameTM;

//============================================================================== main ======================================================
int main() {
	std::string sname = "unknown";
	int sscore = 9999999;
	int state = 0;
	sf::Font font;

	int score[6] = {};
	std::string name[6] = {};
	char temp[255] = {};

	std::vector <std::pair<int, std::string>> userScore;
	FILE* fp;
	// high score
	
		font.loadFromFile("Silver.ttf");
		fp = fopen("Score.txt", "r");
		for (int i = 0; i < 5; i++)
		{
			
			fscanf(fp, "%s", &temp);
			name[i] = temp;

			fscanf(fp, "%d", &score[i]);
			if (score[i] == 0)
				score[i] = 9999999;
			userScore.push_back(make_pair(score[i], name[i]));
			//cout << temp << " " << score;
		}
		//userScore.push_back(make_pair(sscore, sname));
		sort(userScore.begin(), userScore.end());
		fclose(fp);

		

		for (int i = 0; i < 5; i++)
		{
			cout << userScore[i].first<<" ";
			cout << userScore[i].second<<endl;
			//userScore.push_back(make_pair(score[i], name[i]));
			//cout << temp << " " << score;
		}


start:;

	chk_1[6] = { 0 };
	pst = 0;

	chksup_1[1] = { 0 };


	chkboss_1[3] = { 0 };
	chkboss_3[3] = { 0 };

	chest_open = false;
	superPower = false;
	use_superpower = false;
	chest_dis1 = false;
	chest_dis2 = false;
	chest_dis3 = false;
	hp_canDown = true;
	BurnTime = true;
	Potion = false;
	showIcon = false;

	EndBossAction = true;
	ActBoss1 = false;
	ActBoss2 = false;
	ActBoss3 = false;
	ActBoss4 = false;

	PlayerHP = 3;
	hpmon1 = 2;
	hpmon2 = 3;
	hpmon3 = 3;
	hpmon4 = 2;
	hpmon5 = 5;
	hpmon6 = 5;
	hpmon7 = 5;
	hpBoss = 30;
	//score = 0;
	TM = 0;
	PTM = 0;
	sample = 0;
	sample2 = 0;
	startBossStage = 0;
	state;
	sf::RenderWindow window(sf::VideoMode(1536, 768), "2D Game", sf::Style::Close | sf::Style::Close);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_LENGTH, VIEW_HEIGHT));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("player2.png");
	Player player(&playerTexture, sf::Vector2u(8, 2), 0.2f, 250.0f, 200.0f);
	sf::Texture BrickTexture;
	BrickTexture.loadFromFile("Brick.png");
	sf::Texture floor1;
	floor1.loadFromFile("floor1fix3.png");
	sf::Texture floor2;
	floor2.loadFromFile("floor2.png");
	sf::Texture floor3;
	floor3.loadFromFile("floor3.png");
	sf::Texture floor4;
	floor4.loadFromFile("floor4.png");
	sf::Texture Box1;
	Box1.loadFromFile("Box1.png");
	sf::Texture Box2;
	Box2.loadFromFile("Box2.png");
	sf::Texture Box3;
	Box3.loadFromFile("Box3.png");
	sf::Texture Box4;
	Box4.loadFromFile("Box4.png");
	sf::Texture tower;
	tower.loadFromFile("tower.png");

	std::vector<Platform> platforms;

	//***********************Box*************************************************************
	platforms.push_back(Platform(&Box1, sf::Vector2f(400.0f, 1000.0f), sf::Vector2f(-750.0f, -475.0f)));
	platforms.push_back(Platform(&Box2, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f)));
	platforms.push_back(Platform(&Box3, sf::Vector2f(200.0f, 350.0f), sf::Vector2f(600.0f, -50.0f)));
	platforms.push_back(Platform(&Box3, sf::Vector2f(200.0f, 350.0f), sf::Vector2f(1450.0f, 20.0f)));
	platforms.push_back(Platform(&Box3, sf::Vector2f(200.0f, 350.0f), sf::Vector2f(6850.0f, 0.0f)));
	platforms.push_back(Platform(&Box4, sf::Vector2f(300.0f, 400.0f), sf::Vector2f(7400.0f, -150.0f)));
	//***************************************************************************************


	//*********************************Brick*************************************************
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(3050.0f, 0.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(3350.0f, 0.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(3650.0f, 0.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(4200.0f, 0.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5300.0f, -25.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5400.0f, -25.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5400.0f, -125.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5500.0f, -25.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5500.0f, -125.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(5500.0f, -225.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6000.0f, -225.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6000.0f, -125.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6000.0f, -25.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6100.0f, -125.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6100.0f, -25.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(6200.0f, -25.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(8050.0f, -280.0f)));
	
	/*platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(9100.0f, -180.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(8800.0f, -310.0f)));*/
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(9700.0f, -25.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(10000.0f, -125.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(10300.0f, -225.0f)));
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(10700.0f, -350.0f)));
	//***************************************************************************************


	//*********************************Floor*************************************************
	platforms.push_back(Platform(&floor1, sf::Vector2f(2500.0f, 350.0f), sf::Vector2f(300.0f, 200.0f)));
	platforms.push_back(Platform(&floor2, sf::Vector2f(1000.0f, 350.0f), sf::Vector2f(2350.0f, 200.0f)));
	platforms.push_back(Platform(&floor2, sf::Vector2f(1000.0f, 350.0f), sf::Vector2f(5050.0f, 200.0f)));
	platforms.push_back(Platform(&floor2, sf::Vector2f(1000.0f, 350.0f), sf::Vector2f(6450.0f, 200.0f)));
	platforms.push_back(Platform(&floor3, sf::Vector2f(2200.0f, 350.0f), sf::Vector2f(8350.0f, 200.0f)));
	platforms.push_back(Platform(&floor4, sf::Vector2f(2000.0f, 350.0f), sf::Vector2f(12000.0f, -375.0f)));
	//***************************************************************************************
	
	//**************************************Tower**********************************************************
	platforms.push_back(Platform(&BrickTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(8600.0f, -280.0f)));
	platforms.push_back(Platform(&tower, sf::Vector2f(300.0f, 1000.0f), sf::Vector2f(11155.0f, -1050.0f)));
	platforms.push_back(Platform(&tower, sf::Vector2f(300.0f, 1000.0f), sf::Vector2f(13150.0f, -725.0f)));

	//*****************************************************************************************************

	sf::Texture monster1Texture;
	monster1Texture.loadFromFile("monster1.png");
	monster1 monster1(&monster1Texture, sf::Vector2u(5, 1), 0.3f, 200.0f);
	sf::Texture monster2Texture;
	monster2Texture.loadFromFile("house.png");
	monster2 monster2(&monster2Texture, sf::Vector2u(4, 1), 0.3f, 200.0f);
	sf::Texture monster3Texture;
	monster3Texture.loadFromFile("monster3.png");
	monster3 monster3(&monster3Texture, sf::Vector2u(7, 1), 0.3f, 200.0f);
	monster4 monster4(&monster1Texture, sf::Vector2u(5, 1), 0.3f, 200.0f);
	monster5 monster5(&monster2Texture, sf::Vector2u(4, 1), 0.3f, 800.0f);
	monster6 monster6(&monster2Texture, sf::Vector2u(4, 1), 0.3f, 800.0f);
	monster7 monster7(&monster2Texture, sf::Vector2u(4, 1), 0.3f, 800.0f);
	sf::Texture BossTexture;
	sf::Texture BossTexture2;
	BossTexture.loadFromFile("Boss.png");
	BossTexture2.loadFromFile("Boss2fix.png");
	Boss Boss1(&BossTexture, sf::Vector2u(6, 1), 0.3f, 200.0f);
	Boss2 Boss2(&BossTexture2, sf::Vector2u(3, 1), 0.3f, 200.0f);
	sf::Texture ChestTexture;
	ChestTexture.loadFromFile("Chestfix.png");
	Chest chest(&ChestTexture, sf::Vector2f(1100.0f, -20.0f));
	Chest chest2(&ChestTexture, sf::Vector2f(4900.0f, -20.0f));
	Chest chest3(&ChestTexture, sf::Vector2f(8800.0f, -405.0f));
	BossAct1 BoxBossAct1(sf::Vector2f(12475.0f, -1025.0f));
	BossAct2 BoxBossAct2(sf::Vector2f(12475.0f, -1040.0f));
	BossAct1 BoxBossAct3(sf::Vector2f(11550.0f, -1025.0f));
	BossAct2 BoxBossAct4(sf::Vector2f(11425.0f, -1040.0f));

	sf::Font textfont;
	font.loadFromFile("Silver.ttf");
	sf::Text scoreText;
	scoreText.setFont(textfont);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setCharacterSize(64);

	//***********************Heart************************************
	sf::RectangleShape heartbar0(sf::Vector2f(380.0f, 95.0f));
	sf::RectangleShape heartbar1(sf::Vector2f(380.0f, 95.0f));
	sf::RectangleShape heartbar2(sf::Vector2f(380.0f, 95.0f));
	sf::RectangleShape heartbar3(sf::Vector2f(380.0f, 95.0f));
	sf::Texture heartbar0Texture;
	sf::Texture heartbar1Texture;
	sf::Texture heartbar2Texture;
	sf::Texture heartbar3Texture;
	heartbar0Texture.loadFromFile("heartbar0.png");
	heartbar1Texture.loadFromFile("heartbar1.png");
	heartbar2Texture.loadFromFile("heartbar2.png");
	heartbar3Texture.loadFromFile("heartbar3fix.png");
	heartbar0.setTexture(&heartbar0Texture);
	heartbar1.setTexture(&heartbar1Texture);
	heartbar2.setTexture(&heartbar2Texture);
	heartbar3.setTexture(&heartbar3Texture);
	//****************************************************************
	
	//***********************BossHeartBar*****************************
	sf::RectangleShape Bossheartbar0(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar1(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar2(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar3(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar4(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar5(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar6(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar7(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar8(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar9(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar10(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar11(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar12(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar13(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar14(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar15(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar16(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar17(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar18(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar19(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar20(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar21(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar22(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar23(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar24(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar25(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar26(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar27(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar28(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar29(sf::Vector2f(720.0f, 63.0f));
	sf::RectangleShape Bossheartbar30(sf::Vector2f(720.0f, 63.0f));
	sf::Texture Bossheartbar0Texture;
	sf::Texture Bossheartbar1Texture;
	sf::Texture Bossheartbar2Texture;
	sf::Texture Bossheartbar3Texture;
	sf::Texture Bossheartbar4Texture;
	sf::Texture Bossheartbar5Texture;
	sf::Texture Bossheartbar6Texture;
	sf::Texture Bossheartbar7Texture;
	sf::Texture Bossheartbar8Texture;
	sf::Texture Bossheartbar9Texture;
	sf::Texture Bossheartbar10Texture;
	sf::Texture Bossheartbar11Texture;
	sf::Texture Bossheartbar12Texture;
	sf::Texture Bossheartbar13Texture;
	sf::Texture Bossheartbar14Texture;
	sf::Texture Bossheartbar15Texture;
	sf::Texture Bossheartbar16Texture;
	sf::Texture Bossheartbar17Texture;
	sf::Texture Bossheartbar18Texture;
	sf::Texture Bossheartbar19Texture;
	sf::Texture Bossheartbar20Texture;
	sf::Texture Bossheartbar21Texture;
	sf::Texture Bossheartbar22Texture;
	sf::Texture Bossheartbar23Texture;
	sf::Texture Bossheartbar24Texture;
	sf::Texture Bossheartbar25Texture;
	sf::Texture Bossheartbar26Texture;
	sf::Texture Bossheartbar27Texture;
	sf::Texture Bossheartbar28Texture;
	sf::Texture Bossheartbar29Texture;
	sf::Texture Bossheartbar30Texture;
	Bossheartbar0Texture.loadFromFile("BossheartBar0.png");
	Bossheartbar1Texture.loadFromFile("BossheartBar1.png");
	Bossheartbar2Texture.loadFromFile("BossheartBar2.png");
	Bossheartbar3Texture.loadFromFile("BossheartBar3.png");
	Bossheartbar4Texture.loadFromFile("BossheartBar4.png");
	Bossheartbar5Texture.loadFromFile("BossheartBar5.png");
	Bossheartbar6Texture.loadFromFile("BossheartBar6.png");
	Bossheartbar7Texture.loadFromFile("BossheartBar7.png");
	Bossheartbar8Texture.loadFromFile("BossheartBar8.png");
	Bossheartbar9Texture.loadFromFile("BossheartBar9.png");
	Bossheartbar10Texture.loadFromFile("BossheartBar10.png");
	Bossheartbar11Texture.loadFromFile("BossheartBar11.png");
	Bossheartbar12Texture.loadFromFile("BossheartBar12.png");
	Bossheartbar13Texture.loadFromFile("BossheartBar13.png");
	Bossheartbar14Texture.loadFromFile("BossheartBar14.png");
	Bossheartbar15Texture.loadFromFile("BossheartBar15.png");
	Bossheartbar16Texture.loadFromFile("BossheartBar16.png");
	Bossheartbar17Texture.loadFromFile("BossheartBar17.png");
	Bossheartbar18Texture.loadFromFile("BossheartBar18.png");
	Bossheartbar19Texture.loadFromFile("BossheartBar19.png");
	Bossheartbar20Texture.loadFromFile("BossheartBar20.png");
	Bossheartbar21Texture.loadFromFile("BossheartBar21.png");
	Bossheartbar22Texture.loadFromFile("BossheartBar22.png");
	Bossheartbar23Texture.loadFromFile("BossheartBar23.png");
	Bossheartbar24Texture.loadFromFile("BossheartBar24.png");
	Bossheartbar25Texture.loadFromFile("BossheartBar25.png");
	Bossheartbar26Texture.loadFromFile("BossheartBar26.png");
	Bossheartbar27Texture.loadFromFile("BossheartBar27.png");
	Bossheartbar28Texture.loadFromFile("BossheartBar28.png");
	Bossheartbar29Texture.loadFromFile("BossheartBar29.png");
	Bossheartbar30Texture.loadFromFile("BossheartBar30.png");
	Bossheartbar0.setTexture(&Bossheartbar0Texture);
	Bossheartbar1.setTexture(&Bossheartbar1Texture);
	Bossheartbar2.setTexture(&Bossheartbar2Texture);
	Bossheartbar3.setTexture(&Bossheartbar3Texture);
	Bossheartbar4.setTexture(&Bossheartbar4Texture);
	Bossheartbar5.setTexture(&Bossheartbar5Texture);
	Bossheartbar6.setTexture(&Bossheartbar6Texture);
	Bossheartbar7.setTexture(&Bossheartbar7Texture);
	Bossheartbar8.setTexture(&Bossheartbar8Texture);
	Bossheartbar9.setTexture(&Bossheartbar9Texture);
	Bossheartbar10.setTexture(&Bossheartbar10Texture);
	Bossheartbar11.setTexture(&Bossheartbar11Texture);
	Bossheartbar12.setTexture(&Bossheartbar12Texture);
	Bossheartbar13.setTexture(&Bossheartbar13Texture);
	Bossheartbar14.setTexture(&Bossheartbar14Texture);
	Bossheartbar15.setTexture(&Bossheartbar15Texture);
	Bossheartbar16.setTexture(&Bossheartbar16Texture);
	Bossheartbar17.setTexture(&Bossheartbar17Texture);
	Bossheartbar18.setTexture(&Bossheartbar18Texture);
	Bossheartbar19.setTexture(&Bossheartbar19Texture);
	Bossheartbar20.setTexture(&Bossheartbar20Texture);
	Bossheartbar21.setTexture(&Bossheartbar21Texture);
	Bossheartbar22.setTexture(&Bossheartbar22Texture);
	Bossheartbar23.setTexture(&Bossheartbar23Texture);
	Bossheartbar24.setTexture(&Bossheartbar24Texture);
	Bossheartbar25.setTexture(&Bossheartbar25Texture);
	Bossheartbar26.setTexture(&Bossheartbar26Texture);
	Bossheartbar27.setTexture(&Bossheartbar27Texture);
	Bossheartbar28.setTexture(&Bossheartbar28Texture);
	Bossheartbar29.setTexture(&Bossheartbar29Texture);
	Bossheartbar30.setTexture(&Bossheartbar30Texture);
	//****************************************************************

	//******************************************sound effect**********************************************
	sf::SoundBuffer titleBack;
	titleBack.loadFromFile("Title.wav");
	sf::Sound TitleBacksound;
	TitleBacksound.setBuffer(titleBack);
	sf::SoundBuffer gameBack;
	gameBack.loadFromFile("Game.wav");
	sf::Sound gameBacksound;
	gameBacksound.setBuffer(gameBack);
	if (state == 1) {
		gameBacksound.setLoop(false);
	}
	if (state == 0) {
		TitleBacksound.setLoop(true);
	}
	if (state == 1) {
		gameBacksound.play();
	}
	if (state == 0) {
		TitleBacksound.play();
	}

	//****************************************************************************************************

	//****************************************** Menu Button**********************************************
	// menu buttonTexture
		sf::Texture btnplayTexture, backTexture;
		sf::Texture hsTexture, settingTexture, exitTexture, commingTexture, returnTexture, gameoverTexture, playagainTexture;


		sf::RectangleShape back(sf::Vector2f(1536.0f, 768.0f));

		sf::RectangleShape btnplay(sf::Vector2f(1300.0f / 3, 300.0f / 3)), sbtnplay(sf::Vector2f(1300.0f / 3 * 1.2, 300.0f / 3 * 1.2));
		sf::RectangleShape btnhs(sf::Vector2f(369.0f, 97.0f)), sbtnhs(sf::Vector2f(369.0f * 1.2, 97.0f * 1.2));
		sf::RectangleShape btnsetting(sf::Vector2f(540.0f / 1.8, 322.0f / 1.8)), sbtnsetting(sf::Vector2f(540.0f / 1.8 * 1.2, 322.0f / 1.8 * 1.2));
		sf::RectangleShape btnexit(sf::Vector2f(540.0f / 2.5, 240.0f / 2.5)), sbtnexit(sf::Vector2f(540.0f / 2.5 * 1.2, 240.0f / 2.5 * 1.2));
		sf::RectangleShape comming(sf::Vector2f(1200.0f / 1.5, 450.0f / 1.5));
		sf::RectangleShape btnreturn(sf::Vector2f(1030.0 / 3.5, 400.0 / 3.5)), sbtnreturn(sf::Vector2f(1030.0 / 3.5 * 1.2, 400.0 / 3.5 * 1.2));
		sf::RectangleShape btngameover(sf::Vector2f(804.0 / 1, 422.0 / 1));
		sf::RectangleShape btnplayagain(sf::Vector2f(738.0 / 2.5, 419.0 / 2.5)), sbtnplayagain(sf::Vector2f(738.0 / 2.5 * 1.2, 419.0 / 2.5 * 1.2));

		backTexture.loadFromFile("manu-background.png");
		back.setTexture(&backTexture);

		btnplayTexture.loadFromFile("startbutton.PNG");
		btnplay.setTexture(&btnplayTexture);
		sbtnplay.setTexture(&btnplayTexture);

		hsTexture.loadFromFile("Highscore.PNG");
		btnhs.setTexture(&hsTexture);
		sbtnhs.setTexture(&hsTexture);

		exitTexture.loadFromFile("Exit.PNG");
		btnexit.setTexture(&exitTexture);
		sbtnexit.setTexture(&exitTexture);

		returnTexture.loadFromFile("return.PNG");
		btnreturn.setTexture(&returnTexture);
		sbtnreturn.setTexture(&returnTexture);

	//***********************Background*******************************
	sf::RectangleShape bg(sf::Vector2f(1536.0f, 768.0f));
	sf::Texture bgTexture;
	bgTexture.loadFromFile("BackGround.png");
	bg.setTexture(&bgTexture);
	//****************************************************************

	//****************************superbulletIcon*********************
	sf::RectangleShape superIcon(sf::Vector2f(50.0f, 50.0f));
	sf::Texture superIconTexture;
	superIconTexture.loadFromFile("superbulleticon.png");
	superIcon.setTexture(&superIconTexture);
	//****************************************************************

	//***************************Gover********************************
	sf::RectangleShape Gover(sf::Vector2f(1536.0f, 768.0f));
	sf::Texture GoverTexture;
	GoverTexture.loadFromFile("Gameover.png");
	Gover.setTexture(&GoverTexture);
	//****************************************************************

	//***************************victory******************************
	sf::RectangleShape Victory(sf::Vector2f(1536.0f, 768.0f));
	sf::Texture VictoryTexture;
	VictoryTexture.loadFromFile("Victory.png");
	Victory.setTexture(&VictoryTexture);
	//****************************************************************

	//***************************return*******************************
	sf::RectangleShape backtomenu(sf::Vector2f(460.0f,190.0f));
	sf::Texture backtomenuTexture;
	backtomenuTexture.loadFromFile("return-menu1.png");
	backtomenu.setTexture(&backtomenuTexture);
	//****************************************************************

	//**************************return ex*****************************
	sf::RectangleShape exbacktomenu(sf::Vector2f(460.0f, 190.0f));
	sf::Texture exbacktomenuTexture;
	exbacktomenuTexture.loadFromFile("return-menu2.png");
	exbacktomenu.setTexture(&exbacktomenuTexture);
	//****************************************************************

	//*************************Name***********************************
	Textbox playernametextbox(70, sf::Color::White, true);
	playernametextbox.setFont(font);
	playernametextbox.setPosition({ player.GetPosition().x -700, player.GetPosition().y +0 });
	playernametextbox.setlimit(true, 10);
	//****************************************************************

	float deltaTime = 1.0f;
	sf::Clock clock;
	float bosshit;
	sf::Clock bossht;
	Clock Cclock;
	int mins = 0, secons = 0, mills = 0;
	sf::Event event;

	while (window.isOpen()) {
		if (state == -1)
		{
			window.clear();

			btnreturn.setPosition(player.GetPosition().x + 400, player.GetPosition().y + 210);
			sbtnreturn.setPosition(player.GetPosition().x + 370, player.GetPosition().y + 190);

			Vector2i mouse = Mouse::getPosition(window);
			printf("mousepos x= %.0f y= %.0f\n", (float)mouse.x, (float)mouse.y);

			back.setPosition(player.GetPosition().x - 768, player.GetPosition().y - 383);

			showHighScore(player.GetPosition().x - 768, player.GetPosition().y - 383, "HIGHSCORE", window, &font);

			for (int i = 4; i >= 0; i--)
			{
				string _time = totime(userScore[i].first);
				showHighScore(player.GetPosition().x - 768+400, player.GetPosition().y - 383+150 + (i + 1) * 60, userScore[i].second, window, &font);
				showHighScore(player.GetPosition().x - 668+100+400, player.GetPosition().y - 383+150 + (i + 1) * 60, _time, window, &font);
			}

			if (mouse.x > 1200 and mouse.x < 1441 and mouse.y>611 and mouse.y <694)
				window.draw(sbtnreturn);
			else
				window.draw(btnreturn);

			window.display();

			if (mouse.x > 1200 and mouse.x < 1441 and mouse.y>611 and mouse.y < 694)
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					state = 0;

			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case Event::Closed:
					window.close();
					break;
				case Event::Resized:
					ResizeView(window, view);
					break;
				}
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (mouse.x > 738 and mouse.x < 1080 and mouse.y>64 and mouse.y < 130)
				{
					state = 1;
				}
			}

		}
		//*******************************************************Menu**************************************
		if (state == 0)
		{
			//printf("player = %.0f %.0f %.0f %.0f %.0f ", player.GetPosition().x, player.GetPosition().y, enemyx, enemyy);

			// all button-------------------------------------------------------------------
			btnplay.setPosition(player.GetPosition().x-260, player.GetPosition().y - 150);
			sbtnplay.setPosition(player.GetPosition().x - 300, player.GetPosition().y - 150);

			btnhs.setPosition(player.GetPosition().x - 232, player.GetPosition().y +20);
			sbtnhs.setPosition(player.GetPosition().x- 255, player.GetPosition().y + 10);


			/*btnsetting.setPosition(player.GetPosition().x + 55, player.GetPosition().y - 30);
			sbtnsetting.setPosition(player.GetPosition().x + 30, player.GetPosition().y - 50);*/

			btnexit.setPosition(player.GetPosition().x - 150, player.GetPosition().y + 170);
			sbtnexit.setPosition(player.GetPosition().x -170, player.GetPosition().y + 160);

			//comming.setPosition(player.GetPosition().x - 400, player.GetPosition().y - 150);


			//-------------------------------------------------------------------------------
			sf::Vector2i mouse = sf::Mouse::getPosition(window);
			printf("mousepos x= %.0f y= %.0f\n", (float)mouse.x, (float)mouse.y);




			back.setPosition(player.GetPosition().x - 768, player.GetPosition().y - 383);

			window.clear(sf::Color(150, 150, 150));
			view.setCenter(player.GetPosition());
			window.setView(view);

			window.draw(back);


			if (mouse.x > 559 and mouse.x < 910 and mouse.y>251 and mouse.y < 325)
				window.draw(sbtnplay);
			else
				window.draw(btnplay);

			if (mouse.x > 582 and mouse.x < 877 and mouse.y>420 and mouse.y < 489)
				window.draw(sbtnhs);
			else
				window.draw(btnhs);


			if (mouse.x > 648 and mouse.x < 815 and mouse.y>570 and mouse.y < 649)
				window.draw(sbtnexit);
			else
				window.draw(btnexit);
			showHighScore(player.GetPosition().x - 700, player.GetPosition().y -50, "ENTER YOUR NAME", window, &font);
			playernametextbox.drawTo(window);

			if (mouse.x > 648 and mouse.x < 815 and mouse.y>570 and mouse.y < 649)
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					window.close();

			if (mouse.x > 582 and mouse.x < 877 and mouse.y>420 and mouse.y < 489)
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					state = -1;

			window.display();
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case Event::Closed:
					window.close();
					break;
				case Event::Resized:
					ResizeView(window, view);
					break;
				case Event::TextEntered:
					playernametextbox.typeOn(event);
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (mouse.x > 559 and mouse.x < 910 and mouse.y>251 and mouse.y < 325){
					sname = playernametextbox.gettext();
					if (sname == "\0")sname = "Unknow";
					Cclock.restart();
					state = 1;
					goto start;
				}
			}
		}
		//*************************************************************************************************
		if (state == 2) {
			sf::Vector2i mouse = sf::Mouse::getPosition(window);
			printf("mousepos x= %.0f y= %.0f\n", (float)mouse.x, (float)mouse.y);
			Gover.setPosition(player.GetPosition().x - 768, player.GetPosition().y - 383);

			backtomenu.setPosition(player.GetPosition().x - 240, player.GetPosition().y + 100);
			exbacktomenu.setPosition(player.GetPosition().x - 240, player.GetPosition().y + 100);

			window.draw(Gover);
			if (mouse.x > 580 and mouse.x < 958 and mouse.y>506 and mouse.y < 650)
				window.draw(backtomenu);
			else
				window.draw(exbacktomenu);
			window.display();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (mouse.x > 580 and mouse.x < 958 and mouse.y>506 and mouse.y < 650) {
					state = 0;
					goto start;
				}
			}
		}
		if (state == 1) {
			cout << sname << endl;
			sf::Vector2f pos = player.GetPosition();
			//printf("%d\n", hpBoss);

			if (player.faceRight == false) {
				pst = 1;
			}
			if (player.faceRight == true) {
				pst = 2;
			}
			//printf("%f\n", pos.y);
			shoot(pos.x, pos.y);
			shot(pos.x, pos.y);
			if (superPower == true) {
				shootsuper(pos.x, pos.y);
				shotsuper(pos.x, pos.y);
			}

			if (player.GetPosition().x > 11200) {
				clockbpn = Bullpn.getElapsedTime().asSeconds();
				clockbpn2 = Bullpn2.getElapsedTime().asSeconds();
				GetBossfight = true;
				startBossStage++;
				if (startBossStage <= 1500) {
					EndBossAction = false;
					if (startBossStage == 1500) {
						EndBossAction = true;
					}
				}
				if (EndBossAction == true) {
					randActBoss();
				}
				if (ActBoss1 == true) {
					ActionBoss1(12200.0f, -1025.0f);
				}
				if (ActBoss2 == true) {
					sample++;
					ActionBoss2();
				}
				if (ActBoss3 == true) {
					ActionBoss3(12000.0f, -1025.0f);
				}
				if (ActBoss4 == true) {
					sample2++;
					ActionBoss4();
				}
			}

			//scoreText.setString(std::to_string(score));

			bg.setPosition(pos.x - 768, pos.y - 384);
			if (superPower == true) {
				superIcon.setPosition(pos.x - 608, pos.y - 270);
			}
			heartbar0.setPosition(pos.x - 698, pos.y - 354);
			heartbar1.setPosition(pos.x - 698, pos.y - 354);
			heartbar2.setPosition(pos.x - 698, pos.y - 354);
			heartbar3.setPosition(pos.x - 698, pos.y - 354);
			Bossheartbar30.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar29.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar28.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar27.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar26.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar25.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar24.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar23.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar22.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar21.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar20.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar19.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar18.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar17.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar16.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar15.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar14.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar13.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar12.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar11.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar10.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar9.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar8.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar7.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar6.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar5.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar4.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar3.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar2.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar1.setPosition(pos.x - 320, pos.y + 300);
			Bossheartbar0.setPosition(pos.x - 320, pos.y + 300);
			//scoreText.setPosition(pos.x + 600, pos.y - 354);
			deltaTime = clock.restart().asSeconds();
			if (deltaTime > 1.0f / 20.0f)
				deltaTime = 1.0f / 20.0f;

			while (window.pollEvent(event))
			{

				switch (event.type)
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
			if (pos.y > 403.5) {
				PlayerHP = 0;
			}
			if (hpBoss <= 0) {
				hpBoss = 0;
			}
			if (startBossStage < 1500) {
				Boss1.UpdateBoss1(deltaTime);
			}
			if (ActBoss1 == true) {
				Boss1.UpdateBoss1(deltaTime);
			}
			if (ActBoss2 == true) {
				Boss2.UpdateBoss1(deltaTime);
			}
			if (ActBoss3 == true) {
				Boss1.UpdateBoss2(deltaTime);
			}
			if (ActBoss4 == true) {
				Boss2.UpdateBoss2(deltaTime);
			}
			sf::Vector2f direction;

			//**************************************************************àªç¤ª¹ºÅêÍ¤**********************************************
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
					if (startBossStage < 1500 || ActBoss1 == true) {
						BoxBossAct1.GetColliderAct1().CheckCollistionbullBoss1(bullet[j].GetCollider(), direction);
					}
					if (ActBoss2 == true)
					{
						BoxBossAct2.GetColliderAct2().CheckCollistionbullBoss2(bullet[j].GetCollider(), direction);
					}
					if (ActBoss3 == true) {
						BoxBossAct3.GetColliderAct1().CheckCollistionbullBoss3(bullet[j].GetCollider(), direction);
					}
					if (ActBoss4 == true) {
						BoxBossAct4.GetColliderAct2().CheckCollistionbullBoss4(bullet[j].GetCollider(), direction);
					}
					monster1.GetCollider().CheckCollistionbull(bullet[j].GetCollider(), direction, 1.0f);
					monster2.GetCollider().CheckCollistionbullhouse(bullet[j].GetCollider(), direction, 1.0f);
					monster3.GetCollider().CheckCollistionbull(bullet[j].GetCollider(), direction, 1.0f);
					monster4.GetCollider().CheckCollistionbull(bullet[j].GetCollider(), direction, 1.0f);
					monster5.GetCollider().CheckCollistionbullhouse(bullet[j].GetCollider(), direction, 1.0f);
					monster6.GetCollider().CheckCollistionbullhouse(bullet[j].GetCollider(), direction, 1.0f);
					monster7.GetCollider().CheckCollistionbullhouse(bullet[j].GetCollider(), direction, 1.0f);
				}

				for (int j = 0; j < 1; j++) {
					platforms[i].GetCollider().CheckCollistionbull(superbullet[j].GetCollider(), direction, 1.0f);
					superbullet[j].GetCollider().CheckCollistionsupbullmon(monster1.GetCollider(), direction);
					superbullet[j].GetCollider().CheckCollistionsupbullmon2(monster2.GetCollider(), direction);
					superbullet[j].GetCollider().CheckCollistionsupbullmon3(monster3.GetCollider(), direction);
					superbullet[j].GetCollider().CheckCollistionsupbullmon4(monster4.GetCollider(), direction);
					superbullet[j].GetCollider().CheckCollistionsupbullmon5(monster5.GetCollider(), direction);
					superbullet[j].GetCollider().CheckCollistionsupbullmon6(monster6.GetCollider(), direction);
					superbullet[j].GetCollider().CheckCollistionsupbullmon7(monster7.GetCollider(), direction);
					if (startBossStage < 1500 || ActBoss1 == true) {
						BoxBossAct1.GetColliderAct1().CheckCollistionsupbullBoss1(superbullet[j].GetCollider(), direction);
					}
					if (ActBoss2 == true)
					{
						BoxBossAct2.GetColliderAct2().CheckCollistionsupbullBoss2(superbullet[j].GetCollider(), direction);
					}
					if (ActBoss3 == true) {
						BoxBossAct3.GetColliderAct1().CheckCollistionsupbullBoss3(superbullet[j].GetCollider(), direction);
					}
					if (ActBoss4 == true) {
						BoxBossAct4.GetColliderAct2().CheckCollistionsupbullBoss4(superbullet[j].GetCollider(), direction);
					}
					monster1.GetCollider().CheckCollistionbull(superbullet[j].GetCollider(), direction, 1.0f);
					monster2.GetCollider().CheckCollistionbullhouse(superbullet[j].GetCollider(), direction, 1.0f);
					monster3.GetCollider().CheckCollistionbull(superbullet[j].GetCollider(), direction, 1.0f);
					monster4.GetCollider().CheckCollistionbull(superbullet[j].GetCollider(), direction, 1.0f);
					monster5.GetCollider().CheckCollistionbullhouse(superbullet[j].GetCollider(), direction, 1.0f);
					monster6.GetCollider().CheckCollistionbullhouse(superbullet[j].GetCollider(), direction, 1.0f);
					monster7.GetCollider().CheckCollistionbullhouse(superbullet[j].GetCollider(), direction, 1.0f);
				}
				if (player.GetPosition().x > 11200) {
					for (int j = 0; j < 3; j++) {
						player.GetCollider().CheckCollistionbulletBossplayer1(bulletboss1[j].GetCollider(), direction, 1.0f);
					}
					for (int j = 0; j < 3; j++) {
						player.GetCollider().CheckCollistionbulletBossplayer2(bulletboss3[j].GetCollider(), direction, 1.0f);
					}
				}
				monster1.GetCollider().CheckCollistionmonplaydog(player.GetCollider(), direction);
				monster2.GetCollider().CheckCollistionmonplayhorse(player.GetCollider(), direction);
				monster3.GetCollider().CheckCollistionmonplaydog(player.GetCollider(), direction);
				monster4.GetCollider().CheckCollistionmonplaydog(player.GetCollider(), direction);
				monster5.GetCollider().CheckCollistionmonplayhorse(player.GetCollider(), direction);
				monster6.GetCollider().CheckCollistionmonplayhorse(player.GetCollider(), direction);
				monster7.GetCollider().CheckCollistionmonplayhorse(player.GetCollider(), direction);
				if (startBossStage < 1500 || ActBoss1 == true) {
					player.GetCollider().CheckCollistionBossplayAct1(BoxBossAct1.GetColliderAct1(), direction);
				}
				if (ActBoss2 == true)
				{
					BoxBossAct2.GetColliderAct2().CheckCollistionBossplayAct2(player.GetCollider(), direction);
				}
				if (ActBoss3 == true) {
					BoxBossAct3.GetColliderAct1().CheckCollistionBossplayAct3(player.GetCollider(), direction);
				}
				if (ActBoss4 == true) {
					BoxBossAct4.GetColliderAct2().CheckCollistionBossplayAct4(player.GetCollider(), direction);
				}
			}
			//*************************************************************************************************************************

			HitTimecount();
			HealTimecount();
			if (chest_dis1 == false) {
				if ((sf::Mouse::isButtonPressed(sf::Mouse::Right)) && chest.GetCollider().CheckCollistionChest(player.GetCollider())) {
					chest.randitem();
					chest_dis1 = true;
				}
			}
			if (chest_dis2 == false) {
				if ((sf::Mouse::isButtonPressed(sf::Mouse::Right)) && chest2.GetCollider().CheckCollistionChest(player.GetCollider())) {
					chest2.randitem();
					chest_dis2 = true;
				}
			}
			if (chest_dis3 == false) {
				if ((sf::Mouse::isButtonPressed(sf::Mouse::Right)) && chest3.GetCollider().CheckCollistionChest(player.GetCollider())) {
					chest3.randitem();
					chest_dis3 = true;
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
			{
				state = 0;
				goto start;
			}
			
			if (PlayerHP > 3) {
				PlayerHP = 3;
			}
			else if (PlayerHP < 0) {
				PlayerHP = 0;
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
			for (int i = 0; i < 1; i++) {
				if (chksup_1[i] == 1) {
					window.draw(superbullet[i].superbullet);
				}
			}
			if (ActBoss1 == true) {
				for (int i = 0; i < 3; i++) {
					if (chkboss_1[i] == 1) {
						window.draw(bulletboss1[i].bulletboss1);
					}
				}
			}
			if (ActBoss3 == true) {
				for (int i = 0; i < 3; i++) {
					if (chkboss_3[i] == 1) {
						window.draw(bulletboss3[i].bulletboss2);
					}
				}
			}

			if (chest_dis1 == false) {
				chest.Draw(window);
			}
			if (chest_dis2 == false) {
				chest2.Draw(window);
			}
			if (chest_dis3 == false) {
				chest3.Draw(window);
			}

			player.Draw(window);
			monster1.Draw(window);
			monster2.Draw(window);
			monster3.Draw(window);
			monster4.Draw(window);
			monster5.Draw(window);
			monster6.Draw(window);
			monster7.Draw(window);
			if (startBossStage < 1500) {
				BoxBossAct1.Draw(window);
				Boss1.Draw(window);
			}
			if (ActBoss1 == true) {
				BoxBossAct1.Draw(window);
				Boss1.Draw(window);
			}
			if (ActBoss2 == true) {
				BoxBossAct2.Draw(window);
				Boss2.Draw(window);
			}
			if (ActBoss3 == true) {
				BoxBossAct3.Draw(window);
				Boss1.Draw(window);
			}
			if (ActBoss4 == true) {
				BoxBossAct4.Draw(window);
				Boss2.Draw(window);
			}

			for (int i = 0; i < platforms.size()-3 ; i++)
			{
					platforms[i].Draw(window);
			}
			if (player.GetPosition().x > 11200) {
				platforms[platforms.size() - 1].Draw(window);
				platforms[platforms.size() - 2].Draw(window);
			}

			if (PlayerHP == 0) {
				window.draw(heartbar0);
			}
			if (PlayerHP == 1) {
				window.draw(heartbar1);
			}
			if (PlayerHP == 2) {
				window.draw(heartbar2);
			}
			if (PlayerHP == 3) {
				window.draw(heartbar3);
			}
			if (player.GetPosition().x > 11200) {
				if (hpBoss == 0) {
					window.draw(Bossheartbar0);
				}
				if (hpBoss == 1) {
					window.draw(Bossheartbar1);
				}
				if (hpBoss == 2) {
					window.draw(Bossheartbar2);
				}
				if (hpBoss == 3) {
					window.draw(Bossheartbar3);
				}
				if (hpBoss == 4) {
					window.draw(Bossheartbar4);
				}
				if (hpBoss == 5) {
					window.draw(Bossheartbar5);
				}
				if (hpBoss == 6) {
					window.draw(Bossheartbar6);
				}
				if (hpBoss == 7) {
					window.draw(Bossheartbar7);
				}
				if (hpBoss == 8) {
					window.draw(Bossheartbar8);
				}
				if (hpBoss == 9) {
					window.draw(Bossheartbar9);
				}
				if (hpBoss == 10) {
					window.draw(Bossheartbar10);
				}
				if (hpBoss == 11) {
					window.draw(Bossheartbar11);
				}
				if (hpBoss == 12) {
					window.draw(Bossheartbar12);
				}
				if (hpBoss == 13) {
					window.draw(Bossheartbar13);
				}
				if (hpBoss == 14) {
					window.draw(Bossheartbar14);
				}
				if (hpBoss == 15) {
					window.draw(Bossheartbar15);
				}
				if (hpBoss == 16) {
					window.draw(Bossheartbar16);
				}
				if (hpBoss == 17) {
					window.draw(Bossheartbar17);
				}
				if (hpBoss == 18) {
					window.draw(Bossheartbar18);
				}
				if (hpBoss == 19) {
					window.draw(Bossheartbar19);
				}
				if (hpBoss == 20) {
					window.draw(Bossheartbar20);
				}
				if (hpBoss == 21) {
					window.draw(Bossheartbar21);
				}
				if (hpBoss == 21) {
					window.draw(Bossheartbar22);
				}
				if (hpBoss == 22) {
					window.draw(Bossheartbar23);
				}
				if (hpBoss == 23) {
					window.draw(Bossheartbar24);
				}
				if (hpBoss == 24) {
					window.draw(Bossheartbar24);
				}
				if (hpBoss == 25) {
					window.draw(Bossheartbar25);
				}
				if (hpBoss == 26) {
					window.draw(Bossheartbar26);
				}
				if (hpBoss == 27) {
					window.draw(Bossheartbar27);
				}
				if (hpBoss == 28) {
					window.draw(Bossheartbar28);
				}
				if (hpBoss == 29) {
					window.draw(Bossheartbar29);
				}
				if (hpBoss == 30) {
					window.draw(Bossheartbar30);
				}

			}
			if (showIcon == true) {
				window.draw(superIcon);
			}
			window.draw(scoreText);
			Time elapsed = Cclock.getElapsedTime();

			mills = int(elapsed.asSeconds() * 100);
			showTime(player.GetPosition().x + 600, player.GetPosition().y - 354, mills, window, &font);
			window.display();
			if (PlayerHP == 0) {
				state = 2;
			}
			if (hpBoss == 0) {
				state = 3;
			}
		}
		if (state == 3) {
			sf::Vector2i mouse = sf::Mouse::getPosition(window);
			printf("mousepos x= %.0f y= %.0f\n", (float)mouse.x, (float)mouse.y);
			Victory.setPosition(player.GetPosition().x - 768, player.GetPosition().y - 383);

			backtomenu.setPosition(player.GetPosition().x - 240, player.GetPosition().y + 100);
			exbacktomenu.setPosition(player.GetPosition().x - 240, player.GetPosition().y + 100);
			sscore = mills;

			userScore.push_back(make_pair(sscore, sname));
			sort(userScore.begin(), userScore.end());


			fopen("Score.txt", "w");
			for (int i = 4; i >= 0; i--)
			{
				strcpy(temp, userScore[i].second.c_str());
				fprintf(fp, "%s %d\n", temp, userScore[i].first);
			}
			fclose(fp);

			window.draw(Victory);

			window.display();
			Sleep(3000);
					state = 0;
					goto start;
		}
	}
	return 0;
}
//============================================================================================================================================

//***********************************************************************¡ÃÐÊØ¹¸ÃÃÁ´Ò*********************************************
void shoot(float x, float y) {
	endd = clock();
	float dif = (float)(endd - start) / CLOCKS_PER_SEC;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&& dif >0.5) {
		for (int i = 0; i < 6; i++) {
			if (chk_1[i] == 0) {
				if (pst == 1) {
					bullet[i].set(x - 20.0f, y);
				}
				if (pst == 2) {
					bullet[i].set(x + 20.0f, y);
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
//***************************************************************************************************************************

//****************************************************************ÂÔ§¡ÃÐÊØ¹¾ÔàÈÉ*********************************************
void shootsuper(float x, float y) {
	endd = clock();
	float dif = (float)(endd - start) / CLOCKS_PER_SEC;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && dif > 0.5) {
		showIcon = false;
		use_superpower = true;
		for (int i = 0; i < 1; i++) {
			if (chksup_1[i] == 0) {
				if (pst == 1) {
					superbullet[i].set(x - 20.0f, y);
				}
				if (pst == 2) {
					superbullet[i].set(x + 20.0f, y);
				}
				pst1sup[i] = pst;
				chksup_1[i] = 1;
				start = clock();
				break;
			}
		}
	}
}

void shotsuper(float x, float y) {
	if (use_superpower == true) {
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
					superPower = false;
					use_superpower = false;
				}
			}
		}
	}
}
//**************************************************************************************************************************

//********************************************************BossAct1*****************************************************************
void ActionBoss1(float x,float y) {
	shootBullBossR1(x, y);
	shotBullBossR1(x,y);
}

void shootBullBossR1(float x, float y) {
	endboss = clock();
	float dif = (float)(endboss - startboss) / CLOCKS_PER_SEC;
	if (clockbpn > 1.5f && dif > 0.5) {
		for (int i = 0; i < 3; i++) {
			if (chkboss_1[i] != 1) {
				bulletboss1[i].set(x -20.0f, y + 400.0f);
				chkboss_1[i] = 1;
				startboss = clock();
				Bullpn.restart();
				break;
			}
		}
		Bullpn.restart();
	}
}

void shotBullBossR1(float x, float y)
{
	for (int i = 0; i < 3; i++) {
		if (chkboss_1[i] == 1) {
			float speed = 2.0f;
			bulletboss1[i].bulletboss1.move(-speed, 0);
			if (bulletboss1[i].bulletboss1.getPosition().x < x - 820) {
				if (bulletboss1[2].bulletboss1.getPosition().x < x - 820) {
					EndBossAction = true;
					ActBoss1 = false;
					Bullpn.restart();
				}
				chkboss_1[i] = 0;
			}
		}
	}
}

void randActBoss()
{
	srand(time(NULL));
	EndBossAction = false;
	randomActBoss = rand() % 4;
	if (randomActBoss == 0) {
		ActBoss1 = true;
	}
	if (randomActBoss == 1) {
		ActBoss2 = true;
	}
	if (randomActBoss == 2) {
		ActBoss3 = true;
	}
	if (randomActBoss == 3) {
		ActBoss4 = true;
	}
}
//****************************************************************************************************************************************

//*************************************************************BossAct2*************************************************************
void ActionBoss2() {

	EndBossAction = false;
	if (sample==750) {
		sample = 0;
		EndBossAction = true;
		ActBoss2 = false;
	}

}
//**********************************************************************************************************************************

//***********************************************************BossAct 3***************************************************************
void ActionBoss3(float x, float y) {
	shootBullBossR3(x, y);
	shotBullBossR3(x, y);
}

void shootBullBossR3(float x, float y) {
	endboss2 = clock();
	float dif = (float)(endboss2 - startboss2) / CLOCKS_PER_SEC;
	if (clockbpn2 > 1.5f && dif > 0.5) {
		for (int i = 0; i < 3; i++) {
			if (chkboss_3[i] != 1) {
				bulletboss3[i].set(x - 20.0f, y + 400.0f);
				chkboss_3[i] = 1;
				startboss2 = clock();
				Bullpn2.restart();
				break;
			}
		}
		Bullpn2.restart();
	}
}

void shotBullBossR3(float x, float y)
{
	for (int i = 0; i < 3; i++) {
		if (chkboss_3[i] == 1) {
			float speed = 2.0f;
			bulletboss3[i].bulletboss2.move(speed, 0);
			if (bulletboss3[i].bulletboss2.getPosition().x > x + 820 ) {
				if (bulletboss3[2].bulletboss2.getPosition().x > x + 820) {
					EndBossAction = true;
					ActBoss3 = false;
					Bullpn2.restart();
				}
				chkboss_3[i] = 0;
			}
		}
	}
}
//***********************************************************************************************************************************

//*************************************************************BossAct 4*************************************************************
void ActionBoss4() {

	EndBossAction = false;
	if (sample2 == 750) {
		sample2 = 0;
		EndBossAction = true;
		ActBoss4 = false;
	}

}
//***********************************************************************************************************************************

//****************************************************Chest*************************************************************************
Chest::Chest(sf::Texture* texture,sf::Vector2f position)
{
	chest.setTexture(texture);
	chest.setSize(sf::Vector2f(72.0f, 45.0f));
	chest.setPosition(sf::Vector2f(position));
}

Chest::~Chest()
{
}

void Chest::randitem()
{
	srand(time(NULL));
	chest_open = true;
	random_item = rand() % 2;
	if (random_item == 0) {
		superPower = true;
		showIcon = true;
	}
	if (random_item == 1) {
		Potion = true;
		UsePotion();
	}
}

void Chest::Draw(sf::RenderWindow& window)
{
	window.draw(chest);
}
//**********************************************************************************************************************************

//********************************************************àªç¤ª¹ÁÍ¹ - ¤¹***************************************************************
bool Collider::CheckCollistionmonplaydog(Collider other, sf::Vector2f& direction)
{

	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetThreeSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetThreeSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX -50.0 < 0.0f && intersectY +30.0 < 0.0f) {
		TM+=1;
		if (hp_canDown == true) {
			if (TM == 1.0f) {
				if (hitchk > 3.5f) {
					PlayerHP--;
				}
			}
			else if (TM > 1.0f) {
				hp_canDown = false;
			}
		}
		return true;
	}
	return false;
}

bool Collider::CheckCollistionmonplayhorse(Collider other, sf::Vector2f& direction)
{

	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetThreeSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetThreeSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX +30.0< 0.0f && intersectY-50.0 < 0.0f) {
		TM += 1;
		if (hp_canDown == true) {
			if (TM == 1.0f) {
				if (hitchk > 3.5f) {
					PlayerHP--;
				}
			}
			else if (TM > 1.0f) {
				hp_canDown = false;
			}
		}
		return true;
	}
	return false;
}

bool Collider::CheckCollistionBossplayAct1(Collider other, sf::Vector2f& direction)
{

	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = (deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	//printf("xxxxx%fxxxxx\n", intersectX);
	//printf("%f\n", intersectY);

	if ((intersectX<-200.0f && intersectX > -400.0f) && intersectY < 100.5f) {
		TM += 1;
		if (hp_canDown == true) {
			if (TM == 1.0f) {
				if (hitchk > 3.5f) {
					PlayerHP--;
				}
			}
			else if (TM > 1.0f) {
				hp_canDown = false;
			}
		}
		return true;
	}
	return false;
}

bool Collider::CheckCollistionBossplayAct3(Collider other, sf::Vector2f& direction)
{

	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = (deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	//printf("xxxxx%fxxxxx\n", intersectX);
	//printf("%f\n", intersectY);
	if ((intersectX < 86.5 && intersectX > -202.1f) && intersectY < 100.5f) {
		TM += 1;
		if (hp_canDown == true) {
			if (TM == 1.0f) {
				if (hitchk > 3.5f) {
					PlayerHP--;
				}
			}
			else if (TM > 1.0f) {
				hp_canDown = false;
			}
		}
		return true;
	}
	return false;
}

bool Collider::CheckCollistionBossplayAct2(Collider other, sf::Vector2f& direction)
{

	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = (deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	//printf("xxxxx%fxxxxx\n", intersectX);
	//printf("%f\n", intersectY);

	if ((intersectX < 145.1f && intersectX >-323.0) && intersectY < 115.1f) {
		TM += 1;
		if (hp_canDown == true) {
			if (TM == 1.0f) {
				if (hitchk > 3.5f) {
					PlayerHP--;
				}
			}
			else if (TM > 1.0f) {
				hp_canDown = false;
			}
		}
		return true;
	}
	return false;
}

bool Collider::CheckCollistionBossplayAct4(Collider other, sf::Vector2f& direction)
{

	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	//printf("xxxxx%fxxxxx\n", intersectX);
	//printf("%f\n", intersectY);

	if ((intersectX < 223.4f && intersectX >-298.6f) && intersectY < 115.5f) {
		TM += 1;
		if (hp_canDown == true) {
			if (TM == 1.0f) {
				if (hitchk > 3.5f) {
					PlayerHP--;
				}
			}
			else if (TM > 1.0f) {
				hp_canDown = false;
			}
		}
		return true;
	}
	return false;
}

bool Collider::CheckCollistionbulletBossplayer1(Collider other, sf::Vector2f& direction, float push)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	//dprintf("xxxxx%fxxxxx\n", intersectX);
	//printf("%f\n", intersectY);

	if (intersectX < -74.5f && intersectY < -47.8f) {
		TM += 1;
		if (hp_canDown == true) {
			if (TM == 1.0f) {
				if (hitchk > 3.5f) {
					PlayerHP--;
				}
			}
			else if (TM > 1.0f) {
				hp_canDown = false;
			}
		}
		other.SetPos(otherPosition.x, 2000.0f);
		return true;
	}
	return false;
}
bool Collider::CheckCollistionbulletBossplayer2(Collider other, sf::Vector2f& direction, float push)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = deltaX - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	//printf("xxxxx%fxxxxx\n", intersectX);
	//printf("%f\n", intersectY);

	if ((intersectX > -246.5f && intersectX < -125.0f) && intersectY < -23.1f) {
		TM += 1;
		if (hp_canDown == true) {
			if (TM == 1.0f) {
				if (hitchk > 3.5f) {
					PlayerHP--;
				}
			}
			else if (TM > 1.0f) {
				hp_canDown = false;
			}
		}
		other.SetPos(otherPosition.x, 2000.0f);
		return true;
	}
	return false;
}

//******************************************************************************************************************************

//**************************************************************äÍà·Á************************************************************
void HitTimecount() {
	if (hp_canDown == false) {
		hitchk = crash.getElapsedTime().asSeconds();
		if (hitchk > 3.5f) {
			crash.restart();
			hp_canDown = true;
			TM = 0;
		}
	}
}

void HealTimecount() {
	if (Potion == false) {
		Potionchk = Heal.getElapsedTime().asSeconds();
		if (Potionchk > 3.5f) {
			Heal.restart();
			Potion = true;
			PTM = 0;
		}
	}
}

void UsePotion() {
	PTM += 1;
	if (Potion == true) {
		if (PTM == 1.0f) {
			if (Potionchk > 2.5f) {
				PlayerHP++;
			}
		}
		else if (PTM > 1.0f) {
			Potion = false;
		}
	}
}
//*********************************************************************************************************************************

//******************************************************************àªç¤ª¹ÁÍ¹*********************************************************
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
		hpmon1 -= 1;
		if (hpmon1 == 0) {
			other.SetPos(0.0f, 1000.0f);
			//score += 100;
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
	/*printf("xxxxx%fxxxxx\n", intersectX);
	printf("%f\n", intersectY);*/

	if (intersectX +70  < 0.0f && intersectY  < 0.0f){
		hpmon2 -= 1;
		if (hpmon2 == 0) {
			other.SetPos(0.0f, 1000.0f);
			//score += 100;
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
		hpmon3 -= 1;
		if (hpmon3 == 0) {
			other.SetPos(0.0f, 1000.0f);
			//score += 100;
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
		hpmon4 -= 1;
		if (hpmon4 == 0) {
			other.SetPos(0.0f, 1000.0f);
			//score += 100;
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

	if (intersectX + 70 < 0.0f && intersectY < 0.0f) {
		hpmon5 -= 1;
		if (hpmon5 == 0) {
			other.SetPos(0.0f, 1000.0f);
			//score += 100;
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

	if (intersectX + 70 < 0.0f && intersectY < 0.0f) {
		hpmon6 -= 1;
		if (hpmon6 == 0) {
			other.SetPos(0.0f, 1000.0f);
			//score += 100;
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

	if (intersectX + 70 < 0.0f && intersectY < 0.0f) {
		hpmon7 -= 1;
		if (hpmon7 == 0) {
			other.SetPos(0.0f, 1000.0f);
		//	score += 100;
		}
		return true;
	}
	return false;
}
bool Collider::CheckCollistionbullBoss1(Collider other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	//printf("xxxxx%fxxxxx\n", intersectX);
	//printf("%f\n", intersectY);

	if ((intersectX < -129.0f ) && (intersectY < 155.1f && intersectY > -40.8f)) {
		hpBoss -= 1;
		if (hpBoss == 0) {
			//score += 1000;
		}
		other.SetPos(0.0f, 2000.0f);
		return true;
	}
	return false;
}
bool Collider::CheckCollistionbullBoss2(Collider other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetFullSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = deltaX - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	//printf("xxxxx%fxxxxx\n", intersectX);
	//printf("%f\n", intersectY);

	if (intersectX > 0.0f && (intersectY < 168.1f && intersectY > -14.0f)) {
		hpBoss -= 1;
		if (hpBoss == 0) {
			//score += 1000;
		}
		other.SetPos(0.0f, 1000.0f);
		return true;
	}
	return false;
}
bool Collider::CheckCollistionbullBoss3(Collider other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	//printf("xxxxx%fxxxxx\n", intersectX);
	//printf("%f\n", intersectY);

	if (intersectX < 58.0f && (intersectY < 155.1f && intersectY > -45.8f)) {
		hpBoss -= 1;
		if (hpBoss == 0) {
		//	score += 1000;
		}
		other.SetPos(0.0f, 1000.0f);
		return true;
	}
	return false;
}
bool Collider::CheckCollistionbullBoss4(Collider other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetFullSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	//printf("xxxxx%fxxxxx\n", intersectX);
	//printf("%f\n", intersectY);

	if (intersectX < -143.0f && (intersectY < 165.1f && intersectY > -40.8f)) {
		hpBoss -= 1;
		if (hpBoss == 0) {
		//	score += 1000;
		}
		other.SetPos(0.0f, 1000.0f);
		return true;
	}
	return false;
}
//*******************************************************************************************************************************************

//**************************************************************àªç¤ª¹ÁÍ¹¡Ñº¡ÃÐÊØ¹¾ÔàÈÉ**********************************************************
bool Collider::CheckCollistionsupbullmon(Collider other, sf::Vector2f& direction)
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
		hpmon1 -= 4;
		if (hpmon1 <= 0) {
			other.SetPos(0.0f, 1000.0f);
		//	score += 100;
		}
		return true;
	}
	return false;
}

bool Collider::CheckCollistionsupbullmon2(Collider other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	//printf("xxxxx%fxxxxx\n", intersectX);
	//printf("%f\n", intersectY);

	if (intersectX + 70 < 0.0f && intersectY < 0.0f) {
		//printf("%d\n", hpmon2);
		hpmon2 -= 4;
		if (hpmon2 <= 0) {
			other.SetPos(0.0f, 1000.0f);
		//	score += 100;
		}
		return true;
	}
	return false;
}
bool Collider::CheckCollistionsupbullmon3(Collider other, sf::Vector2f& direction)
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
		//printf("%d\n", hpmon2);
		hpmon3 -= 4;
		if (hpmon3 <= 0) {
			other.SetPos(0.0f, 1000.0f);
			//score += 100;
		}
		return true;
	}
	return false;
}
bool Collider::CheckCollistionsupbullmon4(Collider other, sf::Vector2f& direction)
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
		//printf("%d\n", hpmon4);
		hpmon4 -= 4;
		if (hpmon4 <= 0) {
			other.SetPos(0.0f, 1000.0f);
		//	score += 100;
		}
		return true;
	}
	return false;
}
bool Collider::CheckCollistionsupbullmon5(Collider other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX + 70 < 0.0f && intersectY < 0.0f) {
		//printf("%d\n", hpmon5);
		hpmon5 -= 4;
		if (hpmon5 <= 0) {
			other.SetPos(0.0f, 1000.0f);
		//	score += 100;
		}
		return true;
	}
	return false;
}
bool Collider::CheckCollistionsupbullmon6(Collider other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX + 70 < 0.0f && intersectY < 0.0f) {
		//printf("%d\n", hpmon6);
		hpmon6 -= 4;
		if (hpmon6 <= 0) {
			other.SetPos(0.0f, 1000.0f);
		//	score += 100;
		}
		return true;
	}
	return false;
}
bool Collider::CheckCollistionsupbullmon7(Collider other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX + 70 < 0.0f && intersectY < 0.0f) {
	//	printf("%d\n", hpmon7);
		hpmon7 -= 4;
		if (hpmon7 <= 0) {
			other.SetPos(0.0f, 1000.0f);
		//	score += 100;
		}
		return true;
	}
	return false;
}
bool Collider::CheckCollistionsupbullBoss1(Collider other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetFullSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	//printf("xxxxx%fxxxxx\n", intersectX);
	//printf("%f\n", intersectY);

	if (intersectX < -150.0f && (intersectY < 138.0f && intersectY > -110.0f)) {
		hpBoss -= 4;
		if (hpBoss <= 0) {
		//	score += 1000;
		}
		other.SetPos(0.0f, 2000.0f);
		return true;
	}
	return false;
}
bool Collider::CheckCollistionsupbullBoss2(Collider other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetFullSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = (deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	//printf("xxxxx%fxxxxx\n", intersectX);
	//printf("%f\n", intersectY);

	if (intersectX > -62.5f && (intersectY < 153.0f && intersectY > -110.0f)) {
		hpBoss -= 4;
		if (hpBoss <= 0) {
		//	score += 1000;
		}
		other.SetPos(0.0f, 1000.0f);
		return true;
	}
	return false;
}
bool Collider::CheckCollistionsupbullBoss3(Collider other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetFullSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	//printf("xxxxx%fxxxxx\n", intersectX);
	//printf("%f\n", intersectY);

	if (intersectX < 68.0f && (intersectY < 137.1f && intersectY > -62.5f)) {
		hpBoss -= 4;
		if (hpBoss <= 0) {
			//score += 1000;
		}
		other.SetPos(0.0f, 1000.0f);
		return true;
	}
	return false;
}
bool Collider::CheckCollistionsupbullBoss4(Collider other, sf::Vector2f& direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetFullSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	//printf("xxxxx%fxxxxx\n", intersectX);
	//printf("%f\n", intersectY);

	if (intersectX < -118.0f && (intersectY < 152.1f && intersectY > -48.0f)) {
		hpBoss -= 4;
		if (hpBoss <= 0) {
			//score += 1000;
		}
		other.SetPos(0.0f, 1000.0f);
		return true;
	}
	return false;
}
//******************************************************************************************************************************************
bool Collider::CheckCollistionChest(Collider other)
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
		return true;
	}
	return false;
}
//********************************************************************************************************************************************

//*****************************************************************Boss2.cpp******************************************************************
Boss2::Boss2(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speedboss = speed;
	rowboss = 0;
	faceRightboss = true;

	bodyBoss.setSize(sf::Vector2f(670.0f, 670.0f));
	bodyBoss.setTexture(texture);
}

Boss2::~Boss2() {}

void Boss2::UpdateBoss1(float deltatimem1) {
	bodyBoss.setPosition(sf::Vector2f(12400.0f, -1140.0f));
	float x = bodyBoss.getPosition().x;
	float y = bodyBoss.getPosition().y;
	sf::Vector2f movement(0.0f, 0.0f);
	faceRightboss = true;
	animation.Update(rowboss, deltatimem1, faceRightboss);
	bodyBoss.setTextureRect(animation.uvRect);
}
void Boss2::UpdateBoss2(float deltatimem1) {
	bodyBoss.setPosition(sf::Vector2f(11350.0f, -1140.0f));
	float x = bodyBoss.getPosition().x;
	float y = bodyBoss.getPosition().y;
	sf::Vector2f movement(0.0f, 0.0f);
	faceRightboss = false;
	animation.Update(rowboss, deltatimem1, faceRightboss);
	bodyBoss.setTextureRect(animation.uvRect);
}

void Boss2::Draw(sf::RenderWindow& window)
{
	window.draw(bodyBoss);
}

//********************************************************************************************************************************************

BossAct1::BossAct1(sf::Vector2f position) 
{
	Bossact1.setSize(sf::Vector2f(270, 470));
	Bossact1.setPosition(sf::Vector2f (position.x,position.y));
	Bossact1.setFillColor(sf::Color::Transparent);
}
void BossAct1::Draw(sf::RenderWindow& window)
{
	window.draw(Bossact1);
}

//*********************************************************************************************************************************************

BossAct2::BossAct2(sf::Vector2f position)
{
	Bossact2.setSize(sf::Vector2f(500, 470));
	Bossact2.setPosition(sf::Vector2f(position.x, position.y));
	Bossact2.setFillColor(sf::Color::Transparent);
}
void BossAct2::Draw(sf::RenderWindow& window)
{
	window.draw(Bossact2);
}
//**********************************************************************************************************************************************