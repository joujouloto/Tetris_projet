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


        void dessiner_figure_courante();
        void effacer_figure_courante();


        void deplacer_vers_le_bas_la_figure_courante();
        void deplacer_vers_la_droite_la_figure_courante();
        void deplacer_vers_la_gauche_la_figure_courante();

        bool figure_courante_va_atteindre_le_bas();
        bool figure_courante_est_en_haut();


        Couleur set_figure_courante_couleur_aleatoire();



        void deplacer_vers_le_haut_la_figure_courante();

        //attributs besoin d emettre en public pour eviter d'appeler des méthodes et surcharger le code
        vector <Figure> figures;
        Figure figure_courante;
        Figure figure_suivante;
        Grille * grille;
        vector <Couleur> couleurs;
        bool jeu_termine = false;


    protected:




    private:



};

#endif // JEU_H
