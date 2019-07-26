/*
 * @fichier main.cpp
 * @brief Affichage graphique
 */

#include "source.h"
#include "modulecode.h"
#include "acceuil.h"
#include "PlateauJeu.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Acceuil a;
    a.show();

    PlateauJeu j;
    j.show();




    return app.exec();
}
