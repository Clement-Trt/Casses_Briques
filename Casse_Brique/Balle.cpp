#include "Balle.h"

Balle::Balle()
{
	rayonBalle = 15;
	tailleBalle = rayonBalle * 2;
	vballe_INIT = 10;
	vBalle = vballe_INIT;

	Win_Width = 1200;
	Win_Height = 800;

	posX = Win_Width / 2;
	posY = (Win_Height - 100) - (1.5 * tailleBalle);
	posXmin = posX - rayonBalle;
	posYmin = posY - rayonBalle;
	posXmax = posX + rayonBalle;
	posYmax = posY + rayonBalle;

	//Vecteur de direction
	dirBalleX_INIT = 0;
	dirBalleY_INIT = 1;
	dirBalle.x = dirBalleX_INIT;
	dirBalle.y = dirBalleY_INIT;

	if (!colBrique.loadFromFile("AIE.wav"))
	{
		std::cout << "Le son de collision avec les briques n'a pas ete correctement charge \n";
	}
	sonB.setBuffer(colBrique);

	if (!colRaquette.loadFromFile("OUILLE.wav"))
	{
		std::cout << "Le son de collision avec la raquette n'a pas ete correctement charge \n";
	}
	sonR.setBuffer(colRaquette);

	if (!colMur.loadFromFile("HUGH.wav"))
	{
		std::cout << "Le son de collision avec les murs n'a pas ete correctement charge \n";
	}
	sonM.setBuffer(colMur);

	if (!lost.loadFromFile("LOSE.wav"))
	{
		std::cout << "Le son pour avoir perdu n'a pas ete correctement charge \n";
	}
	if (!win.loadFromFile("WIN.wav"))
	{
		std::cout << "Le son pour avoir gagne n'a pas ete correctement charge \n";
	}
	if (!piou.loadFromFile("PIOU.wav"))
	{
		std::cout << "Le son PIOU n'a pas ete correctement charge \n";
	}
	sonPIOU.setBuffer(piou);

	ptJ1 = 0;
	ptJ2 = 0;

	niveau = 1;

	Game_Start = false;
	changement_LVL = true;
	perdu = false;
	gagne = false;

	srand(time(NULL));
}

Balle::~Balle()
{}

void Balle::updateVar()
{
	posXmin = posX - rayonBalle;
	posYmin = posY - rayonBalle;
	posXmax = posX + rayonBalle;
	posYmax = posY + rayonBalle;
}

void Balle::créerBalle()
{
	if (!texture.loadFromFile("ballon2.png"))
	{
		std::cout << "La texture de la balle n'a pas ete correctement chargee \n";
	}
	texture.setSmooth(true);
	b.setRadius(rayonBalle);
	b.setOrigin(Vector2f(rayonBalle, rayonBalle));
	b.setTexture(&texture, true);
	b.setPosition(posX, posY);


}
void Balle::créerBalle(int pX, int pY)
{
	posX = pX;
	posY = pY;
	créerBalle();

}

void Balle::setPosition(int x, int y)
{
	b.setPosition(x, y);
}


void Balle::setPosX(int pX)
{
	posX = pX;
	b.setPosition(posX, posY);
}

void Balle::setPosY(int pY)
{
	posY = pY;
	b.setPosition(posX, posY);
}

void Balle::setDirBalle_X(float i)
{
	dirBalle.x = i;
}
void Balle::setDirBalle_Y(float i)
{
	dirBalle.y = i;
	//std::cout << "dirBalle_Y = " << dirBalle.y << std::endl;
}

void Balle::multiplySpeed(float i)
{
	vBalle *= i;
}

CircleShape Balle::getBalle()
{
	return b;
}

float Balle::getPosX()
{
	return posX;
}
float Balle::getPosY()
{
	return posY;
}
float Balle::getPosXmax()
{
	return posXmax;
}
float Balle::getPosXmin()
{
	return posXmin;
}
float Balle::getPosYmin()
{
	return posYmin;
}
float Balle::getPosYmax()
{
	return posYmax;
}


void Balle::GameStart()
{
	posX += (vBalle * dirBalle.x);
	posY += (vBalle * dirBalle.y);
	setPosition(posX, posY);
	Game_Start = true;
}


void Balle::collisions(Raquette& r)
{
	//Cas1 collisions coté HAUT
	if ((posX) > r.getPosXmin() && posX < r.getPosXmax() && posY < r.getPosY())
	{
		if (posYmax > r.getPosYmin())
		{
			sonPIOU.play();
			dirBalle.y *= -1;
			vBalle += 0.5;
			ptJ1++;
			if (r.getPosX() > r.getPos_i()) // Raquette va vers la droite
			{

				if (dirBalle.x > 0)
				{
					dirBalle.x *= 1.4;
				}
				if (dirBalle.x < 0)
				{
					dirBalle.x *= 0.6;
				}
				std::cout << "TOUCHE " << std::endl << std::endl;
			}

			if (r.getPosX() < r.getPos_i()) // Raquette va vers la gauche
			{
				if (dirBalle.x < 0)
				{
					dirBalle.x *= 1.4;
				}
				if (dirBalle.x > 0)
				{
					dirBalle.x *= 0.6;
				}
				std::cout << "TOUCHE " << std::endl << std::endl;
			}

			if (dirBalle.x > 0.984808)
			{
				dirBalle.x = 0.984808;
			}
			if (dirBalle.x < -0.984808)
			{
				dirBalle.x = -0.984808;
			}

		}
	}

	/*
	//Cas 2 collisions coté BAS
	if ((posX) > r.getPosXmin() && posX < r.getPosXmax() && posY > r.getPosY())
	{
		if (posYmin < r.getPosYmax())
		{
			son.setBuffer(colRaquette);
			son.play();
			dirBalle.y *= -1;
			vBalle += 0.5;
		}
	}*/

	//Cas 3 collisions coté GAUCHE
	if ((posY) > r.getPosYmin() && posY < r.getPosYmax() && posX < r.getPosX())
	{
		if (posXmax > r.getPosXmin())
		{
			sonPIOU.play();
			dirBalle.x *= -1;
			ptJ1++;
		}
	}

	//Cas 4 collisions coté DROIT
	if ((posY) > r.getPosYmin() && posY < r.getPosYmax() && posX > r.getPosX())
	{
		if (posXmax < r.getPosXmax())
		{
			sonPIOU.play();
			dirBalle.x *= -1;
			ptJ1++;
		}
	}
}

