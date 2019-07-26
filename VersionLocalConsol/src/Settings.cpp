#include "../include/Settings.h"

using namespace std;

Settings::Settings(){
    language="Français";
    masterVolume=100;
    oldMasterVolume=100;
    musicVolume=100;
    oldMusicVolume=100;
    effectVolume=100;
    oldEffectVolume=100;
    colorTeamOne="Bleu";
    colorTeamTwo="Rouge";
    muted=false;
}

string Settings::getLanguage(){
    return language;
}

int Settings::getMasterVolume(){
    return masterVolume;
}

int Settings::getOldMasterVolume(){
    return oldMasterVolume;
}

int Settings::getMusicVolume(){
    return musicVolume;
}

int Settings::getOldMusicVolume(){
    return oldMusicVolume;
}

int Settings::getEffectVolume(){
    return effectVolume;
}

int Settings::getOldEffectVolume(){
    return oldEffectVolume;
}

string Settings::getColorTeamOne(){
    return colorTeamOne;
}

string Settings::getColorTeamTwo(){
    return colorTeamTwo;
}

void Settings::setLanguage(string language_a){
    language=language_a;
}

void Settings::setMasterVolume(int masterVolume_a){
    masterVolume=masterVolume_a;
}

void Settings::setMusicVolume(int musicVolume_a){
    musicVolume=musicVolume_a;
}

void Settings::setEffectVolume(int effectVolume_a){
    effectVolume=effectVolume_a;
}

void Settings::setColorTeamOne(string colorTeamOne_a){
    colorTeamOne=colorTeamOne_a;
}

void Settings::setColorTeamTwo(string colorTeamTwo_a){
    colorTeamTwo=colorTeamTwo_a;
}

void Settings::mute(){
    oldMasterVolume=masterVolume;
    oldMusicVolume=musicVolume;
    oldEffectVolume=effectVolume;
    masterVolume=0;
    musicVolume=0;
    effectVolume=0;
    muted=true;
}

void Settings::unmute(){
    masterVolume=oldMasterVolume;
    musicVolume=oldMusicVolume;
    effectVolume=oldEffectVolume;
    muted=false;
}