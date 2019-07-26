#include "../include/Block.h"

using namespace std;

Block::Block(){
    word="";
    color=0;
    selected=false;
}

string Block::getWord(){
    return word;
}

int Block::getColor(){
    return color;
}

bool Block::isBlockSelected(){
    return selected;
}

void Block::setWord(string word_a){
    word=word_a;
}

void Block::setColor(int color_a){
    color=color_a;
}

void Block::select(){
    selected=true;
}