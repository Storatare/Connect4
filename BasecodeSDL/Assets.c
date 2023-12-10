#include "Assets.h"

typedef struct TextureSpec_s
{
    SDL_Texture **ptr;
    char *path;
} TextureSpec;

Assets *Assets_New(SDL_Renderer *renderer)
{
    Assets *self = (Assets *)calloc(1, sizeof(Assets));
    AssertNew(self);

    // -------------------------------------------------------------------------
    // Chargement des textures

    TextureSpec texSpecs[] = {
        { &self->Grille, "../Assets/Grille.png" },
        { &self->Red, "../Assets/Red.png" },
        { &self->Yellow, "../Assets/Yellow.png" },
        { &self->Selec, "../Assets/Selec.png" },
        { &self->Vide, "../Assets/Vide.png" },
        { &self->Tiret, "../Assets/Tiret.png" },
        { &self->Restart, "../Assets/restart.png" },
        { &self->Menu, "../Assets/menu.png" },
        { &self->IAWhite, "../Assets/IAWhite.png" },
        { &self->IABlack, "../Assets/IABlack.png" },
        { &self->IAPlayerWhite, "../Assets/IAPlayerWhite.png" },
        { &self->IAPlayerBlack, "../Assets/IAPlayerBlack.png" },
        { &self->PlayerWhite, "../Assets/PlayerWhite.png" },
        { &self->PlayerBlack, "../Assets/PlayerBlack.png" },
        { &self->MenuPage, "../Assets/MenuPage.png" },
        { &self->Begin, "../Assets/Begin.png" },
        { &self->PlayBlack, "../Assets/PlayBlack.png" },
        { &self->PlayWhite, "../Assets/PlayWhite.png" },
        { &self->StatsBlack, "../Assets/StatsBlack.png" },
        { &self->StatsWhite, "../Assets/StatsWhite.png" },
        { &self->AIWin, "../Assets/AIWin.png" },
        { &self->PWin, "../Assets/PWin.png" },
        { &self->AI1Win, "../Assets/AI1Win.png" },
        { &self->P1Win, "../Assets/P1Win.png" },
        { &self->AI2Win, "../Assets/AI2Win.png" },
        { &self->P2Win, "../Assets/P2Win.png" },
        { &self->HomeBlack, "../Assets/HomeBlack.png" },
        { &self->HomeWhite, "../Assets/HomeWhite.png" },
        { &self->Tie, "../Assets/Tie.png" },
        { &self->ExitBlack, "../Assets/ExitBlack.png" },
        { &self->ExitWhite, "../Assets/ExitWhite.png" },
        { &self->Stats, "../Assets/Stats.png" },
        { &self->MenuBlack, "../Assets/MenuBlack.png" },
        { &self->RestartBlack, "../Assets/RestartBlack.png" },
    };
    int texSpecCount = sizeof(texSpecs) / sizeof(TextureSpec);

    for (int i = 0; i < texSpecCount; i++)
    {
        SDL_Texture **texPtr = texSpecs[i].ptr;
        char *path = texSpecs[i].path;

        *texPtr = IMG_LoadTexture(renderer, path);
        if (*texPtr == NULL)
        {
            printf("ERROR - Loading texture %s\n", path);
            printf("      - %s\n", SDL_GetError());
            assert(false);
            abort();
        }
    }

    return self;
}

void Assets_Delete(Assets *self)
{
    if (!self) return;

    // -------------------------------------------------------------------------
    // Libère les textures

    SDL_Texture **texPointers[] = {
        &self->Grille,& self->Red,& self->Yellow,
    };
    int count = sizeof(texPointers) / sizeof(SDL_Texture **);

    for (int i = 0; i < count; i++)
    {
        if (*texPointers[i])
            SDL_DestroyTexture(*(texPointers[i]));
    }

    free(self);
}