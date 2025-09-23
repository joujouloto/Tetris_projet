#include "Figure.h"

#include <iostream>
#include <sstream>

using namespace std;



enum Forme {Carre, Barre, LFigure, SFigure, TFigure};


Figure::Figure(int p_num_forme)
{
    //ctor
    switch(p_num_forme)
    {
        case Carre:
            this->nom_forme = "Carre";
            this->adresse_image_associee = "images\\carre.xcf";
            break;

        case Barre:
            this->nom_forme = "Barre";
            this->adresse_image_associee = "images\\barre.xcf";
            break;

        case LFigure:
            this->nom_forme = "LFigure";
            this->adresse_image_associee = "images\\LFigure.xcf";

            break;

        case SFigure:

            this->nom_forme = "SFigure";
            this->adresse_image_associee = "images\\SFigure.xcf";
            break;

        case TFigure:
            this->nom_forme = "TFigure";
            this->adresse_image_associee = "images\\TFigure.xcf";

            break;

        default:
            cerr << "Erreur " << endl;


    }



}

Figure::~Figure()
{
    //dtor
}

 string Figure::get_nom_forme()
 {


     return this->nom_forme;
 } // Il y a 5 formes (Carré, Barre, LFigure, SFigure, TFigure)


const char * Figure::get_adresse_image_associee()
{

    return this->adresse_image_associee;
} //L'image que l'on affichera dans le jeu par exemple: .../Barre.png

string Figure::to_string()
{
    stringstream ss;

	ss << "nom_forme:";
	ss << this->nom_forme;
	ss << "\n";

	ss << "adresse image associee:";
	ss << this->adresse_image_associee;
	ss << "\n";



	return ss.str();

}
