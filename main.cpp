#include <iostream>
#include <random>


#include "Figure.h"
#include "Jeu.h"
#include "Grille.h"
#include "Couleur.h"
#include "Position.h"


#include "Carre.h"
#include "Barre.h"
#include "JFigure.h"
#include "LFigure.h"
#include "ZFigure.h"
#include "SFigure.h"
#include "TFigure.h"

#define LARGEUR_PREMIERE_FENETRE 1120
#define HAUTEUR_PREMIERE_FENETRE 860
#define ORIGINE_POS_X_PREMIERE_FENETRE 750
#define ORIGINE_POS_Y_PREMIERE_FENETRE 50

#define UNE_SECONDE 1000

#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>


using namespace std;


int temps_courant = 0;
int dernier_temps = 0;
int tour = 1;



//On déclare la fenêtre principale

SDL_Window *fenetre_principale;

//On déclare le rendu qui va permettre de dessiner dans la fenêtre principale

SDL_Renderer *rendu_fenetre_principale;


Jeu jeu;


void dessiner_case(SDL_FRect rect,int pos_x, int pos_y, int cellule_taille, Couleur c)
{
    rect.x = pos_x;
    rect.y = pos_y;
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

void dessiner_grille()
{
    SDL_FRect rects[jeu.grille->nb_lignes][jeu.grille->nb_colonnes];




    for(int ligne = 0 ; ligne < jeu.grille->nb_lignes ; ligne++)
    {

        for(int colonne = 0 ; colonne < jeu.grille->nb_colonnes ; colonne++)
        {
            Couleur c = Couleur (jeu.grille->contenu[ligne][colonne]);
            dessiner_case(rects[ligne][colonne],colonne*jeu.grille->taille_pixels_cellule, ligne*jeu.grille->taille_pixels_cellule, jeu.grille->taille_pixels_cellule,c);

        }




    }
}


SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }



    if (!SDL_CreateWindowAndRenderer("Tetris", LARGEUR_PREMIERE_FENETRE, HAUTEUR_PREMIERE_FENETRE, SDL_WINDOW_RESIZABLE, &fenetre_principale, &rendu_fenetre_principale)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

     if(!SDL_SetWindowPosition(fenetre_principale, ORIGINE_POS_X_PREMIERE_FENETRE, ORIGINE_POS_Y_PREMIERE_FENETRE))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Peut pas changer la position de la fenêtre %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }


    SDL_SetAppMetadata("Tetris", "1.0", "tetris");


    SDL_SetRenderDrawColor(rendu_fenetre_principale, 0, 0, 0, SDL_ALPHA_OPAQUE);  /* black, full alpha */


    SDL_RenderPresent(rendu_fenetre_principale);



    /* clear the window to the draw color. */
    //SDL_RenderClear(rendu_fenetre_principale);



     return SDL_APP_CONTINUE;
}

/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }

    switch(event->key.scancode)
    {
        case SDLK_DOWN:
            jeu.deplacer_vers_le_bas_la_figure_courante();
            break;

        case SDLK_LEFT:
            jeu.deplacer_vers_la_gauche_la_figure_courante();
            break;

        case SDLK_RIGHT:
            jeu.deplacer_vers_la_droite_la_figure_courante();
            break;
    }





    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void *appstate)
{

    temps_courant = SDL_GetTicks();


	 /* as you can see from this, rendering draws over whatever was drawn before it. */
    SDL_SetRenderDrawColor(rendu_fenetre_principale, 150, 150, 150, SDL_ALPHA_OPAQUE);  /* black, full alpha */
    SDL_RenderClear(rendu_fenetre_principale);  /* start with a blank canvas. */


     if(temps_courant > 1.5*UNE_SECONDE + dernier_temps   && tour ==1 )
     {
            jeu.grille->afficher();
            cout << endl << endl;
            tour++;
     }

    //jeu.figure_courante.dessiner(jeu.grille);

    dessiner_grille();





    SDL_RenderPresent(rendu_fenetre_principale);


    if(temps_courant > 1.5*UNE_SECONDE + dernier_temps   )
    {


        dernier_temps = temps_courant;
        jeu.deplacer_vers_le_bas_la_figure_courante();


    }






    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{

    /* SDL will clean up the window/renderer for us. */


}





