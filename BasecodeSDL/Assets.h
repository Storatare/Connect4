#pragma once

#include "Settings.h"

typedef struct Assets_s
{
    SDL_Texture *textureExample;
    SDL_Texture* Grille;
    SDL_Texture* Red;
    SDL_Texture* Yellow;
    SDL_Texture* Selec;
    SDL_Texture* Vide;
    SDL_Texture* Tiret;
    SDL_Texture* Restart;
    SDL_Texture* Menu;
    SDL_Texture* MenuPage;
    SDL_Texture* IABlack;
    SDL_Texture* IAWhite;
    SDL_Texture* PlayerBlack;
    SDL_Texture* PlayerWhite;
    SDL_Texture* IAPlayerWhite;
    SDL_Texture* IAPlayerBlack;
    SDL_Texture* Begin;
    SDL_Texture* PlayWhite;
    SDL_Texture* PlayBlack;
    SDL_Texture* StatsWhite;
    SDL_Texture* StatsBlack;
    SDL_Texture* HomeBlack;
    SDL_Texture* HomeWhite;
    SDL_Texture* AIWin;
    SDL_Texture* PWin;
    SDL_Texture* AI1Win;
    SDL_Texture* P1Win;
    SDL_Texture* AI2Win;
    SDL_Texture* P2Win;
    SDL_Texture* Tie;
    SDL_Texture* ExitWhite;
    SDL_Texture* ExitBlack;
    SDL_Texture* Stats;
    SDL_Texture* MenuBlack;
    SDL_Texture* RestartBlack;

} Assets;

Assets *Assets_New(SDL_Renderer *renderer);
void Assets_Delete(Assets *self);
