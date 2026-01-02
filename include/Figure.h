#ifndef FIGURE_H
#define FIGURE_H

#include <string>
#include <map>

#include "Couleur.h"
#include "Position.h"
#include "Grille.h"

using namespace std;

enum Forme {C_arre, B_arre, L_Figure, S_Figure, T_Figure,J_Figure,Z_Figure};

class Figure
{
    public:
        int id;
        Figure ();
        Figure(int origine_ligne, int origine_colonne);

        string nom_forme;
        map<int,vector<Position>> cellules;
        int cellule_taille;
        int rotation_etat;
        int nb_rotations_possibles;

        int origine_x;
        int origine_y;

        string to_string();
        Couleur couleur_cellule;

        void setPosition(Position p);
        void setPosition(int p_x, int p_y);


        virtual void maj_position();
        void rotation_sens_antihoraire(Grille * grille);
        void rotation_sens_horaire(Grille * grille);

        void descendre();
        void monter();//undo descendre


        void aller_a_gauche();
        void aller_a_droite();

        bool est_en_collision_en_bas(Grille * grille);
        bool est_en_collision_a_gauche(Grille * grille);
        bool est_en_collision_a_droite(Grille * grille);

        bool est_en_collision_en_rotation_droite(Grille * grille);
        bool est_en_collision_en_rotation_gauche(Grille * grille);

        void setCouleur(Couleur c);
        Couleur getCouleur();


    protected:


    private:



};

#endif // FIGURE_H
