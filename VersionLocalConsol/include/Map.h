#ifndef DEF_MAP
#define DEF_MAP

#include <string>
#include <time.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Block.h"
#include "Clue.h"

class Map{
/*Methods*/
    public:
    //Constuctor :
    Map();

    //Getters :
    bool isKeyTeamOne();
    bool isTeamOneTurn();
    Clue getClue();
    Block getBlock(int idBlock);
    int getScoreTeamOne();
    int getScoreTeamTwo();

    //Setters :


    //Initializers :
    private:
    void randomTeamKey();
    int addWords();
    void addColors();

    //Checkers :
    bool isDoublon(std::string clue_a);
    bool verifClue(std::string clue_a);

    //Changers :
    public:
    void switchTurn();
    int playBlock(int idBlock, bool bonusTry);

    //Askers :
    void askNewClue();
    int askWhichBlock();

/*Attributes*/
    private:
    bool keyTeamOne;
    bool teamOneTurn;
    Block tab[25];
    Clue clue;
    int scoreTeamOne;
    int scoreTeamTwo;
};

#endif