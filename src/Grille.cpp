#include "Grille.h"

#include <iostream>

#include "Couleur.h"


using namespace std;

Grille::Grille()
{
    //ctor

    nb_colonnes = 15;
    nb_lignes = 20;

    couleur_fonds = Couleur(gris_fonce);



    initialiser();

    this->taille_pixels_cellule = 40;

    initialiser();

}


void Grille::initialiser()
{
    vector<int> contenu_ligne;


    for(int i=0 ; i< nb_lignes; i++)
    {
        for(int j=0 ; j<nb_colonnes; j++)
        {
            contenu_ligne.push_back(couleur_fonds.id);

        }

        contenu.push_back(contenu_ligne);
        contenu_ligne.clear();


    }




}

void Grille::afficher()
{
    vector<int> contenu_ligne;

    for(vector<vector<int>>::iterator it = contenu.begin(); it!=contenu.end() ; it++ )
    {
        contenu_ligne = (*it);
        for(vector<int>::iterator it_ligne = contenu_ligne.begin() ; it_ligne!=contenu_ligne.end(); it_ligne++)
        {
            cout << (*it_ligne) << " ";
        }
        cout << endl;
    }
}


void Grille::dessiner(int num_ligne, int num_colonne, Couleur c)
{
    contenu[num_ligne][num_colonne] = c.id;
}

bool Grille::est_hors_grille(int num_ligne, int num_colonne)
{
    bool est_en_dehors = false;

    if( num_ligne<0 || num_ligne >= this->nb_lignes || num_colonne < 0 || num_colonne >= this->nb_colonnes)
    {
        est_en_dehors = true;
    }

    return est_en_dehors;



}


