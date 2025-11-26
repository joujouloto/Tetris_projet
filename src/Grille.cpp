#include "Grille.h"

#include <iostream>

#include "Couleur.h"


using namespace std;

Grille::Grille()
{
    //ctor

    nb_colonnes = 15;
    nb_lignes = 20;

    initialiser();

    this->taille_pixels_cellule = 30;

    initialiser();

}


void Grille::initialiser()
{
    vector<int> contenu_ligne;

    int compteur_couleur = 0;
    Couleur c(compteur_couleur);

    for(int i=0 ; i< nb_lignes; i++)
    {
        for(int j=0 ; j<nb_colonnes; j++)
        {
            contenu_ligne.push_back(compteur_couleur);
            if(compteur_couleur==c.get_cellules_couleur().size()-1)
            {
                compteur_couleur=0;

            }else
            {
                compteur_couleur++;
            }
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

