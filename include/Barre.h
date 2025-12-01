#ifndef BARRE_H
#define BARRE_H

#include "Couleur.h"
#include "Figure.h"


class Barre: public Figure
{
    public:
        Barre(int origine_ligne, int origine_colonne, int p_couleur);

        void maj_position() override;
        void rotation() override;


    protected:

    private:
};

#endif // BARRE_H
