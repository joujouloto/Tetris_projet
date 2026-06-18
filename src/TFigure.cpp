#include "TFigure.h"

TFigure::TFigure(int origine_ligne, int origine_colonne, int p_couleur)
{
    Couleur c(p_couleur);

    this->id = T_Figure;
    this->couleur_cellule = c;

    this->setPosition(origine_ligne,origine_colonne);




    this->nb_rotations_possibles = 4;

    maj_position();

    this->nom_forme = "TFigure";


}

TFigure::TFigure()
{
    Couleur c(noir);

    this->id = T_Figure;
    this->couleur_cellule = c;

    initialiser_coordonnees();

    this->nb_rotations_possibles = 4;

    this->nom_forme = "TFigure";

    maj_position();
}



void TFigure::maj_position()
{
    int origine_ligne  = this->origine_x;
    int origine_colonne  = this->origine_y;

    this->cellules[0] = {
        Position(origine_ligne,origine_colonne+1),
        Position(origine_ligne+1,origine_colonne),
        Position(origine_ligne+1,origine_colonne+1),
        Position(origine_ligne+1,origine_colonne+2)
    };

    this->cellules[1] = {
        Position(origine_ligne,origine_colonne+1),
        Position(origine_ligne+1,origine_colonne),
        Position(origine_ligne+1,origine_colonne+1),
        Position(origine_ligne+2,origine_colonne+1)
    };



    this->cellules[2] = {
        Position(origine_ligne,origine_colonne),
        Position(origine_ligne+1,origine_colonne),
        Position(origine_ligne,origine_colonne+2),
        Position(origine_ligne+1,origine_colonne+1)
    };

    this->cellules[3] = {
        Position(origine_ligne,origine_colonne),
        Position(origine_ligne+1,origine_colonne),
        Position(origine_ligne+1,origine_colonne+1),
        Position(origine_ligne+2,origine_colonne)
    };

}


