#include "Grille.h"

#include <array>
#include <iostream>

using namespace std;

Grille::Grille()
{
    //ctor

    nb_colonnes = 10;
    nb_lignes = 20;


    this->taille_pixels_cellule = 30;

    initialiser();

}


void Grille::initialiser()
{
    for(int ligne = 0 ; ligne < nb_lignes ; ligne++ )
    {
        for(int colonne = 0 ; colonne < nb_colonnes ; colonne++)
        {
                contenu[ligne][colonne] = 0;
        }
    }

}

void Grille::afficher()
{
    for(int ligne = 0 ; ligne < nb_lignes ; ligne++ )
    {
        for(int colonne = 0 ; colonne < nb_colonnes ; colonne++)
        {
                cout << contenu[ligne][colonne] << " ";
        }
        cout << endl ;
    }
}


