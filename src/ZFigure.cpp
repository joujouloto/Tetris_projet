#include "ZFigure.h"

ZFigure::ZFigure(int origine_ligne, int origine_colonne, int p_couleur)
{
    Couleur c(p_couleur);

    this->id = Z_Figure;
    this->couleur_cellule = c;

    this->origine_x = origine_ligne;
    this->origine_y = origine_colonne;



   this->nb_rotations_possibles = 2;

   maj_position();
}


void ZFigure::maj_position()
{
    int origine_ligne  = this->origine_x;
    int origine_colonne  = this->origine_y;

    this->cellules[0] = {
        Position(origine_ligne,origine_colonne),
        Position(origine_ligne,origine_colonne+1),
        Position(origine_ligne+1,origine_colonne+1),
        Position(origine_ligne+1,origine_colonne+2)
    };

    this->cellules[1] = {
        Position(origine_ligne,origine_colonne+1),
        Position(origine_ligne+1,origine_colonne),
        Position(origine_ligne+1,origine_colonne+1),
        Position(origine_ligne+2,origine_colonne)
    };



}

