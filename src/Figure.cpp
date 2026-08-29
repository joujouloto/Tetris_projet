#include "Figure.h"

#include <iostream>
#include <sstream>

#include <map>
#include <vector>

#include "Position.h"
#include "Couleur.h"
#include "Grille.h"

using namespace std;

Figure::Figure()
{
    cellule_taille = 30;
    rotation_etat = 0;
    this->couleur_cellule = noir;

    this->initialiser_coordonnees();

    this->nb_rotations_possibles = 1;

}




Figure::Figure(int origine_ligne, int origine_colonne)
{
    cellule_taille = 30;
    rotation_etat = 0;
    this->couleur_cellule = noir;

    setPosition(origine_ligne,origine_colonne);

    this->nb_rotations_possibles = 1;


}

string Figure::to_string()
{
    stringstream ss;

	ss << "nom_forme:";
	ss << this->nom_forme;
	ss << "\n";


	return ss.str();

}

void Figure::setPosition(Position p)
{
    this->origine_x = p.getLigne();
    this->origine_y = p.getColonne();

}


void Figure::setPosition(int p_x, int p_y)
{
    this->origine_x = p_x;
    this->origine_y = p_y;
}

void Figure::descendre()
{
    int nouvel_abscisse_origine = origine_x+1;
    int nouvelle_ordonne_origine = origine_y;

    setPosition(nouvel_abscisse_origine,nouvelle_ordonne_origine);
    maj_position();


}

void Figure::rotation_sens_antihoraire(Grille * grille) //  attention la barre n'a que 2 rotations possibles
//donc antihoraire est pareil que horaire
{
    if(!this->est_en_collision_en_rotation_gauche(grille))
    {
         if(this->rotation_etat==this->nb_rotations_possibles-1)
        {
            rotation_etat = 0;

        }else
        {
            rotation_etat++;
        }
    }
}

void Figure::rotation_sens_horaire(Grille * grille) //  attention la barre n'a que 2 rotations possibles
//donc antihoraire est pareil que horaire
{
    if(!this->est_en_collision_en_rotation_droite(grille))
    {
        if(this->rotation_etat==0)
        {
            rotation_etat = this->nb_rotations_possibles-1;

        }else
        {
            rotation_etat--;
        }
    }


}

void Figure::aller_a_gauche()
{

        int nouvel_abscisse_origine = origine_x;
        int nouvelle_ordonne_origine = origine_y-1;


        setPosition(nouvel_abscisse_origine,nouvelle_ordonne_origine);
        maj_position();
}

void Figure::aller_a_droite()
{
    int nouvel_abscisse_origine = origine_x;
    int nouvelle_ordonne_origine = origine_y+1;

    setPosition(nouvel_abscisse_origine,nouvelle_ordonne_origine);
    maj_position();

}


/*
    La condition est toujours vrai pour le carre car je verifie sur chaque cellule si la cellule d'en bas
    est occupee et bien sur c'est occupée car le carre est composee de 2 cellules en haut
    et 2 cellules en bas.
    Il faut verifier si les cellule les plus en bas rentrent en collision.


    Retour en arriere, mal compris la condition est vide je me suis trompé et me suis mélangé les pinceaux
    la fatigue, j'ai visionné le tuto raylib tetris il ne fait pas pareil que moi

*/


bool Figure::est_en_collision_en_bas(Grille *grille)
{
    vector<Position> figure = cellules[rotation_etat];

    for(Position cellule : figure)
    {


        if(!grille->est_vide(cellule.getLigne() + 1, cellule.getColonne()))
        {
            return true;
        }
    }

    return false;
}

bool Figure::est_en_collision_en_haut(Grille * grille)
{
    vector<Position> figure = this->cellules[rotation_etat];

    for(Position cellule: figure)
    {
        if(!grille->est_vide(cellule.getLigne()-1,cellule.getColonne()))
        {
            return true;
        }
    }

    return false;
}

bool Figure::est_en_collision_a_gauche(Grille * grille)
{
    vector<Position> figure = this->cellules[rotation_etat];

    for(Position cellule: figure)
    {
        if(!grille->est_vide(cellule.getLigne(),cellule.getColonne()-1))
        {
            return true;
        }
    }

    return false;
}

bool Figure::est_en_collision_a_droite(Grille * grille)
{
    vector<Position> figure = this->cellules[rotation_etat];

    for(Position cellule: figure)
    {
        if(!grille->est_vide(cellule.getLigne(),cellule.getColonne()+1))
        {
            return true;
        }
    }

    return false;
}

bool Figure::est_en_collision_en_rotation_droite(Grille * grille)
{
    int future_rotation = rotation_etat-1;


    if(future_rotation<0)
    {
            future_rotation= this->nb_rotations_possibles-1;
    }

    vector<Position> figure = this->cellules[future_rotation];

    for(Position cellule: figure)
    {
        if(!grille->est_vide(cellule.getLigne(),cellule.getColonne()))
        {
            return true;
        }
    }

    return false;

}

