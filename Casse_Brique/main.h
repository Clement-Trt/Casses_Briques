#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "Input.h"
#include "Raquette.h"
#include "Balle.h"
#include "Dessins.h"
#include "Brique.h"

using namespace sf;
using namespace std;

void Action();
void UpdateVariables();
void Collisions();