#include "Input.h"

Input::Input()
{
	button.up = button.left = button.right = button.space = button.escape = false;
	button.down = true;
}
Input::~Input() {}

Input::Button Input::getButton()
{
	return button;
}

void Input::setSpaceFalse()
{
	button.space = false;
}
void Input::setUpFalse()
{
	button.up = false;
}
void Input::setDownTrue()
{
	button.down = true;
}


float Input::getPosX_Souris(RenderWindow& window)
{
	float posSouris = Mouse::getPosition(window).x;
	return posSouris;
}
float Input::getPosY_Souris(RenderWindow& window)
{
	float posSouris = Mouse::getPosition(window).y;
	return posSouris;
}

void Input::inputHandler(Event event, RenderWindow& window)
{
	if (event.type == Event::Closed)
	{
		window.close();
	}


	if (event.type == Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case Keyboard::Z:
			button.up = true;
			break;
		case Keyboard::S:
			button.down = true;
			break;
		case Keyboard::Q:
			button.left = true;
			break;
		case Keyboard::D:
			button.right = true;
			break;
		case Keyboard::Space:
			button.space = true;
			break;
		case Keyboard::Escape:
			button.escape = true;
			break;
		default:
			break;
		}
	}

	if (event.type == Event::KeyReleased)
	{
		switch (event.key.code)
		{
			
		case Keyboard::Z:
			button.up = false;
			break;
		case Keyboard::S:
			button.down = false;
			break;
		case Keyboard::Q:
			button.left = false;
			break;
		case Keyboard::D:
			button.right = false;
			break;
			/*
		case Keyboard::Space:
			button.space = false;
			break;
			*/

		case Keyboard::Escape:
			button.escape = false;
			break;
		default:
			break;
		}
	}
}
