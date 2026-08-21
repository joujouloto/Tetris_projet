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

    Test test;


    test.test_creation_grille_si_vide();

    cout << "test creation grille vide ok" << endl;






    return 0;
}
