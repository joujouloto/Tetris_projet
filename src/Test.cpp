#include "Test.h"

#include "Grille.h"
#include "Barre.h"
#include "SFigure.h"
#include "Carre.h"
#include "TFigure.h"
#include "ZFigure.h"

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
Collision avec le bas (limite bas)
Collision avec le haut (limite haut)
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

void Test::deplacement_a_gauche()
{
    cout << "Deplacement a gauche ";

    Grille g;
    Barre b(0,1,noir);

    cout << " Barre 0,1 noir " ;
    g.dessiner(&b);



    b.aller_a_gauche();

    g.effacer(&b);

    g.dessiner(&b);


    assert(!g.est_vide(0,0));
    afficher_message_ok();



    cout << " sfigure rouge 5,5 (origine)";
    SFigure sf(5,5,r_ouge);
    g.dessiner(&sf);

    sf.aller_a_gauche();
    g.effacer(&sf);

    g.dessiner(&sf);

    assert(!g.est_vide(5,5));//voir dans sfigure la figure est compris dans un rectangle plus grand donc l'origine est 0,0 mais la case occupee est 0,1...etc
    afficher_message_ok();

}

void Test::deplacement_a_droite()
{
    cout << "Deplacement a gauche ";

    Grille g;
    Barre b(0,0,noir);

    cout << " Barre 0,0 noir " ;
    g.dessiner(&b);



    b.aller_a_droite();

    g.effacer(&b);

    g.dessiner(&b);


    assert(!g.est_vide(0,4));
    afficher_message_ok();



    cout << " sfigure rouge 5,5 (origine)";
    SFigure sf(5,5,r_ouge);
    g.dessiner(&sf);

    sf.aller_a_droite();
    g.effacer(&sf);

    g.dessiner(&sf);

    assert(!g.est_vide(5,6));//voir dans sfigure la figure est compris dans un rectangle plus grand donc l'origine est 0,0 mais la case occupee est 0,1...etc
    afficher_message_ok();
}

void Test::limite_gauche()
{
    cout << "Limite gauche ";

    Grille g;
    Barre b(0,0,noir);


    cout << " Barre 0,0 noir " ;
    g.dessiner(&b);

    cout << "Test de la fonction peut aller a gauche doit indiquer qu'elle peut pas car au bord ";

    assert(!b.peut_aller_a_gauche(&g));
    afficher_message_ok();



    cout << "Test que aller a gauche ne modifie pas les coordonnees";

    if(b.peut_aller_a_gauche(&g))
    {
        b.aller_a_gauche();
    }

    cout << "origine y " << b.get_origine_y() << endl;
    assert(b.get_origine_y()==0);
    afficher_message_ok();

}

void Test::limite_droite()
{
    Grille g;
    cout << "Limite droite ";

    cout << " Carre 0,"<<g.get_nb_colonnes()-2<<" vert ";

    Carre c(0,g.get_nb_colonnes()-2,v_ert);

    cout << "peut aller droite ";


    if(c.peut_aller_a_droite(&g))
    {
        c.aller_a_droite();
    }

    cout << " c.get_origine_y()= "<< c.get_origine_y()<< "g.get_nb_colonnes()-2="<< g.get_nb_colonnes()-2 << endl;


    assert(c.get_origine_y()==g.get_nb_colonnes()-2);
    afficher_message_ok();
}

void Test::limite_bas()
{
    Grille g;
    cout << "Limite bas ";cout << endl;

    cout << "TFigure "<<g.get_nb_lignes()-1<<",0 jaune";
    TFigure tf(g.get_nb_lignes()-1,0,jaune);


    if(tf.peut_descendre(&g))
    {
        tf.descendre();
    }
    assert(tf.get_origine_x()==g.get_nb_lignes()-1);
    afficher_message_ok();


}

void Test::limite_haut()
{
    cout << "Limite haut " << endl;

    Grille g;

    cout << " ZFigure 0 0 violet";
    ZFigure zf(0,0,violet);




    if(zf.peut_monter(&g))
    {
        zf.monter();
    }
    assert(zf.get_origine_x()==0);
    afficher_message_ok();
}

void Test::collision_avec_une_piece()
{
    cout << "collision avec une piece " <<endl;


    Barre b(0,0,noir);
    cout << " Barre 0,0 noir ";


    Grille g;

    g.occuper(0,4);

    assert(!b.peut_aller_a_droite(&g));

    afficher_message_ok();

}

void Test::voir_position_reelles()
{
    Barre b(0,0,noir);

    b.voir_positions_reelles_cellules();

    afficher_message_ok();
}

