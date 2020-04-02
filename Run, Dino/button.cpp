#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Button {
	public:
		bool chosen;
		int num;
		float x, y;
		sf::Texture unchosenTexture, choosenTexture;
		sf::Sprite sprite;
		sf::Text text;

		Button(int temp1, sf::Texture temp2, sf::Texture temp3, sf::Sprite temp4, sf::Text temp5) {
			num = temp1;
			unchosenTexture = temp2;
			choosenTexture = temp3;
			sprite = temp4;
			text = temp5;
			x = 260;
			text.setFillColor(sf::Color::Black);

			if (num == 1) {
				chosen = true;
				y = 282;
			}
			else if(num == 2){
				chosen = false;
				y = 412;
			}
			else {
				chosen = false;
				y = 542;
			}
		}
		void chose() {
			chosen = true;
			sprite.setTexture(unchosenTexture);
		}
		void unchose() {
			chosen = false;
			sprite.setTexture(choosenTexture);
		}
		void drawButton(sf::RenderWindow& window) {
			sprite.setPosition(sf::Vector2f(x, y));
			text.setPosition(sf::Vector2f(x + 245, y + 30));
			window.draw(sprite);
			window.draw(text);
		}
};