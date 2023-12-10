#include <SDL.h>
#include "Assets.h"
#include "Input.h"
#include "Game.h"

#pragma once

typedef struct Coos_s
{
    int x;
    int y;
} Coos;

int Colone(SDL_Renderer* renderer, Assets* assets, Input* input, int page);

int Menu(SDL_Renderer* renderer, Assets* assets, Input* input, int page);

int MenuIcon(SDL_Renderer* renderer, Assets* assets, Input* input, int page);

int MenuWin(SDL_Renderer* renderer, Assets* assets, Input* input, int page);

int BeginPage(SDL_Renderer* renderer, Assets* assets, Input* input, int page, Game* game);