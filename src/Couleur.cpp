#include "Couleur.h"

Couleur::Couleur(gris_fonce)
{

    nom_couleur = "gris fonce";
    //ctor

    rouge = 169;
    vert = 169;
    bleu = 169;
}

Couleur::Couleur(vert)
{
    nom_couleur = "vert";


    //ctor

    rouge = 0;
    vert = 255;
    bleu = 0;
}



Couleur::Couleur(rouge)
{
    nom_couleur = "rouge";
    //ctor

    rouge = 255;
    vert = 0;
    bleu = 0;
}

Couleur::Couleur(orange)
{
    nom_couleur = "orange";
    //ctor

    rouge = 255;
    vert = 165;
    bleu = 0;
}



Couleur::Couleur(jaune)
{
    nom_couleur = "jaune";
    //ctor

    rouge = 255;
    vert = 255;
    bleu = 0;
}

Couleur::Couleur(violet)
{
    nom_couleur = "violet";
    //ctor

    rouge = 238;
    vert = 130;
    bleu = 238;
}

vioelt,cyan,bleu};

Couleur::Couleur(cyan)
{
    nom_couleur = "cyan";
    //ctor

    rouge = 43;
    vert = 255;
    bleu = 255;
}


Couleur::Couleur(bleu)
{
    nom_couleur = "bleu";
    //ctor

    rouge = 0;
    vert = 0;
    bleu = 255;
}

 vector<Couleur> Couleur::get_cellules_couleur()
{
    vector<Couleur> couleurs;

    couleurs.push_back (Couleur(gris_fonce));
    couleurs.push_back (Couleur(vert));
    couleurs.push_back (Couleur(rouge));
    couleurs.push_back (Couleur(orange));
    couleurs.push_back (Couleur(jaune));
    couleurs.push_back (Couleur(violet));
    couleurs.push_back (Couleur(cyan));
    couleurs.push_back (Couleur(bleu));


    return couleurs;
}





