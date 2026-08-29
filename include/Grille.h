#ifndef GRILLE_H
#define GRILLE_H

#include <vector>

#include "Couleur.h"

#define NB_LIGNES_DEFAULT 20
#define NB_COLONNES_DEFAULT 15
#define TAILLE_PIXELS_DEFAULT 40



using namespace std;

class Figure;// Déclaration anticipée


class Grille
{
    public:
        Grille();
        void initialiser();
        void afficher();

        void dessiner(int num_ligne, int num_colonne, Couleur c);
        void occuper(int num_ligne, int num_colonne);

        void dessiner(Figure * f);
        void effacer(Figure * f);


        bool n_est_pas_occupee(int num_ligne, int num_colonne);



        bool est_vide(int num_ligne, int num_colonne);

        int get_nb_colonnes();
        int get_nb_lignes();


        vector < vector<int> > get_contenu();
        Couleur getCouleurFonds();

    protected:

        int taille_pixels_cellule;
        Couleur couleur_fonds;
        vector <vector<int>> contenu;


    private:
        int nb_colonnes;
        int nb_lignes;






};

#endif // GRILLE_H
