#include "SFigure.h"

SFigure::SFigure(int origine_ligne, int origine_colonne, int p_couleur)
{
    //ctor

    Couleur c(p_couleur);

    this->id = S_Figure;
    this->couleur_cellule = c;

    this->setPosition(origine_ligne,origine_colonne);

    this->nb_rotations_possibles = 2;


    maj_position();

    this->nom_forme = "SFigure";

}

SFigure::SFigure()
{
    Couleur c(noir);

    this->id = S_Figure;
    this->couleur_cellule = c;

    initialiser_coordonnees();

    this->nb_rotations_possibles = 2;

    this->nom_forme = "SFigure";

    maj_position();
}


void SFigure::maj_position()
{
    int origine_ligne  = this->origine_x;
    int origine_colonne  = this->origine_y;

    this->cellules[0] = {
        Position(origine_ligne+1,origine_colonne+1),
        Position(origine_ligne+1,origine_colonne+2),
        Position(origine_ligne+2,origine_colonne),
        Position(origine_ligne+2,origine_colonne+1)
    };

    this->cellules[1] = {
        Position(origine_ligne,origine_colonne+1),
        Position(origine_ligne+1,origine_colonne+1),
        Position(origine_ligne+1,origine_colonne+2),
        Position(origine_ligne+2,origine_colonne+2)
    };


}

