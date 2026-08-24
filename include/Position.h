#ifndef POSITION_H
#define POSITION_H


class Position
{
    public:
        Position ();
        Position(int p_ligne, int p_colonne);

        int getLigne();
        int getColonne();

    protected:
        int ligne;
        int colonne;

    private:

};

#endif // POSITION_H
