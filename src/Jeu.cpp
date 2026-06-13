#include "Jeu.h"

#include "Carre.h"
#include "Barre.h"
#include "JFigure.h"
#include "LFigure.h"
#include "ZFigure.h"
#include "SFigure.h"
#include "TFigure.h"



#include <iostream>

#include <chrono>
#include <random>

Jeu::Jeu()
{
    Couleur c;


    grille = new Grille();





    couleurs = c.get_cellules_couleur();


    figures =
    get_tous_les_figures();



    figure_courante = get_figure_aleatoire();


    figure_suivante = get_figure_aleatoire();

    figure_courante.setCouleur(set_figure_courante_couleur_aleatoire());
    figure_suivante.setCouleur(set_figure_courante_couleur_aleatoire());


    dessiner_figure_courante();

}

Figure Jeu::get_figure_aleatoire()
{


    if(figures.empty())
    {

        figures = get_tous_les_figures();

    }


    // construct a trivial random generator engine from a time-based seed:
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);

    uniform_int_distribution<int> distribution(0,figures.size()-1);




    int index_aleatoire =  distribution(generator) ;



    Figure figure = figures[index_aleatoire];
    //figures.erase(figures.begin()+index_aleatoire);
    /*
        Erreur de segmentation fault
    */




    return figure;
}

/*
return {Barre(),Carre(),JFigure(),LFigure(),SFigure(),TFigure(),ZFigure()};

J'avais codé ceci mais ça plantait le programme, ça tombait sur un segmentation fault. Je vais copier
comme j'ai fait pour get couleur de couleur

Apparament c'est l'oubli de Figure devant chaque figure qui fait planter le programme

Je suppose qu'on fournit une variable y a pas d'adresse mémoire ça marche pour l'initialisation mais apres qu'il y ait plus de
figures, ca plante

*/


vector<Figure> Jeu::get_tous_les_figures()
{
    vector<Figure> nouvelles_figures;


    nouvelles_figures.push_back(Barre());
    nouvelles_figures.push_back(Carre());
    nouvelles_figures.push_back(JFigure());
    nouvelles_figures.push_back(LFigure());
    nouvelles_figures.push_back(SFigure());
    nouvelles_figures.push_back(TFigure());
    nouvelles_figures.push_back(ZFigure());


    return nouvelles_figures;

    //return {Barre(),Carre(),JFigure(),LFigure(),SFigure(),TFigure(),ZFigure()}; CA FAIT PLANTER!!!
}

void Jeu::dessiner_figure_courante()
{
    vector<Position> figure = figure_courante.cellules[figure_courante.rotation_etat];

    for(Position cellule: figure)
    {
        grille->
        dessiner(figure_courante.origine_x+cellule.ligne,
                 figure_courante.origine_y+cellule.colonne,
                 figure_courante.couleur_cellule);


    }

    cout << figure_courante.origine_x << " " << figure_courante.origine_y << endl;
}

void Jeu::deplacer_vers_le_bas_la_figure_courante()
{
    effacer_figure_courante();
    if( !figure_courante_va_atteindre_le_bas() && !figure_courante.est_en_collision_en_bas(this->grille) )
    {

        figure_courante.descendre();
        dessiner_figure_courante();


    }
    else if(figure_courante_va_atteindre_le_bas() || figure_courante.est_en_collision_en_bas(this->grille))
    {
        dessiner_figure_courante();
        figure_courante = get_figure_aleatoire();

        figure_courante.setCouleur(set_figure_courante_couleur_aleatoire());


    }


    if(figure_courante_est_en_haut()&&figure_courante.est_en_collision_en_haut(this->grille))
    {
        jeu_termine = true;
    }





}

void Jeu::deplacer_vers_la_droite_la_figure_courante()
{
    if( !figure_courante.est_en_collision_a_droite(this->grille))
    {
        effacer_figure_courante();
        this->figure_courante.aller_a_droite();
        dessiner_figure_courante();
    }


}

void Jeu::deplacer_vers_la_gauche_la_figure_courante()
{
    if( !figure_courante.est_en_collision_a_gauche(this->grille))
    {
        effacer_figure_courante();
        this->figure_courante.aller_a_gauche();
        dessiner_figure_courante();
    }

}

Couleur Jeu::set_figure_courante_couleur_aleatoire()
{
    Couleur c(gris_fonce);


    if(couleurs.empty())
    {



        couleurs = c.get_cellules_couleur();


    }


    // construct a trivial random generator engine from a time-based seed:
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);

    uniform_int_distribution<int> distribution(0,figures.size()-1);


    int index_aleatoire =  distribution(generator) ;
    c = couleurs[index_aleatoire];

    couleurs.erase(couleurs.begin()+index_aleatoire);


    return c;

}

void Jeu::effacer_figure_courante()
{
    vector<Position> figure = figure_courante.cellules[figure_courante.rotation_etat];

    for(Position cellule: figure)
    {
        grille->
        dessiner(
                 figure_courante.origine_x+cellule.ligne,
                 figure_courante.origine_y+cellule.colonne,
                 grille->couleur_fonds);

    }
}

bool Jeu::figure_courante_va_atteindre_le_bas()
{
    vector<Position> figure = figure_courante.cellules[figure_courante.rotation_etat];

    for(Position cellule: figure)
    {
        if( figure_courante.origine_x+cellule.ligne+1 >= grille->nb_lignes )
        {
            return true;
        }
    }

    return false;
}

bool Jeu::figure_courante_est_en_haut()
{

    vector<Position> figure = figure_courante.cellules[figure_courante.rotation_etat];


    /*
        Ne passe jamais dans la condition suivante
        figure_courante.origine_x+cellule.ligne < 0
    */



    for(Position cellule: figure)
    {
        if( figure_courante.origine_x+cellule.ligne-1 < 0  )
        {
            return true;
        }
    }

    return false;

}










