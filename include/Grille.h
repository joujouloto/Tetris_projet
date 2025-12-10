#ifndef GRILLE_H
#define GRILLE_H

#include <vector>

#include "Couleur.h"


using namespace std;


class Grille
{
    public:
        Grille();
        void initialiser();
        vector <vector<int>> contenu;
        void afficher();
        void dessiner(int num_ligne, int num_colonne, Couleur c);

        int nb_colonnes;
        int nb_lignes;

        int taille_pixels_cellule;
        Couleur couleur_fonds;

        bool est_vide(int num_ligne, int num_colonne);
        bool est_dans_la_grille(int num_ligne, int num_colonne);

    protected:




    private:







};

#endif // GRILLE_H
