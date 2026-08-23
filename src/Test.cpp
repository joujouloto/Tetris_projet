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

void Test::test_creation_grille_si_vide()
{
    Grille grille;

    int cellule = 0;


    cout << "test creation grille vide" << endl;
    for( vector<int> ligne : grille.get_contenu() )
    {
        for( int i: ligne )
        {
            assert(i==gris_fonce);
        }
    }
    cout << "--> ok" << endl;

}

void Test::case_occupee()
{
    Grille g;
    Couleur cnoir;//noir


    g.dessiner(0,0,cnoir);

    cout << "Test case occupee 0,0 noir" << endl;

    assert(!g.est_vide(0,0));

    cout << "--> ok" << endl;



    Couleur crouge(r_ouge);

    cout << "Test case occupee 5,5 rouge " << endl;
    g.dessiner(5,5,crouge);
    assert(!g.est_vide(5,5));
    cout << "--> ok" << endl;


    Couleur cvert(v_ert);


    cout << "Test case occupee "<<g.get_nb_lignes()-1 << " ," << g.get_nb_colonnes()-1 << " rouge " << endl;
    g.dessiner(g.get_nb_lignes()-1,g.get_nb_colonnes()-1,cvert);
    assert(!g.est_vide(g.get_nb_lignes()-1,g.get_nb_colonnes()-1));
    cout << "--> ok" << endl;




}
