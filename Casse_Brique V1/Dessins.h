#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>
#include "Balle.h"
#include "Raquette.h"
#include "Input.h"
#include "Brique.h"

using namespace std;

class Dessins
{
public:
	Dessins();
	~Dessins();

	void creerText();
	void afficherText(sf::RenderWindow& game, Input input, int ptJ1, int ptJ2);
	void changementLVL(sf::RenderWindow& game, Balle& b);

	void perdu(RenderWindow& game, Balle& b);
	void gagne(RenderWindow& game, Balle& b);

	void creerFormes(sf::RenderWindow& game, Balle& b, Raquette& r);
	void afficherFormes(sf::RenderWindow& game, Balle& b, Raquette& r, Tabl_briques& tabl);

	void setRotationArrow(sf::RenderWindow& game, Input input, Balle& b);
	void setPosArrow(Balle& b);

	void afficherTOUT(sf::RenderWindow& game, Input input, Balle& b, Raquette& r, int ptJ1, int ptJ2, Tabl_briques& tabl);

	void fondEcran();
	void afficher_fondEcran(sf::RenderWindow& game);

protected:

	sf::Texture texture;

	sf::Text pointsJ1, pointsJ2, posX_Souris, posY_Souris;
	sf::Font font;

	sf::Text chgmtLVL, lose, win;

	sf::CircleShape arrow;

	sf::RectangleShape fond_ecran;

	int Win_Width;
	int Win_Height;
	const float Pi = 3.14159265358979323846;;
};

