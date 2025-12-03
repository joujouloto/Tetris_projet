#include "Carre.h"

#include "Figure.h"

Carre::Carre(int origine_ligne, int origine_colonne, int p_couleur)
{
    //ctor
    Couleur c(p_couleur);

    this->origine_x = origine_ligne;
    this->origine_y = origine_colonne;

    this->nb_rotations_possibles = 1;


    this->id = C_arre;
    this->couleur_cellule = c;
    maj_position();

}

void Carre::maj_position()
{
    int origine_ligne  = this->origine_x;
    int origine_colonne  = this->origine_y;

    this->cellules[0] =
    { Position(origine_ligne,origine_colonne),
    Position(origine_ligne,origine_colonne+1),
    Position(origine_ligne+1,origine_colonne),
    Position(origine_ligne+1,origine_colonne+1)};

}



