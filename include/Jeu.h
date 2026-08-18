#ifndef JEU_H
#define JEU_H

#include "Grille.h"
#include "Figure.h"
#include <vector>


class Jeu
{
    public:
        Jeu();
        Figure get_figure_aleatoire();
        vector<Figure> get_tous_les_figures();
        Couleur set_figure_courante_couleur_aleatoire();
        void deplacer_vers_le_haut_la_figure_courante();

        void mettre_a_jour();
        bool est_termine();

        void afficher();



        //attributs besoin d emettre en public pour eviter d'appeler des méthodes et surcharger le code

    protected:


    private:
        vector <Figure> figures;
        Figure figure_courante;
        Figure figure_suivante;
        Grille * grille;
        vector <Couleur> couleurs;
        bool jeu_termine = false;



};

#endif // JEU_H
