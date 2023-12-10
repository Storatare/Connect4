#include "bouton.h"
#include "Assets.h"
#include "Game.h"
#include <SDL.h>
#include <stdio.h>

int BeginPage(SDL_Renderer* renderer, Assets* assets, Input* input, int page, Game* game)
{
	int mouseX = 0, mouseY = 0;
	SDL_GetMouseState(&mouseX, &mouseY);

	if (mouseX >= 220 && mouseX <= 560 && mouseY >= 320 && mouseY <= 430 && page == 0 && Game_GetState(game) == GAME_IN_PROGRESS)
	{
		SDL_FRect PlayerButton;
		PlayerButton.x = 150;
		PlayerButton.y = 250;
		PlayerButton.w = 480;
		PlayerButton.h = 252;
		SDL_RenderCopyF(renderer, assets->PlayBlack, NULL, &PlayerButton);
		if (input->clickLeftPressed) {
			return 1;
		}
	}

	if (mouseX >= 720 && mouseX <= 1060 && mouseY >= 320 && mouseY <= 430 && page == 0 && Game_GetState(game) == GAME_IN_PROGRESS)
	{
		SDL_FRect StatsButton;
		StatsButton.x = 650;
		StatsButton.y = 250;
		StatsButton.w = 480;
		StatsButton.h = 252;
		SDL_RenderCopyF(renderer, assets->StatsBlack, NULL, &StatsButton);
		if (input->clickLeftPressed) {
			return 11;
		}
	}
	/*
	if (mouseX >= 482 && mouseX <= 802 && mouseY >= 245 && mouseY <= 640)
	{
		SDL_FRect IAPlayer;
		IAPlayer.x = 435;
		IAPlayer.y = 180;
		IAPlayer.w = 413;
		IAPlayer.h = 523;
		SDL_RenderCopyF(renderer, assets->IAPlayerBlack, NULL, &IAPlayer);
		if (input->clickLeftPressed) {
			return 2;
		}
	}
	*/
	else if (mouseX >= 470 && mouseX <= 810 && mouseY >= 520 && mouseY <= 635 && page == 0 && Game_GetState(game) == GAME_IN_PROGRESS)
	{
		SDL_FRect Exit;
		Exit.x = 400;
		Exit.y = 450;
		Exit.w = 480;
		Exit.h = 252;
		SDL_RenderCopyF(renderer, assets->ExitBlack, NULL, &Exit);
		if (input->clickLeftPressed) {
			return 100;
		}
	}
	else if (mouseX >= 105 && mouseX <= 425 && mouseY >= 245 && mouseY <= 640 && page == 1 && Game_GetState(game) == GAME_IN_PROGRESS)
	{
		SDL_FRect Player;
		Player.x = 60;
		Player.y = 180;
		Player.w = 413;
		Player.h = 523;
		SDL_RenderCopyF(renderer, assets->PlayerBlack, NULL, &Player);
		if (input->clickLeftPressed) {
			return 2;
		}
	}
	else if (mouseX >= 482 && mouseX <= 802 && mouseY >= 245 && mouseY <= 640 && page == 1 && Game_GetState(game) == GAME_IN_PROGRESS)
	{
		SDL_FRect IAPlayer;
		IAPlayer.x = 435;
		IAPlayer.y = 180;
		IAPlayer.w = 413;
		IAPlayer.h = 523;
		SDL_RenderCopyF(renderer, assets->IAPlayerBlack, NULL, &IAPlayer);
		if (input->clickLeftPressed) {
			return 3;
		}
	}
	else if (mouseX >= 857 && mouseX <= 1177 && mouseY >= 245 && mouseY <= 640 && page == 1 && Game_GetState(game) == GAME_IN_PROGRESS)
	{
		SDL_FRect IA;
		IA.x = 810;
		IA.y = 180;
		IA.w = 413;
		IA.h = 523;
		SDL_RenderCopyF(renderer, assets->IABlack, NULL, &IA);
		if (input->clickLeftPressed) {
			return 4;
		}
	}
	else if ((mouseX > 470 && mouseX <= 810 && mouseY >= 370 && mouseY <= 485) && page == 11)
	{
		SDL_FRect Home;
		Home.x = 400;
		Home.y = 300;
		Home.w = 480;
		Home.h = 252;

		SDL_RenderCopyF(renderer, assets->HomeBlack, NULL, &Home);

		if (input->clickLeftPressed) {
			return 15;
		}

	}
	else if ((mouseX > 470 && mouseX <= 810 && mouseY >= 370 && mouseY <= 485) && page == 99)
	{
		SDL_FRect Home;
		Home.x = 400;
		Home.y = 300;
		Home.w = 480;
		Home.h = 252;
		
		SDL_RenderCopyF(renderer, assets->HomeBlack, NULL, &Home);
		
		if (input->clickLeftPressed) {
			return 15;
		}
		
	}
	else if ((mouseX > 1020 && mouseX <= 1140 && mouseY >= 600 && mouseY <= 700) && page == 99)
	{
		SDL_FRect Restart;
		Restart.x = 740;
		Restart.y = 165;
		Restart.w = 30;
		Restart.h = 7;
		//SDL_SetRenderDrawColor(renderer, 255, 128, 0, 128);
		SDL_RenderCopyF(renderer, assets->Restart, NULL, &Restart);
		if (input->clickLeftPressed) {
			return 11;
		}
	}
	if (mouseX > 1160 && mouseX <= 1260 && mouseY >= 600 && mouseY <= 700 && Game_GetState(game) == GAME_IN_PROGRESS && (page == 2 || page == 3 || page == 4))
	{
		SDL_FRect Menu;
		Menu.x = 1160;
		Menu.y = 600;
		Menu.w = 100;
		Menu.h = 100;
		SDL_RenderCopyF(renderer, assets->MenuBlack, NULL, &Menu);

		if (input->clickLeftPressed) {
			return 15;
		}
	}

	else if (mouseX > 1020 && mouseX <= 1140 && mouseY >= 600 && mouseY <= 700 && Game_GetState(game) == GAME_IN_PROGRESS && (page == 2 || page == 3 || page == 4))
	{
		SDL_FRect Restart;
		Restart.x = 1020;
		Restart.y = 600;
		Restart.w = 120;
		Restart.h = 100;
		SDL_RenderCopyF(renderer, assets->RestartBlack, NULL, &Restart);
		if (input->clickLeftPressed) {
			return 58;
		}
	}
	else
	{
		return 10000;
	}
}
/*
int Menu(SDL_Renderer* renderer, Assets* assets, Input* input, int page)
{
	int mouseX = 0, mouseY = 0;
	SDL_GetMouseState(&mouseX, &mouseY);

	if (mouseX >= 105 && mouseX <= 425 && mouseY >= 245 && mouseY <= 640 && page == 1)
	{
		SDL_FRect Player;
		Player.x = 60;
		Player.y = 180;
		Player.w = 413;
		Player.h = 523;
		SDL_RenderCopyF(renderer, assets->PlayerBlack, NULL, &Player);
		if (input->clickLeftPressed) {
			return 1;
		}
	}
	if (mouseX >= 482 && mouseX <= 802 && mouseY >= 245 && mouseY <= 640 && page == 1)
	{
		SDL_FRect IAPlayer;
		IAPlayer.x = 435;
		IAPlayer.y = 180;
		IAPlayer.w = 413;
		IAPlayer.h = 523;
		SDL_RenderCopyF(renderer, assets->IAPlayerBlack, NULL, &IAPlayer);
		if (input->clickLeftPressed) {
			return 2;
		}
	}
	if (mouseX >= 857 && mouseX <= 1177 && mouseY >= 245 && mouseY <= 640 && page == 1)
	{
		SDL_FRect IA;
		IA.x = 810;
		IA.y = 180;
		IA.w = 413;
		IA.h = 523;
		SDL_RenderCopyF(renderer, assets->IABlack, NULL, &IA);
		if (input->clickLeftPressed) {
			return 3;
		}
	}
	else
	{
		return 10000;
	}
}
*/