bool Figure::est_en_collision_en_rotation_gauche(Grille * grille)
{
    int future_rotation = rotation_etat+1;


    if(future_rotation>this->nb_rotations_possibles-1)
    {
            future_rotation=0;

    }

    vector<Position> figure = this->cellules[future_rotation];

        for(Position cellule: figure)
        {
            if(!grille->est_vide(cellule.getLigne(),cellule.getColonne()))
            {
                return true;
            }
        }


    return false;
}

void Figure::maj_position()
{

}

void Figure::setCouleur(Couleur c)
{
    this->couleur_cellule = c;
}

Couleur Figure::getCouleur()
{
    return this->couleur_cellule;
}

void Figure::monter()
{
    int nouvel_abscisse_origine = origine_x-1;
    int nouvelle_ordonne_origine = origine_y;

    setPosition(nouvel_abscisse_origine,nouvelle_ordonne_origine);
    maj_position();
}


void Figure::initialiser_coordonnees()
{
    origine_x = ORIGINE_X_DEFAULT;
    origine_y = ORIGINE_Y_DEFAULT;
}

void Figure::afficher_position()
{
    cout << "origine x :" << this->origine_x << endl
    << "origine y:" << this->origine_y << endl;


    vector<Position> figure = this->cellules[this->rotation_etat];
    int i=1;

    for(Position cellule : figure)
    {
        cout << "Cellule " << i << " x:" << cellule.getLigne() << " (" << cellule.getLigne()+origine_x << ")"
        " y:" << cellule.getColonne() << " (" << cellule.getColonne()+origine_y << ")" <<endl;
        i++;
    }

}

bool Figure::peut_monter(Grille * g)
{

    vector < Position> reelles_position = donner_reelles_coordonnees_cellules();

    bool n_est_pas_occupee = false;

    for(Position p: reelles_position)
    {
       if(p.getLigne()-1<0)
       {
           return false;
       }
    }

    for(Position p: reelles_position)
    {
       n_est_pas_occupee = g->n_est_pas_occupee(p.getLigne()-1, p.getColonne());

       if(!n_est_pas_occupee)
       {
           return n_est_pas_occupee;
       }
    }


    return n_est_pas_occupee;

}

bool Figure::peut_descendre(Grille * g)
{
    vector <Position> reelles_positions = donner_reelles_coordonnees_cellules();



    bool n_est_pas_occupee = false;

    for(Position p: reelles_positions)
    {


       if(p.getLigne()+1>=g->get_nb_lignes())
       {
           return false;
       }
    }

    for(Position p: reelles_positions)
    {
       n_est_pas_occupee = g->n_est_pas_occupee(p.getLigne()+1, p.getColonne());

       if(!n_est_pas_occupee)
       {
           return n_est_pas_occupee;
       }
    }


    return n_est_pas_occupee;

}

bool  Figure::peut_aller_a_gauche(Grille * g)
{
    bool n_est_pas_occupee = true;


    vector <Position> reelles_positions = donner_reelles_coordonnees_cellules();

    for(Position p: reelles_positions)
    {
       if(p.getColonne()-1<0)
       {
           return false;
       }
    }

     for(Position p: reelles_positions)
    {
       n_est_pas_occupee = g->n_est_pas_occupee(p.getLigne(), p.getColonne()-1);

        if(!n_est_pas_occupee)
       {
           return n_est_pas_occupee;
       }
    }

    return n_est_pas_occupee;


}

bool  Figure::peut_aller_a_droite(Grille * g)
{

    bool n_est_pas_occupee = true;

    vector <Position> reelles_positions = donner_reelles_coordonnees_cellules();

    for(Position p: reelles_positions)
    {
       if(p.getColonne()+1>=g->get_nb_colonnes())
       {
           return false;
       }
    }


    for(Position p: cellules[this->getRotationEtat()])
    {
       n_est_pas_occupee = g->n_est_pas_occupee(p.getLigne(),p.getColonne()+1 );

       if(!n_est_pas_occupee)//si OCCUPEE
       {
           return n_est_pas_occupee;
       }
    }

    return n_est_pas_occupee;





}

map<int,vector<Position>> Figure::getCellules()
{
    return cellules;

}

int Figure::getRotationEtat()
{
    return rotation_etat;
}

int Figure::get_origine_y()
{
    return origine_y;
}

int Figure::get_origine_x()
{
    return origine_x;
}

vector<Position> Figure::donner_reelles_coordonnees_cellules()
{
    vector <Position> cellules_reelles_position;

    vector <Position> cellules_position_relatives = cellules[this->getRotationEtat()];


    for( Position position_reelle : cellules_position_relatives)
    {
        cellules_reelles_position.
        push_back(Position(position_reelle.getLigne()+origine_x,
                               position_reelle.getColonne()+origine_y));
    }


    return cellules_reelles_position;
}

void Figure::voir_positions_reelles_cellules()
{
    vector cellules_position_reelles = donner_reelles_coordonnees_cellules();


    for(Position p: cellules_position_reelles)
    {
        cout << p.toString();
    }


}

