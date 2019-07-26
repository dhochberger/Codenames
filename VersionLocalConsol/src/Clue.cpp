#include "../include/Clue.h"

using namespace std;

Clue::Clue(){
    clue="";
    nbWord4Clue=0;
    bonusTryAlreadyUsed=false;
}

Clue::Clue(string word){
    clue=word;
    nbWord4Clue=0;
    bonusTryAlreadyUsed=false;
}

Clue::Clue(string word, int value){
    clue=word;
    nbWord4Clue=value;
    bonusTryAlreadyUsed=false;
}

string Clue::getClue(){
    return clue;
}

int Clue::getNbWord4Clue(){
    return nbWord4Clue;
}

bool Clue::isBonusTryAlreadyUsed(){
    return bonusTryAlreadyUsed;
}

void Clue::reduceNbWord4Clue(){
    nbWord4Clue--;
}

void Clue::useBonusTry(){
    bonusTryAlreadyUsed=true;
}