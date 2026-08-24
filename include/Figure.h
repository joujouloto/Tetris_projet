#ifndef FIGURE_H
#define FIGURE_H

#include <string>
#include <map>

#include "Couleur.h"
#include "Position.h"

class Grille;

using namespace std;


#define ORIGINE_X_DEFAULT 0
#define ORIGINE_Y_DEFAULT 5

enum Forme {C_arre, B_arre, L_Figure, S_Figure, T_Figure,J_Figure,Z_Figure};

class Figure
{
    public:

        Figure ();
        Figure(int origine_ligne, int origine_colonne);




        string to_string();


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
        bool est_en_collision_en_haut(Grille * grille);

        bool est_en_collision_en_rotation_droite(Grille * grille);
        bool est_en_collision_en_rotation_gauche(Grille * grille);

        void setCouleur(Couleur c);
        Couleur getCouleur();

        void initialiser_coordonnees();
        void afficher_position();


        bool peut_monter();
        bool peut_descendre(int nb_lignes_grille);
        bool peut_aller_a_gauche(int nb_colonnes_grille);
        bool peut_aller_a_droite(int nb_colonnes_grille);

        map<int,vector<Position>> getCellules();
        int getRotationEtat();


    protected:
        int id;
        string nom_forme;

        int cellule_taille;
        int rotation_etat;
        int nb_rotations_possibles;
        int origine_x;
        int origine_y;
        Couleur couleur_cellule;
        map<int,vector<Position>> cellules;

    private:





};

#endif // FIGURE_H
