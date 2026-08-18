#include "RendererSDL.h"

RendererSDL::RendererSDL()
{
    //ctor
}

RendererSDL::~RendererSDL()
{
    //dtor
}


void RendererSDL::dessiner_grille()
{
    /*
    SDL_FRect rects[jeu.grille->nb_lignes][jeu.grille->nb_colonnes];

    for(int ligne = 0 ; ligne < jeu.grille->nb_lignes ; ligne++)
    {

        for(int colonne = 0 ; colonne < jeu.grille->nb_colonnes ; colonne++)
        {
            Couleur c = Couleur (jeu.grille->contenu[ligne][colonne]);

            rect.x = colonne*jeu.grille->taille_pixels_cellule;
            rect.y = ligne*jeu.grille->taille_pixels_cellule;
            rect.w = cellule_taille ;
            rect.h = cellule_taille;

            int r,g,b;
            r = c.rouge;
            g = c.vert;
            b = c.bleu;

            const SDL_FRect * const_rect = &rect;



            SDL_SetRenderDrawColor(rendu_fenetre_principale, r, g, b, SDL_ALPHA_OPAQUE);
            SDL_RenderFillRect(rendu_fenetre_principale, const_rect);

            SDL_SetRenderDrawColor(rendu_fenetre_principale, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderRects(rendu_fenetre_principale,const_rect,1);



        }




    }*/
}