int Colone(SDL_Renderer* renderer, Assets* assets, Input* input, int page)
{
	int mouseX = 0, mouseY = 0;
	SDL_GetMouseState(&mouseX, &mouseY);

	if (mouseX >= 138 && mouseX <= 198 && mouseY >= 0 && mouseY <= 720)
	{
		SDL_FRect Tiret;
		Tiret.x = 156;
		Tiret.y = 140;
		Tiret.w = 30;
		Tiret.h = 7;
		SDL_RenderCopyF(renderer, assets->Tiret, NULL, &Tiret);
		if (input->clickLeftPressed) {
			return 1;
		}
	}

	else if (mouseX > 224 && mouseX <= 284 && mouseY >= 0 && mouseY <= 720)
	{
		SDL_FRect Tiret;
		Tiret.x = 242;
		Tiret.y = 140;
		Tiret.w = 30;
		Tiret.h = 7;
		SDL_RenderCopyF(renderer, assets->Tiret, NULL, &Tiret);
		if (input->clickLeftPressed) {
			return 2;
		}
	}
	else if (mouseX > 318 && mouseX <= 378 && mouseY >= 0 && mouseY <= 720)
	{
		SDL_FRect Tiret;
		Tiret.x = 335;
		Tiret.y = 140;
		Tiret.w = 30;
		Tiret.h = 7;
		SDL_RenderCopyF(renderer, assets->Tiret, NULL, &Tiret);
		if (input->clickLeftPressed) {
			return 3;
		}
	}

	else if (mouseX > 410 && mouseX <= 470 && mouseY >= 0 && mouseY <= 720)
	{
		SDL_FRect Tiret;
		Tiret.x = 425;
		Tiret.y = 140;
		Tiret.w = 30;
		Tiret.h = 7;
		SDL_RenderCopyF(renderer, assets->Tiret, NULL, &Tiret);
		if (input->clickLeftPressed) {
			return 4;
		}
	}
	else if (mouseX > 506 && mouseX <= 566 && mouseY >= 0 && mouseY <= 720)
	{
		SDL_FRect Tiret;
		Tiret.x = 522;
		Tiret.y = 140;
		Tiret.w = 30;
		Tiret.h = 7;
		SDL_RenderCopyF(renderer, assets->Tiret, NULL, &Tiret);
		if (input->clickLeftPressed) {
			return 5;
		}
	}
	else if (mouseX > 595 && mouseX <= 655 && mouseY >= 0 && mouseY <= 720)
	{
		SDL_FRect Tiret;
		Tiret.x = 613;
		Tiret.y = 140;
		Tiret.w = 30;
		Tiret.h = 7;
		SDL_RenderCopyF(renderer, assets->Tiret, NULL, &Tiret);
		if (input->clickLeftPressed) {
			return 6;
		}
	}

	else if (mouseX > 685 && mouseX <= 745 && mouseY >= 0 && mouseY <= 720)
	{
		SDL_FRect Tiret;
		Tiret.x = 700;
		Tiret.y = 140;
		Tiret.w = 30;
		Tiret.h = 7;
		SDL_RenderCopyF(renderer, assets->Tiret, NULL, &Tiret);
		if (input->clickLeftPressed) {
			return 7;
		}
	}
	else
	{
	return 10000;
	}
}


