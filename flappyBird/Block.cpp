#include "Block.h"



Block::Block(sf::RenderWindow &win)
{
	window = &win;
	size_y = height;
	cor_x = width;
	cor_open = rand() % ((int)height - (int)size_open);
	cor_y = 0;
	close.setSize(sf::Vector2f(size_x,size_y));
	close.setPosition(cor_x, cor_y);
	open.setSize(sf::Vector2f(size_x, size_open));
	open.setPosition(cor_x, cor_open);
	
	close.setFillColor(sf::Color(155, 155, 255));
	open.setFillColor(sf::Color(0, 0, 0));



}

Block::Block(sf::RenderWindow &win,float x)
{
	window = &win;
	size_y = height;
	cor_x = x;
	cor_open = rand() % ((int)height - (int)size_open);
	cor_y = 0;
	close.setSize(sf::Vector2f(size_x, size_y));
	close.setPosition(cor_x, cor_y);
	open.setSize(sf::Vector2f(size_x, size_open));
	open.setPosition(cor_x, cor_open);

	close.setFillColor(sf::Color(155, 155, 255));
	open.setFillColor(sf::Color(0, 0, 0));
}


Block::~Block()
{
}

void Block::move() {
	if (cor_x > 90) {
		cor_x += vel_x;
		close.setPosition(cor_x, cor_y);
		open.setPosition(cor_x, cor_open);

	}
	else {
		times++;
		restart();
	}
}

void Block::restart() {
	cor_x = width;
	cor_open = rand() % ((int)height-((int)(size_open * 1.8)));
}

void Block::print() {
	(*window).draw(close);
	(*window).draw(open);

}



void Block::set_x(float x) {
	cor_x = x;
}
void Block::set_y(float x) {
	cor_y = x;
}
void Block::set_open_y(float x) {
	cor_open = x;
}
void Block::set_vel_x(float x) {
	vel_x = x;
}

float Block::get_x() {
	return cor_x;
}

float Block::get_y() {
	return cor_y;
}

float Block::get_open_y() {
	return cor_open;
}

float Block::get_vel_x() {
	return vel_x;
}

int Block::get_score() {
	return times;
}

void Block::set_score(int x) {
	times = x;
}