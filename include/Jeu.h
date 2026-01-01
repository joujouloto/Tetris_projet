#ifndef JEU_H
#define JEU_H

#include "Grille.h"
#include "Figure.h"
#include <vector>


class Jeu
{
    public:
        Jeu();
        Grille grille;


        Figure get_figure_aleatoire();
        vector<Figure> get_tous_les_figures();
        void dessiner();


        void deplacer_vers_le_bas_la_figure_courante();
        void deplacer_vers_la_droite_la_figure_courante();
        void deplacer_vers_la_gauche_la_figure_courante();


    protected:

    private:
        vector <Figure> figures;
        Figure figure_courante;
        Figure figure_suivante;

};

#endif // JEU_H
