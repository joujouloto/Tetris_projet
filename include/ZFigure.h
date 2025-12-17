#ifndef ZFIGURE_H
#define ZFIGURE_H

#include "Figure.h"

class ZFigure: public Figure
{
    public:
        ZFigure(int origine_ligne, int origine_colonne, int p_couleur);
        ZFigure();

        void maj_position() override;


    protected:

    private:
};

#endif // ZFIGURE_H
