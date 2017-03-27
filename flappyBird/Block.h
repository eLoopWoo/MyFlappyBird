#pragma once
#include <cstdlib>
#include <SFML\Graphics.hpp>
class Block
{
private:

	sf::RectangleShape close;
	sf::RectangleShape open;
	sf::RenderWindow *window;

	float cor_y;
	float cor_x;

	float size_x=30;
	float size_y;

	float size_open=150;
	float cor_open;

	float vel_x=-2;

	float height = 480;
	float width = 640;

	int times =0;

public:
	Block(sf::RenderWindow &win);
	Block(sf::RenderWindow &w, float x);
	~Block();

	void move();

	void restart();

	void print();

	void set_x(float x);
	void set_y(float x);
	void set_open_y(float x);
	void set_vel_x(float x);

	float get_x();
	float get_y();
	float get_open_y();
	float get_vel_x();

	int get_score();
	void set_score(int x);
};

