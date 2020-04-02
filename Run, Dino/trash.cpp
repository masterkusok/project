#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
class Trash
{
public:
	float x, y, counter;
	bool frst, scnd, thrd;
	sf::Sprite sprite1, sprite2, sprite3;
	Trash() {
		srand(std::time(0));
		sf::Texture text1;
		sf::Texture text2;
		sf::Texture text3;
		text1.loadFromFile("trash1.png");
		text1.loadFromFile("trash2.png");
		text1.loadFromFile("trash3.png");
		sprite1.setTexture(text1);
		sprite2.setTexture(text2);
		sprite3.setTexture(text3);
		counter = -10;
		y = 680+rand()% 745;
	}
	void drawTrash(sf::RenderWindow& window, float time, float speed) {
		if (counter > 0) {
			if (!frst && !scnd && !thrd) {
				counter -= time;
				if (counter < 0) {
					int a = rand() % 2;
					if (a == 0) {
						frst = true;
						scnd = false;
						thrd = false;
					}
					else if (a == 1) {
						frst = false;
						scnd = true;
						thrd = false;
					}
					else if (a == 2) {
						frst = false;
						scnd = false;
						thrd = true;
					}
				}
			}
		}
		else {
			if (frst) {
				x -= speed;
				sprite1.setPosition(sf::Vector2f(x, y));
				window.draw(sprite1);
				if (x < -10) {
					counter = 1500 + rand() % 4500;
					x = 1200 + rand() % 2000;
					frst = false;
					scnd = false;
					thrd = false;
				}
			}
			if (scnd) {
				x -= speed;
				sprite2.setPosition(sf::Vector2f(x, y));
				window.draw(sprite2);
				if (x < -10) {
					counter = 1500 + rand() % 4500;
					x = 1200 + rand() % 2000;
					frst = false;
					scnd = false;
					thrd = false;
				}
			}
			if (thrd) {
				x -= speed;
				sprite3.setPosition(sf::Vector2f(x, y));
				window.draw(sprite3);
				if (x < -10) {
					counter = 1500 + rand() % 4500;
					x = 1200 + rand() % 2000;
					frst = false;
					scnd = false;
					thrd = false;
				}
			}
		}
	}
};

class Cloud :public Trash
{

};
