#include "Brique.h"

Brique::Brique()
{
	briquePX = 300;
	briquePY = 400;
	briqueHeight = 25;
	briqueWidth = 200;
	briquePXmax = briquePX + (briqueWidth / 2);
	briquePXmin = briquePX - (briqueWidth / 2);
	briquePYmax = briquePY + (briqueHeight / 2);
	briquePYmin = briquePY - (briqueHeight / 2);
}

Brique::Brique(float posX, float posY)
{
	briquePX = posX;
	briquePY = posY;
	briqueHeight = 25;
	briqueWidth = 200;
	briquePXmax = briquePX + (briqueWidth / 2);
	briquePXmin = briquePX - (briqueWidth / 2);
	briquePYmax = briquePY + (briqueHeight / 2);
	briquePYmin = briquePY - (briqueHeight / 2);
}

Brique::~Brique()
{

}

void Brique::créerBrique()
{
	if (!texture.loadFromFile("brique.png"))
	{
		std::cout << "La texture des brique n'a pas ete correctement chargee \n";
	}
	texture.setSmooth(true);
	b.setSize(sf::Vector2f(briqueWidth, briqueHeight));
	b.setOrigin(briqueWidth / 2, briqueHeight / 2);
	b.setTexture(&texture, true);
	
	b.setPosition(briquePX, briquePY);
	b.setOutlineColor(sf::Color::Black);
	b.setOutlineThickness(1);
}
/*
void Brique::créerBrique(int posX, int posY)
{
	briquePX = posX;
	briquePY = posY;
	briquePXmax = briquePX + (briqueWidth / 2);
	briquePXmin = briquePX - (briqueWidth / 2);
	briquePYmax = briquePY + (briqueHeight / 2);
	briquePYmin = briquePY - (briqueHeight / 2);

	b.setSize(sf::Vector2f(briqueWidth, briqueHeight));
	b.setOrigin(briqueWidth / 2, briqueHeight / 2);
	b.setFillColor(sf::Color(0, 0, 200));
	b.setPosition(briquePX, briquePY);
	b.setOutlineColor(sf::Color::White);
	b.setOutlineThickness(1);
}
*/

sf::RectangleShape Brique::getBrique()
{
	return b;
}

float Brique::getPosX()
{
	return briquePX;
}
float Brique::getPosY()
{
	return briquePY;
}
float Brique::getPosXmax()
{
	return briquePXmax;
}
float Brique::getPosXmin()
{
	return briquePXmin;
}
float Brique::getPosYmax()
{
	return briquePYmax;
}
float Brique::getPosYmin()
{
	return briquePYmin;
}


/***************************************************************************************************************************************************************/


Tabl_briques::Tabl_briques()
{
	niveau1();
}

Tabl_briques::~Tabl_briques()
{
	for (int i(0); i < m_grille.size(); ++i)
	{
		delete m_grille[i];
		m_grille[i] = 0;
	}
}

int Tabl_briques::getSize()
{
	return m_grille.size();
}
int Tabl_briques::getTailleGrille()
{
	int tempSize = m_grille.size();
	return tempSize;
}

float Tabl_briques::getPosX(int i)
{

	return m_grille[i]->getPosX();
}
float Tabl_briques::getPosXmin(int i)
{
	return m_grille[i]->getPosXmin();
}
float Tabl_briques::getPosXmax(int i)
{
	return m_grille[i]->getPosXmax();
}

float Tabl_briques::getPosY(int i)
{
	return m_grille[i]->getPosY();
}
float Tabl_briques::getPosYmin(int i)
{
	return m_grille[i]->getPosYmin();
}
float Tabl_briques::getPosYmax(int i)
{
	return m_grille[i]->getPosYmax();
}



void Tabl_briques::ajouterBrique(float posX, float posY)
{
	m_grille.push_back(new Brique(posX, posY));
}

void Tabl_briques::créerBrique(int i)
{
	return m_grille[i]->créerBrique();
}

void Tabl_briques::casserBrique(int i)
{
	delete m_grille[i];
	m_grille[i] = 0;

}

sf::RectangleShape Tabl_briques::getBriqueRect(int i)
{
	return m_grille[i]->getBrique();
}

Brique* Tabl_briques::getBrique(int i)
{
	return m_grille[i];
}



void Tabl_briques::reinitTabl()
{
	int taille = m_grille.size();
	for (int i = 0; i < taille; ++i)
	{
		m_grille.pop_back();
	}

}

void Tabl_briques::getNiveau(int lvl)
{
	switch (lvl)
	{
	case 1:
		niveau1();
		break;
	case 2:
		niveau2();
		break;
	case 3:
		niveau3();
		break;
	default:
		break;

	}
}


void Tabl_briques::niveau1()
{
	// Creer 4 briques sur une ligne
	int i;
	for (i = 1; i < 5; i++)
	{
		ajouterBrique(i * 250, 300);
		créerBrique(i - 1);
	}

}

void Tabl_briques::niveau2()
{
	// Creer 4 briques sur une ligne, puis 3 en dessous, puis 2 puis 1.
	int i;
	for (i = 1; i < 5; i++)
	{
		ajouterBrique(i * 1200 / 5, 150);
		créerBrique(i - 1);
	}
	for (i = 5; i < 8; i++)
	{
		ajouterBrique((i - 4) * 1200 / 4, 200);
		créerBrique(i - 1);
	}
	for (i = 8; i < 10; i++)
	{
		ajouterBrique((i - 7) * 1200 / 3, 250);
		créerBrique(i - 1);
	}
	for (i = 10; i < 12; i++)
	{
		ajouterBrique((i - 9) * 1200 / 3, 300);
		créerBrique(i - 1);
	}
	for (i = 12; i < 14; i++)
	{
		ajouterBrique((i - 11) * 1200 / 3, 400);
		créerBrique(i - 1);
	}
}

void Tabl_briques::niveau3()
{
	// Creer 4 briques sur une ligne, puis 3 en dessous, puis 4 puis 3.
	int i;
	for (i = 1; i < 5; i++)
	{
		ajouterBrique(i * 1200 / 5, 150);
		créerBrique(i - 1);
	}
	for (i = 5; i < 8; i++)
	{
		ajouterBrique((i - 4) * (1200 / 5) + (1200 / 10), 200);
		créerBrique(i - 1);
	}
	for (i = 8; i < 12; i++)
	{
		ajouterBrique((i - 7) * 1200 / 5, 250);
		créerBrique(i - 1);
	}
	for (i = 12; i < 15; i++)
	{
		ajouterBrique((i - 11) * (1200 / 5) + (1200 / 10), 300);
		créerBrique(i - 1);
	}
	for (i = 15; i < 19; i++)
	{
		ajouterBrique((i - 14) * 1200 / 5, 350);
		créerBrique(i - 1);
	}
	for (i = 19; i < 22; i++)
	{
		ajouterBrique((i - 18) * (1200 / 5) + (1200 / 10), 400);
		créerBrique(i - 1);
	}

}