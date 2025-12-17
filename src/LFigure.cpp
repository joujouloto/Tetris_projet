#include "LFigure.h"

LFigure::LFigure(int origine_ligne, int origine_colonne, int p_couleur)
{

    Couleur c(p_couleur);


    this->id = J_Figure;
    this->couleur_cellule = c;

    this->origine_x = origine_ligne;
    this->origine_y = origine_colonne;

    this->nb_rotations_possibles = 4;

    maj_position();
}

LFigure::LFigure()
{
    int noir = -1;

    Couleur c(noir);
    this->id = J_Figure;
    this->couleur_cellule = c;

    this->origine_x = -1;
    this->origine_y = -1;

    this->nb_rotations_possibles = 4;
}


void LFigure::maj_position()
{
    int origine_ligne  = this->origine_x;
    int origine_colonne  = this->origine_y;


    this->cellules[0] = { Position(origine_ligne,origine_colonne+1),
    Position(origine_ligne+1,origine_colonne+1),
    Position(origine_ligne+2,origine_colonne+1),
    Position(origine_ligne+2,origine_colonne+2)};

     this->cellules[1] =
     { Position(origine_ligne,origine_colonne+2),
     Position(origine_ligne+1,origine_colonne),
     Position(origine_ligne+1,origine_colonne+1),
     Position(origine_ligne+1,origine_colonne+2)};

     this->cellules[2] =
     { Position(origine_ligne,origine_colonne),
     Position(origine_ligne,origine_colonne+1),
     Position(origine_ligne+1,origine_colonne+1),
     Position(origine_ligne+2,origine_colonne+1)};

     this->cellules[3] =
     { Position(origine_ligne+1,origine_colonne),
     Position(origine_ligne+1,origine_colonne+1),
     Position(origine_ligne+1,origine_colonne+2),
     Position(origine_ligne+2,origine_colonne)};
}




