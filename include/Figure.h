#ifndef FIGURE_H
#define FIGURE_H

#include <string>

using namespace std;



class Figure
{
    public:
        Figure(int p_num_forme);
        string get_nom_forme(); // Il y a 5 formes (Carré, Barre, LFigure, SFigure, TFigure)
        const char * get_adresse_image_associee(); //L'image que l'on affichera dans le jeu par exemple: .../Barre.png


        string to_string();

        virtual ~Figure();

    protected:
        string nom_forme;
        const char * adresse_image_associee;

    private:

};

#endif // FIGURE_H
