/*
 * @fichier moduleCode.cpp
 * @brief Fichier contenant le code du jeu
 */

#include "modulecode.h"



bool RandColorKey(){
	return (((rand()%2)==1)?true:false);
}

bool IsDoublon(Block tab[], string s){
	int i;
	for(i=0;i<25;i++){
        if(tab[i].word==s){return true;}    //Si doublon il y a on retourne directement le résultat
	}
	//Si la fonction n'a pas été quitté c'est qu'il n'y a pas de doublon
	return false;
}

bool VerifClue(string clue, Block tab[]){
	int i;
	for(i=0;i<25;i++){
	    //Test si le mot n'as pas encore été selectionné et qu'il est égale à l'indice
        if(!(tab[i].selected) && tab[i].word==clue){
			return false;
		}
	}
	return true;
}

int AddWords(Block tab[]){
    ifstream wordsFile("/Users/lynearmand/Test2_projet/CodenamesFR.txt");
	//En cas d'échec d'ouverture on quitte la fonction
	if(!wordsFile){
		cout << "Erreur pour l'ouverture de CodenamesFR.txt" << endl;
		return (-1);
	}

	int i,j,randLine;
	string lineX;
	
	for(i=0;i<25;i++){
		//Tant que le mot tiré est un doublon on retire un nouveau mot
		while(IsDoublon(tab,lineX)){
			//Tire un mot parmi les lignes du fichier
			randLine=(rand()%696)+1;
			for(j=0;j<randLine;j++){
				getline(wordsFile,lineX);
			}
			wordsFile.seekg(ios::beg);
		}
		//Une fois que le mot est unique on l'insert
		tab[i].word=lineX;
	}
	return 0; 
}

void AddColors(Block tab[], bool isBlue){
	//Le nombre de chaque type de témoins
	int nbNeutre=7;
    int nbAssassin=1;
	//On module le nombre de blocks bleu et rouge en fonction de la clef
	int nbBlueBlock=8+isBlue;
    int nbRedBlock=9-isBlue;

	//Stockera la couleur tiré aléatoirement puis la couleur de la case s'y rapportant
	int colorBlock;
	//i est un compteur et whichCheck sert de pointeur pour connaître quel type de témoins décrémenter
	int *whichCheck,i;

	//On parcourt tout le tableau de Blocks
	for(i=0;i<25;i++){
		//Tire un nombre aléatoire entre 0 et 23
		colorBlock=rand()%24;
		
		//En fonction de la couleur tiré on regardera la variable correspondante
		switch(colorBlock)
        {
            case 0:
				whichCheck=&nbAssassin;
				colorBlock=3;
                break;
			case 1 ... 8 :
				whichCheck=&nbBlueBlock;
				colorBlock=1;
                break;
            case 9 ... 16 :
				whichCheck=&nbRedBlock;
				colorBlock=2;
                break;
            default:whichCheck=&nbNeutre;
				colorBlock=0;
        }
		
		if(*whichCheck==0){
			//Si la quantité du rôle tiré est épuisé on permet d'en tirer un autre
            i--;
        } else {
			//Sinon on décrémente le nombre de rôle restant puis on l'attribue
			(*whichCheck)--;
			tab[i].color=colorBlock;
		}
	}
}

Map CreateMap(){
	Map m;
	//Assigne la couleur de la clef
	m.keyColorIsBlue=RandColorKey();
	//L'équipe qui commence est celle dont la couleur est la même que la clef
	m.isBlueTurn=m.keyColorIsBlue;
	//Ajout des mots tiré aléatoirement0
	AddWords(m.tab);
	//Définie les rôles sur chaque témoin
	AddColors(m.tab,m.keyColorIsBlue);
	return m;
}
