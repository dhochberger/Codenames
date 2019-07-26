#include "../include/Map.h"

using namespace std;

Map::Map(){
    srand(time(NULL));
    randomTeamKey();
	teamOneTurn=keyTeamOne;
	if(addWords()==(-1)){exit(EXIT_FAILURE);}
	addColors();
	scoreTeamOne=0;
	scoreTeamTwo=0;
}

bool Map::isKeyTeamOne(){
	return keyTeamOne;
}

bool Map::isTeamOneTurn(){
	return teamOneTurn;
}

Clue Map::getClue(){
	return clue;
}

Block Map::getBlock(int nbrBlock){
	return tab[nbrBlock];
}

int Map::getScoreTeamOne(){
	return scoreTeamOne;
}

int Map::getScoreTeamTwo(){
	return scoreTeamTwo;
}

void Map::randomTeamKey(){
	keyTeamOne=(((rand()%2)==1)?true:false);
}

int Map::addWords(){
    ifstream wordsFile("./media/CodenamesFR.txt");
	if(!wordsFile){
		cout << "Erreur pour l'ouverture de CodenamesFR.txt" << endl;
		return (-1);
	}

	int randLine;	
	string lineX;
	
	for(int i=0;i<25;i++){
		while(isDoublon(lineX)){
			randLine=(rand()%696)+1;
			for(int j=0;j<randLine;j++){
				getline(wordsFile,lineX);
			}
			wordsFile.seekg(ios::beg);
		}
		tab[i].setWord(lineX);
	}
	return 0; 
}

void Map::addColors(){
	int nbNeutre=7;
    int nbAssassin=1;
	
	int nbTeamOneBlock=8+keyTeamOne;
    int nbTeamTwoBlock=9-keyTeamOne;

	int colorBlock;
	int *whichCheck;

	for(int i=0;i<25;i++){
		colorBlock=rand()%24;
		
		switch(colorBlock)
        {
            case 0:
				whichCheck=&nbAssassin;
				colorBlock=3;
                break;
			case 1 ... 8 :
				whichCheck=&nbTeamOneBlock;
				colorBlock=1;
                break;
            case 9 ... 16 :
				whichCheck=&nbTeamTwoBlock;
				colorBlock=2;
                break;
            default:whichCheck=&nbNeutre;
				colorBlock=0;
        }
		
		if(*whichCheck==0){
            i--;
        } else {
			(*whichCheck)--;
			tab[i].setColor(colorBlock);
		}
	}
}

bool Map::isDoublon(string s){
	int i;
	for(i=0;i<25;i++){
        if(tab[i].getWord()==s){return true;}
	}
	return false;
}

bool Map::verifClue(string clue_a){
    if(clue_a.empty() || clue_a.front()=='-' || clue_a.back()=='-'){return false;}
    
    for(int i=0;i<(clue_a.length());i++)
    {
        if((!isalpha(clue_a[i]) && clue_a[i]!='-') || (clue_a[i]=='-' && clue_a[i+1]=='-')){return false;}
    }
    
	for(int i=0;i<25;i++){
        if(!(tab[i].isBlockSelected()) && tab[i].getWord()==clue_a){return false;}
	}
	return true;
}

void Map::switchTurn(){
	teamOneTurn=(!teamOneTurn);
	cout << "Changement d'équipe !" << endl;
	askNewClue();
}

int Map::playBlock(int ieme, bool bonusTry){
	tab[ieme].select();

	if(tab[ieme].getColor()==0){
		switchTurn();
		return 0;
	}

	if(tab[ieme].getColor()==3){
		return ((teamOneTurn)?2:1); 
	}
	
	int *whichScore;
	bool turnToCheck;
	int maxScore=8;

	if(tab[ieme].getColor()==1){
		whichScore=&scoreTeamOne;
		turnToCheck=(!teamOneTurn);
		maxScore+=keyTeamOne;
	} else {
		whichScore=&scoreTeamTwo;
		turnToCheck=teamOneTurn;
		maxScore+=(1-keyTeamOne);
	}

	*(whichScore)++;
	if(*(whichScore)==maxScore){return tab[ieme].getColor();}

	if(turnToCheck){
		switchTurn();
	} else {
		if(bonusTry){
			switchTurn();
		} else {
			clue.reduceNbWord4Clue();
		}
	}

	return 0;
}

void Map::askNewClue(){
	cout << "Maître espion " << (teamOneTurn?"BLEU":"ROUGE") << " entre l'indice pour ton équipe :" << endl;
	cin.ignore();
	string tmpStr="";
	int tmpNbr;
	while(!verifClue(tmpStr)){
		getline(cin,tmpStr);
	}
	cout << "Maintenant le nombre de code auquel il fait référence :" << endl;
	cin >> tmpNbr;
	clue=Clue(tmpStr,tmpNbr);
}

int Map::askWhichBlock(){
	int colonne,ligne;
	cout << "Sur quelle colonne se situe le mot que vous choisissez? ";
	cin >> colonne;
	cout << "Sur quelle ligne se situe le mot que vous choisissez? ";
	cin >> ligne;
	cout << endl << endl;
	int nbBlock=colonne+((ligne-1)*5)-1;
	if(tab[nbBlock].isBlockSelected()){return askWhichBlock();}
	return nbBlock;
}