#ifndef COULEUR_H
#define COULEUR_H

#include <string>

enum couleur {gris_fonce,vert,rouge,orange,jaune,vioelt,cyan,bleu};


class Couleur
{
    public:
        Couleur(int p_couleur);
        vector<Couleur> get_cellules_couleur();


    protected:
        int rouge;
        int vert;
        int bleu;
        string nom_couleur;

    private:
};

#endif // COULEUR_H
