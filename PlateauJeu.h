/*
 * @fichier PlateauJeu.h
 * @brief Fichier contenant le plateau de jeu
 *
 */

#ifndef PLATEUJEU_H
#define PLATEUJEU_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>

class PlateauJeu : public QWidget{

public:
    PlateauJeu();   //Constructeur -> permet de créer une fenêtre de type Plateau de Jeu

private:
    //Variable privé
    QGridLayout* layout; //Grille pour mettre les boutons à la bonne place

};

#endif // PLATEUJEU_H
