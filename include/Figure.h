#ifndef FIGURE_H
#define FIGURE_H

#include <string>
#include <map>

#include "Couleur.h"
#include "Position.h"
#include "Grille.h"

using namespace std;

enum Forme {C_arre, B_arre, L_Figure, S_Figure, T_Figure};

class Figure
{
    public:
        int id;

        Figure();

        string nom_forme;
        map<int,vector<Position>> cellules;
        int cellule_taille;
        int rotation_etat;
        string to_string();
        Couleur couleur_cellule;

        void dessiner(Grille * grille);


    protected:


    private:



};

#endif // FIGURE_H
