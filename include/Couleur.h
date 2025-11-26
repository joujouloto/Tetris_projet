#ifndef COULEUR_H
#define COULEUR_H

#include <string>
#include <vector>

using namespace std;

enum couleur {v_ert,r_ouge,jaune,violet,cyan,b_leu,orange,gris_clair};


class Couleur
{
    public:
        Couleur();
        Couleur(int p_couleur);
        vector<Couleur> get_cellules_couleur();

        float rouge;
        float vert;
        float bleu;
        string nom_couleur;
        int id;


    protected:


    private:
};

#endif // COULEUR_H
