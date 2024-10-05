#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Input
{
	struct Button{bool up, down, left, right, space, escape;};

public:

	Input();
	~Input();
	Button getButton();
	void inputHandler(Event event, RenderWindow& window);
	void setSpaceFalse();
	void setUpFalse();

	void setDownTrue();

	float getPosX_Souris(RenderWindow& window);
	float getPosY_Souris(RenderWindow& window);

protected:

	Button button;

};

