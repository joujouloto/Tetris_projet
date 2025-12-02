#include "JFigure.h"

JFigure::JFigure(int origine_ligne, int origine_colonne, int p_couleur)
{
    Couleur c(p_couleur);


    this->id = J_Figure;
    this->couleur_cellule = c;
    this->cellules[0] = { Position(origine_ligne,origine_colonne),Position(origine_ligne+1,origine_colonne),Position(origine_ligne+1,origine_colonne+1),Position(origine_ligne+1,origine_colonne+2)};
    /*pas bon*/this->cellules[1] = { Position(origine_ligne,origine_colonne),Position(origine_ligne+1,origine_colonne),Position(origine_ligne+2,origine_colonne),Position(origine_ligne+3,origine_colonne)};
}

void JFigure::maj_position()
{


}

void JFigure::rotation()
{

}
