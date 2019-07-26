#ifndef DEF_CLUE
#define DEF_CLUE

#include <string>

class Clue{
/*Methods*/
    public: 
    //Constructor :
    Clue();
    Clue(std::string clue_a);
    Clue(std::string clue_a, int nbWord4Clue_a);

    //Getters :
    std::string getClue();
    int getNbWord4Clue();
    bool isBonusTryAlreadyUsed();

    //Setters :
    void reduceNbWord4Clue();
    void useBonusTry();

/*Attributes*/
    private:
    std::string clue;
    int nbWord4Clue;
    bool bonusTryAlreadyUsed;
};

#endif