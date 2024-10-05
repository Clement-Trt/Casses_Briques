#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
//#include "main.h"

using namespace sf;

class Raquette
{
public:
	Raquette();
	~Raquette();
	void updateVar();
	void créerRaquette(int posX, int posY);

	void raquetteIA(int bX);

	void moveRight();
	void moveLeft();

	void setPosition(int x);

	void setPosX(int pX);
	void setPosY(int pY);

	RectangleShape getRaquette();
	int getPos_i();
	int setPos_i(int pos_raquette);
	float getPosX();
	float getPosY();
	float getPosXmax();
	float getPosXmin();
	float getPosYmin();
	float getPosYmax();


protected:
	RectangleShape r;
	Texture texture;

	float posX;
	float posY;
	float posXmin;
	float posYmin;
	float posXmax;
	float posYmax;

	int hauteurRaq;
	int largeurRaq;
	int vRaquette;

	int pos_i;
};

