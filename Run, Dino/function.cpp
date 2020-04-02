#pragma once
#include "Header.h"

void get_recs(int Recs[10]) {
	std::ifstream file;
	file.open("records.txt");
	if (!file.is_open()) {
		std::ofstream new_file;
		new_file.open("records.txt");
		new_file << "0 0 0 0 0 0 0 0 0 0";
		new_file.close();
		for (int i = 0; i < 10; i++) {
			Recs[i] = 0;
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			file >> Recs[i];
		}
	}
}

void recs_set(int Recs[10]) {
	std::ofstream file;
	file.open("records.txt");
	for (int i = 0; i < 10; i++) {
		file << Recs[i] << " ";
	}
	file.close();
}

void set_recs(int Recs[10], int score) {
	if (score > Recs[0]) {
		std::ofstream rec_file;
		rec_file.open("records.txt");
		rec_file << score << " " << Recs[0] << " " << Recs[1] << " " << Recs[2] << " " << Recs[3] << " " << Recs[4] << " " << Recs[5] << " "
			<< Recs[6] << " " << Recs[7] << " " << Recs[8];
		rec_file.close();
		Recs[9] = Recs[8];
		Recs[8] = Recs[7];
		Recs[7] = Recs[6];
		Recs[6] = Recs[5];
		Recs[5] = Recs[4];
		Recs[4] = Recs[3];
		Recs[3] = Recs[2];
		Recs[2] = Recs[1];
		Recs[1] = Recs[0];
		Recs[0] = score;
	}
	else if (score > Recs[1]) {
		std::ofstream rec_file;
		rec_file.open("records.txt");
		rec_file << Recs[0] << " " << score << " " << Recs[1] << " " << Recs[2] << " " << Recs[3] << " " << Recs[4] << " " << Recs[5] << " "
			<< Recs[6] << " " << Recs[7] << " " << Recs[8];
		rec_file.close();
		Recs[9] = Recs[8];
		Recs[8] = Recs[7];
		Recs[7] = Recs[6];
		Recs[6] = Recs[5];
		Recs[5] = Recs[4];
		Recs[4] = Recs[3];
		Recs[3] = Recs[2];
		Recs[2] = Recs[1];
		Recs[1] = score;
	}
	else if (score > Recs[2]) {
			std::ofstream rec_file;
			rec_file.open("records.txt");
			rec_file << Recs[0] << " " << Recs[1] << " " << score << " " << Recs[2] << " " << Recs[3] << " " << Recs[4] << " " << Recs[5] << " "
				<< Recs[6] << " " << Recs[7] << " " << Recs[8];
			rec_file.close();
			Recs[9] = Recs[8];
			Recs[8] = Recs[7];
			Recs[7] = Recs[6];
			Recs[6] = Recs[5];
			Recs[5] = Recs[4];
			Recs[4] = Recs[3];
			Recs[3] = Recs[2];
			Recs[2] = score;
		}
		else if (score > Recs[3]) {
			std::ofstream rec_file;
			rec_file.open("records.txt");
			rec_file << Recs[0] << " " << Recs[1] << " " << Recs[2] << " " << score << " " << Recs[3] << " " << Recs[4] << " " << Recs[5] << " "
				<< Recs[6] << " " << Recs[7] << " " << Recs[8];
			rec_file.close();
			Recs[9] = Recs[8];
			Recs[8] = Recs[7];
			Recs[7] = Recs[6];
			Recs[6] = Recs[5];
			Recs[5] = Recs[4];
			Recs[4] = Recs[3];
			Recs[3] = score;

		}
		else if (score > Recs[4]) {
			std::ofstream rec_file;
			rec_file.open("records.txt");
			rec_file << Recs[0] << " " << Recs[1] << " " << Recs[2] << " " << Recs[3] << " " << score << " " << Recs[4] << " "
				<< Recs[5] << " " << Recs[6] << " " << Recs[7] << " " << Recs[8];
			rec_file.close();
			Recs[9] = Recs[8];
			Recs[8] = Recs[7];
			Recs[7] = Recs[6];
			Recs[6] = Recs[5];
			Recs[5] = Recs[4];
			Recs[4] = score;
		}
		else if (score > Recs[5]) {
			std::ofstream rec_file;
			rec_file.open("records.txt");
			rec_file << Recs[0] << " " << Recs[1] << " " << Recs[2] << " " << Recs[3] << " " << Recs[4] << " " << score << " "
				<< Recs[5] << " " << Recs[6] << " " << Recs[7] << " " << Recs[8];
			rec_file.close();
			Recs[9] = Recs[8];
			Recs[8] = Recs[7];
			Recs[7] = Recs[6];
			Recs[6] = Recs[5];
			Recs[5] = score;
		}
		else if (score > Recs[6]) {
			std::ofstream rec_file;
			rec_file.open("records.txt");
			rec_file << Recs[0] << " " << Recs[1] << " " << Recs[2] << " " << Recs[3] << " " << Recs[4] << " " << Recs[5] << " "
				<< score << " " << Recs[6] << " " << Recs[7] << " " << Recs[8];
			rec_file.close();
			Recs[9] = Recs[8];
			Recs[8] = Recs[7];
			Recs[7] = Recs[6];
			Recs[6] = score;
		}
		else if (score > Recs[7]) {
			std::ofstream rec_file;
			rec_file.open("records.txt");
			rec_file << Recs[0] << " " << Recs[1] << " " << Recs[2] << " " << Recs[3] << " " << Recs[4] << " " << Recs[5] << " "
				<< Recs[6] << " " << score << " " << Recs[7] << " " << Recs[8];
			rec_file.close();
			Recs[9] = Recs[8];
			Recs[8] = Recs[7];
			Recs[7] = score;
		}
		else if (score > Recs[8]) {
			std::ofstream rec_file;
			rec_file.open("records.txt");
			rec_file << Recs[0] << " " << Recs[1] << " " << Recs[2] << " " << Recs[3] << " " << Recs[4] << " " << Recs[5] << " "
				<< Recs[6] << " " << Recs[7] << " " << score << " " << Recs[8];
			rec_file.close();
			Recs[9] = Recs[8];
			Recs[8] = score;
		}
		else if (score > Recs[9]) {
			std::ofstream rec_file;
			rec_file.open("records.txt");
			rec_file << Recs[0] << " " << Recs[1] << " " << Recs[2] << " " << Recs[3] << " " << Recs[4] << " " << Recs[5] << " "
				<< Recs[6] << " " << Recs[7] << " " << Recs[8] << " " << score;
			rec_file.close();
			Recs[9] = score;

		}
}

