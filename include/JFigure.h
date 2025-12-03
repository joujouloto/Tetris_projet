#ifndef JFIGURE_H
#define JFIGURE_H

#include "Figure.h"

class JFigure: public Figure
{
    public:
        JFigure(int origine_ligne, int origine_colonne, int p_couleur);

        void maj_position() override;


    protected:

    private:
};

#endif // JFIGURE_H
