#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
class Background
{
public:
	float x_1, x_2;
	sf::Sprite sprite_1, sprite_2;

	Background(sf::Sprite tmp1, sf::Sprite tmp2) {
		x_1 =  0;
		x_2 = x_1+2400;
		sprite_1 = tmp1;
		sprite_2 = tmp2;

	};

	void MoveBg(float speed) {
		x_1 -= speed;
		x_2 -= speed;
		if (x_1 < -2400) {
			x_1 += 4800;
		}
		if (x_2 < -2400) {
			x_2 += 4800;
		}
		sprite_1.setPosition(sf::Vector2f(x_1, 0));
		sprite_2.setPosition(sf::Vector2f(x_2, 0));
	}

};
