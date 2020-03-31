#pragma once
#include "Header.h"

int choseCactus() {
	srand(std::time(0));
	switch (1 + (rand()% 4)) {
	case 1: {
		return 1;
	}
	case 2: {
		return 2;
	}
	case 3: {
		return 3;
	}
	case 4: {
		return 4;
	}
	}
	
}


int checkCollision(PowerUp power1, Hero hero) {
	if ((hero.x > power1.x - hero.width) && (hero.x < power1.x + hero.width) && (hero.y < power1.y + hero.height) && (hero.y > power1.y - hero.height))
	{
		return 1;
	}
	else {
		return 0;
	}
}


int checkCactusCollision(Hero hero, Cactus cactus) {
	if ((hero.x > cactus.x - hero.width) && (hero.x < cactus.x + hero.width) && (hero.y < cactus.y + hero.width) && (hero.y > cactus.y - hero.width))
	{
		return 1;
	}
	else {
		return 0;
	}
}

void FuncGameOver(sf::RenderWindow & window, Background back_g, Hero mainHero, bool cts1, bool cts2, bool cts3, bool cts4, 
	Cactus cactus_1, Cactus cactus_2, Cactus cactus_3, Cactus cactus_4, PowerUp powerUp1, PowerUp powerUp2, int score)
{
	std::ostringstream outScore;
	outScore << round(score);
	sf::Font font;
	font.loadFromFile("font.ttf");
	sf::Text gameOverText("", font, 30);
	gameOverText.setPosition(sf::Vector2f(300, 100));
	sf::Text addGameOverText("press ENTER to restart, press ESCAPE to return to menu", font, 20);
	addGameOverText.setPosition(sf::Vector2f(200, 150));
	gameOverText.setString("Game over! your score is: " + outScore.str());

	window.clear();
	window.draw(back_g.sprite_1);
	window.draw(back_g.sprite_2);
	window.draw(mainHero.sprite);
	if (cts1) {
		window.draw(cactus_1.sprite);
	}
	else if (cts2) {
		window.draw(cactus_2.sprite);
	}
	else if (cts3) {
		window.draw(cactus_3.sprite);
	}
	else if (cts4) {
		window.draw(cactus_4.sprite);
	}

	if (!powerUp1.isTaken) {
		window.draw(powerUp1.sprite);
	}

	if (!powerUp2.isTaken) {
		window.draw(powerUp2.sprite);
	}
	window.draw(gameOverText);
	window.draw(addGameOverText);
	window.display();
}

int gameOverContr() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		return 1;
	}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

	//}
}