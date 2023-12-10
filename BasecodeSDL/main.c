#include "Settings.h"
#include "Common.h"
#include "Input.h"
#include "Assets.h"
#include "Game.h"
#include "AI.h"
#include "bouton.h"

// IMPORTANT :
// Les librairies SDL_TTF et SDL_Mixer sont configurées dans le projet mais ne
// sont pas initialisées.
// Vous devez pour cela modifier les fonctions App_Init() et App_Quit() dans
// le fichier Common.c

int main(int argc, char *argv[])
{
    bool playerDef = true;

    //pannels
    int page = 0;
    int mdj = 0;

    //scores
    int scorePlayer1 = 0;
    int scorePlayer2 = 0;

    Game* game = Game_New();

    //game->state = 2;

    // Initialisation de la SDL
    App_Init(SDL_INIT_VIDEO, IMG_INIT_PNG);

    // Crée la fenêtre et le moteur de rendu
    int sdlFlags = 0;
#ifdef FULLSCREEN
    sdlFlags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
#endif

    SDL_Window *window = SDL_CreateWindow(
        u8"Connect 4 by ACartelot and ADumond", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH, WINDOW_HEIGHT, sdlFlags
    );

    if (!window)
    {
        printf("ERROR - Create window %s\n", SDL_GetError());
        assert(false); abort();
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    SDL_RenderSetLogicalSize(renderer, LOGICAL_WIDTH, LOGICAL_HEIGHT);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    if (!renderer)
    {
        printf("ERROR - Create renderer %s\n", SDL_GetError());
        assert(false); abort();
    }

    // Crée le temps global du jeu
    g_time = Timer_New();
    AssertNew(g_time);

    // Crée le gestionnaire des entrées utilisateur
    Input *input = Input_New();

    // Chargement des assets
    Assets *assets = Assets_New(renderer);

    //--------------------------------------------------------------------------
    // Boucle de rendu

    // Position et vitesse du logo (exemple)
    SDL_FRect Yellow;
    SDL_FRect Red;
    SDL_FRect Vide;
    Yellow.x = 0;
    Yellow.y = 0;
    Red.x = 0;
    Red.y = 0;
    Vide.x = 1000;
    Vide.y = 0;

    Coos** tabCoos = NULL;
    tabCoos = (Coos**)calloc(6, sizeof(Coos*));
    for (int i = 0; i < 6; i++)
        tabCoos[i] = (Coos*)calloc(7, sizeof(Coos));

    for (int i = 0; i < 6; i++) {
        tabCoos[i][0].x = 82;
        tabCoos[i][1].x = 170;
        tabCoos[i][2].x = 263;
        tabCoos[i][3].x = 355;
        tabCoos[i][4].x = 450;
        tabCoos[i][5].x = 540;
        tabCoos[i][6].x = 630;
    }

    for (int i = 0; i < 7; i++) {
        tabCoos[0][i].y = 530;
        tabCoos[1][i].y = 450;
        tabCoos[2][i].y = 370;
        tabCoos[3][i].y = 290;
        tabCoos[4][i].y = 210;
        tabCoos[5][i].y = 130;
    }

    // Définir la couleur du texte
    SDL_Color textColor = { 255, 255, 255, 255 };

    // initialisation de la variable
    int value = 42;
    char text[32] = "aaa";

    SDL_Color White = { 255, 255, 255 };
    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 100);
    
    /*
    TTF_Font* Serif = TTF_OpenFont("arial.ttf", 24);
    if (!Serif) {
        printf("Error: %s\n", TTF_GetError());
        return 1;
    }
    */
    

    while (true)
    {
        //printf("Page : %d\n", page);

        // Met à jour le temps
        Timer_Update(g_time);

        //printf("%f\n", g_time->m_currentTime);

        // Met à jour les entrées
        Input_Update(input);

        if (input->quitPressed)
            break;
        /*
        SDL_Surface* textSurface = TTF_RenderText_Solid(Serif, "aaa", White);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        */

        // Efface le rendu précédent
        SDL_RenderClear(renderer);

        if (Game_GetState(game) == GAME_IN_PROGRESS)
        {
            //Page début
            if (page == 0)
            {
                playerDef = true;

                SDL_FRect Begin;
                Begin.x = 0;
                Begin.y = 0;
                Begin.w = 1280;
                Begin.h = 720;
                SDL_RenderCopyF(renderer, assets->Begin, NULL, &Begin);

                SDL_FRect PlayerButton;
                PlayerButton.x = 150;
                PlayerButton.y = 250;
                PlayerButton.w = 480;
                PlayerButton.h = 252;
                SDL_RenderCopyF(renderer, assets->PlayWhite, NULL, &PlayerButton);

                SDL_FRect StatsButton;
                StatsButton.x = 650;
                StatsButton.y = 250;
                StatsButton.w = 480;
                StatsButton.h = 252;
                SDL_RenderCopyF(renderer, assets->StatsWhite, NULL, &StatsButton);

                SDL_FRect ExitButton;
                ExitButton.x = 400;
                ExitButton.y = 450;
                ExitButton.w = 480;
                ExitButton.h = 252;
                SDL_RenderCopyF(renderer, assets->ExitWhite, NULL, &ExitButton);         

                /*
                SDL_Rect textRect;
                textRect.x = 0;
                textRect.y = 0;
                textRect.w = 100;
                textRect.h = 100;
                SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                */

            }

            //Page menu
            if (page == 1)
            {
                SDL_FRect MenuPage;
                MenuPage.x = 0;
                MenuPage.y = 0;
                MenuPage.w = 1280;
                MenuPage.h = 720;
                SDL_RenderCopyF(renderer, assets->MenuPage, NULL, &MenuPage);

                SDL_FRect Player;
                Player.x = 60;
                Player.y = 180;
                Player.w = 413;
                Player.h = 523;
                SDL_RenderCopyF(renderer, assets->PlayerWhite, NULL, &Player);

                SDL_FRect IAPlayer;
                IAPlayer.x = 435;
                IAPlayer.y = 180;
                IAPlayer.w = 413;
                IAPlayer.h = 523;
                SDL_RenderCopyF(renderer, assets->IAPlayerWhite, NULL, &IAPlayer);

                SDL_FRect IA;
                IA.x = 810;
                IA.y = 180;
                IA.w = 413;
                IA.h = 523;
                SDL_RenderCopyF(renderer, assets->IAWhite, NULL, &IA);
            }

            if (page == 11)
            {
                SDL_FRect StatsPage;
                StatsPage.x = 0;
                StatsPage.y = 0;
                StatsPage.w = 1280;
                StatsPage.h = 720;
                SDL_RenderCopyF(renderer, assets->Stats, NULL, &StatsPage);

                SDL_FRect Home;
                Home.x = 400;
                Home.y = 300;
                Home.w = 480;
                Home.h = 252;
                SDL_RenderCopyF(renderer, assets->HomeWhite, NULL, &Home);
            }

            //Player VS Player
            if (page == 2)
            {
                SDL_FRect Grille;
                Grille.x = 0;
                Grille.y = 0;
                Grille.w = 1280;
                Grille.h = 720;
                SDL_RenderCopyF(renderer, assets->Grille, NULL, &Grille);

                SDL_FRect lampPlayer;
                lampPlayer.x = 965;
                lampPlayer.y = 125;
                lampPlayer.w = 175;
                lampPlayer.h = 175;
                SDL_RenderCopyF(renderer, assets->Red, NULL, &lampPlayer);

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

                for (int i = 0; i < 6; i++) {
                    for (int j = 0; j < 7; j++) {
                        if (game->grid[i][j] == 0) {
                            Vide.x = tabCoos[i][j].x;
                            Vide.y = tabCoos[i][j].y;
                            Vide.w = 175;
                            Vide.h = 175;
                            SDL_RenderCopyF(renderer, assets->Vide, NULL, &Vide);
                        }
                        else if (game->grid[i][j] == 1) {
                            Red.x = tabCoos[i][j].x;
                            Red.y = tabCoos[i][j].y;
                            Red.w = 175;
                            Red.h = 175;
                            SDL_RenderCopyF(renderer, assets->Red, NULL, &Red);
                        }
                        else if (game->grid[i][j] == 2) {
                            Yellow.x = tabCoos[i][j].x;
                            Yellow.y = tabCoos[i][j].y;
                            Yellow.w = 175;
                            Yellow.h = 175;
                            SDL_RenderCopyF(renderer, assets->Yellow, NULL, &Yellow);
                        }
                    }
                }

                int column = -1;
                column = Colone(renderer, assets, input, page) - 1;

                if (playerDef == true)
                {
                    SDL_RenderCopyF(renderer, assets->Red, NULL, &lampPlayer);
                }
                else if (playerDef == false)
                {
                    SDL_RenderCopyF(renderer, assets->Yellow, NULL, &lampPlayer);
                }

                if ((column >= 0 && column <= 6 && game->grid[5][column] == 0) && playerDef == true)
                {
                    Game_PlayTurn(game, column);
                    playerDef = false;
                }
                else if ((column >= 0 && column <= 6 && game->grid[5][column] == 0) && playerDef == false)
                {
                    Game_PlayTurn(game, column);
                    playerDef = true;
                }

            }

            //Player VS IA
            if (page == 3)
            {
                SDL_FRect Grille;
                Grille.x = 0;
                Grille.y = 0;
                Grille.w = 1280;
                Grille.h = 720;
                SDL_RenderCopyF(renderer, assets->Grille, NULL, &Grille);

                SDL_FRect lampPlayer;
                lampPlayer.x = 965;
                lampPlayer.y = 125;
                lampPlayer.w = 175;
                lampPlayer.h = 175;
                SDL_RenderCopyF(renderer, assets->Red, NULL, &lampPlayer);

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

                for (int i = 0; i < 6; i++) {
                    for (int j = 0; j < 7; j++) {
                        if (game->grid[i][j] == 0) {
                            Vide.x = tabCoos[i][j].x;
                            Vide.y = tabCoos[i][j].y;
                            Vide.w = 175;
                            Vide.h = 175;
                            SDL_RenderCopyF(renderer, assets->Vide, NULL, &Vide);
                        }
                        else if (game->grid[i][j] == 1) {
                            Red.x = tabCoos[i][j].x;
                            Red.y = tabCoos[i][j].y;
                            Red.w = 175;
                            Red.h = 175;
                            SDL_RenderCopyF(renderer, assets->Red, NULL, &Red);
                        }
                        else if (game->grid[i][j] == 2) {
                            Yellow.x = tabCoos[i][j].x;
                            Yellow.y = tabCoos[i][j].y;
                            Yellow.w = 175;
                            Yellow.h = 175;
                            SDL_RenderCopyF(renderer, assets->Yellow, NULL, &Yellow);
                        }
                    }
                }

                int column = -1;
                column = Colone(renderer, assets, input, page) - 1;

                if (playerDef == true)
                {
                    SDL_RenderCopyF(renderer, assets->Red, NULL, &lampPlayer);
                }
                else if (playerDef == false)
                {
                    SDL_RenderCopyF(renderer, assets->Yellow, NULL, &lampPlayer);
                }

                if ((column >= 0 && column <= 6 && game->grid[5][column] == 0) && playerDef == true)
                {
                    Game_PlayTurn(game, column);
                    playerDef = false;
                }
                else if (playerDef == false)
                {
                    Game_PlayTurn(game, AI_ComputeMove(game, 2));
                    playerDef = true;
                }

                int bouton = -1;
                bouton = MenuIcon(renderer, assets, input, page);

            }

            //IA VS IA
            if (page == 4)
            {
                SDL_FRect Grille;
                Grille.x = 0;
                Grille.y = 0;
                Grille.w = 1280;
                Grille.h = 720;
                SDL_RenderCopyF(renderer, assets->Grille, NULL, &Grille);

                SDL_FRect lampPlayer;
                lampPlayer.x = 965;
                lampPlayer.y = 125;
                lampPlayer.w = 175;
                lampPlayer.h = 175;
                SDL_RenderCopyF(renderer, assets->Red, NULL, &lampPlayer);

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

                for (int i = 0; i < 6; i++) {
                    for (int j = 0; j < 7; j++) {
                        if (game->grid[i][j] == 0) {
                            Vide.x = tabCoos[i][j].x;
                            Vide.y = tabCoos[i][j].y;
                            Vide.w = 175;
                            Vide.h = 175;
                            SDL_RenderCopyF(renderer, assets->Vide, NULL, &Vide);
                        }
                        else if (game->grid[i][j] == 1) {
                            Red.x = tabCoos[i][j].x;
                            Red.y = tabCoos[i][j].y;
                            Red.w = 175;
                            Red.h = 175;
                            SDL_RenderCopyF(renderer, assets->Red, NULL, &Red);
                        }
                        else if (game->grid[i][j] == 2) {
                            Yellow.x = tabCoos[i][j].x;
                            Yellow.y = tabCoos[i][j].y;
                            Yellow.w = 175;
                            Yellow.h = 175;
                            SDL_RenderCopyF(renderer, assets->Yellow, NULL, &Yellow);
                        }
                    }
                }

                int column = -1;
                column = Colone(renderer, assets, input, page) - 1;

                if (playerDef == true)
                {
                    SDL_RenderCopyF(renderer, assets->Red, NULL, &lampPlayer);
                }
                else if (playerDef == false)
                {
                    SDL_RenderCopyF(renderer, assets->Yellow, NULL, &lampPlayer);
                }

                if (playerDef == true)
                {
                    Game_PlayTurn(game, AI_ComputeMove(game, 1));
                    playerDef = false;
                }
                else if (playerDef == false)
                {
                    Game_PlayTurn(game, AI_ComputeMove(game, 2));
                    playerDef = true;
                }

                int bouton = -1;
                bouton = MenuIcon(renderer, assets, input, page);

            }
            if (page == 100)
            {
                Assets_Delete(assets);
                assets = NULL;

                Input_Delete(input);
                input = NULL;

                Timer_Delete(g_time);
                g_time = NULL;

                SDL_DestroyRenderer(renderer);
                renderer = NULL;

                SDL_DestroyWindow(window);
                window = NULL;

                App_Quit();

                Game_Delete(game);

                return EXIT_SUCCESS;
            }
            if (BeginPage(renderer, assets, input, page, game) == 1)
            {
                page = 1;
            }
            else if (BeginPage(renderer, assets, input, page, game) == 2)
            {
                page = 2;
                mdj = page;
            }
            else if (BeginPage(renderer, assets, input, page, game) == 3)
            {
                page = 3;
                mdj = page;
            }
            else if (BeginPage(renderer, assets, input, page, game) == 4)
            {
                page = 4;
                mdj = page;
            }
            else if (BeginPage(renderer, assets, input, page, game) == 11)
            {
                page = 11;
            }
            else if (BeginPage(renderer, assets, input, page, game) == 15)
            {
                Game_Delete(game);
                game = Game_New();
                page = 0;
                playerDef = true;
            }
            else if (BeginPage(renderer, assets, input, page, game) == 58)
            {
                Game_Delete(game);
                game = Game_New();
                playerDef = true;
            }
            else if (BeginPage(renderer, assets, input, page, game) == 100)
            {
                page = 100;
            }
            SDL_RenderPresent(renderer);
        }

        if (Game_GetState(game) == GAME_P1_WON || Game_GetState(game) == GAME_P2_WON || Game_GetState(game) == GAME_IS_TIED)
        {
            page = 99;
        }

        if (Game_GetState(game) == GAME_P1_WON || Game_GetState(game) == GAME_P2_WON || Game_GetState(game) == GAME_IS_TIED)
        {
            if (page == 99)
            {
                SDL_FRect Page;
                Page.x = 0;
                Page.y = 0;
                Page.w = 1280;
                Page.h = 720;

                SDL_FRect Home;
                Home.x = 400;
                Home.y = 300;
                Home.w = 480;
                Home.h = 252;

                SDL_FRect Restart;
                Restart.x = 580;
                Restart.y = 550;
                Restart.w = 120;
                Restart.h = 100;

                if (Game_GetState(game) == GAME_P1_WON)
                {
                    if (mdj == 2)
                    {
                        SDL_RenderCopyF(renderer, assets->P1Win, NULL, &Page);
                        SDL_RenderCopyF(renderer, assets->HomeWhite, NULL, &Home);
                    }
                    else if (mdj == 3)
                    {
                        SDL_RenderCopyF(renderer, assets->PWin, NULL, &Page);
                        SDL_RenderCopyF(renderer, assets->HomeWhite, NULL, &Home);
                    }
                    else if (mdj == 4)
                    {
                        SDL_RenderCopyF(renderer, assets->AI1Win, NULL, &Page);
                        SDL_RenderCopyF(renderer, assets->HomeWhite, NULL, &Home);
                    }
                }
                else if (Game_GetState(game) == GAME_P2_WON)
                {
                    if (mdj == 2)
                    {
                        SDL_RenderCopyF(renderer, assets->P2Win, NULL, &Page);
                        SDL_RenderCopyF(renderer, assets->HomeWhite, NULL, &Home);
                    }
                    else if (mdj == 3)
                    {
                        SDL_RenderCopyF(renderer, assets->AIWin, NULL, &Page);
                        SDL_RenderCopyF(renderer, assets->HomeWhite, NULL, &Home);
                    }
                    else if (mdj == 4)
                    {
                        SDL_RenderCopyF(renderer, assets->AI2Win, NULL, &Page);
                        SDL_RenderCopyF(renderer, assets->HomeWhite, NULL, &Home);
                    }
                }
                else if (Game_GetState(game) == GAME_IS_TIED)
                {
                    if (mdj == 2 || mdj == 3 || mdj == 4)
                    {
                        SDL_RenderCopyF(renderer, assets->Tie, NULL, &Page);
                        SDL_RenderCopyF(renderer, assets->HomeWhite, NULL, &Home);
                    }
                }

                if (BeginPage(renderer, assets, input, page, game) == 15)
                {
                    Game_Delete(game);
                    game = Game_New();
                    page = 0;
                    game->state = GAME_IN_PROGRESS;
                }
                SDL_RenderPresent(renderer);
            }
        }
    }
    //--------------------------------------------------------------------------
    // Libération de la mémoire

    Assets_Delete(assets);
    assets = NULL;

    Input_Delete(input);
    input = NULL;

    Timer_Delete(g_time);
    g_time = NULL;

    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    App_Quit();

    Game_Delete(game);

    return EXIT_SUCCESS;
}