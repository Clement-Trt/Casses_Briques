#include "main.h"

//Gestion des entrées (clavier, souris)
Input input;

//Affichage fenêtre
RenderWindow game;
Dessins dessin;

int Win_Width = 1200;
int Win_Height = 800;

//Raquettes
Raquette r;

//Balle
Balle b;

//Brique
Tabl_briques tabl;

int main()
{
	ContextSettings options;
	options.antialiasingLevel = 8;

	Music music;
	if (!music.openFromFile("musique3.wav"))
	{
		std::cout << "La musique n'a pas ete correctement chargee \n";
	}

	music.play();

	game.create(VideoMode(Win_Width, Win_Height, 32), "GAME - PONG", Style::Default, options);
	game.setVerticalSyncEnabled(true);

	dessin.fondEcran();
	dessin.creerFormes(game, b, r);
	dessin.creerText();

	while (game.isOpen())
	{
		Event event;

		if (game.pollEvent(event))
		{
			input.inputHandler(event, game);
		}
		Action();
		UpdateVariables();
		Collisions();

		dessin.afficherTOUT(game, input, b, r, b.getPtJ1(), b.getPtJ2(), tabl);

	}
	return 0;
}

void Action()
{
	int posR = r.getPosX();
	r.setPos_i(posR);

	if (input.getButton().up)
	{
		b.restart(r, input, tabl);
	}
	if (!input.getButton().down)
	{
		b.nextLVL(r, input, tabl);
		input.setDownTrue();
	}
	if (input.getButton().left)
	{
		r.moveLeft();
	}
	if (input.getButton().right)
	{
		r.moveRight();
	}
	if (input.getButton().space)
	{
		b.GameStart();
	}
	if (input.getButton().escape)
	{
		game.close();
	}
}

void UpdateVariables()
{
	//Variables Raquette 
	r.updateVar();

	//Variables balle
	b.updateVar();
}

void Collisions()
{
	b.collisions(r);
	b.collisionsMurs(r, input, tabl);

	for (int i = 0; i < tabl.getSize(); i++)
	{

		if (tabl.getBrique(i) != 0)
		{
			b.collisionsBriques(r, input, tabl, i);
		}
	}
}
