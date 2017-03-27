#include "Bird.h"



Bird::Bird(sf::RenderWindow &w)
{
	window = &w;
	this->cor_y = height / 3;
	this->cor_x = width / 5;
	bird.setRadius(this->radius);
	bird.setPosition(sf::Vector2f(cor_x, cor_y));
	bird.setFillColor(sf::Color(125, 65, 7));


	this->score = 0;


	(*font).loadFromFile("C:\\abc.ttf");
	// Create a text
	(*text).setFont(*font);
	(*text).setCharacterSize(30);
	(*text).setStyle(sf::Text::Bold);
	//(*text).setColor(sf::Color(44,127,255));

}
Bird::~Bird()
{
}

void Bird::jump() {
	if (this->vel_y > 0)
		this->vel_y = 0;
	else
		this->vel_y -= 0.025;
	//bird.setPosition(sf::Vector2f(cor_x, cor_y));
}

void Bird::a_gravity() {
	while (true) {
		this->vel_y += this->acceleration;
		Sleep(10);
	}
}

void Bird::move() {
	this->cor_y += this->vel_y;
	bird.setPosition(sf::Vector2f(cor_x, cor_y));
}

void Bird::print() {
	(*window).draw(bird);
}

void Bird::bound() {
	if (cor_y < 0.5) {
		cor_y = 0.5;
		vel_y = 0;
	}
	if (cor_y > (height * 4) / 5){
		score++;
		cor_y = height / 3;
		vel_y = -3;


	}
}

void Bird::set_x(float x) {
	cor_x = x;
}
void Bird::set_y(float x) {
	cor_y = x;
}

void Bird::set_vel_x(float x) {
	vel_x = x;
}

float Bird::get_vel_x() {
	return vel_x;
}


float Bird::get_x() {
	return cor_x;
}

float Bird::get_y() {
	return cor_y;
}

void Bird::set_score(int x) {
	this->score = get_score() + x;
}
int Bird::get_score() {
	return(this->score);
}

sf::Text* Bird::toString() {
	(*text).setString(std::to_string(get_score()));
	return (text);
}