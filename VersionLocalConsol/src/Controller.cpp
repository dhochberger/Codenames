#include "../include/Controller.h"

using namespace std;

bool Controller::isTeamOnePlaying(){
    return map.isTeamOneTurn();
}

int Controller::blockColor(int idBlock){
    return map.getBlock(idBlock).getColor();
}

string Controller::blockWord(int idBlock){
    return map.getBlock(idBlock).getWord();
}

bool Controller::isBlockSelected(int idBlock){
    return map.getBlock(idBlock).isBlockSelected();
}

int Controller::playBlock(int idBlock){
    bool tmpBool=(map.getClue().isBonusTryAlreadyUsed()==false)&&(map.getClue().getNbWord4Clue()==0);
    if(tmpBool){
        map.getClue().useBonusTry();
    }
    return map.playBlock(idBlock,tmpBool);
}

string Controller::getLanguage(){
    return set.getLanguage();
}

int Controller::getMasterVolume(){
    return set.getMasterVolume();
}

int Controller::getMusicVolume(){
    return set.getMusicVolume();
}

int Controller::getEffectVolume(){
    return set.getEffectVolume();
}

string Controller::getColorTeamOne(){
    return set.getColorTeamOne();
}

string Controller::getColorTeamTwo(){
    return set.getColorTeamTwo();
}