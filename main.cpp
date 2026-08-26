#include <iostream>
#include <random>


#include "Figure.h"
#include "Jeu.h"
#include "Grille.h"
#include "Couleur.h"
#include "Position.h"
#include "Test.h"


#include "Carre.h"
#include "Barre.h"
#include "JFigure.h"
#include "LFigure.h"
#include "ZFigure.h"
#include "SFigure.h"
#include "TFigure.h"



int main()
{/*
    Jeu jeu;

    while(!jeu.est_termine())
    {
        char touche;

        std::cin >> touche;

        //jeu.gerer_entree(touche);

        jeu.mettre_a_jour();

        jeu.afficher();
    }
*/

    Test tests;


    tests.test_creation_grille_si_vide();
    tests.case_occupee();
    tests.deplacement_a_gauche();
    tests.deplacement_a_droite();
    tests.limite_gauche();






    return 0;
}
