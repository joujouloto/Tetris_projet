#ifndef POSITION_H
#define POSITION_H

#include <string>

using namespace std;


class Position
{
    public:
        Position ();
        Position(int p_ligne, int p_colonne);

        int getLigne();
        int getColonne();

        string toString();

    protected:
        int ligne;
        int colonne;

    private:

};

#endif // POSITION_H
