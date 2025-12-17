#ifndef JEU_H
#define JEU_H

#include "Grille.h"
#include "Figure.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

class Jeu
{
    public:
        Jeu();
        Grille grille;
        Figure get_figure_aleatoire();
        vector<Figure> figures;
        vector<Figure> get_toutes_les_figures();

        void dessiner();


    protected:

    private:

        Figure figure_courante;
        Figure prochaine_figure;




};

#endif // JEU_H
