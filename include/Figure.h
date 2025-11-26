#ifndef FIGURE_H
#define FIGURE_H

#include <string>
#include <map>

#include "Couleur.h"
#include "Position.h"

using namespace std;



class Figure
{
    public:
        Figure(int p_num_forme);
        string get_nom_forme(); // Il y a 5 formes (Carré, Barre, LFigure, SFigure, TFigure)
        const char * get_adresse_image_associee(); //L'image que l'on affichera dans le jeu par exemple: .../Barre.png


        string nom_forme;

        map<int,vector<Position>> cellule;
        int nb_cellules;
        Couleur couleur_cellule;




        string to_string();

        virtual ~Figure();

    protected:



        const char * adresse_image_associee;

    private:

        int cellule_taille;
        int rotation_etat;

};

#endif // FIGURE_H
