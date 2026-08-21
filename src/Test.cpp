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


    for( vector<int> ligne : grille.get_contenu() )
    {
        for( int i: ligne )
        {
            assert(i==gris_fonce);
        }
    }






}
