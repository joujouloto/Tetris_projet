#include "Barre.h"

Barre::Barre(int origine_ligne, int origine_colonne, int p_couleur)
{
    //ctor
    Couleur c(p_couleur);


    this->id = B_arre;
    this->couleur_cellule = c;
    this->cellules[0] = { Position(origine_ligne,origine_colonne),Position(origine_ligne,origine_colonne+1),Position(origine_ligne,origine_colonne+2),Position(origine_ligne,origine_colonne+3)};
    this->cellules[1] = { Position(origine_ligne,origine_colonne),Position(origine_ligne+1,origine_colonne),Position(origine_ligne+2,origine_colonne),Position(origine_ligne+3,origine_colonne)};

}


void Barre::maj_position()
{
    int origine_ligne  = this->origine_x;
    int origine_colonne  = this->origine_y;

    this->cellules[0] = { Position(origine_ligne,origine_colonne),Position(origine_ligne,origine_colonne+1),Position(origine_ligne,origine_colonne+2),Position(origine_ligne,origine_colonne+3)};
    this->cellules[1] = { Position(origine_ligne,origine_colonne),Position(origine_ligne+1,origine_colonne),Position(origine_ligne+2,origine_colonne),Position(origine_ligne+3,origine_colonne)};
}


void Barre::rotation()
{
    if(this->rotation_etat==1)
    {
        rotation_etat = 0;

    }else
    {
        rotation_etat=1;
    }
}
