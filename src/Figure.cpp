#include "Figure.h"

#include <iostream>
#include <sstream>

#include <map>
#include <vector>

#include "Position.h"
#include "Couleur.h"
#include "Grille.h"

using namespace std;

Figure::Figure()
{
    cellule_taille = 30;
    rotation_etat = 0;
    this->couleur_cellule = noir;

    this->initialiser_coordonnees();

    this->nb_rotations_possibles = 1;

}




Figure::Figure(int origine_ligne, int origine_colonne)
{
    cellule_taille = 30;
    rotation_etat = 0;
    this->couleur_cellule = noir;

    setPosition(origine_ligne,origine_colonne);

    this->nb_rotations_possibles = 1;


}

string Figure::to_string()
{
    stringstream ss;

	ss << "nom_forme:";
	ss << this->nom_forme;
	ss << "\n";


	return ss.str();

}

void Figure::setPosition(Position p)
{
    this->origine_x = p.ligne;
    this->origine_y = p.colonne;

}


void Figure::setPosition(int p_x, int p_y)
{
    this->origine_x = p_x;
    this->origine_y = p_y;
}

void Figure::descendre()
{
    int nouvel_abscisse_origine = origine_x+1;
    int nouvelle_ordonne_origine = origine_y;

    setPosition(nouvel_abscisse_origine,nouvelle_ordonne_origine);
    maj_position();


}

void Figure::rotation_sens_antihoraire(Grille * grille) //  attention la barre n'a que 2 rotations possibles
//donc antihoraire est pareil que horaire
{
    if(!this->est_en_collision_en_rotation_gauche(grille))
    {
         if(this->rotation_etat==this->nb_rotations_possibles-1)
        {
            rotation_etat = 0;

        }else
        {
            rotation_etat++;
        }
    }
}

void Figure::rotation_sens_horaire(Grille * grille) //  attention la barre n'a que 2 rotations possibles
//donc antihoraire est pareil que horaire
{
    if(!this->est_en_collision_en_rotation_droite(grille))
    {
        if(this->rotation_etat==0)
        {
            rotation_etat = this->nb_rotations_possibles-1;

        }else
        {
            rotation_etat--;
        }
    }


}

void Figure::aller_a_gauche()
{
    int nouvel_abscisse_origine = origine_x;
    int nouvelle_ordonne_origine = origine_y-1;


    setPosition(nouvel_abscisse_origine,nouvelle_ordonne_origine);
    maj_position();
}

void Figure::aller_a_droite()
{
    int nouvel_abscisse_origine = origine_x;
    int nouvelle_ordonne_origine = origine_y+1;

    setPosition(nouvel_abscisse_origine,nouvelle_ordonne_origine);
    maj_position();

}


/*
    La condition est toujours vrai pour le carre car je verifie sur chaque cellule si la cellule d'en bas
    est occupee et bien sur c'est occupée car le carre est composee de 2 cellules en haut
    et 2 cellules en bas.
    Il faut verifier si les cellule les plus en bas rentrent en collision.


    Retour en arriere, mal compris la condition est vide je me suis trompé et me suis mélangé les pinceaux
    la fatigue, j'ai visionné le tuto raylib tetris il ne fait pas pareil que moi

*/


bool Figure::est_en_collision_en_bas(Grille *grille)
{
    vector<Position> figure = cellules[rotation_etat];

    for(Position cellule : figure)
    {


        if(!grille->est_vide(cellule.ligne + 1, cellule.colonne))
        {
            return true;
        }
    }

    return false;
}

bool Figure::est_en_collision_en_haut(Grille * grille)
{
    vector<Position> figure = this->cellules[rotation_etat];

    for(Position cellule: figure)
    {
        if(!grille->est_vide(cellule.ligne-1,cellule.colonne))
        {
            return true;
        }
    }

    return false;
}

bool Figure::est_en_collision_a_gauche(Grille * grille)
{
    vector<Position> figure = this->cellules[rotation_etat];

    for(Position cellule: figure)
    {
        if(!grille->est_vide(cellule.ligne,cellule.colonne-1))
        {
            return true;
        }
    }

    return false;
}

bool Figure::est_en_collision_a_droite(Grille * grille)
{
    vector<Position> figure = this->cellules[rotation_etat];

    for(Position cellule: figure)
    {
        if(!grille->est_vide(cellule.ligne,cellule.colonne+1))
        {
            return true;
        }
    }

    return false;
}

bool Figure::est_en_collision_en_rotation_droite(Grille * grille)
{
    int future_rotation = rotation_etat-1;


    if(future_rotation<0)
    {
            future_rotation= this->nb_rotations_possibles-1;
    }

    vector<Position> figure = this->cellules[future_rotation];

    for(Position cellule: figure)
    {
        if(!grille->est_vide(cellule.ligne,cellule.colonne))
        {
            return true;
        }
    }

    return false;

}

bool Figure::est_en_collision_en_rotation_gauche(Grille * grille)
{
    int future_rotation = rotation_etat+1;


    if(future_rotation>this->nb_rotations_possibles-1)
    {
            future_rotation=0;

    }

    vector<Position> figure = this->cellules[future_rotation];

        for(Position cellule: figure)
        {
            if(!grille->est_vide(cellule.ligne,cellule.colonne))
            {
                return true;
            }
        }


    return false;
}

void Figure::maj_position()
{

}

void Figure::setCouleur(Couleur c)
{
    this->couleur_cellule = c;
}

Couleur Figure::getCouleur()
{
    return this->couleur_cellule;
}

void Figure::monter()
{
    int nouvel_abscisse_origine = origine_x-1;
    int nouvelle_ordonne_origine = origine_y;

    setPosition(nouvel_abscisse_origine,nouvelle_ordonne_origine);
    maj_position();
}


void Figure::initialiser_coordonnees()
{
    origine_x = ORIGINE_X_DEFAULT;
    origine_y = ORIGINE_Y_DEFAULT;
}

void Figure::afficher_position()
{
    cout << "origine x :" << this->origine_x << endl
    << "origine y:" << this->origine_y << endl;


    vector<Position> figure = this->cellules[this->rotation_etat];
    int i=1;

    for(Position cellule : figure)
    {
        cout << "Cellule " << i << " x:" << cellule.ligne << " (" << cellule.ligne+origine_x << ")"
        " y:" << cellule.colonne << " (" << cellule.colonne+origine_y << ")" <<endl;
        i++;
    }

}

bool Figure::peut_monter()
{

    int origine_x_qui_monte = origine_x-1;

    return origine_x_qui_monte>=0;

}

bool Figure::peut_descendre(int nb_lignes_grille)
{
    int origine_x_qui_descend = origine_x + 1;

    return origine_x_qui_descend<nb_lignes_grille;
}

bool  Figure::peut_aller_a_gauche()
{
    int origine_y_qui_va_a_gauche = origine_y-1;

    return origine_y_qui_va_a_gauche>=0;
}

bool  Figure::peut_aller_a_droite(int nb_colonnes_grille)
{
    int origine_y_qui_va_a_gauche = origine_y+1;

    return origine_y_qui_va_a_gauche<nb_colonnes_grille;
}

