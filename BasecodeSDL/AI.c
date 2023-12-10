#include "AI.h"

INLINE int Int_Max(int a, int b) { return a > b ? a : b; }
INLINE int Int_Min(int a, int b) { return a < b ? a : b; }


//  Check ligne à droite
//
INLINE int checkLDroite(int currentPosI, int currentPosJ, Game* self, int playerID) {
    int score = 0;
    for (int i = 0; i < 4; ++i) {
        if (currentPosJ + i > 6)
            continue;
        if (self->grid[currentPosI][currentPosJ + i] == playerID || self->grid[currentPosI][currentPosJ + i] == 0)
            ++score;
        else
            score = 0;
    }
    if (score == 4)
        return 1;
    else
        return 0;
}

//
//  Check ligne à gauche
//
INLINE int checkLGauche(int currentPosI, int currentPosJ, Game* self, int playerID) {
    int score = 0;
    for (int i = 0; i < 4; ++i) {
        if (currentPosJ - i < 0)
            continue;
        if (self->grid[currentPosI][currentPosJ - i] == playerID || self->grid[currentPosI][currentPosJ - i] == 0)
            ++score;
        else
            score = 0;
    }
    if (score == 4)
        return 1;
    else
        return 0;
}

//
//  Check demie ligne à droite
//
INLINE int checkL2Droite(int currentPosI, int currentPosJ, Game* self, int playerID) {
    int score = 0;

    if (currentPosJ - 1 < 0)
        return 0;

    if (self->grid[currentPosI][currentPosJ - 1] != playerID && self->grid[currentPosI][currentPosJ - 1] != 0)
        return 0;

    for (int i = 0; i < 3; ++i) {
        if (currentPosJ + i > 6)
            continue;
        if (self->grid[currentPosI][currentPosJ + i] == playerID || self->grid[currentPosI][currentPosJ + i] == 0)
            ++score;
        else
            score = 0;
    }
    if (score == 3)
        return 1;
    else
        return 0;
}

//
//  Check demie ligne à gauche
//
INLINE int checkL2Gauche(int currentPosI, int currentPosJ, Game* self, int playerID) {
    int score = 0;

    if (currentPosJ + 1 > 6)
        return 0;

    if (self->grid[currentPosI][currentPosJ + 1] != playerID && self->grid[currentPosI][currentPosJ + 1] != 0)
        return 0;

    for (int i = 0; i < 3; ++i) {
        if (currentPosJ - i < 0)
            continue;
        if (self->grid[currentPosI][currentPosJ - i] == playerID || self->grid[currentPosI][currentPosJ - i] == 0)
            ++score;
        else
            score = 0;
    }
    if (score == 3)
        return 1;
    else
        return 0;
}

//
//  Check colonne en haut
//
INLINE int checkCHaut(int currentPosI, int currentPosJ, Game* self, int playerID) {
    int score = 0;
    for (int i = 0; i < 4; ++i) {
        if (currentPosI + i > 5)
            continue;
        if (self->grid[currentPosI + i][currentPosJ] == playerID || self->grid[currentPosI + i][currentPosJ] == 0)
            ++score;
        else
            score = 0;
    }
    if (score == 4)
        return 1;
    else
        return 0;
}

//
//  Check colonne en bas
//
INLINE int checkCBas(int currentPosI, int currentPosJ, Game* self, int playerID) {
    int score = 0;
    for (int i = 0; i < 4; ++i) {
        if (currentPosI - i < 0)
            continue;
        if (self->grid[currentPosI - i][currentPosJ] == playerID || self->grid[currentPosI - i][currentPosJ] == 0)
            ++score;
        else
            score = 0;
    }
    if (score == 4)
        return 1;
    else
        return 0;
}

