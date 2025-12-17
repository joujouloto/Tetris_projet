#ifndef SFIGURE_H
#define SFIGURE_H

#include "Figure.h"

class SFigure: public Figure
{
    public:
        SFigure(int origine_ligne, int origine_colonne, int p_couleur);
        SFigure();

        void maj_position() override;

    protected:

    private:
};

#endif // SFIGURE_H
