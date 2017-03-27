#include <SFML\Graphics.hpp>
#include <iostream>
#include <Bird.h>
#include <Block.h>

Bird *x;
Block *y;
Block *z;


void flappy() {
	while (true) {
		if ((int)(*x).get_x() == (int)(*y).get_x())
			if ( (int)(*x).get_y() - (int)(*y).get_open_y() > 110 || (int)(*y).get_open_y() > (int)(*x).get_y()) {
				(*y).restart();
				(*x).set_score((*x).get_score() * -1);
				printf("Gett");
			}
		if ((int)(*x).get_x() == (int)(*z).get_x())
			if ((int)(*x).get_y() - (int)(*z).get_open_y() > 110 || (int)(*z).get_open_y() > (int)(*x).get_y()) {
				(*z).restart();
				(*x).set_score((*x).get_score() * -1);
				printf("Gett");
			}
		(*x).set_score((*y).get_score() + (*z).get_score());
		(*y).set_score(0);
		(*z).set_score(0);
		(*x).move();
		(*x).bound();
		(*y).move();
		(*z).move();
		Sleep(10);
	}
}
void gravity() {
	(*x).a_gravity();
}


int main() {
	sf::RenderWindow window(sf::VideoMode(640, 480), "FlappyBird Ver1.0");
	Bird player1(window);
	Block player2(window);
	Block player3(window,400);
	y = &player2;
	z = &player3;
	x = &player1;


	sf::Text* string;

	sf::Font fonts;
	fonts.loadFromFile("C:\\abc.ttf");
	// Create a text
	sf::Text texts("Created by eLoopWoo", fonts);
	texts.setCharacterSize(30);
	texts.setStyle(sf::Text::Bold);
	texts.setPosition(sf::Vector2f(300, 400));
	
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)gravity, NULL, NULL, NULL);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)flappy, NULL, NULL, NULL);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (GetAsyncKeyState(VK_UP))
			player1.jump();


		window.clear();

		window.draw(texts);
		player2.print();
		player3.print();
		player1.print();
		string = (*x).toString();
		(*string).setPosition(sf::Vector2f(50, 10));
		window.draw(*string);

		window.display();
	}
	return 0;
}