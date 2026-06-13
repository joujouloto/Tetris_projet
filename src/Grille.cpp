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
            contenu_ligne.push_back(gris_fonce);

        }

        contenu.push_back(contenu_ligne);
        contenu_ligne.clear();


    }




}

void Grille::afficher()
{
    vector<int> contenu_ligne;

    int i=1;

    for(vector<vector<int>>::iterator it = contenu.begin(); it!=contenu.end() ; it++ )
    {
        contenu_ligne = (*it);
        for(vector<int>::iterator it_ligne = contenu_ligne.begin() ; it_ligne!=contenu_ligne.end(); it_ligne++)
        {
            cout << (*it_ligne) << " ";
        }
        cout << endl;

        i++;
    }
}


void Grille::dessiner(int num_ligne, int num_colonne, Couleur c)
{
    contenu[num_ligne][num_colonne] = c.id;
}





bool Grille::est_vide(int num_ligne, int num_colonne)
{

    if(num_ligne<0||num_ligne>=nb_lignes)
    {
        return false;
    }

    if(num_colonne <0 || num_colonne >= nb_colonnes)
    {
        return false;
    }


    if( contenu[num_ligne][num_colonne]==gris_fonce)
    {
        return true;
    }
    return false;
}




