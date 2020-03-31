#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class PowerUp {
	public:
		sf::Sprite sprite;
		float x, y, width, height, length, timer;;
		bool isTaken, current;
		PowerUp(sf::Sprite tmp1, float tmp2) {
			sprite = tmp1;
			width = 50;
			height = 50;
			length = tmp2;
			isTaken = false;
			timer = length;
			current = false;
			y = 300;
		}

		void take() {
			isTaken = true;
		}

		void Move_power_up(float speed) {
			srand(std::time(0));
			if (!isTaken) {
				if (x < -width) {
					x = 10000 + (rand() % 10000);
				}
				x -= speed;
			}
			sprite.setPosition(sf::Vector2f(x, y));
		}

};