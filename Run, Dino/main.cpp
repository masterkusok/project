#pragma once
#include "Header.h"

int main()
{
	sf::Music music1;
	music1.openFromFile("audio/soundtrack/soundtrack.ogg");
	music1.setVolume(10);
	music1.play();
	music1.setLoop(1);
	Trash mainTrash;

	sf::SoundBuffer jump;
	jump.loadFromFile("audio/sounds/jump_3.wav");
	sf::Sound jumpSound;
	jumpSound.setBuffer(jump);

	sf::SoundBuffer hit;
	hit.loadFromFile("audio/sounds/hit_1.wav");
	sf::Sound hitSound;
	hitSound.setBuffer(hit);

	sf::SoundBuffer powerup1;
	powerup1.loadFromFile("audio/sounds/powerup_1.wav");
	sf::Sound powerup1Sound;
	powerup1Sound.setBuffer(powerup1);
	
	sf::SoundBuffer powerup2;
	powerup2.loadFromFile("audio/sounds/powerup_2.wav");
	sf::Sound powerup2Sound;
	powerup2Sound.setBuffer(powerup2);



	bool gameOver = false, used = false;
	srand(std::time(0));
	sf::Sprite pwrUp1;
	sf::Sprite pwrUp2;
	sf::Texture pwr1;
	sf::Texture pwr2;
	pwr1.loadFromFile("images/powerup2.png");
	pwr2.loadFromFile("images/powerup1.png");
	pwrUp1.setTexture(pwr1);
	pwrUp2.setTexture(pwr2);
	PowerUp powerUp1(pwrUp1, 800);
	PowerUp powerUp2(pwrUp2, 1300);
	float score = 0;

	sf::Font font;
	font.loadFromFile("font.ttf");
	sf::Text scoreText("", font, 30	);
	//scoreText.setColor(sf::Color::Black);
	scoreText.setPosition(500, 100);

	sf::Sprite cactus1;
	sf::Sprite cactus2;
	sf::Sprite cactus3;
	sf::Sprite cactus4;

	sf::Texture c_text1;
	sf::Texture c_text2;
	sf::Texture c_text3;
	sf::Texture c_text4;

	c_text1.loadFromFile("images/cactus1.png");
	c_text2.loadFromFile("images/cactus2.png");
	c_text3.loadFromFile("images/cactus3.png");
	c_text4.loadFromFile("images/cactus4.png");

	Cactus cactus_1(1200.0, 550.0, 80.0, 160.0, c_text1, cactus1);
	Cactus cactus_2(1200.0, 520.0, 200.0, 160.0, c_text2, cactus2);
	Cactus cactus_3(1200.0, 590.0, 100.0, 130.0, c_text3, cactus3);
	Cactus cactus_4(1200.0, 520.0, 120.0, 160.0, c_text4, cactus4);

	bool cts1 = true, cts2 = false, cts3 = false, cts4 = false;

	sf::RenderWindow window(sf::VideoMode(1200, 800), "Run Dino!");
	float frameCount = 0;
	sf::Texture texture;
	texture.loadFromFile("images/hero1-sheet.png");
	sf::Sprite hero;
	sf::Image imagee;
	Hero mainHero(100.0, 550.0, 170.0, 170.0, imagee, texture, hero);
	sf::Clock clock;
	float createCounter = 0;

	sf::Sprite bg_sprite1;
	sf::Sprite bg_sprite2;
	sf::Texture bg_texture1;
	sf::Texture bg_texture2 ;
	bg_texture1.loadFromFile("images/bg.png");
	bg_texture2.loadFromFile("images/bg.png");
	bg_sprite1.setTexture(bg_texture1);
	bg_sprite2.setTexture(bg_texture2);
	Background back_g(bg_sprite1, bg_sprite2);
	bool is_menu = true, pause = false;

	int Top[10];
	get_recs(Top);

	drawMenu(window, Top);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (!gameOver && !pause) {
			used = false;
			float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
			clock.restart();
			time = time / 4000;
			float speed = 3.5 * time;
			frameCount += 0.05 * time;
			mainHero.sprite.setTextureRect(sf::IntRect(170 * int(frameCount), 0, 170, 170));
			if (score > 1000) {
				speed += 1;
			}
			if (score > 3000) {
				speed += 2;
			}
			if (score > 5000) {
				speed += 3;
			}
			std::ostringstream outScore;
			outScore << round(score);

			if (!mainHero.DoubleScore) {
				score = score + (0.05 * time);
				scoreText.setString("score is:  " + outScore.str());
			}
			else {
				score = score + ((0.05 * time) * 2);
				scoreText.setString("score is:  " + outScore.str() + " x2");
			}

			if (frameCount > 7) {
				frameCount -= 7;
			}

			if (!mainHero.isJump) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
					jumpSound.play();
					mainHero.isJump = true;
				}
			}
			else {
				mainHero.jump(time);
			}

			if (createCounter <= 0) {
				int chosing = choseCactus();
				if (chosing == 1) {
					cts1 = true;
					cts2 = false;
					cts3 = false;
					cts4 = false;
					cactus_1.x = 1200 + rand() % 500;

				}
				else if (chosing == 2) {
					cts1 = false;
					cts2 = true;
					cts3 = false;
					cts4 = false;
					cactus_2.x = 1200 + rand() % 500;
				}
				else if (chosing == 3) {
					cts1 = false;
					cts2 = false;
					cts3 = true;
					cts4 = false;
					cactus_3.x = 1200 + rand() % 500;
				}
				else if (chosing == 4) {
					cts1 = false;
					cts2 = false;
					cts3 = false;
					cts4 = true;
					cactus_4.x = 1200 + rand() % 500;
				}
				if (speed < 4) {
					createCounter += 300;
				}
				else if (speed < 6) {
					createCounter += 200;
				}
				else if(speed < 9) {
					createCounter += 130;
				}
				else {
					50;
				}
			}

			if (powerUp1.x == powerUp2.x) {
				powerUp2.x += 10000+(rand()%10000);
			}

			createCounter -= 0.5 * time;
			back_g.MoveBg(speed);

			if (!mainHero.DoubleScore && !mainHero.Undead) {
				powerUp1.Move_power_up(speed);
				powerUp2.Move_power_up(speed);

				if (checkCollision(powerUp1, mainHero)) {
					powerup1Sound.play();
					powerUp1.take();
					mainHero.makeDoubleScore();
					powerUp1.x = -100;
					powerUp1.Move_power_up(speed);
				}

				if (checkCollision(powerUp2, mainHero)) {
					powerup2Sound.play();
					powerUp2.take();
					mainHero.makeUndead();
					powerUp2.x = -100;
					powerUp2.Move_power_up(speed);
				}
			}

			else {
				if (powerUp1.isTaken){
					powerUp1.timer -= 0.5*time;
					if(powerUp1.timer < 0) {
						powerUp1.isTaken = false;
						mainHero.DoubleScore = false;
						powerUp1.timer = powerUp1.length;
					}
				}
				if (powerUp2.isTaken) {
					powerUp2.timer -= 0.5 * time;
					if (powerUp2.timer < 0) {
						powerUp2.isTaken = false;
						mainHero.Undead = false;
						powerUp2.timer = powerUp2.length;
					}
				}
			}

			if (mainHero.Undead) {
				mainHero.sprite.setColor(sf::Color(200, 10, 10));
			}
			else if (mainHero.DoubleScore) {
				mainHero.sprite.setColor(sf::Color(10, 200, 10));
			}
			else {
				mainHero.sprite.setColor(sf::Color(10, 10, 200));
			} 

			window.clear();
			window.draw(back_g.sprite_1);
			window.draw(back_g.sprite_2);
			mainTrash.drawTrash(window, time, speed);
			window.draw(mainHero.sprite);
			if (cts1) {
				if (checkCactusCollision(mainHero, cactus_1)) {
					if (!mainHero.Undead) {
						gameOver = true;
						hitSound.play();
					}
				}
				cactus_1.Movement(speed);
				window.draw(cactus_1.sprite);
			}
			else if (cts2) {
				if (checkCactusCollision(mainHero, cactus_2)) {
					if (!mainHero.Undead) {
						gameOver = true;
						hitSound.play();
					}
				}
				cactus_2.Movement(speed);
				window.draw(cactus_2.sprite);
			}
			else if (cts3) {
				
				if (checkCactusCollision(mainHero, cactus_3)) {
					if (!mainHero.Undead) {
						gameOver = true;
						hitSound.play();
					}
				}
				
				cactus_3.Movement(speed);
				window.draw(cactus_3.sprite);
			}
			else if (cts4) {
				if (checkCactusCollision(mainHero, cactus_4)) {
					if (!mainHero.Undead) {
						gameOver = true;
						hitSound.play();
					}
				}
				cactus_4.Movement(speed);
				window.draw(cactus_4.sprite);
			}

			if (!powerUp1.isTaken) {
				window.draw(powerUp1.sprite);
			}

			if (!powerUp2.isTaken) {
				window.draw(powerUp2.sprite);
			}

			window.draw(scoreText);
			window.display();
		}
		else {
			FuncGameOver(window, back_g, mainHero, cts1, cts2, cts3, cts4, cactus_1, cactus_2, cactus_3, cactus_4, powerUp1, powerUp2, score);
			get_recs(Top);
			if (!used) {
				set_recs(Top, int(score));
				used = true;
			}
			if (gameOverContr() == 1) {
				gameOver = false;
				score = 0;
				back_g.x_1 = 0;
				back_g.x_2 = 2400;
				powerUp1.isTaken = false;
				powerUp2.isTaken = false;
				powerUp1.x = 10000 + (rand() % 10000);;
				powerUp2.x = powerUp1.x;
				mainHero.DoubleScore = false;
			}
			else if (gameOverContr() == 2) {
				gameOver = false;
				score = 0;
				back_g.x_1 = 0;
				back_g.x_2 = 2400;
				powerUp1.isTaken = false;
				powerUp2.isTaken = false;
				powerUp1.x = 10000 + (rand() % 10000);;
				powerUp2.x = powerUp1.x;
				mainHero.DoubleScore = false;
				drawMenu(window, Top);
			}
		}
	}
	return 0;
}