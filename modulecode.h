/*
 * @fichier modulecode.h
 * @brief Fichier contenant les prototypes des fonctions
 */

#ifndef MODULECODE_H
#define MODULECODE_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "source.h"

using namespace std;

/*
 * @struct Block
 * @brief
 */
typedef struct{
    string word;            //Le mot contenu dans la case
    int color;              //La couleur de la case (arbitraire): 0->Neutre, 1->Bleue, 2->Rouge et 3->Assassin
    bool selected=false;    //Si la case a été "joué" ou non
}Block;

/*
 * @struct Clue
 * @brief
 */
typedef struct{
    string clue;            //L'indice en question
    int nbWord4Clue=0;      //Le nombre de mot auquel il se réfère
}Clue;

/*
 * @struct Map
 * @brief
 */
typedef struct
{
    bool keyColorIsBlue;    //Si true la clef est bleue si false elle est rouge
    Block tab[25];          //Tableau de block qui forme le terrain de jeu
    int scoreBlue=0;        //Score équipe bleu
    int scoreRed=0;         //Score équipe rouge
    bool isBlueTurn;        //Si vrai c'est le tour de l'équipe bleue sinon de l'équipe rouge
    Clue clue;              //L'indice en cours
    int nbTurn=1;           //Le numéro du tour actuel

}Map;



/*
 * @fn bool RandColorKey()
 * @brief Tire aléatoirement entre true et false
 */
bool RandColorKey();

/*
 * @fn bool IsDoublon(Block tab[], string s)
 * @brief Renvoie true si s est présent dans le tableau tab, false dans le cas contraire
 */
bool IsDoublon(Block tab[], string s);

/*
 * @fn bool VerifClue(string clue, Block tab[])
 * @brief Renvoie true si l'indice est correct et false sinon
 */
bool VerifClue(string clue, Block tab[]);

/*
 * @fn int AddWords(Block tab[])
 * @brief Ajoute les mots dans le tableau passé en argument
 */
int AddWords(Block tab[]);

/*
 * @fn void AddColors(Block tab[], bool isBlue)
 * @brief Ajoute les couleur dans le tableu passé en argument
 */
void AddColors(Block tab[], bool isBlue);

/*
 * @fn Map CreateMap()
 * @brief Génère une map de jeu
 */
Map CreateMap();

/*
 * @fn Map int ModifMap(Map *m, int ieme, bool bonusTry)
 * @brief Change le statut du ieme block ainsi que le score de la partie;
 *        si cela engendre la victoire des bleues cela renvoie 1, renvoie 2
 *        pour l'épuipe rouge et 0 si cela n'affecte pas la victoire d'une équipe.
 */
int ModifMap(Map *m, int ieme, bool bonusTry);

#endif // MODULECODE_H