//
//  Check demie colonne en haut
//
INLINE int checkC2Haut(int currentPosI, int currentPosJ, Game* self, int playerID) {
    int score = 0;

    if (currentPosI - 1 < 0)
        return 0;

    if (self->grid[currentPosI - 1][currentPosJ] != playerID && self->grid[currentPosI - 1][currentPosJ] != 0)
        return 0;

    for (int i = 0; i < 3; ++i) {
        if (currentPosI + i > 5)
            continue;
        if (self->grid[currentPosI + i][currentPosJ] == playerID || self->grid[currentPosI + i][currentPosJ] == 0)
            ++score;
        else
            score = 0;
    }
    if (score == 3)
        return 1;
    else
        return 0;
}

//
//  Check demie colonne en bas
//
INLINE int checkC2Bas(int currentPosI, int currentPosJ, Game* self, int playerID) {
    int score = 0;

    if (currentPosI + 1 > 5)
        return 0;

    if (self->grid[currentPosI + 1][currentPosJ] != playerID && self->grid[currentPosI + 1][currentPosJ] != 0)
        return 0;

    for (int i = 0; i < 3; ++i) {
        if (currentPosI - i < 0)
            continue;
        if (self->grid[currentPosI - i][currentPosJ] == playerID || self->grid[currentPosI - i][currentPosJ] == 0)
            ++score;
        else
            score = 0;
    }
    if (score == 3)
        return 1;
    else
        return 0;
}

//
//  Check Diagonale en haut à droite
//
INLINE int checkDHautDroite(int currentPosI, int currentPosJ, Game* self, int playerID) {
    int score = 0;

    for (int i = 0; i < 4; ++i) {
        if (currentPosI + i > 5)
            continue;
        if (currentPosJ + i > 6)
            continue;
        if (self->grid[currentPosI + i][currentPosJ + i] == playerID ||
            self->grid[currentPosI + i][currentPosJ + i] == 0)
            ++score;
        else
            score = 0;
    }
    if (score == 4)
        return 1;
    else
        return 0;
}

//
//  Check demie Diagonale en haut à droite
//
INLINE int checkD2HautDroite(int currentPosI, int currentPosJ, Game* self, int playerID) {
    int score = 0;

    if (currentPosI - 1 < 0 || currentPosJ - 1 < 0)
        return 0;

    if (self->grid[currentPosI - 1][currentPosJ - 1] != playerID && self->grid[currentPosI - 1][currentPosJ - 1] != 0)
        return 0;


    for (int i = 0; i < 3; ++i) {
        if (currentPosI + i > 5)
            continue;
        if (currentPosJ + i > 6)
            continue;
        if (self->grid[currentPosI + i][currentPosJ + i] == playerID ||
            self->grid[currentPosI + i][currentPosJ + i] == 0)
            ++score;
        else
            score = 0;
    }
    if (score == 3)
        return 1;
    else
        return 0;
}

//
//  Check Diagonale en haut à gauche
//
INLINE int checkDHautGauche(int currentPosI, int currentPosJ, Game* self, int playerID) {
    int score = 0;

    for (int i = 0; i < 4; ++i) {
        if (currentPosI + i > 5)
            continue;
        if (currentPosJ - i < 0)
            continue;
        if (self->grid[currentPosI + i][currentPosJ - i] == playerID ||
            self->grid[currentPosI + i][currentPosJ - i] == 0)
            ++score;
        else
            score = 0;
    }
    if (score == 4)
        return 1;
    else
        return 0;
}

//
//  Check demie Diagonale en haut à gauche
//
INLINE int checkD2HautGauche(int currentPosI, int currentPosJ, Game* self, int playerID) {
    int score = 0;

    if (currentPosI - 1 < 0 || currentPosJ + 1 > 6)
        return 0;

    if (self->grid[currentPosI - 1][currentPosJ + 1] != playerID && self->grid[currentPosI - 1][currentPosJ + 1] != 0)
        return 0;


    for (int i = 0; i < 3; ++i) {
        if (currentPosI + i > 5)
            continue;
        if (currentPosJ - i < 0)
            continue;
        if (self->grid[currentPosI + i][currentPosJ - i] == playerID ||
            self->grid[currentPosI + i][currentPosJ - i] == 0)
            ++score;
        else
            score = 0;
    }
    if (score == 3)
        return 1;
    else
        return 0;
}

