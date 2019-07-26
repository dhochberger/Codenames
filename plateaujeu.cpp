#include "PlateauJeu.h"
#include "modulecode.h"

PlateauJeu::PlateauJeu(){
    //Création d'un map
     Map m = CreateMap();

     // Création des 25 boutons (5 par 5)

     QVector<QPushButton*> mesBouttons(25);

      for(int i = 0; i < 25; i++){
         QString contenu = QString::fromStdString(m.tab[i].word);
          mesBouttons[i] = new QPushButton(contenu, this);
        }

        QGridLayout *layout = new QGridLayout;

        for(int i = 0; i < 25; i++){
            layout->addWidget(mesBouttons.at(i),i/5,i%5);
        }

        this->setLayout(layout);

}
