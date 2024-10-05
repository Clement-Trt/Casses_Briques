#pragma once

#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
#include "Raquette.h"
#include "Input.h"
#include "Brique.h"
//#include "Dessins.h"

using namespace sf;

class Balle
{
public:
	Balle();
	~Balle();
	void updateVar();
	void créerBalle();
	void créerBalle(int posX, int posY);

	void collisions(Raquette& r);
	void collisionsMurs(Raquette& r, Input& input, Tabl_briques& tabl);
	void collisionsBriques(Raquette& r, Input& input, Tabl_briques& tabl, int i);

	void setPosition(int x, int y);

	void setPosX(int pX);
	void setPosY(int pY);
	void setDirBalle_X(float i);
	void setDirBalle_Y(float i);

	void multiplySpeed(float i);


	CircleShape getBalle();
	float getPosX();
	float getPosY();
	float getPosXmax();
	float getPosXmin();
	float getPosYmin();
	float getPosYmax();

	int getNiveau();
	int getPtJ1();
	int getPtJ2();

	void restart(Raquette& r, Input& input, Tabl_briques& tabl);
	void GameStart();

	bool setGame_Start(bool i);
	bool getGame_Start();
	bool changementLVL();

	bool getPerdu();
	bool getGagne();

	void nextLVL(Raquette& r, Input& input, Tabl_briques& tabl);
	void setChangementLVL_false();
	void setPerdu_false();
	void setGagne_false();
	


protected:

	float posX;
	float posY;
	float posXmin;
	float posYmin;
	float posXmax;
	float posYmax;

	CircleShape b;
	Texture texture;
	SoundBuffer colBrique, colMur, colRaquette, lost, win, piou;
	Sound son, sonB, sonM, sonR, sonPIOU;

	int rayonBalle;
	int tailleBalle;
	int vballe_INIT;
	float vBalle;

	bool Game_Start;
	bool changement_LVL;
	bool perdu;
	bool gagne;

	//Vecteur de direction
	float dirBalleX_INIT;
	float dirBalleY_INIT;
	Vector2f dirBalle;

	int Win_Width;
	int Win_Height;

	int ptJ1;
	int ptJ2;

	int niveau;
};