void drawMenu(sf::RenderWindow&window, int Records[10]){
	sf::SoundBuffer move;
	move.loadFromFile("audio/sounds/menu_move.wav");
	sf::Sound moveSound;
	moveSound.setBuffer(move);

	sf::SoundBuffer select;
	select.loadFromFile("audio/sounds/menu_select.wav");
	sf::Sound selectSound;
	selectSound.setBuffer(select);

	bool is_menu = true;
	bool records = false;
	sf::Texture bg_texture;
	bg_texture.loadFromFile("images/menbg.png");
	sf::Sprite bg;
	bg.setTexture(bg_texture);
	sf::Font font;
	font.loadFromFile("font.ttf");
	sf::Texture chsTexture, unchsTexture;
	chsTexture.loadFromFile("images/chosenButton.png");
	unchsTexture.loadFromFile("images/unchosenButton.png");
	sf::Sprite button_sprite_1;
	sf::Sprite button_sprite_2;
	sf::Sprite button_sprite_3;
	sf::Text btn1_text("Start game", font, 30);
	sf::Text btn2_text("Reords tab", font, 30);
	sf::Text btn3_text("Exit game", font, 30);
	Button exit_btn(3, chsTexture, unchsTexture, button_sprite_3, btn3_text);
	Button recrds_btn(2, chsTexture, unchsTexture, button_sprite_2, btn2_text);
	Button strt_game(1, chsTexture, unchsTexture, button_sprite_1, btn1_text);
	strt_game.chose();
	recrds_btn.unchose();
	exit_btn.unchose();
	sf::Text records_text(" ", font, 25);
	records_text.setPosition(sf::Vector2f(280, 260));
	float pressCounter = 300;
	while (is_menu) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (!records) {
			pressCounter--;
			if (pressCounter < 100) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					pressCounter += 300;
					if (strt_game.chosen) {
						selectSound.play();
						is_menu = false;
					}
					else if (recrds_btn.chosen) {
						selectSound.play();
						records = true;
					}
					else {
						window.close();
						selectSound.play();
						is_menu = false;
					}
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					moveSound.play();
					pressCounter += 300;
					if (strt_game.chosen) {
						exit_btn.chose();
						strt_game.unchose();
						recrds_btn.unchose();
					}
					else if (recrds_btn.chosen) {
						strt_game.chose();
						exit_btn.unchose();
						recrds_btn.unchose();
					}
					else {
						recrds_btn.chose();
						exit_btn.unchose();
						strt_game.unchose();
					}
				}

				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					moveSound.play();
					pressCounter += 300;
					if (strt_game.chosen) {
						recrds_btn.chose();
						exit_btn.unchose();
						strt_game.unchose();
					}
					else if (recrds_btn.chosen) {
						exit_btn.chose();
						strt_game.unchose();
						recrds_btn.unchose();
					}
					else {
						strt_game.chose();
						exit_btn.unchose();
						recrds_btn.unchose();
					}
				}
			}
			window.clear();
			window.draw(bg);
			strt_game.drawButton(window);
			recrds_btn.drawButton(window);
			exit_btn.drawButton(window);
			window.display();
		}
		else {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				records = false;
			}

			std::ostringstream Top[10];
			Top[0] << Records[0];
			Top[1] << Records[1];
			Top[2] << Records[2];
			Top[3] << Records[3];
			Top[4] << Records[4];
			Top[5] << Records[5];
			Top[6] << Records[6];
			Top[7] << Records[7];
			Top[8] << Records[8];
			Top[9] << Records[9];

			records_text.setString("1 - " + Top[0].str() + "\n" + "2 - " + Top[1].str() + "\n" + 
				"3 - " + Top[2].str() + "\n" + "4 - " + Top[3].str() + "\n"
				"5 - " + Top[4].str() + "\n" + "6 - " + Top[5].str() + "\n"
				"7 - " + Top[6].str() + "\n" + "8 - " + Top[7].str() + "\n"
				"9 - " + Top[8].str() + "\n" + "10 - " + Top[9].str() + "\n");
			window.clear();
			window.draw(bg);
			window.draw(records_text);
			window.display();
		}
	}
}

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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		return 2;
	}
}