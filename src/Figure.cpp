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
    this->couleur_cellule = -1;

    this->origine_x=0;
    this->origine_y=0;

    this->nb_rotations_possibles = 1;

}




Figure::Figure(int origine_ligne, int origine_colonne)
{
    cellule_taille = 30;
    rotation_etat = 0;
    this->couleur_cellule = -1;

    this->origine_x=origine_ligne;
    this->origine_y=origine_colonne;

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

void Figure::dessiner(Grille * grille)
{
    vector<Position> figure = this->cellules[this->rotation_etat];

    for(Position cellule: figure)
    {
        grille->dessiner(cellule.ligne,cellule.colonne,this->couleur_cellule);

    }

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

void Figure::effacer(Grille * grille)
{
    vector<Position> figure = this->cellules[this->rotation_etat];

    for(Position cellule: figure)
    {
        grille->dessiner(cellule.ligne,cellule.colonne,grille->couleur_fonds);

    }

}

void Figure::descendre()
{
    setPosition(origine_x+1,origine_y);
    maj_position();

}

void Figure::rotation_sens_antihoraire()
{
     if(this->rotation_etat==this->nb_rotations_possibles-1)
    {
        rotation_etat = 0;

    }else
    {
        rotation_etat++;
    }
}

void Figure::rotation_sens_horaire()
{
    if(this->rotation_etat==0)
    {
        rotation_etat = this->nb_rotations_possibles-1;

    }else
    {
        rotation_etat--;
    }

}

void Figure::aller_a_gauche()
{
    setPosition(origine_x,origine_y-1);
    maj_position();
}

void Figure::aller_a_droite()
{
    setPosition(origine_x,origine_y+1);
    maj_position();
}
