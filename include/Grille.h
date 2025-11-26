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

    protected:




    private:







};

#endif // GRILLE_H
