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




/*
    couleurs = c.get_cellules_couleur();


    figures =
    get_tous_les_figures();



    figure_courante = get_figure_aleatoire();


    figure_suivante = get_figure_aleatoire();

    figure_courante.setCouleur(set_figure_courante_couleur_aleatoire());
    figure_suivante.setCouleur(set_figure_courante_couleur_aleatoire());
*/
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


/*
    penser a ne pas appeler tableau mais c'est un vecteur je veux dire ne pas appele rles indices juste changer la position

*/


vector<Figure> Jeu::get_tous_les_figures()
{
    vector<Figure> nouvelles_figures;


    /*
        Les figure existent dans des rectangles et les coordonnees
        sont par rapport à l'origine de ce rectangle (origine =0,0)
    */



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

bool Jeu::est_termine()
{
    return this->jeu_termine;
}

void Jeu::afficher()
{
    cout << "jeu" << endl;
}

void Jeu::mettre_a_jour()
{

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












