#pragma once
#include <SFML\Graphics.hpp>
#include <Windows.h>
class Bird
{
private:

	sf::CircleShape bird;
	sf::RenderWindow * window;
	float cor_y;
	float cor_x;
	float radius = 20;
	int score=0;

	float acceleration= 0.1;

	float vel_x=0;
	float vel_y=0;

	float height=480;
	float width=640;

	sf::Font fot;
	sf::Text tet;
	sf::Font* font = &fot;
	sf::Text* text = &tet;




public:
	Bird(sf::RenderWindow &w);

	~Bird();
	void jump();
	void a_gravity();
	void move();

	void print();

	void bound();


	void set_x(float x);
	void set_y(float y);
	void set_vel_x(float x);

	float get_x();
	float get_y();
	float get_vel_x();


	void set_score(int x);
	int get_score();
	sf::Text* toString();
	
};

