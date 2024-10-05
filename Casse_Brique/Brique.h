#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Input.h"

class Brique
{
public:

	Brique();
	Brique(float posX, float posY);
	~Brique();

	//void updateVar();
	void créerBrique();
	//void créerBrique(float posX, float posY);

	//void setPosition(int x);

	//void setPosX(int pX);
	//void setPosY(int pY);

	sf::RectangleShape getBrique();
	float getPosX();
	float getPosY();
	float getPosXmax();
	float getPosXmin();
	float getPosYmin();
	float getPosYmax();

protected:

	sf::RectangleShape b;

	Texture texture;

	float briqueHeight;
	float briqueWidth;
	float briquePX;
	float briquePY;
	float briquePXmax;
	float briquePXmin;
	float briquePYmax;
	float briquePYmin;

};

/***************************************************************************************************************************************************************/

class Tabl_briques
{
public:

	Tabl_briques();
	~Tabl_briques();

	void ajouterBrique(float posX, float posY);
	void créerBrique(int i);
	void casserBrique(int i);
	sf::RectangleShape getBriqueRect(int i);
	Brique* getBrique(int i);

	int getSize();
	int getTailleGrille();


	float getPosX(int i);
	float getPosXmin(int i);
	float getPosXmax(int i);

	float getPosY(int i);
	float getPosYmin(int i);
	float getPosYmax(int i);

	void reinitTabl();

	void getNiveau(int lvl);
	void niveau1();
	void niveau2();
	void niveau3();

protected:

	std::vector<Brique*> m_grille;

};