int MenuIcon(SDL_Renderer* renderer, Assets* assets, Input* input, int page)
{
	/*
	int mouseX = 0, mouseY = 0;
	SDL_GetMouseState(&mouseX, &mouseY);

	SDL_FRect Menu;
	Menu.x = 1160;
	Menu.y = 600;
	Menu.w = 100;
	Menu.h = 100;
	SDL_RenderCopyF(renderer, assets->Menu, NULL, &Menu);

	SDL_FRect Restart;
	Restart.x = 1020;
	Restart.y = 600;
	Restart.w = 120;
	Restart.h = 100;
	SDL_RenderCopyF(renderer, assets->Restart, NULL, &Restart);


	if (mouseX > 1160 && mouseX <= 1260 && mouseY >= 600 && mouseY <= 700)
	{
		SDL_SetTextureAlphaMod(renderer, 90);
		if (input->clickLeftPressed) {
			return 0;
		}
	}
	
	else if (mouseX > 1020 && mouseX <= 1140 && mouseY >= 600 && mouseY <= 700)
	{
		SDL_RenderCopyF(renderer, assets->Restart, NULL, &Restart);
		if (input->clickLeftPressed) {
			return 11;
		}
	}
	{
		return 10000;
	}	
	*/
}

/*
int MenuWin(SDL_Renderer* renderer, Assets* assets, Input* input, int page)
{
	int mouseX = 0, mouseY = 0;
	SDL_GetMouseState(&mouseX, &mouseY);

	if ((mouseX > 470 && mouseX <= 810 && mouseY >= 370 && mouseY <= 485) && (page == 2 || page == 3 || page == 4))
	{
		SDL_FRect Home;
		Home.x = 400;
		Home.y = 300;
		Home.w = 480;
		Home.h = 252;
		SDL_RenderCopyF(renderer, assets->HomeBlack, NULL, &Home);
		if (input->clickLeftPressed) {
			return 0;
		}
	}
	else if ((mouseX > 1020 && mouseX <= 1140 && mouseY >= 600 && mouseY <= 700) && (page == 2 || page == 3 || page == 4))
	{
		SDL_FRect Restart;
		Restart.x = 740;
		Restart.y = 165;
		Restart.w = 30;
		Restart.h = 7;
		//SDL_SetRenderDrawColor(renderer, 255, 128, 0, 128);
		SDL_RenderCopyF(renderer, assets->Restart, NULL, &Restart);
		if (input->clickLeftPressed) {
			return 11;
		}
	}
	{
		return 10000;
	}
}
*/