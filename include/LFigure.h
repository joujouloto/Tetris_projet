#ifndef LFIGURE_H
#define LFIGURE_H

#include "Figure.h"

class LFigure: public Figure
{
    public:
        LFigure(int origine_ligne, int origine_colonne, int p_couleur);

        void maj_position() override;
        void rotation() override;

    protected:

    private:
};

#endif // LFIGURE_H
