#ifndef TFIGURE_H
#define TFIGURE_H

#include "Figure.h"

class TFigure: public Figure
{
    public:
        TFigure(int origine_ligne, int origine_colonne, int p_couleur);

        void maj_position() override;
        void rotation() override;

    protected:

    private:
};

#endif // TFIGURE_H
