#include "Jeu.h"

#include "Carre.h"
#include "Barre.h"
#include "JFigure.h"
#include "LFigure.h"
#include "ZFigure.h"
#include "SFigure.h"
#include "TFigure.h"


#include <random>

Jeu::Jeu()
{


    figures =
    get_tous_les_figures();

    figure_courante = get_figure_aleatoire();
    figure_suivante = get_figure_aleatoire();





}

Figure Jeu::get_figure_aleatoire()
{

    if(figures.empty())
    {
        figures = get_tous_les_figures();

    }


    int index_aleatoire =  rand()% figures.size();
    Figure figure = figures[index_aleatoire];

    figures.erase(figures.begin()+index_aleatoire);
    return figure;
}

vector<Figure> Jeu::get_tous_les_figures()
{
    return {Barre(),Carre(),JFigure(),LFigure(),SFigure(),TFigure(),ZFigure()};
}

void Jeu::dessiner()
{

}

void Jeu::deplacer_vers_le_bas_la_figure_courante()
{

    if( grille.est_dans_la_grille(figure_courante.origine_x+1,figure_courante.origine_y)
        &&
        !figure_courante.est_en_collision_en_bas(&grille)
       )
    {
        this->figure_courante.descendre();
    }



}

void Jeu::deplacer_vers_la_droite_la_figure_courante()
{
    if( grille.est_dans_la_grille(figure_courante.origine_x,figure_courante.origine_y+1)
    &&
       !figure_courante.est_en_collision_a_droite(&grille)

       )
    {
        this->figure_courante.aller_a_droite();
    }


}

void Jeu::deplacer_vers_la_gauche_la_figure_courante()
{
    if( grille.est_dans_la_grille(figure_courante.origine_x,figure_courante.origine_y-1)
    &&
        ! figure_courante.est_en_collision_a_gauche(&grille)

       )
    {

        this->figure_courante.aller_a_gauche();
    }
}

