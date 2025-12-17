#include "Jeu.h"

#include <random>





#include "Figure.h"
#include "Carre.h"
#include "Barre.h"


#include "JFigure.h"
#include "LFigure.h"
#include "ZFigure.h"
#include "SFigure.h"
#include "TFigure.h"

Jeu::Jeu()
{

    grille = Grille();
    figures = get_toutes_les_figures();
    this->figure_courante = this->get_figure_aleatoire();
    this->prochaine_figure = this->get_figure_aleatoire();


}

Figure Jeu::get_figure_aleatoire()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, figures.size()-1);//le nombre aléatoire peut tomber entre 1 et 4
    int index_aleatoire= dis(gen);


    if(figures.empty())
    {
        figures = get_toutes_les_figures();
    }



    Figure figure = figures[index_aleatoire];

    figures.erase(figures.begin()+index_aleatoire);

    return figure;

}

vector<Figure> Jeu::get_toutes_les_figures()
{
    return {Barre(),Carre(),JFigure(),LFigure(),SFigure(),TFigure(),ZFigure()};
}

void Jeu::dessiner()
{
    grille.dessiner();
}




