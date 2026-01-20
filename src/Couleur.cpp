#include "Couleur.h"


Couleur::Couleur()
{
    nom_couleur = "noir";
    id=noir;

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

        id = p_couleur;

        break;

        case r_ouge:

        nom_couleur = "rouge";
        //ctor

        rouge = 255;
        vert = 0;
        bleu = 0;

        id = p_couleur;

        break;

        case jaune:
        nom_couleur = "jaune";
        //ctor

        rouge = 255;
        vert = 255;
        bleu = 0;

        id = p_couleur;

        break;

        case violet:

         nom_couleur = "violet";
        //ctor

        rouge = 255;
        vert = 0;
        bleu = 255;

        id = p_couleur;

        break;

        case cyan:

        nom_couleur = "cyan";
        //ctor

        rouge = 0;
        vert = 255;
        bleu = 255;

        id = p_couleur;

        break;

        case b_leu:

        nom_couleur = "bleu";
        //ctor

        rouge = 0;
        vert = 0;
        bleu = 255;

        id = p_couleur;

        break;

        case orange:

        nom_couleur = "orange";


        rouge = 255;
        vert = 165;
        bleu = 0;

        id = p_couleur;

        break;

        case gris_clair:

        nom_couleur = "gris_clair";

        rouge = 211;
        vert = 211;
        bleu = 211;

        id = p_couleur;

        break;

        case gris_fonce:

        nom_couleur = "gris_fonce";

        rouge = 169;
        vert = 169;
        bleu = 169;

        id = p_couleur;

        break;


        default:
        nom_couleur = "noir";
        id = 0;

        rouge=0;
        vert=0;
        bleu=0;

        break;


    }



}


 vector<Couleur> Couleur::get_cellules_couleur()
{
    vector<Couleur> couleurs;


    couleurs.push_back (Couleur(noir));
    couleurs.push_back (Couleur(v_ert));
    couleurs.push_back (Couleur(r_ouge));
    couleurs.push_back (Couleur(jaune));
    couleurs.push_back (Couleur(violet));
    couleurs.push_back (Couleur(cyan));
    couleurs.push_back (Couleur(b_leu));
    couleurs.push_back (Couleur(orange));
    couleurs.push_back (Couleur(gris_clair));


    return couleurs;
}





