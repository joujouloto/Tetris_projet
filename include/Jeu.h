#ifndef JEU_H
#define JEU_H

#include "Grille.h"
#include "Figure.h"
#include <vector>


class Jeu
{
    public:
        Jeu();
        Grille * grille;


        vector <Couleur> couleurs;

        Figure get_figure_aleatoire();
        vector<Figure> get_tous_les_figures();


        void dessiner_figure_courante();
        void effacer_figure_courante();


        void deplacer_vers_le_bas_la_figure_courante();
        void deplacer_vers_la_droite_la_figure_courante();
        void deplacer_vers_la_gauche_la_figure_courante();

        bool figure_courante_a_atteint_le_bas();
        bool figure_courante_est_en_haut();


        bool figure_courante_en_collision_par_le_bas();



        Couleur set_figure_courante_couleur_aleatoire();

        vector <Figure> figures;
        Figure figure_courante;
        Figure figure_suivante;

        bool jeu_termine = false;



    protected:

    private:


};

#endif // JEU_H
