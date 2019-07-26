#include "acceuil.h"

Acceuil::Acceuil(){
    setWindowTitle("Acceuil");

    //Construction des boutons
    bPlay = new QPushButton("Jouer",this);
    bRules = new QPushButton("Règles",this);
    bParam = new QPushButton("Options",this);
    bQuit = new QPushButton("Quitter",this);



    layout = new QGridLayout;
    layout->addWidget(bPlay,0,0);
    layout->addWidget(bRules,1,0);
    layout->addWidget(bParam,2,0);
    layout->addWidget(bQuit,3,0);

    this->setLayout(layout);



}
