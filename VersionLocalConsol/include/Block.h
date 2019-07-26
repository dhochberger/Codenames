#ifndef DEF_BLOCK
#define DEF_BLOCK

#include <string>

class Block{
/*Methods*/
    public:
    //Constructor :
    Block();

    //Getters :
    std::string getWord();
    int getColor();
    bool isBlockSelected();

    //Setters :
    void setWord(std::string word_a);
    void setColor(int color_a);
    void select();

/*Attributes*/
    private:
    std::string word;
    int color;
    bool selected;
};

#endif