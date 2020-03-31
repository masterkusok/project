#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Hero {
	public:
		double x, y, width, height, strt_x, strt_y;
		bool isJump, DoubleScore, Undead;
		float jumpCount;
		sf::Texture texture;
		sf::Sprite sprite;
		sf::Image img;
		float frameCount;

		Hero(double tmp1, double tmp2, double tmp3, double tmp4, sf::Image tmp5, sf::Texture tmp6, sf::Sprite tmp7) {
			x = tmp1;
			y = tmp2;
			strt_x = x;
			strt_y = y;
			width = tmp3-60;
			height = tmp4;
			img = tmp5;
			sprite = tmp7;
			texture = tmp6;
			isJump = false;
			DoubleScore = false;
			Undead = false;
			jumpCount = 5.0;
			sprite.setPosition(sf::Vector2f(x, y));
			sprite.setTexture(texture);
			frameCount = 0;
		}

		void jump(float time) {
			int h = int(jumpCount);
			if (isJump) {
				if (h >= -5) {
					if (h < 0) {
						if (y < 550) {
							y += (jumpCount * jumpCount)/2;
						}
						jumpCount -= 0.08 * time;
						sprite.setPosition(x, y);
					}
					else {
						y -= (jumpCount * jumpCount)/2;
						jumpCount-= 0.08*time;
						sprite.setPosition(x, y);
					}
					
				}
				else {
					x = strt_x;
					y = strt_y;
					sprite.setPosition(x, y);
					isJump = false;
					jumpCount = 5;
				}

			}
		}

		void makeUndead() {
			Undead = true;
		}
		void makeDoubleScore() {
			DoubleScore = true;
		}
};