//
//  Check Diagonale en bas à droite
//
INLINE int checkDBasDroite(int currentPosI, int currentPosJ, Game* self, int playerID) {
    int score = 0;

    for (int i = 0; i < 4; ++i) {
        if (currentPosI - i < 0)
            continue;
        if (currentPosJ + i > 6)
            continue;
        if (self->grid[currentPosI - i][currentPosJ + i] == playerID ||
            self->grid[currentPosI - i][currentPosJ + i] == 0)
            ++score;
        else
            score = 0;
    }
    if (score == 4)
        return 1;
    else
        return 0;
}

//
//  Check demie Diagonale en bas à droite
//
INLINE int checkD2BasDroite(int currentPosI, int currentPosJ, Game* self, int playerID) {
    int score = 0;

    if (currentPosI + 1 > 5 || currentPosJ - 1 < 0)
        return 0;

    if (self->grid[currentPosI + 1][currentPosJ - 1] != playerID && self->grid[currentPosI + 1][currentPosJ - 1] != 0)
        return 0;


    for (int i = 0; i < 3; ++i) {
        if (currentPosI - i < 0)
            continue;
        if (currentPosJ + i > 6)
            continue;
        if (self->grid[currentPosI - i][currentPosJ + i] == playerID ||
            self->grid[currentPosI - i][currentPosJ + i] == 0)
            ++score;
        else
            score = 0;
    }
    if (score == 3)
        return 1;
    else
        return 0;
}

//
//  Check Diagonale en bas à gauche
//
INLINE int checkDBasGauche(int currentPosI, int currentPosJ, Game* self, int playerID) {
    int score = 0;

    for (int i = 0; i < 4; ++i) {
        if (currentPosI - i < 0)
            continue;
        if (currentPosJ - i < 0)
            continue;
        if (self->grid[currentPosI - i][currentPosJ - i] == playerID ||
            self->grid[currentPosI - i][currentPosJ - i] == 0)
            ++score;
        else
            score = 0;
    }
    if (score == 4)
        return 1;
    else
        return 0;
}

//
//  Check demie Diagonale en bas à gauche
//
INLINE int checkD2BasGauche(int currentPosI, int currentPosJ, Game* self, int playerID) {
    int score = 0;

    if (currentPosI + 1 > 5 || currentPosJ + 1 > 6)
        return 0;

    if (self->grid[currentPosI + 1][currentPosJ + 1] != playerID && self->grid[currentPosI + 1][currentPosJ + 1] != 0)
        return 0;


    for (int i = 0; i < 3; ++i) {
        if (currentPosI - i < 0)
            continue;
        if (currentPosJ - i < 0)
            continue;
        if (self->grid[currentPosI - i][currentPosJ - i] == playerID ||
            self->grid[currentPosI - i][currentPosJ - i] == 0)
            ++score;
        else
            score = 0;
    }
    if (score == 3)
        return 1;
    else
        return 0;
}

int Game_Eval(Game* self, int playerID) {

    int res = 0;
    int score = 0;

    for (int i = 0; i < GRID_H; ++i) {
        for (int j = 0; j < GRID_W; ++j) {
            score = 0;
            score += checkLDroite(i, j, self, playerID);
            score += checkLGauche(i, j, self, playerID);
            score += checkL2Droite(i, j, self, playerID);
            score += checkL2Gauche(i, j, self, playerID);
            score += checkCHaut(i, j, self, playerID);
            score += checkCBas(i, j, self, playerID);
            score += checkC2Haut(i, j, self, playerID);
            score += checkC2Bas(i, j, self, playerID);
            score += checkDHautDroite(i, j, self, playerID);
            score += checkD2HautDroite(i, j, self, playerID);
            score += checkDHautGauche(i, j, self, playerID);
            score += checkD2HautGauche(i, j, self, playerID);
            score += checkDBasDroite(i, j, self, playerID);
            score += checkD2BasDroite(i, j, self, playerID);
            score += checkDBasGauche(i, j, self, playerID);
            score += checkD2BasGauche(i, j, self, playerID);;

            playerID = 3 - playerID;

            score += checkLDroite(i, j, self, playerID);
            score += checkLGauche(i, j, self, playerID);
            score += checkL2Droite(i, j, self, playerID);
            score += checkL2Gauche(i, j, self, playerID);
            score += checkCHaut(i, j, self, playerID);
            score += checkCBas(i, j, self, playerID);
            score += checkC2Haut(i, j, self, playerID);
            score += checkC2Bas(i, j, self, playerID);
            score += checkDHautDroite(i, j, self, playerID);
            score += checkD2HautDroite(i, j, self, playerID);
            score += checkDHautGauche(i, j, self, playerID);
            score += checkD2HautGauche(i, j, self, playerID);
            score += checkDBasDroite(i, j, self, playerID);
            score += checkD2BasDroite(i, j, self, playerID);
            score += checkDBasGauche(i, j, self, playerID);
            score += checkD2BasGauche(i, j, self, playerID);

            if (self->grid[i][j] == 1)
                res += score;
            if (self->grid[i][j] == 2)
                res -= score;
        }
    }


    if (playerID == 2) {
        return -res;
    }
    //printf("res : %d\n", res);

    return score;
}

