#include "Grille.h"

#include <iostream>

#include "Couleur.h"
#include "Position.h"

#include <map>

#include "Figure.h"



using namespace std;

Grille::Grille()
{
    //ctor

    nb_colonnes = NB_COLONNES_DEFAULT;
    nb_lignes = NB_LIGNES_DEFAULT;

    couleur_fonds = Couleur(gris_fonce);


    this->taille_pixels_cellule = TAILLE_PIXELS_DEFAULT;

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
    if((num_ligne>=0||num_ligne<this->nb_lignes) && (num_colonne>=0||num_colonne<this->nb_colonnes))
    {

        contenu[num_ligne][num_colonne] = c.getId();



    }

}

void Grille::dessiner(Figure * f)
{
   vector<Position> cellules = f->getCellules()[f->getRotationEtat()];


    for(Position cellule: cellules)
    {
        contenu[cellule.getLigne()][cellule.getColonne()] = f->getCouleur().getId();
    }



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


vector < vector<int> > Grille::get_contenu()
{
    return contenu;
}

int Grille::get_nb_lignes()
{
    return nb_lignes;
}

int Grille::get_nb_colonnes()
{
    return nb_colonnes;
}


