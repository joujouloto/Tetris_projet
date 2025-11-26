#include "Carre.h"

#include "Figure.h"

Carre::Carre(int p_couleur)
{
    //ctor
    Couleur c(p_couleur);


    this->id = C_arre;
    this->couleur_cellule = c;
    this->cellules[0] = { Position(0,0),Position(0,1),Position(1,0),Position(1,1)};

}