/// @brief Détruit récursivement un noeud et tous ses sous-arbres.
/// @param self le noeud.
void AINode_DeleteRec(AINode* node) {
    if (node == NULL) {
        return;
    }
    Game_Delete(node->gameState);
    for (int i = 0; i < GRID_W; i++) {
        AINode_DeleteRec(node->children[i]);
    }
    free(node);
}

AINode* AINode_NewMinMax(Game* game, int depth, bool minLayer, int playerID, int alpha, int beta) {
    AINode* node = (AINode*)calloc(1, sizeof(AINode));
    AssertNew(node);
    node->gameState = game;
    if (game->state != GAME_IN_PROGRESS)
    {
        if (game->state == playerID) node->score = 999999999;
        else if (game->state == GAME_IS_TIED) node->score = 0;
        else node->score = -999999999;
        return node;
    }

    if (depth == 0)
    {
        node->score = Game_Eval(game, playerID);
        //printf("Score1 : %d\n", Game_Eval(game, playerID));
        return node;
    }

    int tab[] = { 3, 2, 4, 1, 5, 0, 6 };

    node->score = (minLayer) ? +1000000000 : -1000000000;
    node->move = -100;


    for (int i = 0; i < GRID_W; i++)
    {
        int colone = tab[i];

        if (Game_CanPlayAt(game, colone) == true)
        {

            Game* newGame = Game_Copy(game);
            Game_PlayTurn(newGame, colone);
            node->children[colone] = AINode_NewMinMax(newGame, depth - 1, !minLayer, playerID, alpha, beta);

            if (minLayer)
            {
                if (node->children[colone]->score < node->score) {
                    node->score = node->children[colone]->score;
                    node->move = colone;
                }
                beta = Int_Min(beta, node->score);

            }
            else {
                if (node->children[colone]->score > node->score) {
                    node->score = node->children[colone]->score;
                    node->move = colone;
                }
                alpha = Int_Max(alpha, node->score);
            }
        }
        AINode_DeleteRec(node->children[colone]);
        node->children[colone] = NULL;
        if (beta <= alpha)
        {
            return node;
        }
    }
    return node;
}

AITree* AITree_NewMinMax(Game* game, int depth, int playerID)
{
    AITree* self = (AITree*)calloc(1, sizeof(AITree));
    AssertNew(self);

    Game* curGame = Game_Copy(game);
    self->root = AINode_NewMinMax(curGame, depth, false, playerID, -1000000000, 1000000000);

    return self;
}

void AITree_Delete(AITree* self)
{
    if (!self) return;

    AINode_DeleteRec(self->root);
    free(self);
}

int AI_ComputeMove(Game* game, int playerID)
{
    /////////
    // TODO : Cette fonction représente votre IA.
    // Modifiez-la comme vous le souhaitez.

    int depth = 6;
    AITree* aiTree = AITree_NewMinMax(game, depth, playerID);
    int move = aiTree->root->move;
    AITree_Delete(aiTree);

    return move;
}