void Balle::collisionsBriques(Raquette& r, Input& input, Tabl_briques& tabl, int i)
{
	//Cas1 collisions coté HAUT
	if ((posX) > tabl.getPosXmin(i) && posX < tabl.getPosXmax(i) && posY < tabl.getPosY(i))
	{
		if (posYmax > tabl.getPosYmin(i))
		{
			sonB.play();
			dirBalle.y *= -1;
			tabl.casserBrique(i);
			ptJ1++;
		}
	}

	//Cas 2 collisions coté BAS
	else if ((posX) > tabl.getPosXmin(i) && posX < tabl.getPosXmax(i) && posY > tabl.getPosY(i))
	{
		if (posYmin < tabl.getPosYmax(i))
		{
			sonB.play();
			dirBalle.y *= -1;
			tabl.casserBrique(i);
			ptJ1++;
		}
	}

	//Cas 3 collisions coté GAUCHE
	else if ((posY) > tabl.getPosYmin(i) && posY < tabl.getPosYmax(i) && posX < tabl.getPosX(i))
	{
		if (posXmax > tabl.getPosXmin(i))
		{
			sonR.play();
			dirBalle.x *= -1;
			tabl.casserBrique(i);
			ptJ1++;
		}
	}

	//Cas 4 collisions coté DROIT
	else if ((posY) > tabl.getPosYmin(i) && posY < tabl.getPosYmax(i) && posX > tabl.getPosX(i))
	{
		if (posXmax < tabl.getPosXmax(i))
		{
			sonR.play();
			dirBalle.x *= -1;
			tabl.casserBrique(i);
			ptJ1++;
		}
	}

	int compteur = 0;
	for (int i = 0; i < tabl.getSize(); i++)
	{
		if (tabl.getBrique(i) == 0)
		{
			compteur++;
		}
	}

	if (compteur == tabl.getSize())
	{
		niveau++;
		changement_LVL = true;
		Time t = seconds(0.5f);
		sleep(t);
		restart(r, input, tabl);
	}
}


void Balle::collisionsMurs(Raquette& r, Input& input, Tabl_briques& tabl)
{
	if (posXmax > Win_Width)
	{
		sonM.play();
		dirBalle.x *= -1;
		ptJ1++;
	}
	if (posXmin < 0)
	{
		sonM.play();
		dirBalle.x *= -1;
		ptJ1++;
	}

	if (posYmax > Win_Height)
	{
		son.setBuffer(lost);
		son.play();
		//niveau = 1;
		perdu = true;
		restart(r, input, tabl);
	}
	if (posYmin < 0)
	{
		sonM.play();
		dirBalle.y *= -1;
		ptJ1++;
	}

}

void Balle::restart(Raquette& r, Input& input, Tabl_briques& tabl)
{
	r.setPosX(Win_Width / 2);
	r.setPosY(Win_Height - 100);

	posX = Win_Width / 2;
	posY = r.getPosY() - 1.5 * tailleBalle;
	setPosition(posX, posY);

	dirBalle.x = dirBalleX_INIT;
	dirBalle.y = dirBalleY_INIT;

	vBalle = vballe_INIT;

	tabl.reinitTabl();
	if (niveau > 3)
	{
		son.setBuffer(win);
		son.play();
		niveau = 1;
		gagne = true;
		//Defini le record minimum de rebonds

		if (ptJ2 != 0)
		{
			if (ptJ1 < ptJ2)
			{
				ptJ2 = ptJ1;
			}
		}
		else
		{
			ptJ2 = ptJ1;
		}
		ptJ1 = 0;
	}
	//Redessine le niveau
	tabl.getNiveau(niveau);
	Game_Start = false;
	changement_LVL = true;

	input.setSpaceFalse();
}


bool Balle::getGame_Start()
{
	return Game_Start;
}
bool Balle::setGame_Start(bool i)
{
	return Game_Start = i;
}
bool Balle::changementLVL()
{
	return changement_LVL;
}
bool Balle::getPerdu()
{
	return perdu;
}
bool Balle::getGagne()
{
	return gagne;
}


void Balle::nextLVL(Raquette& r, Input& input, Tabl_briques& tabl)
{
	niveau++;
	restart(r, input, tabl);
}
void Balle::setChangementLVL_false()
{
	changement_LVL = false;
}
void Balle::setPerdu_false()
{
	perdu = false;
}
void Balle::setGagne_false()
{
	gagne = false;
}

int Balle::getPtJ1()
{
	return ptJ1;
}
int Balle::getPtJ2()
{
	return ptJ2;
}
int Balle::getNiveau()
{
	return niveau;
}

