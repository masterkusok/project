#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include "powerUp.cpp"
#include "bg.cpp"
#include "cactus.cpp"
#include "hero.cpp"
#include "button.cpp"
#include "trash.cpp"
#include <fstream>

void recs_set(int Recs[10]);
void set_recs(int Recs[10], int score);
void get_recs(int Recs[10]);
void drawMenu(sf::RenderWindow& window, int Records[]);
int choseCactus();
int checkCollision(PowerUp power1, Hero hero);
int checkCactusCollision(Hero hero, Cactus cactus);
void FuncGameOver(sf::RenderWindow & window, Background back_g, Hero mainHero, bool cts1, bool cts2, bool cts3, bool cts4, Cactus cactus_1, Cactus cactus_2, Cactus cactus_3, 
Cactus cactus_4, PowerUp powerUp1, PowerUp powerUp2, int score);
int gameOverContr();