#include "Position.h"


#include <sstream>

Position::Position()
{
    ligne = -1;
    colonne = -1;
}

Position::Position(int p_ligne, int p_colonne)
{
    //ctor
    ligne = p_ligne;
    colonne = p_colonne;


}

int Position::getLigne()
{
    return ligne;
}

int Position::getColonne()
{
    return colonne;
}

string Position::toString()
{
    stringstream ss;


    ss << "(";


    ss << this->ligne;
    ss << ",";
    ss <<  this->colonne;
    ss << ")" ;


     return ss.str();
}




