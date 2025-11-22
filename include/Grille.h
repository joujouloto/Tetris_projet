#ifndef GRILLE_H
#define GRILLE_H

#include <vector>

using namespace std;


class Grille
{
    public:
        Grille();
        void initialiser();
        int contenu[20][10];
        void afficher();

    protected:




    private:

        int nb_colonnes;
        int nb_lignes;

        int taille_pixels_cellule;





};

#endif // GRILLE_H
