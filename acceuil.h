#ifndef ACCEUIL_H
#define ACCEUIL_H
/*
 * @fichier acceuil.h
 * @brief Fichier contenant l'accueil
 */

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>

//On hérite de QWidget
class Acceuil : public QWidget{

public:
    Acceuil();  //Constructeur -> permet de créer une fenêtre de type Acceuil

private:
    //Variables privées
    QPushButton * bPlay;    //bouton pour Jouer
    QPushButton * bRules;   //bouton pour Règle
    QPushButton * bParam;   //bouton pour Options
    QPushButton * bQuit;    //bouton pour Quitter
    QGridLayout* layout;    //grille pour mettre les boutons à la bonne place

};

#endif // ACCEUIL_H
