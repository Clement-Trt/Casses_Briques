#include "Raquette.h"

Raquette::Raquette()
{
	posX = 500;
	posY = 500;
	hauteurRaq = 20;
	largeurRaq = 150;
	vRaquette = 15;
	
	posXmin = posX - (largeurRaq / 2);
	posYmin = posY - (hauteurRaq / 2);
	posXmax = posX + (largeurRaq / 2);
	posYmax = posY + (hauteurRaq / 2);

	pos_i = 0;	
}
Raquette::~Raquette()
{}

void Raquette::updateVar()
{
	posXmin = posX - (largeurRaq / 2);
	posYmin = posY - (hauteurRaq / 2);
	posXmax = posX + (largeurRaq / 2);
	posYmax = posY + (hauteurRaq / 2);
}

void Raquette::créerRaquette(int pX, int pY)
{
	posX = pX;
	posY = pY;
	if (!texture.loadFromFile("raquette.png"))
	{
		std::cout << "La texture de la raquette n'a pas ete correctement chargee \n";
	}
	texture.setSmooth(true);
	r.setSize(Vector2f(largeurRaq, hauteurRaq));
	r.setOrigin(Vector2f(largeurRaq / 2, hauteurRaq / 2));
	r.setTexture(&texture, true);
	r.setPosition(posX, posY);
}

void Raquette::raquetteIA(int bX)
{
	if (posX < bX)
	{
		posX += vRaquette;
		if ((posX + (largeurRaq / 2)) > 1200)
		{
			posX = 1200 - largeurRaq / 2;
		}
	}

	if (posX > bX)
	{
		posX -= vRaquette;
		if ((posX - (largeurRaq / 2)) < 0)
		{
			posX = largeurRaq / 2;
		}
	}
	setPosition(posX);
}

void Raquette::moveRight()
{
	posX += vRaquette;
	if ((posX + (largeurRaq / 2)) > 1200)
	{
		posX = 1200 - largeurRaq / 2;
	}
	setPosition(posX);
}
void Raquette::moveLeft()
{
	posX -= vRaquette;
	if ((posX - (largeurRaq / 2)) < 0)
	{
		posX = largeurRaq / 2;
	}
	setPosition(posX);
}



void Raquette::setPosition(int x)
{
	r.setPosition(x, posY);
}
void Raquette::setPosX(int pX)
{
	posX = pX;
	r.setPosition(posX, posY);
}

void Raquette::setPosY(int pY)
{
	posY = pY;
	r.setPosition(posX, posY);
}

RectangleShape Raquette::getRaquette()
{
	return r;
}

int Raquette::getPos_i()
{
	return pos_i;
}
int Raquette::setPos_i(int pos_raquette)
{
	return  pos_i = pos_raquette;
}

float Raquette::getPosX()
{
	return posX;
}
float Raquette::getPosY()
{
	return posY;
}
float Raquette::getPosXmax()
{
	return posXmax;
}
float Raquette::getPosXmin()
{
	return posXmin;
}
float Raquette::getPosYmin()
{
	return posYmin;
}
float Raquette::getPosYmax()
{
	return posYmax;
}