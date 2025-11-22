#include "Couleur.h"


Couleur::Couleur()
{
    nom_couleur = "noir";

    rouge=0;
    vert=0;
    bleu=0;
}


Couleur::Couleur( int p_couleur)
{

    switch(p_couleur)
    {



        case v_ert:

        nom_couleur = "vert";
        //ctor

        rouge = 0;
        vert = 255;
        bleu = 0;

        break;

        case r_ouge:

        nom_couleur = "rouge";
        //ctor

        rouge = 255;
        vert = 0;
        bleu = 0;
        break;

        case jaune:
        nom_couleur = "jaune";
        //ctor

        rouge = 255;
        vert = 255;
        bleu = 0;

        break;

        case violet:

         nom_couleur = "violet";
        //ctor

        rouge = 255;
        vert = 0;
        bleu = 255;

        break;

        case cyan:

        nom_couleur = "cyan";
        //ctor

        rouge = 0;
        vert = 255;
        bleu = 255;

        break;

        case b_leu:

        nom_couleur = "bleu";
        //ctor

        rouge = 0;
        vert = 0;
        bleu = 255;

        break;
    }

}


 vector<Couleur> Couleur::get_cellules_couleur()
{
    vector<Couleur> couleurs;


    couleurs.push_back (Couleur(v_ert));
    couleurs.push_back (Couleur(r_ouge));
    couleurs.push_back (Couleur(jaune));
    couleurs.push_back (Couleur(violet));
    couleurs.push_back (Couleur(cyan));
    couleurs.push_back (Couleur(b_leu));


    return couleurs;
}





