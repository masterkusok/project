#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
class Barrier
{
public:
	double x, y, width, height, strt_x, strt_y;
	sf::Texture texture;
	sf::Sprite sprite;

	void Movement(float speed) {
		x -= speed;
		sprite.setPosition(x, y);
	}

};

class Cactus : public Barrier {
public:
	Cactus(double tmp1, double tmp2, double tmp3, double tmp4, sf::Texture tmp5, sf::Sprite tmp6) {
		x = tmp1;
		y = tmp2;
		strt_x = x;
		strt_y = y;
		width = tmp3;
		height = tmp4;
		sprite = tmp6;
		texture = tmp5;
		sprite.setTexture(texture);
	}
};

