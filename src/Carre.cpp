#include "Carre.h"

#include "Figure.h"

Carre::Carre(int origine_ligne, int origine_colonne, int p_couleur)
{
    //ctor
    Couleur c(p_couleur);


    this->id = C_arre;
    this->couleur_cellule = c;
    this->cellules[0] = { Position(origine_ligne,origine_colonne),Position(origine_ligne,origine_colonne+1),Position(origine_ligne+1,origine_colonne),Position(origine_ligne+1,origine_colonne+1)};

}
