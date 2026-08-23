#include "Test.h"

#include "Grille.h"

#include <iostream>

Test::Test()
{
    //ctor
}

Test::~Test()
{
    //dtor
}
/*
Test
Grille initialement vide
Occuper une case
Déplacement gauche
Déplacement droite
Limite gauche
Limite droite
Collision avec le bas
Collision avec une pièce
Fixation dans la grille
Nouvelle pièce
Rotation
Formes à 4 cellules
Suppression d'une ligne
Game over	*/

void Test::afficher_message_ok()
{
    cout << endl << "--> ok" << endl;
}

void Test::test_creation_grille_si_vide()
{
    Grille grille;

    int cellule = 0;


    cout << "test creation grille vide";
    for( vector<int> ligne : grille.get_contenu() )
    {
        for( int i: ligne )
        {
            assert(i==gris_fonce);
        }
    }
    afficher_message_ok();

}

void Test::case_occupee()
{
    Grille g;
    Couleur cnoir;//noir


    g.dessiner(0,0,cnoir);

    cout << "Test case occupee 0,0 noir";

    assert(!g.est_vide(0,0));

    afficher_message_ok();



    Couleur crouge(r_ouge);

    cout << "Test case occupee 5,5 rouge ";
    g.dessiner(5,5,crouge);
    assert(!g.est_vide(5,5));
    afficher_message_ok();


    Couleur cvert(v_ert);


    cout << "Test case occupee "<<g.get_nb_lignes()-1 << " ," << g.get_nb_colonnes()-1 << " rouge ";
    g.dessiner(g.get_nb_lignes()-1,g.get_nb_colonnes()-1,cvert);
    assert(!g.est_vide(g.get_nb_lignes()-1,g.get_nb_colonnes()-1));
    afficher_message_ok();




}
