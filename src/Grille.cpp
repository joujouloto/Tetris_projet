#include "Grille.h"

#include <array>
#include <iostream>

using namespace std;

Grille::Grille()
{
    //ctor

    nb_cases_par_ligne = 10;
    nb_lignes = 20;




    vector<int> ligne;


    for(int j = 0 ; j < nb_cases_par_ligne ; j++)
    {

            ligne.push_back(0);
    }





    for(int i = 0; i < nb_lignes ; i++)
    {
        conteneur.push_back(ligne);

    }







}

void Grille::afficher_dans_console()
{
    vector<vector<int>>::iterator iterateur_grille_ligne;
     vector<int>::iterator iterateur_case;

     int  i = 0;
     int j = 0;

    vector<int> vecteur_de_cases_d_une_ligne;


    for(iterateur_grille_ligne = conteneur.begin(); iterateur_grille_ligne != conteneur.end() ; iterateur_grille_ligne++)
    {

        vecteur_de_cases_d_une_ligne = *iterateur_grille_ligne;

        for(iterateur_case = vecteur_de_cases_d_une_ligne.begin(); iterateur_case != vecteur_de_cases_d_une_ligne.end() ; iterateur_case++ )
        {
             cout << i << "," << j << ":"<< *iterateur_case << endl;
            j++;

        }
        i++;
        j=0;
    }

}
