#ifndef CARRE_H
#define CARRE_H

#include "Figure.h"

class Carre: public Figure
{
    public:
        Carre(int origine_ligne, int origine_colonne, int p_couleur);

        void  maj_position() override;

    protected:

    private:
};

#endif // CARRE_H
