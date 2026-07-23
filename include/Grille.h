#ifndef GRILLE_H
#define GRILLE_H

#include <vector>

#include "Couleur.h"

#define NB_LIGNES_DEFAULT 20
#define NB_COLONNES_DEFAULT 15
#define TAILLE_PIXELS_DEFAULT 40



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



    protected:




    private:







};

#endif // GRILLE_H
