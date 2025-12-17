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
    this->couleur_cellule = -1;

    this->origine_x=0;
    this->origine_y=0;

    this->nb_rotations_possibles = 1;

}




Figure::Figure(int origine_ligne, int origine_colonne)
{
    cellule_taille = 30;
    rotation_etat = 0;
    this->couleur_cellule = -1;

    this->origine_x=origine_ligne;
    this->origine_y=origine_colonne;

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

void Figure::dessiner(Grille * grille)
{
    vector<Position> figure = this->cellules[this->rotation_etat];


    for(Position cellule: figure)
    {
        grille->dessiner(cellule.ligne,cellule.colonne,this->couleur_cellule);

    }





}

void Figure::setPosition(Position p)
{
    this->origine_x = p.ligne;
    this->origine_y = p.colonne;

}


void Figure::setPosition(int p_x, int p_y)
{
    this->origine_x = p_x;
    this->origine_y = p_y;
}

void Figure::effacer(Grille * grille)
{
    vector<Position> figure = this->cellules[this->rotation_etat];

    for(Position cellule: figure)
    {
        grille->dessiner(cellule.ligne,cellule.colonne,grille->couleur_fonds);

    }

}

void Figure::descendre(Grille * grille)
{
    int nouvel_abscisse_origine = origine_x+1;
    int nouvelle_ordonne_origine = origine_y;



    if( grille->est_dans_la_grille(nouvel_abscisse_origine,nouvelle_ordonne_origine)
        &&
        !est_en_collision_en_bas(grille)
       )
    {
        setPosition(nouvel_abscisse_origine,nouvelle_ordonne_origine);
        maj_position();

    }
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

void Figure::aller_a_gauche(Grille * grille)
{
    int nouvel_abscisse_origine = origine_x;
    int nouvelle_ordonne_origine = origine_y-1;



    if( grille->est_dans_la_grille(nouvel_abscisse_origine,nouvelle_ordonne_origine)
    &&
        ! this->est_en_collision_a_gauche(grille)

       )
    {
        setPosition(nouvel_abscisse_origine,nouvelle_ordonne_origine);
        maj_position();
    }




}

void Figure::aller_a_droite(Grille * grille)
{
    int nouvel_abscisse_origine = origine_x;
    int nouvelle_ordonne_origine = origine_y+1;



    if( grille->est_dans_la_grille(nouvel_abscisse_origine,nouvelle_ordonne_origine)
    &&
       !this->est_en_collision_a_droite(grille)

       )
    {
        setPosition(nouvel_abscisse_origine,nouvelle_ordonne_origine);
        maj_position();
    }
}

bool Figure::est_en_collision_en_bas(Grille * grille)
{
    vector<Position> figure = this->cellules[rotation_etat];

    for(Position cellule: figure)
    {
        if(!grille->est_vide(cellule.ligne+1,cellule.colonne))
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
        if(!grille->est_vide(cellule.ligne,cellule.colonne-1))
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
        if(!grille->est_vide(cellule.ligne,cellule.colonne+1))
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
        if(!grille->est_vide(cellule.ligne,cellule.colonne))
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
            if(!grille->est_vide(cellule.ligne,cellule.colonne))
            {
                return true;
            }
        }


    return false;
}

void Figure::maj_position()
{

}

