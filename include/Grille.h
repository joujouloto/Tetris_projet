#ifndef GRILLE_H
#define GRILLE_H

#include <vector>

using namespace std;


class Grille
{
    public:
        Grille();
        void dessiner_sdl();
        void afficher_dans_console();

    protected:




    private:

        int nb_cases_par_ligne;
        int nb_lignes;

        int taille_pixels_cellule;


        vector<vector<int>> conteneur;


};

#endif // GRILLE_H
