#include "Dessins.h"

Dessins::Dessins()
{
	Win_Width = 1200;
	Win_Height = 800;
}
Dessins::~Dessins()
{

}

void Dessins::creerText()
{
	if (!font.loadFromFile("AldotheApache.ttf"))
	{
		cout << "Font AldotheApache.ttf cannot be read." << endl;
	}

	pointsJ1.setCharacterSize(24);
	pointsJ1.setFillColor(sf::Color::Red);
	pointsJ1.setPosition(sf::Vector2f(10, Win_Height / 2 - 40));
	pointsJ1.setFont(font);

	pointsJ2.setCharacterSize(24);
	pointsJ2.setFillColor(sf::Color::Blue);
	pointsJ2.setPosition(sf::Vector2f(10, Win_Height / 2 + 40));
	pointsJ2.setFont(font);

	posX_Souris.setCharacterSize(24);
	posX_Souris.setFillColor(sf::Color::White);
	posX_Souris.setPosition(sf::Vector2f(10, 20));
	posX_Souris.setFont(font);
	posY_Souris.setCharacterSize(24);
	posY_Souris.setFillColor(sf::Color::White);
	posY_Souris.setPosition(sf::Vector2f(10, 45));
	posY_Souris.setFont(font);
}

void Dessins::afficherText(sf::RenderWindow& game, Input input, int ptJ1, int ptJ2)
{
	pointsJ1.setString("Actuel :\n" + to_string(ptJ1));
	pointsJ2.setString("Record :\n" + to_string(ptJ2));
	game.draw(pointsJ1);
	game.draw(pointsJ2);
	/*
	posX_Souris.setString(to_string(input.getPosX_Souris(game)));
	posY_Souris.setString(to_string(input.getPosY_Souris(game)));
	game.draw(posX_Souris);
	game.draw(posY_Souris);*/
}

void Dessins::changementLVL(sf::RenderWindow& game, Balle& b)
{
	if (!font.loadFromFile("AldotheApache.ttf"))
	{
		cout << "Font AldotheApache.ttf cannot be read." << endl;
	}

	chgmtLVL.setCharacterSize(96);
	//chgmtLVL.setOrigin(7 * 48 / 2, 48);

	chgmtLVL.setFillColor(sf::Color::Red);
	chgmtLVL.setPosition(Win_Width / 2, Win_Height / 2);
	chgmtLVL.setFont(font);

	string LVL = "Niveau " + to_string(b.getNiveau());

	chgmtLVL.setString(LVL);
	chgmtLVL.setOrigin(chgmtLVL.getGlobalBounds().getSize().x / 2, chgmtLVL.getGlobalBounds().getSize().y / 2);

	game.draw(chgmtLVL);
	game.display();
	b.setChangementLVL_false();
	sf::Time t = seconds(1.5f);
	sf::sleep(t);
	game.clear(Color::Black);
}

void Dessins::perdu(RenderWindow& game, Balle& b)
{
	if (!font.loadFromFile("AldotheApache.ttf"))
	{
		cout << "Font AldotheApache.ttf cannot be read." << endl;
	}

	lose.setCharacterSize(96);
	//lose.setOrigin((5 * 96) / 2, 48);
	lose.setFillColor(sf::Color::Red);
	lose.setPosition(Win_Width / 2, Win_Height / 2);
	lose.setFont(font);
	lose.setString("Perdu ! Nullos...");
	lose.setOrigin(lose.getGlobalBounds().getSize().x / 2, lose.getGlobalBounds().getSize().y / 2);

	game.draw(lose);
	game.display();
	b.setPerdu_false();
	Time t = seconds(2);
	sleep(t);
	game.clear(Color::Black);
}

void Dessins::gagne(RenderWindow& game, Balle& b)
{
	if (!font.loadFromFile("AldotheApache.ttf"))
	{
		cout << "Font AldotheApache.ttf cannot be read." << endl;
	}

	win.setCharacterSize(96);
	//win.setOrigin((5 * 96) / 2, 48);
	win.setFillColor(sf::Color::Red);
	win.setPosition(Win_Width / 2, Win_Height / 2);
	win.setFont(font);
	win.setString("Bien joue, c'est gagne !!");
	win.setOrigin(win.getGlobalBounds().getSize().x / 2, win.getGlobalBounds().getSize().y / 2);

	game.draw(win);
	game.display();
	b.setGagne_false();
	Time t = seconds(6);
	sleep(t);
	game.clear(Color::Black);
}

void Dessins::creerFormes(sf::RenderWindow& game, Balle& b, Raquette& r)
{
	r.créerRaquette(Win_Width / 2, Win_Height - 100);

	b.créerBalle();

	arrow.setRadius(20);
	arrow.setPointCount(3);
	arrow.setOrigin(20, 30);
	arrow.setFillColor(Color::Magenta);
	arrow.setPosition(600, 400);
	arrow.setPosition(b.getPosX(), b.getPosY());
	arrow.setScale(0.5, 4);
}


void Dessins::afficherFormes(sf::RenderWindow& game, Balle& b, Raquette& r, Tabl_briques& tabl)
{
	game.draw(r.getRaquette());

	if (!b.getGame_Start())
	{
		setPosArrow(b);
		game.draw(arrow);
	}


	game.draw(b.getBalle());

	for (int i = 0; i < tabl.getSize(); ++i)
	{
		if (tabl.getBrique(i) != 0)
		{
			game.draw(tabl.getBriqueRect(i));
		}
	}
}

void Dessins::afficherTOUT(sf::RenderWindow& game, Input input, Balle& b, Raquette& r, int ptJ1, int ptJ2, Tabl_briques& tabl)
{
	game.clear(Color::Black);

	if (b.getPerdu())
	{
		//Affichage texte PERDU
		perdu(game, b);

	}
	if (b.getGagne())
	{
		//Affichage texte GAGNE
		gagne(game, b);

	}
	if (b.changementLVL())
	{
		//Affichage texte changement de niveau
		changementLVL(game, b);
	}
		if (!b.getGame_Start())
		{
			b.setPosX(r.getPosX());
			setPosArrow(b);
			setRotationArrow(game, input, b);
		}
		afficher_fondEcran(game);
		afficherText(game, input, ptJ1, ptJ2);
		afficherFormes(game, b, r, tabl);

		game.display();
}


void Dessins::setRotationArrow(sf::RenderWindow& game, Input input, Balle& b)
{
	//Rotation en radiants
	float rotation = std::atan2(input.getPosY_Souris(game) - b.getPosY(), input.getPosX_Souris(game) - b.getPosX());

	float direction = (180 / Pi) * rotation + 90;

	if (direction < -80 || direction > 180)
	{
		direction = -80;
		rotation = (direction - 90) / (180 / Pi);
	}
	if (direction > 80 && direction < 180)
	{
		direction = 80;
		rotation = (direction - 90) / (180 / Pi);
	}
	b.setDirBalle_X(cos(rotation));
	b.setDirBalle_Y(sin(rotation));
	arrow.setRotation(direction);
}

void Dessins::setPosArrow(Balle& b)
{
	arrow.setPosition(b.getPosX(), b.getPosY());
}


void Dessins::fondEcran()
{
	if (!texture.loadFromFile("fond_ecran4.png"))
	{
		std::cout << "La texture du fond d'ecran n'a pas ete correctement chargee \n";
	}
	//texture.setSmooth(true);
	fond_ecran.setTexture(&texture);
	fond_ecran.setSize(Vector2f(1200, 800));
	fond_ecran.setPosition(0, 0);
}

void Dessins::afficher_fondEcran(sf::RenderWindow& game)
{
	game.draw(fond_ecran);
}